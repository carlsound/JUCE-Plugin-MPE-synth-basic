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

using namespace juce;

class MPESynth : MPESynthesiser
{
public:
	MPESynth();
	explicit MPESynth(MPEInstrument *instrument);
	~MPESynth();

	//==============================================================================

	void clearVoices();
	int getNumVoices();
	MPESynthesiserVoice* getVoice(int index) const;
	void addVoice(MPESynthesiserVoice* newVoice);
	void removeVoice(int index);
	void reduceNumVoices();
	void turnOffAllVoices(bool allowTailOff);
	void setVoiceStealingEnabled(bool shouldSteal);
	bool isVoiceStealingEnabled() const noexcept;
	void setCurrentPlaybackSampleRate(double newRate);
	void handleMidiEvent(const MidiMessage&);
	void handleController(int, int, int);
	void handleProgramChange(int, int);

	//==============================================================================

protected:
	void noteAdded(MPENote newNote);
	void noteReleased(MPENote finishedNote);
	void notePressureChanged(MPENote changedNote);
	void notePitchbendChanged(MPENote changedNote);
	void noteTimbreChanged(MPENote changedNote);
	void noteKeyStateChanged(MPENote changedNote);
	void renderNextSubBlock(AudioBuffer<float> &outputAudio, int startSample, int numSamples);
	void renderNextSubBlock(AudioBuffer<double> &outputAudio, int startSample, int numSamples);
	MPESynthesiserVoice* findFreeVoice(MPENote noteToFindVoiceFor, bool stealIfNoneAvailable);
	MPESynthesiserVoice* findVoiceToSteal(MPENote noteToStealVoiceFor);
	void startVoice(MPESynthesiserVoice* voice, MPENote noteToStart);
	void stopVoice(MPESynthesiserVoice* voice, MPENote noteToStop, bool allowTailOff);

private:
};