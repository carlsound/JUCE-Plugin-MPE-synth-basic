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

using namespace juce;

//==============================================================================
class MidiInCallback : virtual MidiInputCallback
{
	MidiInCallback();
	~MidiInCallback();
	//==============================================================================

	
public:
	void handleIncomingMidiMessage(MidiInput *source, const MidiMessage &message);
	void handlePartialSysexMessage(MidiInput *source, const uint8 *messageData, int numBytesSoFar, double timestamp);
};