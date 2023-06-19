/*
  ==============================================================================

    Main.h
    Created: 19 Jun 2023 2:46:58pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui_ImageKnob.h"
#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"

class Main: public juce::Component
{
    
public:
    
    
    Main(AntimatterUITemplateAudioProcessor& p): ImageKnob(p, "ImageKnobAttachment")
    {

        auto area = getLocalBounds();
    
        imageKnob.setBounds (area);
        addAndMakeVisible(imageKnob);

    }
    
    void paint (juce::Graphics& g) override
    {
        auto area = getLocalBounds();
    }
    
    void resized() override
    {
        juce::Grid grid;
        
        using Track = juce::Grid::TrackInfo;
        using fr = juce::Grid::Fr;
        using px = juce::Grid::Px;
        using gridItem = juce::GridItem;
        
        auto area = getLocalBounds();
        area.removeFromRight(padding);
        area.removeFromLeft(padding);
        area.removeFromBottom(padding);
        area.removeFromTop(padding);
        
        grid.items = { gridItem(imageKnob) };
        grid.templateRows = { Track (fr(1)) };
        grid.templateColumns = { fr(1) };
        grid.setGap(px(gap));
        grid.performLayout(juce::Rectangle<int> (area.getX(), area.getY(), area.getWidth(), 75));
    }
    
    ~Main(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 20;
    int gap = 2;
    ImageKnob imageKnob;
    RoundedRectangleBackground RoundedRectangleBackground;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Main)
};


