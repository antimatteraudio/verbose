
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Main_Component.h"

//==============================================================================

class AntimatterUITemplateAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AntimatterUITemplateAudioProcessorEditor (AntimatterUITemplateAudioProcessor&);
    ~AntimatterUITemplateAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    
    
private:

    AntimatterUITemplateAudioProcessor& audioProcessor;


    SceneComponent scene;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AntimatterUITemplateAudioProcessorEditor)
};
