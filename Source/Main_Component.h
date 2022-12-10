/*
 ==============================================================================
 
 Components.h
 Created: 21 Nov 2022 9:50:26am
 Author:  jeph
 
 ==============================================================================
 */

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "Scale_Component.h"
#include "Header_Component.h"
#include "Snapshot_Component.h"

class SceneComponent: public juce::Component
{
    
public:
    
//    std::unique_ptr<ScaleButton> c_scale_button = std::make_unique<ScaleButton>();
//    std::vector<std::unique_ptr<juce::TextButton>> scaleButtons;
    
    SceneComponent(VerboseAudioProcessor& p): Scale(p), Header(p), Snapshot(p)
    {

        // TODO: These are temporary bounds values
        Header.setBounds (0, 0, 1000, 200);
        Snapshot.setBounds (0, 200, 1000, 200);
        Scale.setBounds (0, 400, 1000, 200);
        addAndMakeVisible(Header);
        addAndMakeVisible(Snapshot);
        addAndMakeVisible(Scale);
            
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        juce::FlexBox fb;
        fb.flexDirection = juce::FlexBox::Direction::column;
 
//        juce::FlexItem header  ((float) getWidth() / 4.0f, (float) getHeight(), Header);
//        juce::FlexItem snapshot ((float) getWidth() / 4.0f, (float) getHeight(), Snapshot);
//        juce::FlexItem scale  ((float) getWidth() / 2.0f, (float) getHeight(), Scale);
 
//        fb.items.addArray ( { header, snapshot, scale } );
        fb.performLayout (getLocalBounds().toFloat());
    }
    
    ~SceneComponent(){
        setLookAndFeel(nullptr);
    }
    
private:
    
    ScaleComponent Scale;
    HeaderComponent Header;
    SnapshotComponent Snapshot;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SceneComponent)
};

