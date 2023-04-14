/*
  ==============================================================================

    Snapshot_Wrapper.h
    Created: 2 Apr 2023 7:40:26pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "APVTS_Constants.h"
#include "Snapshot_Component.h"

class SnapshotWrapper: public juce::Component
{
    
public:

    SnapshotWrapper(VerboseAudioProcessor& p): Snapshot(p)
    {}
    
    void paint (juce::Graphics& g) override
    {
        auto area = getLocalBounds();
        RoundedRectangleBackground.drawBackground(g, area, midGrey, 8, 8);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        juce::Rectangle<int> rect (0, 0, 800, 200);
//        Snapshot.setBoundsToFit(rect, 4, true);
        Snapshot.setBounds(area);
//        Snapshot.centreWithSize(600, 200);
        addAndMakeVisible(Snapshot);

        
    }
    
    ~SnapshotWrapper(){}
    
private:
    SnapshotComponent Snapshot;
    RoundedRectangleBackground RoundedRectangleBackground;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SnapshotWrapper)
};

