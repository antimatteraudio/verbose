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
        Header.setBounds (0, 0, 800, 200);
        Snapshot.setBounds (0, 200, 800, 200);
        Scale.setBounds (0, 400, 800, 200);
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
 
        juce::FlexItem header  (800, 100, Header);
        juce::FlexItem snapshot (800, 200, Snapshot);
        juce::FlexItem scale  (800, 400, Scale);
 
        fb.items.addArray ( { header, snapshot, scale } );
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

