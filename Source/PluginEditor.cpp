/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Scale_Component.h"

//==============================================================================
VerboseAudioProcessorEditor::VerboseAudioProcessorEditor (VerboseAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), scene(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(scene);
    setSize (400, 300);
}

VerboseAudioProcessorEditor::~VerboseAudioProcessorEditor()
{
}

//==============================================================================
void VerboseAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void VerboseAudioProcessorEditor::resized()
{
    scene.setBounds (0, 0, getWidth(), getHeight());

}
