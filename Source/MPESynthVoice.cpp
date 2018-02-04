/*
  ==============================================================================

    MPESynthVoice.cpp
    Created: 26 Jan 2018 12:49:14am
    Author:  john_

  ==============================================================================
*/

#include "MPESynthVoice.h"

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
	//currently_playing_note_ = nullptr;
	//oscillator = std::shared_ptr<maxiOsc>{ new maxiOsc };
	oscillator = std::make_shared<maxiOsc>();
	//oscillator_settings_ = std::shared_ptr<maxiSettings>{ new maxiSettings };
	oscillator_settings_ = std::make_shared<maxiSettings>();
	phase = 0.0;
    allow_tail_off_ = true;
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
		phase = 0.0;
	}
}

void MPESynthVoice::noteStopped(bool allowTailOff)
{
    allow_tail_off_ = allowTailOff;
    if(allowTailOff)
    {
        
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
}

void MPESynthVoice::noteTimbreChanged()
{
}

void MPESynthVoice::noteKeyStateChanged()
{
	key_state_previous_ = currentlyPlayingNote.keyState;
	if (MPENote::keyDown == currentlyPlayingNote.keyState)
	{
	}
	if (MPENote::sustained == currentlyPlayingNote.keyState)
	{
	}
	if (MPENote::keyDownAndSustained == currentlyPlayingNote.keyState)
	{
	}
}

//==============================================================================

void MPESynthVoice::renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	ScopedNoDenormals noDenormals;
	const int totalNumChannels = outputBuffer.getNumChannels();
	//
	// This is the place where you'd normally do the guts of your plugin's
	// audio processing...
	/*
	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		float* channelData = buffer.getWritePointer (channel);

		// ..do something to the data...
	}
	*/
    if(allow_tail_off_)
    {
        clearCurrentNote();
    }
	for (int sample = startSample; sample < (startSample + numSamples); ++sample)
	{
		sample_amplitude_ = oscillator->sinewave(frequency_Hz_);
		for(int channel = 0; channel < totalNumChannels; ++channel)
		{
			float* channelData = outputBuffer.getWritePointer(channel);
			channelData[sample] = static_cast<float>(sample_amplitude_);
		}
	}
}

void MPESynthVoice::renderNextBlock(AudioBuffer<double>& outputBuffer, int startSample, int numSamples)
{
	ScopedNoDenormals noDenormals;
	const int totalNumChannels = outputBuffer.getNumChannels();
    //
    if(allow_tail_off_)
    {
        clearCurrentNote();
    }
    for (int sample = startSample; sample < (startSample + numSamples); ++sample)
    {
        sample_amplitude_ = oscillator->sinewave(frequency_Hz_);
        for(int channel = 0; channel < totalNumChannels; ++channel)
        {
            double* channelData = outputBuffer.getWritePointer(channel);
            channelData[sample] = sample_amplitude_;
        }
    }
}

//==============================================================================

//void MPESynthVoice::setCurrentSampleRate(double newRate){}
//double MPESynthVoice::getSampleRate() const noexcept { return 0.0; }
//bool MPESynthVoice::wasStartedBefore(const MPESynthesiserVoice & other) const noexcept { return false; }
//void MPESynthVoice::clearCurrentNote() noexcept{}
