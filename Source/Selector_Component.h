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
    SelectorComponent(VerboseAudioProcessor& p, juce::String paramID)
    {
        UpOctaveButton.setBounds(0, 0, 16, 16);
        DownOctaveButton.setBounds(0, 0, 16, 16);
        DownOctaveButton.setShape(getLeftArrow(DownOctaveButton.getWidth(), DownOctaveButton.getHeight()), false, false, false);
        UpOctaveButton.setShape(getRightArrow(UpOctaveButton.getWidth(), UpOctaveButton.getHeight()), false, false, false);
        addAndMakeVisible(DownOctaveButton);
        addAndMakeVisible(UpOctaveButton);
        addAndMakeVisible(Label);
        upOctaveButtonAttachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, paramID, UpOctaveButton));
        downOctaveButtonAttachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.verboseAPVTS, paramID, DownOctaveButton));
//        auto labelText = p.verboseAPVTS.getParameter(paramID);
//        auto labelText = std::to_string(p.var1);
//        double f3;
//        double f2 = std::modf(f, &f3);
        
//        float gui_var1 = p.verboseAPVTS.getParameterAsValue(scaleButtonOctaveState.C).getValue();
        auto gui_var1 = dynamic_cast<juce::AudioParameterInt*>(p.verboseAPVTS.getParameter(scaleButtonOctaveState.C));
//        auto gui_var1 = p.verboseAPVTS.getParameter(scaleButtonOctaveState.C);
        auto labelText = std::to_string(gui_var1->get());
        Label.setText(labelText, juce::dontSendNotification);
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

        juce::FlexItem leftOctaveArrowButton  (16, 16, DownOctaveButton);
        juce::FlexItem octaveText (16, 20, Label);
        juce::FlexItem rightOctaveArrowButton  (16, 16, UpOctaveButton);

        fb.items.addArray ( { leftOctaveArrowButton, octaveText, rightOctaveArrowButton } );
        fb.performLayout (getLocalBounds().toFloat());
    
    }
    
    ~SelectorComponent(){
        setLookAndFeel(nullptr);
    }
    
private:
    juce::ShapeButton DownOctaveButton{ "left-octave-button", darkGrey1, darkGrey1, darkGrey1};
    juce::ShapeButton UpOctaveButton{ "right-octave-button", darkGrey1, darkGrey1, darkGrey1};
    juce::Label Label;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> upOctaveButtonAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> downOctaveButtonAttachment;
//    juce::AudioProcessorValueTreeState::ButtonAttachment LeftOctaveArrowButtonAttachment;
//    juce::AudioProcessorValueTreeState::ButtonAttachment RightOctaveArrowButtonAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SelectorComponent)
};

