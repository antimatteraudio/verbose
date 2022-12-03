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
    
//    std::unique_ptr<ScaleButton> c_scale_button = std::make_unique<ScaleButton>();
    //    std::vector<std::unique_ptr<juce::TextButton>> scaleButtons;
    
    ScaleComponent(VerboseAudioProcessor& p)
    {
        setLookAndFeel(&ScaleButtonLookAndFeel);
        // TODO: Temporary bounds values
        for (int i = 0; i < scale_buttons.size(); i++){
            scale_buttons[i] -> setBounds(i * 100, 0, 100, 100);
            addAndMakeVisible(scale_buttons[i]);
        }
//        c_scale_button.setBounds (0, 0, 100, 100);
//        c_sharp_scale_button.setBounds (0, 0, 100, 100);
//        d_scale_button.setBounds (0, 0, 100, 100);
//        d_sharp_scale_button.setBounds (0, 0, 100, 100);
//        addAndMakeVisible(c_scale_button);
//        addAndMakeVisible(c_sharp_scale_button);
//        addAndMakeVisible(d_scale_button);
//        addAndMakeVisible(d_sharp_scale_button);
        //auto scaleButt = std::make_unique<juce::TextButton>(noteNames[i]);
       // scaleButt->setBounds(i * buttonWidth + 10, 100, buttonWidth, buttonHeight);
//        addAndMakeVisible(*c_scale_button);
        //      Add to vector?
        //      scaleButtons.push_back(std::move(scaleButt));
        
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
    std::vector<juce::TextButton*> scale_buttons = {
        &c_scale_button,
        &c_sharp_scale_button,
        &d_scale_button,
        &d_sharp_scale_button,
    };
    
//    std::make_unique<juce::TextButton> c_sharp_scale_button;
//    std::make_unique<juce::TextButton> d_scale_button;
//    std::make_unique<juce::TextButton> d_sharp_scale_button;
//    std::unique_ptr<juce::TextButton> c_scale_button = std::make_unique<ScaleButton>();
    struct {
        std::string c = "C";
        std::string c_sharp = "C#";
        std::string d = "D";
        std::string d_sharp = "D#";
        std::string e = "E";
        std::string f = "F";
        std::string f_sharp = "F#";
        std::string g = "G";
        std::string g_sharp = "G#";
        std::string a = "A";
        std::string a_sharp = "A#";
        std::string b = "B";
    } scale_button_labels;
    int border = 4;
    int buttonHeight = 100;
    int buttonWidth = 60;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleComponent)
};

