/*
  ==============================================================================

    MPESynth.cpp
    Created: 24 Jan 2018 12:33:41am
    Author:  john_

  ==============================================================================
*/

#include "MPESynth.h"

MPESynth::MPESynth()
{
}

MPESynth::MPESynth(MPEInstrument * instrument)
{
}

MPESynth::~MPESynth()
{
}

//void MPESynth::clearVoices(){}
//int MPESynth::getNumVoices(){}
//MPESynthesiserVoice * MPESynth::getVoice(int index) const{}
//void MPESynth::addVoice(MPESynthesiserVoice * newVoice){}
//void MPESynth::removeVoice(int index){}
//void MPESynth::reduceNumVoices(){}
//void MPESynth::turnOffAllVoices(bool allowTailOff){}
//void MPESynth::setVoiceStealingEnabled(bool shouldSteal){}
//bool MPESynth::isVoiceStealingEnabled() const noexcept{}
//void MPESynth::setCurrentPlaybackSampleRate(double newRate){}
//void MPESynth::handleMidiEvent(const MidiMessage &){}

void MPESynth::handleController(int, int, int)
{
}

void MPESynth::handleProgramChange(int, int)
{
}

//==============================================================================

//void MPESynth::noteAdded(MPENote newNote){}
//void MPESynth::noteReleased(MPENote finishedNote){}
//void MPESynth::notePressureChanged(MPENote changedNote){}
//void MPESynth::notePitchbendChanged(MPENote changedNote){}
//void MPESynth::noteTimbreChanged(MPENote changedNote){}
//void MPESynth::noteKeyStateChanged(MPENote changedNote){}

void MPESynth::renderNextSubBlock(AudioBuffer<float>& outputAudio, int startSample, int numSamples)
{
}

void MPESynth::renderNextSubBlock(AudioBuffer<double> &outputAudio, int startSample, int numSamples)
{
}

//MPESynthesiserVoice * MPESynth::findFreeVoice(MPENote noteToFindVoiceFor, bool stealIfNoneAvailable){}
//MPESynthesiserVoice * MPESynth::findVoiceToSteal(MPENote noteToStealVoiceFor){}
//void MPESynth::startVoice(MPESynthesiserVoice * voice, MPENote noteToStart){}
//void MPESynth::stopVoice(MPESynthesiserVoice * voice, MPENote noteToStop, bool allowTailOff){}
