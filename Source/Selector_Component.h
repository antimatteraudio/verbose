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
    SelectorComponent(VerboseAudioProcessor& p, juce::String paramID): audioProcessor(p), paramID(paramID)
    {


        octaveSliderAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (p.verboseAPVTS, paramID, OctaveSlider));

        juce::Range<double>* r = new juce::Range<double>(-2.0, 8.0);
        OctaveSlider.setSliderStyle(juce::Slider::SliderStyle::IncDecButtons);
        OctaveSlider.setRange (*r, 1);
        auto area = getLocalBounds();
        OctaveSlider.setBounds(area);
        OctaveSlider.setValue(0);
        OctaveSlider.setIncDecButtonsMode (juce::Slider::incDecButtonsDraggable_Vertical);
        Label.attachToComponent(&OctaveSlider, true);
        addAndMakeVisible(Label);
        addAndMakeVisible (OctaveSlider);
//        OctaveSlider.addListener(this);
    }
    
    void paint (juce::Graphics& g) override
    {
        auto area = getLocalBounds();
        OctaveSlider.setBounds(area);
        
    }
    void resized() override
    {
//        juce::FlexBox fb;
//        fb.flexDirection = juce::FlexBox::Direction::row;
//        fb.alignContent = juce::FlexBox::AlignContent::center;
//        fb.justifyContent = juce::FlexBox::JustifyContent::center;
//        fb.alignItems = juce::FlexBox::AlignItems::center;
//        fb.performLayout (getLocalBounds().toFloat());
    
    }
    
    ~SelectorComponent(){
        setLookAndFeel(nullptr);
    }
    
private:
    juce::Slider OctaveSlider;
    juce::Label Label;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> octaveSliderAttachment;
    VerboseAudioProcessor& audioProcessor;
    juce::String paramID;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SelectorComponent)
};

