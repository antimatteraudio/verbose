

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "APVTS_Constants.h"
#include "ScaleButtonWrapper_Component.h"

class ScaleComponent: public juce::Component
{
    
public:
    
    ScaleComponent(VerboseAudioProcessor& p): CScaleButton(p, scaleButtonToggleState.C, scaleButtonLabels.C),
    CSharpScaleButton(p, scaleButtonToggleState.CSharp, scaleButtonLabels.CSharp)
    {

        setLookAndFeel(&ScaleButtonLookAndFeel);
        
        for (int i = 0; i < scale_buttons.size(); i++){
//            scale_buttons[i] -> setButtonText(scale_button_labels[i]);
            scale_buttons[i] -> setBounds(i * buttonHeight, 0, buttonHeight, buttonHeight);
            addAndMakeVisible(scale_buttons[i]);
        }
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
//        auto area = getLocalBounds();
        juce::Grid sharps;
        juce::Grid naturals;
        
        using Track = juce::Grid::TrackInfo;
        using fr = juce::Grid::Fr;
        using px = juce::Grid::Px;
        
        // Sharps
        
        sharps.templateRows    = { Track (px (buttonHeight))};
        sharps.templateColumns = { px(buttonWidth), px(buttonWidth), px(buttonWidth), px(buttonWidth), px(buttonWidth)};
        sharps.setGap(juce::Grid::Px(buttonWidth));
        
        juce::GridItem c = juce::GridItem(CScaleButton);
        juce::GridItem cSharp = juce::GridItem(CSharpScaleButton);

        
        cSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(1));
//        dSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(2));
//        fSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(4));
//        gSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(5));
//        aSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(6));
            
        sharps.items = { cSharp };
//        sharps.items = { cSharp, dSharp, fSharp, gSharp, aSharp };
        
        // Naturals

        naturals.templateRows    = { Track (px (buttonHeight))};
        naturals.templateColumns = { px(buttonWidth), px(buttonWidth), px(buttonWidth), px(buttonWidth), px(buttonWidth), px(buttonWidth), px(buttonWidth) };
        naturals.setGap(juce::Grid::Px(buttonWidth));
        
//        juce::GridItem c = juce::GridItem(CScaleButton);
//        juce::GridItem d = juce::GridItem(d_scale_button);
//        juce::GridItem e = juce::GridItem(e_scale_button);
//        juce::GridItem f = juce::GridItem(f_scale_button);
//        juce::GridItem g = juce::GridItem(g_scale_button);
//        juce::GridItem a = juce::GridItem(a_scale_button);
//        juce::GridItem b = juce::GridItem(b_scale_button);
        
        c.setArea(juce::GridItem::Property(1), juce::GridItem::Property(1));
//        d.setArea(juce::GridItem::Property(1), juce::GridItem::Property(2));
//        e.setArea(juce::GridItem::Property(1), juce::GridItem::Property(3));
//        f.setArea(juce::GridItem::Property(1), juce::GridItem::Property(4));
//        g.setArea(juce::GridItem::Property(1), juce::GridItem::Property(5));
//        a.setArea(juce::GridItem::Property(1), juce::GridItem::Property(6));
//        b.setArea(juce::GridItem::Property(1), juce::GridItem::Property(7));
        
//        naturals.items = { c, d, e, f, g, a, b };
        naturals.items = { c };
        
        sharps.performLayout (juce::Rectangle<int> (buttonWidth, 0, 800, buttonHeight));
        naturals.performLayout (juce::Rectangle<int> (0, buttonHeight, 800, buttonHeight));
    }
    
    ~ScaleComponent(){
        setLookAndFeel(nullptr);
    }
    juce::TextButton ScaleButton;
    juce::TextButton button1;
    
private:
    
    ScaleButtonLookAndFeel ScaleButtonLookAndFeel;
    
    // Define the scale component buttons
    ScaleButtonWrapperComponent CScaleButton;
    ScaleButtonWrapperComponent CSharpScaleButton;

    
    // Define a vector for iterating over the buttons
    std::vector<ScaleButtonWrapperComponent*> scale_buttons = {
        &CScaleButton,
        &CSharpScaleButton
    };

    // Define the button labels
    std::vector<std::string> scale_button_labels = {
        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
    };

    int border = 4;
    int buttonHeight = 120;
    int buttonWidth = 60;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleComponent)
};

