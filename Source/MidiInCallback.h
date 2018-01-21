/*
  ==============================================================================

    MidiInCallback.h
    Created: 14 Jan 2018 10:32:10pm
    Author:  John Carlson

  ==============================================================================
*/

#pragma once
#include "juce_audio_devices/midi_io/juce_MidiInput.h"
#include "juce_audio_devices/midi_io/juce_MidiMessageCollector.h"
#include "juce_audio_basics\midi\juce_MidiMessage.h"
#include "juce_core/maths/juce_MathsFunctions.h"

//==============================================================================
class MidiInCallback : juce::MidiInputCallback
{
	MidiInCallback();
	~MidiInCallback();
	//==============================================================================

	
public:
	void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message);
	void handlePartialSysexMessage(juce::MidiInput* source, const juce::uint8* messageData, int numBytesSoFar, double timestamp);
};