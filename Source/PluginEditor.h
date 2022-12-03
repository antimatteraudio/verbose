
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Main_Component.h"

//==============================================================================

class VerboseAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    VerboseAudioProcessorEditor (VerboseAudioProcessor&);
    ~VerboseAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    VerboseAudioProcessor& audioProcessor;

    SceneComponent scene;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VerboseAudioProcessorEditor)
};
