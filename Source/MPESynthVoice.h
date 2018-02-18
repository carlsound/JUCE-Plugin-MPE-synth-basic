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
#include "ConsoleOutput.h"
#include <string>
//
using namespace juce;
//
class MPESynthVoice : public juce::MPESynthesiserVoice
{
public:
	//==============================================================================
	MPESynthVoice();
	//MPESynthVoice(int sampleRate);
	MPESynthVoice(int voiceNumber);
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
	std::unique_ptr<maxiOsc> oscillator_;
	std::unique_ptr<maxiSettings> oscillator_settings_;
	double frequency_Hz_;
	double phase;
    bool allow_tail_off_;
	std::shared_ptr<AudioBuffer<float>> audio_buffer_float_;
	std::shared_ptr<AudioBuffer<double>> audio_buffer_double_;
	std::vector<float*> channel_data_float_;
	std::vector<double*> channel_data_double_;
	int start_sample_;
	int voice_number_;
};
