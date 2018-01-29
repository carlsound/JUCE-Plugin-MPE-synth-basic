/*
  ==============================================================================

    MidiInCallback.h
    Created: 14 Jan 2018 10:32:10pm
    Author:  John Carlson

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
//#include "juce_audio_devices/midi_io/juce_MidiInput.h"
//#include "juce_audio_devices/midi_io/juce_MidiMessageCollector.h"
//#include "juce_audio_basics\midi\juce_MidiMessage.h"
//#include "juce_core/maths/juce_MathsFunctions.h"
//
#include "MPESynthVoice.h"
//
using namespace juce;

//==============================================================================
class MPESynthEngine : protected MidiInputCallback
{
public:
	//==============================================================================
	MPESynthEngine();
	~MPESynthEngine() = default;

	//==============================================================================
	void handleIncomingMidiMessage(MidiInput *source, const MidiMessage &message) override;
	//void handlePartialSysexMessage(MidiInput *source, const uint8 *messageData, int numBytesSoFar, double timestamp);

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock);
	void processBlock(AudioSampleBuffer&, int numInputChannels, int numOutputChannels, MidiBuffer& midiMessages);

protected:
	//==============================================================================

private:
	//==============================================================================
	std::unique_ptr<MPESynthesiser> mpeSynthesiser;
	std::shared_ptr<MPESynthVoice*> mpeSynthVoice;
	//
	std::unique_ptr<MidiMessageCollector> midiMessageCollector;
	//
	const int numVoices = 10;
	std::vector<int> voicesArray;
};