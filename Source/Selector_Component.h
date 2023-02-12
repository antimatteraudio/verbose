/*
  ==============================================================================

    Selector_Component.h
    Created: 18 Dec 2022 7:30:02pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "APVTS_Constants.h"
#include "Colors.h"
#include "Shapes.h"

class SelectorComponent: public juce::Component
{
    
public:
    SelectorComponent(VerboseAudioProcessor& p)
    {
        RightOctaveArrowButton.setBounds(0, 0, 16, 16);
        LeftOctaveArrowButton.setBounds(0, 0, 16, 16);
        LeftOctaveArrowButton.setShape(getLeftArrow(LeftOctaveArrowButton.getWidth(), LeftOctaveArrowButton.getHeight()), false, false, false);
        RightOctaveArrowButton.setShape(getRightArrow(RightOctaveArrowButton.getWidth(), RightOctaveArrowButton.getHeight()), false, false, false);
        addAndMakeVisible(LeftOctaveArrowButton);
        addAndMakeVisible(RightOctaveArrowButton);
        addAndMakeVisible(Label);
        Label.setText("0", juce::dontSendNotification);
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
        fb.alignContent = juce::FlexBox::AlignContent::center;
        fb.justifyContent = juce::FlexBox::JustifyContent::center;
        fb.alignItems = juce::FlexBox::AlignItems::center;

        juce::FlexItem leftOctaveArrowButton  (16, 16, LeftOctaveArrowButton);
        juce::FlexItem octaveText (20, 16, Label);
        juce::FlexItem rightOctaveArrowButton  (16, 16, RightOctaveArrowButton);

        fb.items.addArray ( { leftOctaveArrowButton, octaveText, rightOctaveArrowButton } );
        fb.performLayout (getLocalBounds().toFloat());
    
    }
    
    ~SelectorComponent(){
        setLookAndFeel(nullptr);
    }
    
private:
    juce::ShapeButton LeftOctaveArrowButton{ "left-octave-button", darkGrey1, darkGrey1, darkGrey1};
    juce::ShapeButton RightOctaveArrowButton{ "right-octave-button", darkGrey1, darkGrey1, darkGrey1};
    juce::Label Label;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> right_arrow_attachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> left_arrow_attachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SelectorComponent)
};

