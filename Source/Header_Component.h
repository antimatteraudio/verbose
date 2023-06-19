

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "APVTS_Constants.h"

class HeaderComponent: public juce::Component
{
    
public:
    
    HeaderComponent(AntimatterUITemplateAudioProcessor& p)
    {
        title.setFont (juce::Font (22.0f, juce::Font::bold));
        title.setText("Chord Portal", juce::dontSendNotification);
        title.setColour (juce::Label::textColourId, juce::Colours::white);
        addAndMakeVisible(title);
    }
    
    void paint (juce::Graphics& g) override
    {

    }
    
    void resized() override
    {
//      TODO: Can we make this a global helper function?
        auto area = getLocalBounds();
        area.removeFromRight(padding);
        area.removeFromLeft(padding);
        area.removeFromBottom(padding);
        area.removeFromTop(padding);
//
        title.setBounds(area);
    }
    
    ~HeaderComponent(){

    }

    
private:
    int padding = 16;
    juce::Label title;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent)
};

