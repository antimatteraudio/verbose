/*
  ==============================================================================

    ScaleButtonWrapper_Component.h
    Created: 18 Dec 2022 2:19:53pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

#include "GUI_Classes.h"

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
    ScaleButtonWrapperComponent(VerboseAudioProcessor& p): LeftArrow("LeftArrow", darkGrey1, darkGrey1, darkGrey1),  RightArrow("RightArrow", darkGrey1, darkGrey1, darkGrey1)
    {
        setLookAndFeel(&ScaleButtonLookAndFeel);
        // TODO: These are temporary bounds values
        LeftArrow.setShape(Triangle, true, true, false);
        RightArrow.setShape(Triangle, true, true, false);
        LeftArrow.setBounds (0, 0, 100, 150);
        RightArrow.setBounds (0, 0, 100, 150);
//        OctaveText.setBounds (0, 0, 100, 150);
//        ScaleButton.setBounds (0, 0, 100, 150);
//        Triangle.addTriangle({0,0}, {10, 10}, {20, 20});
//        LeftArrow.setShape(triangle);

        
 
        addAndMakeVisible(ScaleButton);
//        setLookAndFeel(&OctaveButtonLookAndFeel);
        addAndMakeVisible(LeftArrow);
        addAndMakeVisible(RightArrow);
        
        addAndMakeVisible(OctaveText);
            
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
        Triangle.startNewSubPath(19.0 / 2.0, 2.0);
        Triangle.lineTo(17.0, 17.0);
        Triangle.lineTo(2.0, 17.0);
        Triangle.closeSubPath();
        auto fillType = juce::FillType();
        fillType.setColour(darkGrey1);
        g.setFillType(fillType);
        auto transform = juce::AffineTransform::rotation(-0.45);
        g.fillPath(Triangle, transform);
        
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
    juce::ShapeButton LeftArrow;
    juce::ShapeButton RightArrow;
    juce::Label OctaveText;
    juce::TextButton ScaleButton;
    juce::Path Triangle;
    

//    OctaveButton OctaveButtonLookAndFeel;
//    int height = 150;
//    int width = 100;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleButtonWrapperComponent)
};

