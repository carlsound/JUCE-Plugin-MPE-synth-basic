/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/
#include <numeric>
//
#include "PluginProcessor.h"
#include "PluginEditor.h"
//
//==============================================================================
JucepluginmpesynthbasicAudioProcessor::JucepluginmpesynthbasicAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	mpeSynthEngine = std::unique_ptr<MPESynthEngine>{ new MPESynthEngine };
}

//JucepluginmpesynthbasicAudioProcessor::~JucepluginmpesynthbasicAudioProcessor(){}

//==============================================================================
const String JucepluginmpesynthbasicAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool JucepluginmpesynthbasicAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool JucepluginmpesynthbasicAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool JucepluginmpesynthbasicAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double JucepluginmpesynthbasicAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int JucepluginmpesynthbasicAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int JucepluginmpesynthbasicAudioProcessor::getCurrentProgram()
{
    return 0;
}

void JucepluginmpesynthbasicAudioProcessor::setCurrentProgram (int index)
{
}

const String JucepluginmpesynthbasicAudioProcessor::getProgramName (int index)
{
    return {};
}

void JucepluginmpesynthbasicAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void JucepluginmpesynthbasicAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	mpeSynthEngine->prepareToPlay(sampleRate, samplesPerBlock);
}

void JucepluginmpesynthbasicAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool JucepluginmpesynthbasicAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void JucepluginmpesynthbasicAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    /*
	for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
	*/

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...

	mpeSynthEngine->processBlock(buffer, totalNumInputChannels, totalNumOutputChannels, midiMessages);

	/*
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
	*/
}

//==============================================================================
bool JucepluginmpesynthbasicAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* JucepluginmpesynthbasicAudioProcessor::createEditor()
{
    return new JucepluginmpesynthbasicAudioProcessorEditor (*this);
}

//==============================================================================
void JucepluginmpesynthbasicAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void JucepluginmpesynthbasicAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JucepluginmpesynthbasicAudioProcessor();
}
