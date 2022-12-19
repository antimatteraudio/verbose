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
    SelectorComponent(VerboseAudioProcessor& p, juce::String label): LeftArrow("LeftArrow", 0.45),  RightArrow("RightArrow", -0.45), LabelText(label)
    {
        addAndMakeVisible(LeftArrow);
        
        LeftArrow.setBounds(0, 0, 50, 50);
        RightArrow.setBounds(0, 0, 50, 50);
        LabelText.setBounds(0, 0, 50, 50);
        addAndMakeVisible(LeftArrow);
        addAndMakeVisible(RightArrow);
        addAndMakeVisible(LabelText);
    }
    
    void paint (juce::Graphics& g) override
    {

        
    }
    
    void resized() override
    {
        
    }
    
    ~SelectorComponent(){
    }
    
private:
    TriangleButtonComponent LeftArrow;
    TriangleButtonComponent RightArrow;
    juce::Label LabelText;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SelectorComponent)
};

