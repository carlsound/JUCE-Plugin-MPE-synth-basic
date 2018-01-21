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

void MidiInCallback::handleIncomingMidiMessage(MidiInput* source, const MidiMessage &message)
{
}

void MidiInCallback::handlePartialSysexMessage(MidiInput* source, const uint8 *messageData, int numBytesSoFar, double timestamp)
{
}
