/*
  ==============================================================================

    MidiInCallback.cpp
    Created: 14 Jan 2018 10:32:10pm
    Author:  John Carlson

  ==============================================================================
*/

#include "MPESynthEngine.h"
#include <locale>


//==============================================================================

MPESynthEngine::MPESynthEngine()
{
	//mpe_synthesiser_ = std::make_shared<MPESynthesiser>();
	//
    mpe_synthesiser_.enableLegacyMode(24);
	mpe_synthesiser_.setVoiceStealingEnabled(true);
	//
	sample_rate_ = 44100;
	samples_per_block_ = 480;
	//
	mpe_synthesiser_.setCurrentPlaybackSampleRate(sample_rate_);
	//
	for (int qty_of_voices_ = 0; qty_of_voices_ < number_of_voices_; ++qty_of_voices_)
	{
		mpe_synthesiser_.addVoice(new MPESynthVoice(qty_of_voices_+1));
	}
}

MPESynthEngine::~MPESynthEngine()
{
	//mpe_synth_voice_ = nullptr;
	//mpe_synthesiser_ = nullptr;
}

//==============================================================================

void MPESynthEngine::handleIncomingMidiMessage(MidiInput* source, const MidiMessage &message)
{
    midi_message_collector_.addMessageToQueue(message);
	//
	//
	/*
	if (SystemStats::getOperatingSystemType() && SystemStats::OperatingSystemType::MacOSX)
	{
		std::cout << message.getDescription();
	}
	if (SystemStats::getOperatingSystemType() && SystemStats::OperatingSystemType::Windows)
	{
		OutputDebugStringA(message.getDescription().toStdString().c_str());
		OutputDebugStringA("\n");
	}
	*/
	//ConsoleOutput *co = new ConsoleOutput();
	//*co << message.getDescription();
	//co->consoleOutput(message.getDescription());
	//
	//ConsoleOutput::consoleOutput(message.getDescription());
}

//void MPESynthEngine::handlePartialSysexMessage(MidiInput* source, const uint8 *messageData, int numBytesSoFar, double timestamp){}

//==============================================================================

MidiInputCallback * MPESynthEngine::getMidiInputCallback()
{
	return this;
}

void MPESynthEngine::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	sample_rate_ = sampleRate;
	samples_per_block_ = samplesPerBlock;
	//
    midi_message_collector_.reset(sample_rate_);
	mpe_synthesiser_.setCurrentPlaybackSampleRate(sample_rate_);
}

//void MPESynthEngine::processBlock(AudioSampleBuffer& buffer, int numInputChannels, int numOutputChannels, MidiBuffer& midiMessages)
void MPESynthEngine::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    midi_message_collector_.removeNextBlockOfMessages(midiMessages, samples_per_block_);
	//
	/*
	int num_events_ = midiMessages.getNumEvents();
	MidiMessage message;
	MidiBuffer::Iterator mbi(midiMessages);
	for (int event = 0; event < num_events_; ++event)
	{
		if (mbi.getNextEvent(message, event))
		{
			//std::cout << message.getDescription();
			//ConsoleOutput::consoleOutput(message.getDescription());
		}
	}
	*/
	//
	mpe_synthesiser_.renderNextBlock(buffer, midiMessages, 0, samples_per_block_);
}
