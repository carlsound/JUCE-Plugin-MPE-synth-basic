/*
  ==============================================================================

    MPESynthVoice.cpp
    Created: 26 Jan 2018 12:49:14am
    Author:  john_

  ==============================================================================
*/

#include "MPESynthVoice.h"
#include <numeric>

MPESynthVoice::MPESynthVoice()
{
	initialize();
}

MPESynthVoice::MPESynthVoice(int sampleRate)
{
	initialize();
	setCurrentSampleRate(sampleRate);
}

void MPESynthVoice::initialize()
{
    setCurrentSampleRate(44100);
	oscillator_ = std::make_shared<maxiOsc>();
	oscillator_settings_ = std::make_shared<maxiSettings>();
	phase = 0.0;
    allow_tail_off_ = false;
	channel_data_float_.clear();
	channel_data_double_.clear();
	audio_buffer_float_ = std::make_shared<AudioBuffer<float>>();
	audio_buffer_double_ = std::make_shared<AudioBuffer<double>>();
}


//MPESynthVoice::~MPESynthVoice(){}

//==============================================================================
void MPESynthVoice::setCurrentSampleRate(int sampleRate)
{
	sample_rate_ = sampleRate;
	oscillator_settings_->sampleRate = sampleRate;
}

//==============================================================================

//MPENote MPESynthVoice::getCurrentlyPlayingNote() noexcept {return MPENote();}
//bool MPESynthVoice::isCurrentlyPlayingNote(MPENote note) const noexcept{}
//bool MPESynthVoice::isActive() const{}
//bool MPESynthVoice::isPlayingButReleased() const noexcept{}

void MPESynthVoice::noteStarted()
{
	if( currentlyPlayingNote.isValid()
		&& 
		(MPENote::keyDown == currentlyPlayingNote.keyState
			||
			MPENote::keyDownAndSustained == currentlyPlayingNote.keyState) )
	{
		frequency_Hz_ = currentlyPlayingNote.getFrequencyInHertz(sample_rate_);
		//phase = 0.0;
	}
}

void MPESynthVoice::noteStopped(bool allowTailOff)
{
    allow_tail_off_ = allowTailOff;
    if(allow_tail_off_)
    {
		clearCurrentNote();
    }
    else
    {
        clearCurrentNote();
    }
}

void MPESynthVoice::notePressureChanged()
{
}

void MPESynthVoice::notePitchbendChanged()
{
	frequency_Hz_ = currentlyPlayingNote.getFrequencyInHertz(sample_rate_);
}

void MPESynthVoice::noteTimbreChanged()
{
	frequency_Hz_ = currentlyPlayingNote.getFrequencyInHertz(sample_rate_);
}

void MPESynthVoice::noteKeyStateChanged()
{
	key_state_previous_ = currentlyPlayingNote.keyState;
	if (MPENote::keyDown == currentlyPlayingNote.keyState)
	{
		frequency_Hz_ = currentlyPlayingNote.getFrequencyInHertz(sample_rate_);
	}
	if (MPENote::sustained == currentlyPlayingNote.keyState)
	{
		frequency_Hz_ = currentlyPlayingNote.getFrequencyInHertz(sample_rate_);
	}
	if (MPENote::keyDownAndSustained == currentlyPlayingNote.keyState)
	{
		frequency_Hz_ = currentlyPlayingNote.getFrequencyInHertz(sample_rate_);
	}
}

//==============================================================================

void MPESynthVoice::renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	ScopedNoDenormals noDenormals;
	const int totalNumChannels = outputBuffer.getNumChannels();
	*audio_buffer_float_ = outputBuffer;
	start_sample_ = startSample;
	channel_data_float_ = std::vector<float*>(totalNumChannels);
	//
	std::cout << "\n" << "start sample = " << startSample;
	//
	for (int channel = 0; channel < totalNumChannels; ++channel)
	
	{
		channel_data_float_[channel] = outputBuffer.getWritePointer(channel);
	}
	//
	/*
    if(allow_tail_off_)
    {
		//
        clearCurrentNote();
    }
	*/
	//
	for (int sample = startSample; sample < (startSample + numSamples); ++sample)
	{
		sample_amplitude_ = oscillator_->sinewave(frequency_Hz_);
		for(int channel = 0; channel < totalNumChannels; ++channel)
		{
			channel_data_float_[channel][sample] = static_cast<float>(sample_amplitude_);
		}
	}
}

void MPESynthVoice::renderNextBlock(AudioBuffer<double>& outputBuffer, int startSample, int numSamples)
{
	ScopedNoDenormals noDenormals;
	const int totalNumChannels = outputBuffer.getNumChannels();
	*audio_buffer_double_ = outputBuffer;
	start_sample_ = startSample;
	channel_data_double_ = std::vector<double*>(totalNumChannels);
	for (int channel = 0; channel < totalNumChannels; ++channel)
	{
		channel_data_double_[channel] = outputBuffer.getWritePointer(channel);
	}
	//
	/*
    if(allow_tail_off_)
    {
		//
        clearCurrentNote();
    }
	*/
    for (int sample = startSample; sample < (startSample + numSamples); ++sample)
	{
		sample_amplitude_ = oscillator_->sinewave(frequency_Hz_);
		for (int channel = 0; channel < totalNumChannels; ++channel)
		{
			channel_data_double_[channel][sample] = sample_amplitude_;
		}
	}
}

//==============================================================================

//void MPESynthVoice::setCurrentSampleRate(double newRate){}
//double MPESynthVoice::getSampleRate() const noexcept { return 0.0; }
//bool MPESynthVoice::wasStartedBefore(const MPESynthesiserVoice & other) const noexcept { return false; }
//void MPESynthVoice::clearCurrentNote() noexcept{}
