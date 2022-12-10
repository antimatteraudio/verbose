

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "APVTS_Constants.h"

class HeaderComponent: public juce::Component
{
    
public:
    
    HeaderComponent(VerboseAudioProcessor& p)
    {
        title.setFont (juce::Font (22.0f, juce::Font::bold));
        title.setText("Chord Portal", juce::dontSendNotification);
        title.setColour (juce::Label::textColourId, juce::Colours::white);
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        title.setBounds(area);
    }
    
    ~HeaderComponent(){

    }

    
private:
    
    juce::Label title;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent)
};

