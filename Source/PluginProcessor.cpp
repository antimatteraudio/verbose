/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "APVTS_Params.h"

//==============================================================================
VerboseAudioProcessor::VerboseAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

VerboseAudioProcessor::~VerboseAudioProcessor()
{
}

//==============================================================================
const juce::String VerboseAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool VerboseAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool VerboseAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool VerboseAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double VerboseAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VerboseAudioProcessor::getNumPrograms()
{
    return 1;
}

int VerboseAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VerboseAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String VerboseAudioProcessor::getProgramName (int index)
{
    return {};
}

void VerboseAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void VerboseAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void VerboseAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool VerboseAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
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

void VerboseAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    getAPVTSParams();
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
    }
}

//==============================================================================
bool VerboseAudioProcessor::hasEditor() const
{
    return true; 
}

juce::AudioProcessorEditor* VerboseAudioProcessor::createEditor()
{
    return new VerboseAudioProcessorEditor (*this);
}

//==============================================================================
void VerboseAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
}

void VerboseAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VerboseAudioProcessor();
}
