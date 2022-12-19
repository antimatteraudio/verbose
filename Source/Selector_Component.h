/*
  ==============================================================================

    Selector_Component.h
    Created: 18 Dec 2022 7:30:02pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "TriangleButton_Component.h"

class SelectorComponent: public juce::Component
{
    
public:
    SelectorComponent(VerboseAudioProcessor& p, juce::String label): LeftArrow("LeftArrow", "left"),  RightArrow("RightArrow", "right"), Label(label)
    {
        addAndMakeVisible(LeftArrow);
        addAndMakeVisible(LeftArrow);
        addAndMakeVisible(RightArrow);
        addAndMakeVisible(Label);
        Label.setText(label, juce::dontSendNotification);
        Label.setColour (juce::Label::textColourId, juce::Colours::white);
    }
    
    void paint (juce::Graphics& g) override
    {

        
    }
//
    void resized() override
    {
        juce::FlexBox fb;
        fb.flexDirection = juce::FlexBox::Direction::row;
        fb.justifyContent = juce::FlexBox::JustifyContent::center;
        fb.alignItems = juce::FlexBox::AlignItems::center;

        juce::FlexItem leftArrow  (40, 40, LeftArrow);
        juce::FlexItem octaveText (20, 20, Label);
        juce::FlexItem rightArrow  (40, 40, RightArrow);

        fb.items.addArray ( { leftArrow, octaveText, rightArrow } );
        fb.performLayout (getLocalBounds().toFloat());
    
    }
    
    ~SelectorComponent(){
    }
    
private:
    TriangleButtonComponent LeftArrow;
    TriangleButtonComponent RightArrow;
    juce::Label Label;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SelectorComponent)
};
