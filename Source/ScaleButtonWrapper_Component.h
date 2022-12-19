/*
  ==============================================================================

    ScaleButtonWrapper_Component.h
    Created: 18 Dec 2022 2:19:53pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

#include "GUI_Classes.h"
#include "TriangleButton_Component.h"

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
    ScaleButtonWrapperComponent(VerboseAudioProcessor& p): LeftArrow("LeftArrow", 0.45),  RightArrow("RightArrow", -0.45)
    {
        setLookAndFeel(&ScaleButtonLookAndFeel);

        addAndMakeVisible(ScaleButton);
        addAndMakeVisible(LeftArrow);
        
        LeftArrow.setBounds(0, 0, 50, 50);
        RightArrow.setBounds(0, 0, 50, 50);
        addAndMakeVisible(RightArrow);
        addAndMakeVisible(OctaveText);
            
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
//        Triangle.startNewSubPath(19.0 / 2.0, 2.0);
//        Triangle.lineTo(17.0, 17.0);
//        Triangle.lineTo(2.0, 17.0);
//        Triangle.closeSubPath();
//        auto fillType = juce::FillType();
//        fillType.setColour(darkGrey1);
//        g.setFillType(fillType);
//        auto transform = juce::AffineTransform::rotation(-0.45);
//        g.fillPath(Triangle, transform);
        
    }
    
    void resized() override
    {
//        juce::FlexBox fb;
//        fb.flexDirection = juce::FlexBox::Direction::column;
//
//        juce::FlexItem leftArrow  (150, 100, LeftArrow);
//        juce::FlexItem octaveText (150, 100, OctaveText);
//        juce::FlexItem rightArrow  (150, 100, RightArrow);
//
//        fb.items.addArray ( { leftArrow, octaveText, rightArrow } );
//        fb.performLayout (getLocalBounds().toFloat());
        
    }
    
    ~ScaleButtonWrapperComponent(){
        setLookAndFeel(nullptr);
    }
    
private:
    TriangleButtonComponent LeftArrow;
    TriangleButtonComponent RightArrow;
    juce::Label OctaveText;
    juce::TextButton ScaleButton;

//    OctaveButton OctaveButtonLookAndFeel;
//    int height = 150;
//    int width = 100;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleButtonWrapperComponent)
};

