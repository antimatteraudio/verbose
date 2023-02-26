

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "APVTS_Constants.h"
#include "ScaleButtonWrapper_Component.h"

class ScaleComponent: public juce::Component
{
    
public:

    ScaleComponent(VerboseAudioProcessor& p): classMemberProcessor(p)
    {
//        ScaleComponent::classMemberProcessor = p;
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
        
        
        juce::GridItem cSharp = juce::GridItem(CSharpScaleButton);
        juce::GridItem dSharp = juce::GridItem(DSharpScaleButton);
        juce::GridItem fSharp = juce::GridItem(FSharpScaleButton);
        juce::GridItem gSharp = juce::GridItem(GSharpScaleButton);
        juce::GridItem aSharp = juce::GridItem(ASharpScaleButton);
    
        cSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(1));
        dSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(2));
        fSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(4));
        gSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(5));
        aSharp.setArea(juce::GridItem::Property(1), juce::GridItem::Property(6));
            
        sharps.items = { cSharp, dSharp, fSharp, gSharp, aSharp };
        
        // Naturals

        naturals.templateRows    = { Track (px (buttonHeight))};
        naturals.templateColumns = { px(buttonWidth), px(buttonWidth), px(buttonWidth), px(buttonWidth), px(buttonWidth), px(buttonWidth), px(buttonWidth) };
        naturals.setGap(juce::Grid::Px(buttonWidth));
        
        juce::GridItem c = juce::GridItem(CScaleButton);
        juce::GridItem d = juce::GridItem(DScaleButton);
        juce::GridItem e = juce::GridItem(EScaleButton);
        juce::GridItem f = juce::GridItem(FScaleButton);
        juce::GridItem g = juce::GridItem(GScaleButton);
        juce::GridItem a = juce::GridItem(AScaleButton);
        juce::GridItem b = juce::GridItem(BScaleButton);
        
        c.setArea(juce::GridItem::Property(1), juce::GridItem::Property(1));
        d.setArea(juce::GridItem::Property(1), juce::GridItem::Property(2));
        e.setArea(juce::GridItem::Property(1), juce::GridItem::Property(3));
        f.setArea(juce::GridItem::Property(1), juce::GridItem::Property(4));
        g.setArea(juce::GridItem::Property(1), juce::GridItem::Property(5));
        a.setArea(juce::GridItem::Property(1), juce::GridItem::Property(6));
        b.setArea(juce::GridItem::Property(1), juce::GridItem::Property(7));
        
        naturals.items = { c, d, e, f, g, a, b };
//        naturals.items = { c };
        
        sharps.performLayout (juce::Rectangle<int> (buttonWidth, 0, 800, buttonHeight));
        naturals.performLayout (juce::Rectangle<int> (0, buttonHeight, 800, buttonHeight));
    }
    
    ~ScaleComponent(){
        setLookAndFeel(nullptr);
    }
    juce::TextButton ScaleButton;
    juce::TextButton button1;
    
private:
    // Adds 'p' as a class member so we can access it outside of the constructor
    VerboseAudioProcessor& classMemberProcessor;
    ScaleButtonLookAndFeel ScaleButtonLookAndFeel;

    // Define the scale component buttons for naturals
    ScaleButtonWrapperComponent CScaleButton { ScaleComponent::classMemberProcessor, scaleButtonToggleState.C, scaleButtonOctaveState.C, scaleButtonLabels.C };
    ScaleButtonWrapperComponent DScaleButton { this->classMemberProcessor, scaleButtonToggleState.D, scaleButtonOctaveState.D, scaleButtonLabels.D };
    ScaleButtonWrapperComponent EScaleButton { this->classMemberProcessor, scaleButtonToggleState.E, scaleButtonOctaveState.E, scaleButtonLabels.E };
    ScaleButtonWrapperComponent FScaleButton { this->classMemberProcessor, scaleButtonToggleState.F, scaleButtonOctaveState.F, scaleButtonLabels.F };
    ScaleButtonWrapperComponent GScaleButton { this->classMemberProcessor, scaleButtonToggleState.G, scaleButtonOctaveState.G, scaleButtonLabels.G };
    ScaleButtonWrapperComponent AScaleButton { this->classMemberProcessor, scaleButtonToggleState.A, scaleButtonOctaveState.A, scaleButtonLabels.A };
    ScaleButtonWrapperComponent BScaleButton { this->classMemberProcessor, scaleButtonToggleState.B, scaleButtonOctaveState.B, scaleButtonLabels.B };
    
    // Define the scale component buttons for sharps
    ScaleButtonWrapperComponent CSharpScaleButton { this->classMemberProcessor, scaleButtonToggleState.CSharp, scaleButtonOctaveState.CSharp, scaleButtonLabels.CSharp };
    ScaleButtonWrapperComponent DSharpScaleButton { this->classMemberProcessor, scaleButtonToggleState.DSharp, scaleButtonOctaveState.DSharp, scaleButtonLabels.DSharp };
    ScaleButtonWrapperComponent FSharpScaleButton { this->classMemberProcessor, scaleButtonToggleState.FSharp, scaleButtonOctaveState.FSharp, scaleButtonLabels.FSharp };
    ScaleButtonWrapperComponent GSharpScaleButton { this->classMemberProcessor, scaleButtonToggleState.GSharp, scaleButtonOctaveState.FSharp, scaleButtonLabels.GSharp };
    ScaleButtonWrapperComponent ASharpScaleButton { this->classMemberProcessor, scaleButtonToggleState.ASharp, scaleButtonOctaveState.ASharp, scaleButtonLabels.ASharp };

    
    // Define a vector for iterating over the buttons
    std::vector<ScaleButtonWrapperComponent*> scale_buttons = {
        &CScaleButton,
        &CSharpScaleButton,
        &DScaleButton,
        &DSharpScaleButton,
        &EScaleButton,
        &FScaleButton,
        &FSharpScaleButton,
        &GScaleButton,
        &GSharpScaleButton,
        &AScaleButton,
        &ASharpScaleButton,
        &BScaleButton
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

