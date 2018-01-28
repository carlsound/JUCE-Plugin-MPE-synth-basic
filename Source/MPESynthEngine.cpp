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

}

//void MPESynthEngine::handlePartialSysexMessage(MidiInput* source, const uint8 *messageData, int numBytesSoFar, double timestamp){}

void MPESynthEngine::prepareToPlay(double sampleRate, int samplesPerBlock)
{
}

void MPESynthEngine::processBlock(AudioSampleBuffer &)
{
	/*
	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
	float* channelData = buffer.getWritePointer (channel);

	// ..do something to the data...
	}
	*/
}
