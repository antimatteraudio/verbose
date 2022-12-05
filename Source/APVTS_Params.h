/*
  ==============================================================================

    Params.h
    Created: 3 Dec 2022 10:25:05am
    Author:  jeph

  ==============================================================================
*/

#pragma once
#include "PluginProcessor.h"
#include "Scale_Component.h"
#include "APVTS_Constants.h"



// JXN Function to create APVTS params
juce::AudioProcessorValueTreeState::ParameterLayout
VerboseAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    
    std::vector<std::string> scaleButtonIdsVect = {
        scaleButtonIds.C,
        scaleButtonIds.CSharp,
        scaleButtonIds.D,
        scaleButtonIds.DSharp,
        scaleButtonIds.E,
        scaleButtonIds.F,
        scaleButtonIds.FSharp,
        scaleButtonIds.G,
        scaleButtonIds.GSharp,
        scaleButtonIds.A,
        scaleButtonIds.ASharp,
        scaleButtonIds.B
    };
    
    for (int i = 0; i < scaleButtonIdsVect.size(); i++){
        layout.add(std::make_unique<juce::AudioParameterInt>(juce::ParameterID {scaleButtonIdsVect[i],1}, scaleButtonIdsVect[i],0, 1, 0));
    }
    
    return layout;
}

//Translate APVTS params to program variables
void VerboseAudioProcessor::getAPVTSParams()
{
    scaleButtParam_C = *apvts.getRawParameterValue(scaleButtonIds.C);
    scaleButtParam_CSharp = *apvts.getRawParameterValue(scaleButtonIds.CSharp);
    scaleButtParam_D = *apvts.getRawParameterValue(scaleButtonIds.D);
    scaleButtParam_DSharp = *apvts.getRawParameterValue(scaleButtonIds.DSharp);
    scaleButtParam_E = *apvts.getRawParameterValue(scaleButtonIds.E);
    scaleButtParam_F = *apvts.getRawParameterValue(scaleButtonIds.F);
    scaleButtParam_FSharp = *apvts.getRawParameterValue(scaleButtonIds.FSharp);
    scaleButtParam_G = *apvts.getRawParameterValue(scaleButtonIds.G);
    scaleButtParam_GSharp = *apvts.getRawParameterValue(scaleButtonIds.GSharp);
    scaleButtParam_A = *apvts.getRawParameterValue(scaleButtonIds.A);
    scaleButtParam_ASharp = *apvts.getRawParameterValue(scaleButtonIds.ASharp);
    scaleButtParam_B = *apvts.getRawParameterValue(scaleButtonIds.B);
}


