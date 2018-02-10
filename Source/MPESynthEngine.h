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
//#include "MPESynth.h"
#include "MPESynthVoice.h"
//
using namespace juce;

//==============================================================================
class MPESynthEngine : public MidiInputCallback
{
public:
	//==============================================================================
	MPESynthEngine();
	~MPESynthEngine();

	//==============================================================================
	void handleIncomingMidiMessage(MidiInput *source, const MidiMessage &message) override;
	//void handlePartialSysexMessage(MidiInput *source, const uint8 *messageData, int numBytesSoFar, double timestamp);

	//==============================================================================
	MidiInputCallback* getMidiInputCallback();

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock);
	void processBlock(AudioSampleBuffer&, int numInputChannels, int numOutputChannels, MidiBuffer& midiMessages);

protected:
	//==============================================================================

private:
	//==============================================================================
	std::shared_ptr<MPESynthesiser> mpe_synthesiser_;
	std::shared_ptr<MPESynthVoice*> mpe_synth_voice_;
	//
    MidiMessageCollector midi_message_collector_;
	//
	const int number_of_voices_ = 10;
	//
	double sample_rate_;
	int samples_per_block_;
};
