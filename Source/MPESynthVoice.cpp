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
	sample_rate_ = 0;
	currently_playing_note_ = nullptr;
}

//MPESynthVoice::~MPESynthVoice(){}

//==============================================================================

//MPENote MPESynthVoice::getCurrentlyPlayingNote() noexcept {return MPENote();}
//bool MPESynthVoice::isCurrentlyPlayingNote(MPENote note) const noexcept{}
//bool MPESynthVoice::isActive() const{}
//bool MPESynthVoice::isPlayingButReleased() const noexcept{}



void MPESynthVoice::noteStarted()
{
}

void MPESynthVoice::noteStopped(bool allowTailOff)
{
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
}

void MPESynthVoice::renderNextBlock(AudioBuffer<double>& outputBuffer, int startSample, int numSamples)
{
}

//==============================================================================

//void MPESynthVoice::setCurrentSampleRate(double newRate){}
//double MPESynthVoice::getSampleRate() const noexcept { return 0.0; }
//bool MPESynthVoice::wasStartedBefore(const MPESynthesiserVoice & other) const noexcept { return false; }
//void MPESynthVoice::clearCurrentNote() noexcept{}
