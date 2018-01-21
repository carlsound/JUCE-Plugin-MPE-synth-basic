/*
  ==============================================================================

    MidiInCallback.cpp
    Created: 14 Jan 2018 10:32:10pm
    Author:  John Carlson

  ==============================================================================
*/

#include "MidiInCallback.h"


//==============================================================================

MidiInCallback::MidiInCallback()
{
}

MidiInCallback::~MidiInCallback()
{
}

void MidiInCallback::handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message)
{
}

void MidiInCallback::handlePartialSysexMessage(juce::MidiInput* source, const juce::uint8* messageData, int numBytesSoFar, double timestamp)
{
}
