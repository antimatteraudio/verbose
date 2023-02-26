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

//std::vector<int> octaveOptions = {
//    -2,
//    -1,
//    0,
//    1,
//    2,
//    3,
//    4,
//    5,
//    6,
//    7,
//    8
//};

//auto octaveVal = std::make_unique<juce::String>(juce::ParameterID {"octaveVal"});
//auto isActive = std::make_unique<juce::String>(juce::ParameterID {"isActive"});

// JXN Function to create APVTS params

juce::AudioProcessorValueTreeState::ParameterLayout
VerboseAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    
//    std::vector<std::string> scaleButtonIdsVect = {
//        scaleButtonIds.C,
//        scaleButtonIds.CSharp,
//        scaleButtonIds.D,
//        scaleButtonIds.DSharp,
//        scaleButtonIds.E,
//        scaleButtonIds.F,
//        scaleButtonIds.FSharp,
//        scaleButtonIds.G,
//        scaleButtonIds.GSharp,
//        scaleButtonIds.A,
//        scaleButtonIds.ASharp,
//        scaleButtonIds.B
//    };
//
//    std::vector<std::string> octaveIdsVect = {
//        octaveStateValue.C,
//        octaveStateValue.CSharp,
//        octaveStateValue.D,
//        octaveStateValue.DSharp,
//        octaveStateValue.E,
//        octaveStateValue.F,
//        octaveStateValue.FSharp,
//        octaveStateValue.G,
//        octaveStateValue.GSharp,
//        octaveStateValue.A,
//        octaveStateValue.ASharp,
//        octaveStateValue.B
//    };
    
//    std::vector<std::string> stepButtonIdsVect = {
//        stepButtonIds.one,
//        stepButtonIds.two,
//        stepButtonIds.three,
//        stepButtonIds.four,
//        stepButtonIds.five,
//        stepButtonIds.six,
//        stepButtonIds.seven,
//        stepButtonIds.eight,
//        stepButtonIds.nine,
//        stepButtonIds.ten,
//        stepButtonIds.eleven,
//        stepButtonIds.twelve,
//        stepButtonIds.thirteen,
//        stepButtonIds.fourteen,
//        stepButtonIds.fifteen,
//        stepButtonIds.sixteen
//    };

//    auto buttonStateC = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateC = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
    
//    layout.add(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID {"poles",1}, "poles", juce::NormalisableRange<float>(1, 32,1), 2));
    
//    layout.add(std::make_unique<juce::AudioParameterFloat> (juce::ParameterID {scaleButtonToggleState.C, 1}, scaleButtonToggleState.C, juce::NormalisableRange<float>(0, 1,0), 0));
    auto scaleButtonC = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.C, scaleButtonToggleState.C, 0, 1, 0);
    auto scaleButtonCSharp = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.CSharp, scaleButtonToggleState.CSharp, 0, 1, 0);
    
    
    auto scaleOctaveButtonC = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.C, scaleButtonOctaveState.C, -2, 8, 0);
    auto scaleOctaveButtonCSharp = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.CSharp, scaleButtonOctaveState.CSharp, -2, 8, 0);
    
    layout.add(std::move(scaleButtonC), std::move(scaleButtonCSharp), std::move(scaleOctaveButtonC), std::move(scaleOctaveButtonCSharp));
    
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(scaleButtonIds.C, scaleButtonIds.C, "|", std::move(buttonStateC), std::move(octaveStateC)));
    
//    auto buttonStateCSharp = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateCSharp = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);

