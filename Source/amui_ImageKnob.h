/*
  ==============================================================================

    ImageKnob.h
    Created: 19 Jun 2023 2:16:18pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

class ImageKnob: public juce::Component
{
    
public:

    ImageKnob(AntimatterUITemplateAudioProcessor& p, juce::String imageKnobAttachmentId)
    {
        ImageKnobSlider.setBounds(0, 0, 200, 200);
        addAndMakeVisible(ImageKnobSlider);
        ImageKnobAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (p.APVTS, imageKnobAttachmentId, ImageKnobSlider));
    }
    
    void paint (juce::Graphics& g) override
    {
//        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        ImageKnobSlider.setBounds(0, 0, 200, 200);
    }
    
    ~ImageKnob(){
    }
    
private:
    juce::Slider ImageKnobSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> ImageKnobAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ImageKnob)
};


