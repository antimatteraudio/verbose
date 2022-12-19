/*
  ==============================================================================

    TriangleButton_Component.h
    Created: 18 Dec 2022 6:43:31pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

class TriangleButtonComponent: public juce::Component
{
    
public:
    TriangleButtonComponent(juce::String name, juce::String arrowDirection): ArrowButton(name, darkGrey1, darkGrey1, darkGrey1)
    {
        orientation = arrowDirection;
        ArrowButton.setBounds(0, 0, 40, 40);
//        ArrowButton.setShape(Triangle, true, true, false);
            
        addAndMakeVisible(ArrowButton);
    }
    
    void paint (juce::Graphics& g) override
    {
//        Triangle.startNewSubPath(19.0 / 2.0, 2.0);
//        Triangle.lineTo(17.0, 17.0);
//        Triangle.lineTo(2.0, 17.0);
        
        
        
//        Triangle.startNewSubPath(20/2, 0);
//        Triangle.lineTo(20, 20);
//        Triangle.lineTo(0, 20);
        
        Triangle.addTriangle(0, ArrowButton.getHeight()/2, ArrowButton.getWidth()/2, 0,ArrowButton.getWidth(), ArrowButton.getHeight());
        
//        Triangle.closeSubPath();
        auto fillType = juce::FillType();
        fillType.setColour(darkGrey1);
        g.setFillType(fillType);
//        auto transform = juce::AffineTransform::rotation(orientation);
//        g.fillPath(Triangle, transform);
        g.fillPath(Triangle);
        
    }
    
    void resized() override
    {
        
    }
    
    ~TriangleButtonComponent(){
    }
    
private:
    juce::String orientation;
    juce::Path Triangle;
    juce::ShapeButton ArrowButton;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TriangleButtonComponent)
};

