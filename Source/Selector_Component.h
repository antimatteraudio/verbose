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

class SelectorComponent: public juce::Component, public juce::Button::Listener
{
    
public:
    SelectorComponent(VerboseAudioProcessor& p, juce::String paramID): audioProcessor(p), paramID(paramID)
    {
        DownOctaveButton.addListener (this);
        UpOctaveButton.addListener (this);
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
        octaveVal = dynamic_cast<juce::AudioParameterInt*>(p.verboseAPVTS.getParameter(scaleButtonOctaveState.C));
//        auto gui_var1 = p.verboseAPVTS.getParameter(scaleButtonOctaveState.C);
        auto labelText = std::to_string(octaveVal->get());
        Label.setText(labelText, juce::dontSendNotification);
        Label.setColour (juce::Label::textColourId, juce::Colours::white);
        std::cout << "fooo1";
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
    
    void buttonClicked (juce::Button* button) override
    {
        std::cout << "clicked";
        auto val = dynamic_cast<juce::AudioParameterInt*>(octaveVal)->get();

        std::cout << val;
        if (button == &DownOctaveButton)
               {
                   if(val >= -2){
                       audioProcessor.verboseAPVTS.state.setProperty(paramID, (val - 1), nullptr);
                       std::cout << val;
                   };
               }
        if (button == &UpOctaveButton)
               {
                   if(val < 8){
                       audioProcessor.verboseAPVTS.state.setProperty(paramID, (val + 1), nullptr);
                   };
               }
        
    }
    
    ~SelectorComponent(){
        setLookAndFeel(nullptr);
    }
    
private:
    juce::ShapeButton DownOctaveButton{ "DownOctaveButton", darkGrey1, darkGrey1, darkGrey1};
    juce::ShapeButton UpOctaveButton{ "UpOctaveButton", darkGrey1, darkGrey1, darkGrey1};
    juce::Label Label;
    juce::AudioParameterInt* octaveVal;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> upOctaveButtonAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> downOctaveButtonAttachment;
    VerboseAudioProcessor& audioProcessor;
    juce::String paramID;
//    juce::AudioProcessorValueTreeState::ButtonAttachment LeftOctaveArrowButtonAttachment;
//    juce::AudioProcessorValueTreeState::ButtonAttachment RightOctaveArrowButtonAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SelectorComponent)
};

