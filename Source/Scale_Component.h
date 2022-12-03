/*
 ==============================================================================
 
 Components.h
 Created: 21 Nov 2022 9:50:26am
 Author:  jeph
 
 ==============================================================================
 */

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"


class ScaleComponent: public juce::Component
{
    
public:
    
    ScaleComponent(VerboseAudioProcessor& p)
    {
        int buttonHeight = 100;
        setLookAndFeel(&ScaleButtonLookAndFeel);

        // Button Attachments
        c_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, "scaleButton_C", c_scale_button));
        c_sharp_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, "scaleButton_C#", c_sharp_scale_button));
        d_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, "scaleButton_D" , d_scale_button));
        d_sharp_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, "scaleButton_D#" , d_sharp_scale_button));
        
        
        for (int i = 0; i < scale_buttons.size(); i++){
            scale_buttons[i] -> setButtonText(scale_button_labels[i]);
            scale_buttons[i] -> setBounds(i * buttonHeight, 0, buttonHeight, buttonHeight);
            addAndMakeVisible(scale_buttons[i]);
        }
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        button1.setBounds(area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    }
    
    ~ScaleComponent(){
        setLookAndFeel(nullptr);
    }
    ScaleButton mainLookAndFeel;
    juce::TextButton button1;
    
private:
    //==============================================================================
    
    ScaleButton ScaleButtonLookAndFeel;
    
    juce::TextButton c_scale_button, c_sharp_scale_button, d_scale_button, d_sharp_scale_button;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> c_scale_button_attachment, c_sharp_scale_button_attachment, d_scale_button_attachment, d_sharp_scale_button_attachment;
    
    std::vector<juce::TextButton*> scale_buttons = {
        &c_scale_button,
        &c_sharp_scale_button,
        &d_scale_button,
        &d_sharp_scale_button,
    };

    std::vector<std::string> scale_button_labels = {
        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
    };
    int border = 4;
    int buttonHeight = 100;
    int buttonWidth = 60;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleComponent)
};

