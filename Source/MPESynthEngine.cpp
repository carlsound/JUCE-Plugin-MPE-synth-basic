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
	//mpe_synthesiser_ = std::unique_ptr<MPESynthesiser>{ new MPESynthesiser };
	mpe_synthesiser_ = std::make_shared<MPESynthesiser>();
    //mpe_synthesiser_ = new MPESynthesiser();
	//
    mpe_synthesiser_->enableLegacyMode(24);
	mpe_synthesiser_->setVoiceStealingEnabled(false);
	//
	//midi_message_collector_ = std::unique_ptr<MidiMessageCollector>{ new MidiMessageCollector };
	//midi_message_collector_ = std::make_unique<MidiMessageCollector>();
    //midi_message_collector_ = new MidiMessageCollector();
	//
    /*
	voices_array_.resize(number_of_voices_);
	std::for_each(voices_array_.begin(), voices_array_.end(), [&](MPESynthVoice* voice )
	{
		//mpe_synth_voice_ = std::shared_ptr<MPESynthVoice*>{ new MPESynthVoice* };
		mpe_synth_voice_ = std::make_shared<MPESynthVoice *>();
		mpe_synthesiser_->addVoice(*mpe_synth_voice_);
	});
     */
    for(int qty_of_voices_ = 0; qty_of_voices_ < number_of_voices_; ++qty_of_voices_)
    {
        //mpe_synth_voice_ = std::make_shared<MPESynthVoice *>();
        //mpe_synthesiser_->addVoice(*mpe_synth_voice_);
        mpe_synthesiser_->addVoice(new MPESynthVoice);
    }
	//
	sample_rate_ = 44100;
	samples_per_block_ = 0;
}

//MPESynthEngine::~MPESynthEngine(){}

void MPESynthEngine::handleIncomingMidiMessage(MidiInput* source, const MidiMessage &message)
{
	//midi_message_collector_->addMessageToQueue(message);
    midi_message_collector_.addMessageToQueue(message);
}

//void MPESynthEngine::handlePartialSysexMessage(MidiInput* source, const uint8 *messageData, int numBytesSoFar, double timestamp){}

void MPESynthEngine::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	sample_rate_ = sampleRate;
    //midi_message_collector_->reset(sample_rate_);
    midi_message_collector_.reset(sample_rate_);
	mpe_synthesiser_->setCurrentPlaybackSampleRate(sampleRate);
	samples_per_block_ = samplesPerBlock;
}

void MPESynthEngine::processBlock(AudioSampleBuffer& buffer, int numInputChannels, int numOutputChannels, MidiBuffer& midiMessages)
{
	//midi_message_collector_->removeNextBlockOfMessages(midiMessages, samples_per_block_);
    midi_message_collector_.removeNextBlockOfMessages(midiMessages, samples_per_block_);
	//
	mpe_synthesiser_->renderNextBlock(buffer, midiMessages, 0, samples_per_block_);
}