//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(scaleButtonOctaveState.CSharp, scaleButtonOctaveState.CSharp, "|", std::move(buttonStateCSharp), std::move(octaveStateCSharp)));
//
//    auto buttonStateD = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateD = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
//
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(octaveIds.D, octaveIds.D, "|", buttonStateD, octaveStateD));
//
//    auto buttonStateDSharp = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateDSharp = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
//
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(octaveIds.DSharp, octaveIds.DSharp, "|", buttonStateDSharp, octaveStateDSharp));
//
//    auto buttonStateE = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateE = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
//
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(octaveIds.E, octaveIds.E, "|", buttonStateE, octaveStateE));
//
//    auto buttonStateF = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateF = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
//
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(octaveIds.F, octaveIds.F, "|", buttonStateF, octaveStateF));
//
//    auto buttonStateFSharp = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateFSharp = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
//
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(octaveIds.FSharp, octaveIds.FSharp, "|", buttonStateFSharp, octaveStateFSharp));
//
//    auto buttonStateG = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateG = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
//
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(octaveIds.G, octaveIds.G, "|", buttonStateG, octaveStateG));
//
//    auto buttonStateGSharp = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateGSharp = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
//
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(octaveIds.GSharp, octaveIds.GSharp, "|", buttonStateGSharp, octaveStateGSharp));
//
//    auto buttonStateA = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateA = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
//
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(octaveIds.A, octaveIds.A, "|", buttonStateA, octaveStateA));
//
//    auto buttonStateASharp = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateASharp = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
//
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(octaveIds.ASharp, octaveIds.ASharp, "|", buttonStateASharp, octaveStateASharp));
//
//    auto buttonStateB = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {isActive,1}, isActive,0, 1, 0);
//    auto octaveStateB = std::make_unique<juce::AudioParameterInt>(juce::ParameterID {octaveVal,1}, octaveVal,octaveOptions[0], octaveOptions[10], octaveOptions[2]);
//
//    layout.add(std::make_unique<juce::AudioProcessorParameterGroup>(octaveIds.B, octaveIds.B, "|", buttonStateB, octaveStateB));

    // Add step buttons to tree state
//    for (int i = 0; i < stepButtonIdsVect.size(); i++){
//        layout.add(std::make_unique<juce::AudioParameterInt>(juce::ParameterID {stepButtonIdsVect[i],1}, stepButtonIdsVect[i],0, 1, 0));
//    }
    
    return layout;
}

////Translate APVTS params to program variables
//void VerboseAudioProcessor::getAPVTSParams()
//{
//    octaveIds.C = *verboseAPVTS.getRawParameterValue(octaveIds.C);
//    octaveIds.CSharp = *verboseAPVTS.getRawParameterValue(octaveIds.CSharp);
//    scaleButtonIds.C = *verboseAPVTS.getRawParameterValue(scaleButtonIds.C);
//    scaleButtonIds.CSharp = *verboseAPVTS.getRawParameterValue(scaleButtonIds.CSharp);
////    scaleButtParam_D = *apvts.getRawParameterValue(scaleButtonIds.D);
////    scaleButtParam_DSharp = *apvts.getRawParameterValue(scaleButtonIds.DSharp);
////    scaleButtParam_E = *apvts.getRawParameterValue(scaleButtonIds.E);
////    scaleButtParam_F = *apvts.getRawParameterValue(scaleButtonIds.F);
////    scaleButtParam_FSharp = *apvts.getRawParameterValue(scaleButtonIds.FSharp);
////    scaleButtParam_G = *apvts.getRawParameterValue(scaleButtonIds.G);
////    scaleButtParam_GSharp = *apvts.getRawParameterValue(scaleButtonIds.GSharp);
////    scaleButtParam_A = *apvts.getRawParameterValue(scaleButtonIds.A);
////    scaleButtParam_ASharp = *apvts.getRawParameterValue(scaleButtonIds.ASharp);
////    scaleButtParam_B = *apvts.getRawParameterValue(scaleButtonIds.B);
//    
////    stepButtParam_one = *apvts.getRawParameterValue(stepButtonIds.one);
////    stepButtParam_two = *apvts.getRawParameterValue(stepButtonIds.two);
////    stepButtParam_three = *apvts.getRawParameterValue(stepButtonIds.three);
////    stepButtParam_four = *apvts.getRawParameterValue(stepButtonIds.four);
////    stepButtParam_five = *apvts.getRawParameterValue(stepButtonIds.five);
////    stepButtParam_six = *apvts.getRawParameterValue(stepButtonIds.six);
////    stepButtParam_seven = *apvts.getRawParameterValue(stepButtonIds.seven);
////    stepButtParam_eight = *apvts.getRawParameterValue(stepButtonIds.eight);
////    stepButtParam_nine = *apvts.getRawParameterValue(stepButtonIds.nine);
////    stepButtParam_ten = *apvts.getRawParameterValue(stepButtonIds.ten);
////    stepButtParam_eleven = *apvts.getRawParameterValue(stepButtonIds.eleven);
////    stepButtParam_twelve = *apvts.getRawParameterValue(stepButtonIds.twelve);
////    stepButtParam_thirteen = *apvts.getRawParameterValue(stepButtonIds.thirteen);
////    stepButtParam_fourteen = *apvts.getRawParameterValue(stepButtonIds.fourteen);
////    stepButtParam_fifteen = *apvts.getRawParameterValue(stepButtonIds.fifteen);
////    stepButtParam_sixteen = *apvts.getRawParameterValue(stepButtonIds.sixteen);
//}


