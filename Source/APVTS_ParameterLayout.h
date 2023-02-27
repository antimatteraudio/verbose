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

// **************************************************
// This file sets up the APVTS parameter layout
// **************************************************

juce::AudioProcessorValueTreeState::ParameterLayout
VerboseAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    
    // Scale button toggle state parameters
    auto scaleButtonToggleStateC = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.C, scaleButtonToggleState.C, 0, 1, 0);
    auto scaleButtonToggleStateCSharp = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.CSharp, scaleButtonToggleState.CSharp, 0, 1, 0);
    auto scaleButtonToggleStateD = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.D, scaleButtonToggleState.D, 0, 1, 0);
    auto scaleButtonToggleStateDSharp = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.DSharp, scaleButtonToggleState.DSharp, 0, 1, 0);
    auto scaleButtonToggleStateE = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.E, scaleButtonToggleState.E, 0, 1, 0);
    auto scaleButtonToggleStateF = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.F, scaleButtonToggleState.F, 0, 1, 0);
    auto scaleButtonToggleStateFSharp = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.FSharp, scaleButtonToggleState.FSharp, 0, 1, 0);
    auto scaleButtonToggleStateG = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.G, scaleButtonToggleState.G, 0, 1, 0);
    auto scaleButtonToggleStateGSharp = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.GSharp, scaleButtonToggleState.GSharp, 0, 1, 0);
    auto scaleButtonToggleStateA = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.A, scaleButtonToggleState.A, 0, 1, 0);
    auto scaleButtonToggleStateASharp = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.ASharp, scaleButtonToggleState.ASharp, 0, 1, 0);
    auto scaleButtonToggleStateB = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.B, scaleButtonToggleState.B, 0, 1, 0);
    
    // Scale button octave state parameters
    auto scaleButtonOctaveStateC = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.C, scaleButtonOctaveState.C, -2, 8, 0);
    auto scaleButtonOctaveStateCSharp = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.CSharp, scaleButtonOctaveState.CSharp, -2, 8, 0);
    auto scaleButtonOctaveStateD = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.D, scaleButtonOctaveState.D, -2, 8, 0);
    auto scaleButtonOctaveStateDSharp = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.DSharp, scaleButtonOctaveState.DSharp, -2, 8, 0);
    auto scaleButtonOctaveStateE = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.E, scaleButtonOctaveState.E, -2, 8, 0);
    auto scaleButtonOctaveStateF = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.F, scaleButtonOctaveState.F, -2, 8, 0);
    auto scaleButtonOctaveStateFSharp = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.FSharp, scaleButtonOctaveState.FSharp, -2, 8, 0);
    auto scaleButtonOctaveStateG = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.G, scaleButtonOctaveState.G, -2, 8, 0);
    auto scaleButtonOctaveStateGSharp = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.GSharp, scaleButtonOctaveState.GSharp, -2, 8, 0);
    auto scaleButtonOctaveStateA = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.A, scaleButtonOctaveState.A, -2, 8, 0);
    auto scaleButtonOctaveStateASharp = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.ASharp, scaleButtonOctaveState.ASharp, -2, 8, 0);
    auto scaleButtonOctaveStateB = std::make_unique<juce::AudioParameterInt> (scaleButtonOctaveState.B, scaleButtonOctaveState.B, -2, 8, 0);
    
    layout.add(
               // C button state and octave state
               std::move(scaleButtonToggleStateC),
               std::move(scaleButtonOctaveStateC),
               // C# button state and octave state
               std::move(scaleButtonToggleStateCSharp),
               std::move(scaleButtonOctaveStateCSharp),
               // D button state and octave state
               std::move(scaleButtonToggleStateD),
               std::move(scaleButtonOctaveStateD),
               // D# button state and octave state
               std::move(scaleButtonToggleStateDSharp),
               std::move(scaleButtonOctaveStateDSharp),
               // E button state and octave state
               std::move(scaleButtonToggleStateE),
               std::move(scaleButtonOctaveStateE),
               // F button state and octave state
               std::move(scaleButtonToggleStateF),
               std::move(scaleButtonOctaveStateF),
               // F# button state and octave state
               std::move(scaleButtonToggleStateFSharp),
               std::move(scaleButtonOctaveStateFSharp),
               // G button state and octave state
               std::move(scaleButtonToggleStateG),
               std::move(scaleButtonOctaveStateG),
               // G# button state and octave state
               std::move(scaleButtonToggleStateGSharp),
               std::move(scaleButtonOctaveStateGSharp),
               // A button state and octave state
               std::move(scaleButtonToggleStateA),
               std::move(scaleButtonOctaveStateA),
               // A# button state and octave state
               std::move(scaleButtonToggleStateASharp),
               std::move(scaleButtonOctaveStateASharp),
               // B button state and octave state
               std::move(scaleButtonToggleStateB),
               std::move(scaleButtonOctaveStateB)
               );
    
    
    return layout;
}



