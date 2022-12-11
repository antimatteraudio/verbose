

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "APVTS_Constants.h"

class ScaleComponent: public juce::Component
{
    
public:
    
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
        f_sharp_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.FSharp, f_sharp_scale_button));
        g_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.G, g_scale_button));
        g_sharp_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.GSharp, g_sharp_scale_button));
        a_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.A, a_scale_button));
        a_sharp_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.ASharp, a_sharp_scale_button));
        b_scale_button_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.apvts, scaleButtonIds.B, b_scale_button));
        
        
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
//        auto area = getLocalBounds();
        juce::Grid sharps;
        juce::Grid naturals;
        
        using Track = juce::Grid::TrackInfo;
        using fr = juce::Grid::Fr;
        
        sharps.templateRows    = { Track (fr (1))};
        sharps.templateColumns = { fr(1), fr(1), fr(1), fr(1), fr(1)};
        
//        naturals.templateRows    = { Track (fr (1))};
//        naturals.templateColumns = { fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1) };
        
        juce::GridItem cSharp = juce::GridItem(c_sharp_scale_button);
        cSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(2));
        
        sharps.items = {
            cSharp,
            juce::GridItem(d_sharp_scale_button),
            juce::GridItem(f_sharp_scale_button),
            juce::GridItem(g_sharp_scale_button),
            juce::GridItem(a_sharp_scale_button)
        };
        
//        naturals.items = {
//            juce::GridItem(c_scale_button),
//            juce::GridItem(d_scale_button),
//            juce::GridItem(e_scale_button),
//            juce::GridItem(f_scale_button),
//            juce::GridItem(g_scale_button),
//            juce::GridItem(a_scale_button),
//            juce::GridItem(b_scale_button)
//        };
        
        sharps.performLayout (juce::Rectangle<int> (800, 100));
//        naturals.performLayout (juce::Rectangle<int> (800, 100));
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
//        &c_scale_button,
        &c_sharp_scale_button,
//        &d_scale_button,
        &d_sharp_scale_button,
//        &e_scale_button,
//        &f_scale_button,
        &f_sharp_scale_button,
//        &g_scale_button,
        &g_sharp_scale_button,
//        &a_scale_button,
        &a_sharp_scale_button,
//        &b_scale_button
    };

    // Define the button labels
//    std::vector<std::string> scale_button_labels = {
//        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
//    };
    std::vector<std::string> scale_button_labels = {
        "C#", "D#", "F#", "G#", "A#"
    };
    int border = 4;
    int buttonHeight = 75;
    int buttonWidth = 75;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleComponent)
};

