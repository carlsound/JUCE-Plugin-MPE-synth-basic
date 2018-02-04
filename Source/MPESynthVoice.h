/*
  ==============================================================================

    MPESynthVoice.h
    Created: 26 Jan 2018 12:49:14am
    Author:  john_

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
//
#include "../3rdPartyLibraryCode/maximilian.h"
//
using namespace juce;
//
class MPESynthVoice : public juce::MPESynthesiserVoice
{
public:
	//==============================================================================
	MPESynthVoice();
	MPESynthVoice(int sampleRate);
	//
	~MPESynthVoice() = default;

	//==============================================================================
	void setCurrentSampleRate(int sampleRate);
	//==============================================================================
	//MPENote getCurrentlyPlayingNote() noexcept;
	//bool isCurrentlyPlayingNote(MPENote note) const noexcept;
	//bool isActive() const override;
	//bool isPlayingButReleased() const noexcept;
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
	//void setCurrentSampleRate(double newRate) override;
	//double getSampleRate() const noexcept;
	//bool wasStartedBefore(const MPESynthesiserVoice& other) const noexcept;

//private:
	//==============================================================================

protected:
	//==============================================================================
	//void clearCurrentNote() noexcept;
	void initialize();

	//==============================================================================
	double sample_rate_;
	double sample_amplitude_;
	int key_state_previous_;
	std::shared_ptr<maxiOsc> oscillator;
	std::shared_ptr<maxiSettings> oscillator_settings_;
	double frequency_Hz_;
	double phase;
    bool allow_tail_off_;
	std::vector<float*> channelDataFloat;
	std::vector<double*> channelDataDouble;
};
