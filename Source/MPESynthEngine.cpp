/*
  ==============================================================================

    MidiInCallback.cpp
    Created: 14 Jan 2018 10:32:10pm
    Author:  John Carlson

  ==============================================================================
*/

#include "MPESynthEngine.h"


//==============================================================================

MPESynthEngine::MPESynthEngine()
{
	mpeSynthesiser = std::unique_ptr<MPESynthesiser>{ new MPESynthesiser };
	mpeSynthesiser->enableLegacyMode(24);
	mpeSynthesiser->setVoiceStealingEnabled(false);
	//
	midiMessageCollector = std::unique_ptr<MidiMessageCollector>{ new MidiMessageCollector };
	//
	voicesArray.resize(numVoices);
	std::for_each(voicesArray.begin(), voicesArray.end(), [&]()
	{
		mpeSynthVoice = std::shared_ptr<MPESynthVoice*>{ new MPESynthVoice* };
		mpeSynthesiser->addVoice(*mpeSynthVoice);
	});
}

//MPESynthEngine::~MPESynthEngine(){}

void MPESynthEngine::handleIncomingMidiMessage(MidiInput* source, const MidiMessage &message)
{
	midiMessageCollector->addMessageToQueue();
}

//void MPESynthEngine::handlePartialSysexMessage(MidiInput* source, const uint8 *messageData, int numBytesSoFar, double timestamp){}

void MPESynthEngine::prepareToPlay(double sampleRate, int samplesPerBlock)
{
}

void MPESynthEngine::processBlock(AudioSampleBuffer& buffer, int numInputChannels, int numOutputChannels, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;
	const int totalNumInputChannels = numInputChannels;
	const int totalNumOutputChannels = numOutputChannels;

	// In case we have more outputs than inputs, this code clears any output
	// channels that didn't contain input data, (because these aren't
	// guaranteed to be empty - they may contain garbage).
	// This is here to avoid people getting screaming feedback
	// when they first compile a plugin, but obviously you don't need to keep
	// this code if your algorithm always overwrites all the output channels.
	for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());

	// This is the place where you'd normally do the guts of your plugin's
	// audio processing...
	
	/*
	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
	float* channelData = buffer.getWritePointer (channel);

	// ..do something to the data...
	}
	*/
}
