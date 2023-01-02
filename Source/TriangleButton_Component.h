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
    TriangleButtonComponent(juce::String name, float orientation = 0): ArrowButton(name, darkGrey1, darkGrey1, darkGrey1)
    {
        arrowDirection = orientation;
        addAndMakeVisible(ArrowButton);
    }
    
    void paint (juce::Graphics& g) override
    {
        ArrowButton.setBoundsRelative(0, 0, 1.0, 1.0);
        Triangle.addTriangle(0, ArrowButton.getHeight()/2, ArrowButton.getWidth(), 0,ArrowButton.getWidth(), ArrowButton.getHeight());
        
        auto fillType = juce::FillType();
        fillType.setColour(darkGrey1);
        g.setFillType(fillType);
    
        transform = transform.rotation(arrowDirection, ArrowButton.getWidth()/2, ArrowButton.getHeight()/2);
        g.fillPath(Triangle, transform);
        
    }
    
    void resized() override
    {
        
    }
    
    ~TriangleButtonComponent(){
    }
    
private:
    juce::AffineTransform transform;
    float arrowDirection;
    juce::Path Triangle;
    juce::ShapeButton ArrowButton;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TriangleButtonComponent)
};

