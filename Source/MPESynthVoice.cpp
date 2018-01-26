/*
  ==============================================================================

    MPESynthVoice.cpp
    Created: 26 Jan 2018 12:49:14am
    Author:  john_

  ==============================================================================
*/

#include "MPESynthVoice.h"

MPENote MPESynthVoice::getCurrentlyPlayingNote() noexcept
{
	return MPENote();
}

bool MPESynthVoice::isCurrentlyPlayingNote(MPENote note) const noexcept
{
	return false;
}

bool MPESynthVoice::isActive() const
{
	return false;
}

bool MPESynthVoice::isPlayingButReleased() const noexcept
{
	return false;
}

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

void MPESynthVoice::renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
}

void MPESynthVoice::renderNextBlock(AudioBuffer<double>& outputBuffer, int startSample, int numSamples)
{
}

void MPESynthVoice::setCurrentSampleRate(double newRate)
{
}

double MPESynthVoice::getSampleRate() const noexcept
{
	return 0.0;
}

bool MPESynthVoice::wasStartedBefore(const MPESynthesiserVoice & other) const noexcept
{
	return false;
}

void MPESynthVoice::clearCurrentNote() noexcept
{
}
