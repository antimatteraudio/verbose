/*
  ==============================================================================

    Params.h
    Created: 3 Dec 2022 10:25:05am
    Author:  jeph

  ==============================================================================
*/

#pragma once
#include "PluginProcessor.h"

// JXN Function to create APVTS params
juce::AudioProcessorValueTreeState::ParameterLayout
VerboseAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    
    layout.add(std::make_unique<juce::AudioParameterInt>(juce::ParameterID {"scaleButton_C",1}, "scaleButton_C",0, 1, 0));
    
    layout.add(std::make_unique<juce::AudioParameterInt>(juce::ParameterID {"scaleButton_C#",2}, "scaleButton_C#",0, 1, 0));
    
    layout.add(std::make_unique<juce::AudioParameterInt>(juce::ParameterID {"scaleButton_D",3}, "scaleButton_D",0, 1, 0));
    
    layout.add(std::make_unique<juce::AudioParameterInt>(juce::ParameterID {"scaleButton_D#",3}, "scaleButton_D#",0, 1, 0));
    
    layout.add(std::make_unique<juce::AudioParameterInt>(juce::ParameterID {"scaleButton_E",4}, "scaleButton_E",0, 1, 0));
    
    layout.add(std::make_unique<juce::AudioParameterInt>(juce::ParameterID {"scaleButton_F",4}, "scaleButton_F",0, 1, 0));
    
    return layout;
}

//Translate APVTS params to program variables
void VerboseAudioProcessor::getAPVTSParams()
{
    scaleButtParam_C = *apvts.getRawParameterValue("scaleButton_C");
    scaleButtParam_CSharp = *apvts.getRawParameterValue("scaleButton_C#");
    scaleButtParam_D = *apvts.getRawParameterValue("scaleButton_D");
    scaleButtParam_DSharp = *apvts.getRawParameterValue("scaleButton_D#");

}
