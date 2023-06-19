

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Scale_Component.h"

//==============================================================================
AntimatterUITemplateAudioProcessorEditor::AntimatterUITemplateAudioProcessorEditor (AntimatterUITemplateAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), scene(p)
{
    addAndMakeVisible(scene);
    
    setSize (800, 600);
}

AntimatterUITemplateAudioProcessorEditor::~AntimatterUITemplateAudioProcessorEditor()
{
}

//==============================================================================
void AntimatterUITemplateAudioProcessorEditor::paint (juce::Graphics& g)
{
 
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void AntimatterUITemplateAudioProcessorEditor::resized()
{
    scene.setBounds (0, 0, getWidth(), getHeight());
}
