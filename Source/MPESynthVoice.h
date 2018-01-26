/*
  ==============================================================================

    MPESynthVoice.h
    Created: 26 Jan 2018 12:49:14am
    Author:  john_

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

using namespace juce;

class MPESynthVoice : juce::MPESynthesiserVoice
{
public:
	//==============================================================================
	MPESynthVoice();
	~MPESynthVoice();

	//==============================================================================
	MPENote getCurrentlyPlayingNote() noexcept;
	bool isCurrentlyPlayingNote(MPENote note) const noexcept;
	bool isActive() const override;
	bool isPlayingButReleased() const noexcept;
	void noteStarted() override;
	void noteStopped(bool allowTailOff) override;
	void notePressureChanged() override;
	void notePitchbendChanged() override;
	void noteTimbreChanged() override;
	void noteKeyStateChanged() override;
	//==============================================================================
	void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
	void renderNextBlock(AudioBuffer<double>& outputBuffer, int startSample, int numSamples) override;
	//==============================================================================
	void setCurrentSampleRate(double newRate) override;
	double getSampleRate() const noexcept;
	bool wasStartedBefore(const MPESynthesiserVoice& other) const noexcept;

private:
	//==============================================================================

protected:
	//==============================================================================
	void clearCurrentNote() noexcept;

	//==============================================================================
	double currentSampleRate;
	MPENote currentlyPlayingNote;
};