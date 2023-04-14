

#pragma once

#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "APVTS_Constants.h"
#include "ScaleButton_Component.h"

// This component uses juce::Grid to lay out buttons for sharp and flat notes in a keyboard-style layout.

struct ScaleButtonLabels{
    std::string C = "C";
    std::string CSharp = "C#";
    std::string D = "D";
    std::string DSharp = "D#";
    std::string E = "E";
    std::string F = "F";
    std::string FSharp = "F#";
    std::string G = "G";
    std::string GSharp = "G#";
    std::string A = "A";
    std::string ASharp = "A#";
    std::string B = "B";
};

class ScaleComponent: public juce::Component
{
    
public:

    ScaleComponent(VerboseAudioProcessor& p): classMemberProcessor(p)
    {
        setLookAndFeel(&ScaleButtonLookAndFeel);
        
        for (int i = 0; i < scale_buttons.size(); i++){
            scale_buttons[i] -> setBounds(i * buttonHeight, 0, buttonHeight, buttonHeight);
            addAndMakeVisible(scale_buttons[i]);
        }
    }
    
    void paint (juce::Graphics& g) override
    {
//        auto area = getLocalBounds();
//        RoundedRectangleBackground.drawBackground(g, area, midGrey, 8, 8);
//        area.centreWithSize();

    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        area.removeFromRight(padding);
        area.removeFromLeft(padding);
        area.removeFromBottom(padding);
        area.removeFromTop(padding);
        auto buttonWidth = area.getWidth()/columns;
        
        juce::Grid sharps;
        juce::Grid naturals;
        
        using Track = juce::Grid::TrackInfo;
        using fr = juce::Grid::Fr;
        using px = juce::Grid::Px;
        
        // Grid layout for sharp note buttons
        
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
        
        // Grid layout for natural note buttons

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
        
        sharps.performLayout (juce::Rectangle<int> ((area.getX() + buttonWidth), area.getY(), area.getWidth(), buttonHeight));
        naturals.performLayout (juce::Rectangle<int> (area.getX(), (area.getY() + buttonHeight), area.getWidth(), buttonHeight));
    }
    
    ~ScaleComponent(){
        setLookAndFeel(nullptr);
    }
    juce::TextButton ScaleButton;
    juce::TextButton button1;
    
private:
    // Adds 'p' as a class member so we can access it outside of the constructor
    VerboseAudioProcessor& classMemberProcessor;
    
    ScaleButtonLabels scaleButtonLabels;
    
    ScaleButtonLookAndFeel ScaleButtonLookAndFeel;
    RoundedRectangleBackground RoundedRectangleBackground;

    // Define the scale component buttons for naturals
    ScaleButtonComponent CScaleButton { ScaleComponent::classMemberProcessor, scaleButtonToggleState.C, scaleButtonOctaveState.C, scaleButtonLabels.C };
    ScaleButtonComponent DScaleButton { this->classMemberProcessor, scaleButtonToggleState.D, scaleButtonOctaveState.D, scaleButtonLabels.D };
    ScaleButtonComponent EScaleButton { this->classMemberProcessor, scaleButtonToggleState.E, scaleButtonOctaveState.E, scaleButtonLabels.E };
    ScaleButtonComponent FScaleButton { this->classMemberProcessor, scaleButtonToggleState.F, scaleButtonOctaveState.F, scaleButtonLabels.F };
    ScaleButtonComponent GScaleButton { this->classMemberProcessor, scaleButtonToggleState.G, scaleButtonOctaveState.G, scaleButtonLabels.G };
    ScaleButtonComponent AScaleButton { this->classMemberProcessor, scaleButtonToggleState.A, scaleButtonOctaveState.A, scaleButtonLabels.A };
    ScaleButtonComponent BScaleButton { this->classMemberProcessor, scaleButtonToggleState.B, scaleButtonOctaveState.B, scaleButtonLabels.B };
    
    // Define the scale component buttons for sharps
    ScaleButtonComponent CSharpScaleButton { this->classMemberProcessor, scaleButtonToggleState.CSharp, scaleButtonOctaveState.CSharp, scaleButtonLabels.CSharp };
    ScaleButtonComponent DSharpScaleButton { this->classMemberProcessor, scaleButtonToggleState.DSharp, scaleButtonOctaveState.DSharp, scaleButtonLabels.DSharp };
    ScaleButtonComponent FSharpScaleButton { this->classMemberProcessor, scaleButtonToggleState.FSharp, scaleButtonOctaveState.FSharp, scaleButtonLabels.FSharp };
    ScaleButtonComponent GSharpScaleButton { this->classMemberProcessor, scaleButtonToggleState.GSharp, scaleButtonOctaveState.GSharp, scaleButtonLabels.GSharp };
    ScaleButtonComponent ASharpScaleButton { this->classMemberProcessor, scaleButtonToggleState.ASharp, scaleButtonOctaveState.ASharp, scaleButtonLabels.ASharp };

    
    // Define a vector for iterating over the buttons
    std::vector<ScaleButtonComponent*> scale_buttons = {
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


    int buttonHeight = 120;
    int padding = 16;
    int columns = 13;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleComponent)
};

