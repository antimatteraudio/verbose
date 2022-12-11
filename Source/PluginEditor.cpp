

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Scale_Component.h"

//==============================================================================
VerboseAudioProcessorEditor::VerboseAudioProcessorEditor (VerboseAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), scene(p)
{
    addAndMakeVisible(scene);
    setSize (800, 600);
}

VerboseAudioProcessorEditor::~VerboseAudioProcessorEditor()
{
}

//==============================================================================
void VerboseAudioProcessorEditor::paint (juce::Graphics& g)
{
 
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void VerboseAudioProcessorEditor::resized()
{
    scene.setBounds (0, 0, getWidth(), getHeight());
}
