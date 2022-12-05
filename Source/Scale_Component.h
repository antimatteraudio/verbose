

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"

class ScaleComponent: public juce::Component
{
    
public:
    
    //TODO: The struct scaleButtonIds is already defined in APVTS_Params. My intention for this was to create a shared constant that could be used across multiple files. IS THERE A GOOD WAY TO SHARE CONSTANTS ACROSS MULTIPLE FILES in C++? I've tried: creating a new .h file for it ('symbol multiply defined' error), sharing it as a public member of ScaleComponent (needed to create an instance of ScaleComponent everywhere I wanted to access it, which was not great), making it static, and putting it in the PluginProcessor file.
    struct {
        std::string C = "scaleButton_C";
        std::string CSharp = "scaleButton_C#";
        std::string D = "scaleButton_D";
        std::string DSharp = "scaleButton_D#";
        std::string E = "scaleButton_E";
        std::string F = "scaleButton_F";
        std::string FSharp = "scaleButton_F#";
        std::string G = "scaleButton_G";
        std::string GSharp = "scaleButton_G#";
        std::string A = "scaleButton_A";
        std::string ASharp = "scaleButton_A#";
        std::string B = "scaleButton_B";
    } scaleButtonIds;
    
    ScaleComponent(VerboseAudioProcessor& p)
    {
        setLookAndFeel(&ScaleButtonLookAndFeel);

        // Button Attachments
        c_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.C, c_scale_button));
        c_sharp_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.CSharp, c_sharp_scale_button));
        d_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.D , d_scale_button));
        d_sharp_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.DSharp, d_sharp_scale_button));
        e_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.E, e_scale_button));
        f_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.F, f_scale_button));
        f_sharp_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.DSharp, f_sharp_scale_button));
        g_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.DSharp, g_sharp_scale_button));
        g_sharp_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.F, g_sharp_scale_button));
        a_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.F, a_scale_button));
        a_sharp_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.DSharp, a_sharp_scale_button));
        b_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.F, b_scale_button));
        
        
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
    
    ScaleButton ScaleButtonLookAndFeel;
    
    // Define the scale component buttons
    juce::TextButton c_scale_button;
    juce::TextButton c_sharp_scale_button;
    juce::TextButton d_scale_button;
    juce::TextButton d_sharp_scale_button;
    juce::TextButton e_scale_button;
    juce::TextButton f_scale_button;
    juce::TextButton f_sharp_scale_button;
    juce::TextButton g_scale_button;
    juce::TextButton g_sharp_scale_button;
    juce::TextButton a_scale_button;
    juce::TextButton a_sharp_scale_button;
    juce::TextButton b_scale_button;
    
    // Define the button attachments
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> c_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> c_sharp_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> d_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> d_sharp_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> e_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> f_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> f_sharp_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> g_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> g_sharp_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> a_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> a_sharp_scale_button_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> b_scale_button_attachment;
    
    // Define a vector for iterating over the buttons
    std::vector<juce::TextButton*> scale_buttons = {
        &c_scale_button,
        &c_sharp_scale_button,
        &d_scale_button,
        &d_sharp_scale_button,
        &e_scale_button,
        &f_scale_button,
        &f_sharp_scale_button,
        &g_scale_button,
        &g_sharp_scale_button,
        &a_scale_button,
        &a_sharp_scale_button,
        &b_scale_button
    };

    // Define the button labels
    std::vector<std::string> scale_button_labels = {
        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
    };
    int border = 4;
    int buttonHeight = 100;
    int buttonWidth = 60;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleComponent)
};

