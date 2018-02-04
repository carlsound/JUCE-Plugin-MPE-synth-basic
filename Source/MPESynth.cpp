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
	initialize();
}

MPESynth::MPESynth(MPEInstrument* instrument)
{
	initialize();
}

void MPESynth::initialize()
{
	mpe_synth_voices_.clear();
}

//MPESynth::~MPESynth(){}

void MPESynth::clearVoices()
{
	MPESynthesiser::clearVoices();
	mpe_synth_voices_.clear();
}

int MPESynth::getNumVoices()
{
	return MPESynthesiser::getNumVoices();
}

MPESynthesiserVoice * MPESynth::getVoice(int index) const
{
    return MPESynthesiser:: getVoice(index);
}

void MPESynth::addVoice(MPESynthesiserVoice * newVoice)
{
    MPESynthesiser::addVoice(newVoice);
}

void MPESynth::addVoice(MPESynthVoice* newVoice)
{
	mpe_synth_voices_.push_back(newVoice);
	MPESynthesiser::addVoice(newVoice);
}

void MPESynth::removeVoice(int index)
{
	MPESynthesiser::removeVoice(index);
	mpe_synth_voices_.erase(mpe_synth_voices_.begin() + index);
}

void MPESynth::reduceNumVoices(int newNumVoices)
{
	MPESynthesiser::reduceNumVoices(newNumVoices);
	mpe_synth_voices_.resize(newNumVoices);
}

void MPESynth::turnOffAllVoices(bool allowTailOff)
{
    MPESynthesiser::turnOffAllVoices(allowTailOff);
}

void MPESynth::setVoiceStealingEnabled(bool shouldSteal)
{
	MPESynthesiser::setVoiceStealingEnabled(shouldSteal);
}

bool MPESynth::isVoiceStealingEnabled() const noexcept
{
	return MPESynthesiser::isVoiceStealingEnabled();
}

void MPESynth::setCurrentPlaybackSampleRate(double newRate)
{
	MPESynthesiser::setCurrentPlaybackSampleRate(newRate);
	for_each(mpe_synth_voices_.begin(), mpe_synth_voices_.end(), [&](MPESynthVoice* voice)
	{
		voice->setCurrentSampleRate(newRate);
	});
}

void MPESynth::handleMidiEvent(const MidiMessage& m)
{
	MPESynthesiser::handleMidiEvent(m);
}

void MPESynth::handleController(int, int, int)
{
}

void MPESynth::handleProgramChange(int, int)
{
}

//==============================================================================

void MPESynth::enableLegacyMode(int pitchbendRange, Range< int > channelRange)
{
    MPESynthesiser::enableLegacyMode(pitchbendRange, channelRange);
}

//==============================================================================

void MPESynth::noteAdded(MPENote newNote)
{
	MPESynthesiser::noteAdded(newNote);
}

void MPESynth::noteReleased(MPENote finishedNote)
{
	MPESynthesiser::noteReleased(finishedNote);
}

void MPESynth::notePressureChanged(MPENote changedNote)
{
	MPESynthesiser::notePressureChanged(changedNote);
}

void MPESynth::notePitchbendChanged(MPENote changedNote)
{
	MPESynthesiser::notePitchbendChanged(changedNote);
}

void MPESynth::noteTimbreChanged(MPENote changedNote)
{
	MPESynthesiser::noteTimbreChanged(changedNote);
}

void MPESynth::noteKeyStateChanged(MPENote changedNote)
{
	MPESynthesiser::noteKeyStateChanged(changedNote);
}

void MPESynth::renderNextSubBlock(AudioBuffer<float>& outputAudio, int startSample, int numSamples)
{
}

void MPESynth::renderNextSubBlock(AudioBuffer<double> &outputAudio, int startSample, int numSamples)
{
}

MPESynthesiserVoice * MPESynth::findFreeVoice(MPENote noteToFindVoiceFor, bool stealIfNoneAvailable)
{
    return MPESynthesiser::findFreeVoice(noteToFindVoiceFor, stealIfNoneAvailable);
}

MPESynthesiserVoice * MPESynth::findVoiceToSteal(MPENote noteToStealVoiceFor)
{
    return MPESynthesiser::findVoiceToSteal(noteToStealVoiceFor);
}

void MPESynth::startVoice(MPESynthesiserVoice * voice, MPENote noteToStart)
{
	MPESynthesiser::startVoice(voice, noteToStart);
}

void MPESynth::stopVoice(MPESynthesiserVoice * voice, MPENote noteToStop, bool allowTailOff)
{
	MPESynthesiser::stopVoice(voice, noteToStop, allowTailOff);
}
