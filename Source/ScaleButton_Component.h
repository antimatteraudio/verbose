/*
  ==============================================================================

    ScaleButton_Component.h
    Created: 18 Dec 2022 2:19:53pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

#include "GUI_Classes.h"
#include "IncDec_Component.h"

// This component contains a toggle button and an increment/decrement slider component.
// It requires 'scaleButtonAttachmentId' and 'incDecAttachmentId' strings. This will pass the proper APVTS parameters to the the toggle button and the inc/dec slider.
// New APVTS parameteres must also be added to APVTS/APVTS_ParameterLayout.h

class ScaleButtonComponent: public juce::Component
{
    
public:

    ScaleButtonComponent(VerboseAudioProcessor& p, juce::String scaleButtonAttachmentId, juce::String incDecAttachmentId, juce::String label): IncDec(p, incDecAttachmentId)
    {
        setLookAndFeel(&scaleButtonLookAndFeel);
        ScaleButton.setButtonText(label);
        addAndMakeVisible(ScaleButton);
        ScaleButtonAttachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, scaleButtonAttachmentId, ScaleButton));
        
        
        addAndMakeVisible(IncDec);
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        juce::FlexBox fb;
        fb.flexDirection = juce::FlexBox::Direction::column;

        juce::FlexItem scaleButton  (60, 80, ScaleButton);
        juce::FlexItem incDec (60, 30, IncDec);

        fb.items.addArray ( { scaleButton, incDec } );
        fb.performLayout (getLocalBounds().toFloat());
        
    }
    
    ~ScaleButtonComponent(){
        setLookAndFeel(nullptr);
        ScaleButtonAttachment.reset();
    }
    
private:
    juce::TextButton ScaleButton;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> ScaleButtonAttachment;
    IncDecComponent IncDec;
    ScaleButtonLookAndFeel scaleButtonLookAndFeel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleButtonComponent)
};

