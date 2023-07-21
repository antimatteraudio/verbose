/*
  ==============================================================================

    ComboBox.h
    Created: 19 Jun 2023 2:25:03pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
namespace amui {
class ComboBox: public juce::Component
{
    
public:

    ComboBox(AntimatterUITemplateAudioProcessor& p, juce::String ComboBoxAttachmentId, juce::StringArray items)
    {
//        comboBox.setClickingTogglesState(1);
        comboBox.addItemList(items, 0);
        comboBoxAttachment.reset(new juce::AudioProcessorValueTreeState::ComboBoxAttachment (p.APVTS, ComboBoxAttachmentId, comboBox));
        auto area = getLocalBounds();
        comboBox.setBounds(area);
        addAndMakeVisible(comboBox);
    }
    
    void paint (juce::Graphics& g) override
    {
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        comboBox.setBounds(area);
        addAndMakeVisible(comboBox);
    }
    
    ~ComboBox(){
        setLookAndFeel(nullptr);
        comboBoxAttachment.reset();
    }
    
private:
    juce::ComboBox comboBox;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> comboBoxAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComboBox)
};
};
