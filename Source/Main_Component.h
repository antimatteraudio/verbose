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
#include "Scale_Wrapper.h"
#include "Header_Component.h"
#include "Snapshot_Wrapper.h"

class SceneComponent: public juce::Component
{
    
public:
    
//    std::unique_ptr<ScaleButton> c_scale_button = std::make_unique<ScaleButton>();
//    std::vector<std::unique_ptr<juce::TextButton>> scaleButtons;
    
    SceneComponent(VerboseAudioProcessor& p): Scale(p), Header(p), Snapshot(p)
    {

        // TODO: These are temporary bounds values
        auto area = getLocalBounds();
    
        Header.setBounds (area.removeFromTop(headerHeight));
        Snapshot.setBounds (area.removeFromTop(snapShotHeight));
        Snapshot.setBounds (area.removeFromTop(scaleHeight));
        addAndMakeVisible(Header);
        addAndMakeVisible(Snapshot);
        addAndMakeVisible(Scale);
        
            
    }
    
    void paint (juce::Graphics& g) override
    {
        auto area = getLocalBounds();
        RoundedRectangleBackground.drawBackground(g, area, lightGrey);
    }
    
    void resized() override
    {
        juce::FlexBox fb;
        fb.flexDirection = juce::FlexBox::Direction::column;
 
        juce::FlexItem header  (pluginWidth, headerHeight, Header);
        juce::FlexItem snapshot (pluginWidth, snapShotHeight, Snapshot);
        juce::FlexItem scale  (pluginWidth, scaleHeight, Scale);
 
        fb.items.addArray ( { header, snapshot, scale } );
        fb.performLayout (getLocalBounds().toFloat());
        
    }
    
    ~SceneComponent(){
        setLookAndFeel(nullptr);
    }
    
private:
    int pluginWidth = 800;
    int headerHeight = 100;
    int snapShotHeight = 200;
    int scaleHeight = 300;
    ScaleWrapper Scale;
    HeaderComponent Header;
    SnapshotWrapper Snapshot;
    RoundedRectangleBackground RoundedRectangleBackground;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SceneComponent)
};

