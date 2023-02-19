/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================

class VerboseAudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    VerboseAudioProcessor();
    ~VerboseAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    
    //==============================================================================
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    juce::AudioProcessorValueTreeState verboseAPVTS {*this, nullptr, "Parameters", createParameterLayout()};
//    void getAPVTSParams();
    
//    int scaleButtParam_C;
//    int scaleButtParam_CSharp;
//    int scaleButtParam_D;
//    int scaleButtParam_DSharp;
//    int scaleButtParam_E;
//    int scaleButtParam_F;
//    int scaleButtParam_FSharp;
//    int scaleButtParam_G;
//    int scaleButtParam_GSharp;
//    int scaleButtParam_A;
//    int scaleButtParam_ASharp;
//    int scaleButtParam_B;
    
//    int stepButtParam_one;
//    int stepButtParam_two;
//    int stepButtParam_three;
//    int stepButtParam_four;
//    int stepButtParam_five;
//    int stepButtParam_six;
//    int stepButtParam_seven;
//    int stepButtParam_eight;
//    int stepButtParam_nine;
//    int stepButtParam_ten;
//    int stepButtParam_eleven;
//    int stepButtParam_twelve;
//    int stepButtParam_thirteen;
//    int stepButtParam_fourteen;
//    int stepButtParam_fifteen;
//    int stepButtParam_sixteen;
//    int var1 = 0.0;
        
private:
    //==============================================================================
//    void getGuiParams();
//    std::atomic<float>* gui_var1 = nullptr;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VerboseAudioProcessor)
};
