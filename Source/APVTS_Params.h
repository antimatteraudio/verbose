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
    
    std::vector<std::string> octaveIdsVect = {
        octaveIds.C,
        octaveIds.CSharp,
        octaveIds.D,
        octaveIds.DSharp,
        octaveIds.E,
        octaveIds.F,
        octaveIds.FSharp,
        octaveIds.G,
        octaveIds.GSharp,
        octaveIds.A,
        octaveIds.ASharp,
        octaveIds.B
    };
    
    std::vector<std::string> stepButtonIdsVect = {
        stepButtonIds.one,
        stepButtonIds.two,
        stepButtonIds.three,
        stepButtonIds.four,
        stepButtonIds.five,
        stepButtonIds.six,
        stepButtonIds.seven,
        stepButtonIds.eight,
        stepButtonIds.nine,
        stepButtonIds.ten,
        stepButtonIds.eleven,
        stepButtonIds.twelve,
        stepButtonIds.thirteen,
        stepButtonIds.fourteen,
        stepButtonIds.fifteen,
        stepButtonIds.sixteen
    };
    
    // Add scale buttons to tree state
    for (int i = 0; i < scaleButtonIdsVect.size(); i++){
        layout.add(std::make_unique<juce::AudioParameterInt>(juce::ParameterID {scaleButtonIdsVect[i],1}, scaleButtonIdsVect[i],0, 1, 0));
    }
    
    // Add step buttons to tree state
    for (int i = 0; i < stepButtonIdsVect.size(); i++){
        layout.add(std::make_unique<juce::AudioParameterInt>(juce::ParameterID {stepButtonIdsVect[i],1}, stepButtonIdsVect[i],0, 1, 0));
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
    
    stepButtParam_one = *apvts.getRawParameterValue(stepButtonIds.one);
    stepButtParam_two = *apvts.getRawParameterValue(stepButtonIds.two);
    stepButtParam_three = *apvts.getRawParameterValue(stepButtonIds.three);
    stepButtParam_four = *apvts.getRawParameterValue(stepButtonIds.four);
    stepButtParam_five = *apvts.getRawParameterValue(stepButtonIds.five);
    stepButtParam_six = *apvts.getRawParameterValue(stepButtonIds.six);
    stepButtParam_seven = *apvts.getRawParameterValue(stepButtonIds.seven);
    stepButtParam_eight = *apvts.getRawParameterValue(stepButtonIds.eight);
    stepButtParam_nine = *apvts.getRawParameterValue(stepButtonIds.nine);
    stepButtParam_ten = *apvts.getRawParameterValue(stepButtonIds.ten);
    stepButtParam_eleven = *apvts.getRawParameterValue(stepButtonIds.eleven);
    stepButtParam_twelve = *apvts.getRawParameterValue(stepButtonIds.twelve);
    stepButtParam_thirteen = *apvts.getRawParameterValue(stepButtonIds.thirteen);
    stepButtParam_fourteen = *apvts.getRawParameterValue(stepButtonIds.fourteen);
    stepButtParam_fifteen = *apvts.getRawParameterValue(stepButtonIds.fifteen);
    stepButtParam_sixteen = *apvts.getRawParameterValue(stepButtonIds.sixteen);
}


