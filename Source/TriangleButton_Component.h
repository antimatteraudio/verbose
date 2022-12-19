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
    TriangleButtonComponent(juce::String name, float arrowDirection): ArrowButton(name, darkGrey1, darkGrey1, darkGrey1)
    {
        // TODO: These are temporary bounds values
        orientation = arrowDirection;
        ArrowButton.setShape(Triangle, true, true, false);
        addAndMakeVisible(ArrowButton);
    }
    
    void paint (juce::Graphics& g) override
    {
        Triangle.startNewSubPath(19.0 / 2.0, 2.0);
        Triangle.lineTo(17.0, 17.0);
        Triangle.lineTo(2.0, 17.0);
        Triangle.closeSubPath();
        auto fillType = juce::FillType();
        fillType.setColour(darkGrey1);
        g.setFillType(fillType);
        auto transform = juce::AffineTransform::rotation(orientation);
        g.fillPath(Triangle, transform);
        
    }
    
    void resized() override
    {
        
    }
    
    ~TriangleButtonComponent(){
    }
    
private:
    float orientation;
    juce::Path Triangle;
    juce::ShapeButton ArrowButton;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TriangleButtonComponent)
};

