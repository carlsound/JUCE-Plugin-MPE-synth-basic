/*
  ==============================================================================

    MPESynth.h
    Created: 24 Jan 2018 12:33:41am
    Author:  john_

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
//#include "juce_audio_basics/buffers/juce_AudioSampleBuffer.h"
//#include "juce_audio_basics/midi/juce_MidiMessage.h"
//#include "juce_audio_basics/mpe/juce_MPENote.h"
//#include "juce_audio_basics/mpe/juce_MPESynthesiser.h"
//#include "juce_audio_basics/mpe/juce_MPEInstrument.h"
//#include "juce_audio_basics/mpe/juce_MPESynthesiserVoice.h"

#include "MPESynthVoice.h"
#include "MPESynthVoice.h"

using namespace juce;

class MPESynth : public MPESynthesiser
{
public:
	MPESynth();
	explicit MPESynth(MPEInstrument *instrument);
	~MPESynth() = default;

	//==============================================================================

	void clearVoices();
	int getNumVoices();
	MPESynthesiserVoice* getVoice(int index) const;
	void addVoice(MPESynthesiserVoice* newVoice);
	void addVoice(MPESynthVoice* newVoice);
	void removeVoice(int index);
	void reduceNumVoices(int newNumVoices);
	void turnOffAllVoices(bool allowTailOff) override;
	void setVoiceStealingEnabled(bool shouldSteal);
	bool isVoiceStealingEnabled() const noexcept;
	void setCurrentPlaybackSampleRate(double newRate) override;
	void handleMidiEvent(const MidiMessage& m) override;
	void handleController(int, int, int) override;
	void handleProgramChange(int, int) override;

	//==============================================================================
    
    void enableLegacyMode(int pitchbendRange = 2, Range< int > channelRange = Range< int >(1, 17));

	//==============================================================================

protected:
	void noteAdded(MPENote newNote) override;
	void noteReleased(MPENote finishedNote) override;
	void notePressureChanged(MPENote changedNote) override;
	void notePitchbendChanged(MPENote changedNote) override;
	void noteTimbreChanged(MPENote changedNote) override;
	void noteKeyStateChanged(MPENote changedNote) override;
	void renderNextSubBlock(AudioBuffer<float> &outputAudio, int startSample, int numSamples) override;
	void renderNextSubBlock(AudioBuffer<double> &outputAudio, int startSample, int numSamples)override;
	MPESynthesiserVoice* findFreeVoice(MPENote noteToFindVoiceFor, bool stealIfNoneAvailable);
	MPESynthesiserVoice* findVoiceToSteal(MPENote noteToStealVoiceFor);
	void startVoice(MPESynthesiserVoice* voice, MPENote noteToStart);
	void stopVoice(MPESynthesiserVoice* voice, MPENote noteToStop, bool allowTailOff);

private:
	void initialize();
	std::vector<MPESynthVoice*> mpe_synth_voices_;
};
