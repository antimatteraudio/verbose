

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "APVTS_Constants.h"

// ****************************************
// TODO: This file is a work in progress.
// ****************************************

class SnapshotComponent: public juce::Component
{
    
public:
    
    SnapshotComponent(VerboseAudioProcessor& p)
    {
        setLookAndFeel(&ScaleButtonLookAndFeel);

        // Button Attachments
//        button_one_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.one, button_one));
//        button_two_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.two, button_two));
//        button_three_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.three, button_three));
//        button_four_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.four, button_four));
//        button_five_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.five, button_five));
//        button_six_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.six, button_six));
//        button_seven_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.seven, button_seven));
//        button_eight_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.eight, button_eight));
//        button_nine_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.nine, button_nine));
//        button_ten_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.ten, button_ten));
//        button_eleven_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.eleven, button_eleven));
//        button_twelve_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.twelve, button_twelve));
//        button_thirteen_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.thirteen, button_thirteen));
//        button_fourteen_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.fourteen, button_fourteen));
//        button_fifteen_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.fifteen, button_fifteen));
//        button_sixteen_attachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, stepButtonIds.sixteen, button_sixteen));
  
        for (int i = 0; i < step_buttons.size(); i++){
            step_buttons[i] -> setButtonText(std::to_string(i + 1));
            step_buttons[i] -> setBounds(i * buttonWidth, 0, buttonWidth, buttonHeight);
            addAndMakeVisible(step_buttons[i]);
        }
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        juce::Grid grid;
        
        using Track = juce::Grid::TrackInfo;
        using fr = juce::Grid::Fr;
        using px = juce::Grid::Px;
        using gridItem = juce::GridItem;
        
        grid.items = { gridItem(button_one), gridItem(button_two), gridItem(button_three), gridItem(button_four), gridItem(button_five), gridItem(button_six), gridItem(button_seven), gridItem(button_eight), gridItem(button_nine), gridItem(button_ten), gridItem(button_eleven), gridItem(button_twelve), gridItem(button_thirteen), gridItem(button_fourteen), gridItem(button_fifteen), gridItem(button_sixteen) };
        grid.templateRows = { Track (fr(1)) };
        grid.templateColumns = { fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1), fr(1) };
        grid.setGap(px(4));
        grid.performLayout(juce::Rectangle<int> (0, 0, 800, 75));
        
    }
    
    ~SnapshotComponent(){
        setLookAndFeel(nullptr);
    }
    ScaleButtonLookAndFeel mainLookAndFeel;
    juce::TextButton button1;
    
private:
    
    ScaleButtonLookAndFeel ScaleButtonLookAndFeel;
    
    // Define the scale component buttons
    juce::TextButton button_one;
    juce::TextButton button_two;
    juce::TextButton button_three;
    juce::TextButton button_four;
    juce::TextButton button_five;
    juce::TextButton button_six;
    juce::TextButton button_seven;
    juce::TextButton button_eight;
    juce::TextButton button_nine;
    juce::TextButton button_ten;
    juce::TextButton button_eleven;
    juce::TextButton button_twelve;
    juce::TextButton button_thirteen;
    juce::TextButton button_fourteen;
    juce::TextButton button_fifteen;
    juce::TextButton button_sixteen;
    
    // Define the button attachments
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_one_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_two_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_three_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_four_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_five_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_six_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_seven_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_eight_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_nine_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_ten_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_eleven_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_twelve_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_thirteen_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_fourteen_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_fifteen_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> button_sixteen_attachment;
    
    // Define a vector for iterating over the buttons
    std::vector<juce::TextButton*> step_buttons = {
        &button_one,
        &button_two,
        &button_three,
        &button_four,
        &button_five,
        &button_six,
        &button_seven,
        &button_eight,
        &button_nine,
        &button_ten,
        &button_eleven,
        &button_twelve,
        &button_thirteen,
        &button_fourteen,
        &button_fifteen,
        &button_sixteen
    };

    int border = 4;
    int buttonHeight = 75;
    int buttonWidth = 50;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SnapshotComponent)
};

