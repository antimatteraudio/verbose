/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "APVTS_Params.h"
#include "APVTS_Constants.h"

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

//void VerboseAudioProcessor::getGuiParams()
//{
//    gui_var1 = verboseAPVTS.getRawParameterValue(scaleButtonOctaveState.C);
//    var1 = *gui_var1;
//    std::cout << var1 << "\r";
//}

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
    
//    auto toggleStateC = verboseAPVTS.getRawParameterValue(scaleButtonToggleState.C);
    
//    auto toggleStateCSharp = verboseAPVTS.getRawParameterValue(scaleButtonToggleState.CSharp);
    
    auto scaleButtonOctaveStateC = verboseAPVTS.getRawParameterValue(scaleButtonOctaveState.C);
    auto scaleButtonOctaveStateCSharp = verboseAPVTS.getRawParameterValue(scaleButtonOctaveState.CSharp);
    
//    getGuiParams();
    

    
//    std::cout << toggleStateC->load() << std::endl << toggleStateCSharp->load() << std::endl;
//    std::cout << scaleButtonOctaveStateC->load() << scaleButtonOctaveStateCSharp->load() << std::endl;
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

//    getAPVTSParams();
    
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
    auto state = verboseAPVTS.copyState();
    std::unique_ptr<juce::XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
}

void VerboseAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName (verboseAPVTS.state.getType()))
            verboseAPVTS.replaceState (juce::ValueTree::fromXml (*xmlState));
}

//void getStateInformation (juce::MemoryBlock& destData) override
//{
//    auto state = parameters.copyState();
//    std::unique_ptr<juce::XmlElement> xml (state.createXml());
//    copyXmlToBinary (*xml, destData);
//}

//void setStateInformation (const void* data, int sizeInBytes) override
//{
//    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
//
//    if (xmlState.get() != nullptr)
//        if (xmlState->hasTagName (parameters.state.getType()))
//            parameters.replaceState (juce::ValueTree::fromXml (*xmlState));
//}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VerboseAudioProcessor();
}
