/*
  ==============================================================================

    MPEInstrumentListener.h
    Created: 14 Jan 2018 10:39:03pm
    Author:  John Carlson

  ==============================================================================
*/

#pragma once
#include "juce_audio_basics/mpe/juce_MPEInstrument.h"
#include "juce_audio_basics/mpe/juce_MPENote.h"
#include "juce_audio_basics/mpe/juce_MPESynthesiserBase.h"
#include "juce_audio_basics/mpe/juce_MPESynthesiser.h"


using namespace juce;

class MidiInstrumentListener : virtual MPESynthesiser
{
	MidiInstrumentListener();
	~MidiInstrumentListener();

public:
	void noteAdded(MPENote newNote);
	void notePressureChanged(MPENote changedNote);
	void notePitchbendChanged(MPENote changedNote);
	void noteTimbreChanged(MPENote changedNote);
	void noteKeyStateChanged(MPENote changedNote);
	void noteReleased(MPENote finishedNote);
};
