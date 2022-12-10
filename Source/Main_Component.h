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

class SceneComponent: public juce::Component
{
    
public:
    
//    std::unique_ptr<ScaleButton> c_scale_button = std::make_unique<ScaleButton>();
//    std::vector<std::unique_ptr<juce::TextButton>> scaleButtons;
    
    SceneComponent(VerboseAudioProcessor& p): Scale(p)
    {

        // TODO: These are temporary bounds values
        Scale.setBounds (0, 0, 1200, 600);
        addAndMakeVisible(Scale);
            
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        //auto area = getLocalBounds();
    }
    
    ~SceneComponent(){
        setLookAndFeel(nullptr);
    }
    
private:
    
    ScaleComponent Scale;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SceneComponent)
};

