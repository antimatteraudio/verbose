/*
  ==============================================================================

    ScaleButtonWrapper_Component.h
    Created: 18 Dec 2022 2:19:53pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

#include "GUI_Classes.h"
#include "Selector_Component.h"

class ScaleButtonWrapperComponent: public juce::Component
{
    
public:
    
    void setButtonText(std::string text) {
        ScaleButton.setButtonText(text);
    }
    
//    std::unique_ptr<ScaleButton> c_scale_button = std::make_unique<ScaleButton>();
//    std::vector<std::unique_ptr<juce::TextButton>> scaleButtons;
    
    // TODO: WTF
    ScaleButton ScaleButtonLookAndFeel;
    ScaleButtonWrapperComponent(VerboseAudioProcessor& p): Selector(p, "0")
    {
        setLookAndFeel(&ScaleButtonLookAndFeel);
        addAndMakeVisible(ScaleButton);
        addAndMakeVisible(Selector);
            
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        juce::FlexBox fb;
        fb.flexDirection = juce::FlexBox::Direction::column;

        juce::FlexItem scaleButton  (60, 80, ScaleButton);
        juce::FlexItem selector (60, 30, Selector);

        fb.items.addArray ( { scaleButton, selector } );
        fb.performLayout (getLocalBounds().toFloat());
        
    }
    
    ~ScaleButtonWrapperComponent(){
        setLookAndFeel(nullptr);
    }
    
private:
    juce::TextButton ScaleButton;
    SelectorComponent Selector;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleButtonWrapperComponent)
};

