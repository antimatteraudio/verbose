/*
  ==============================================================================

    Scale_Wrapper.h
    Created: 2 Apr 2023 7:40:26pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "APVTS_Constants.h"
#include "Scale_Component.h"

class ScaleWrapper: public juce::Component
{
    
public:

    ScaleWrapper(AntimatterUITemplateAudioProcessor& p): Scale(p)
    {}
    
    void paint (juce::Graphics& g) override
    {
        auto area = getLocalBounds();
        RoundedRectangleBackground.drawBackground(g, area, midGrey, 8, 8);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        Scale.setBounds(area);
        addAndMakeVisible(Scale);
    }
    
    ~ScaleWrapper(){}
    
private:
    ScaleComponent Scale;
    RoundedRectangleBackground RoundedRectangleBackground;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleWrapper)
};

