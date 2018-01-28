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
	currentSampleRate = 0;
	currentlyPlayingNote = nullptr;
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
}

void MPESynthVoice::renderNextBlock(AudioBuffer<double>& outputBuffer, int startSample, int numSamples)
{
}

//==============================================================================

//void MPESynthVoice::setCurrentSampleRate(double newRate){}
//double MPESynthVoice::getSampleRate() const noexcept { return 0.0; }
//bool MPESynthVoice::wasStartedBefore(const MPESynthesiserVoice & other) const noexcept { return false; }
//void MPESynthVoice::clearCurrentNote() noexcept{}
