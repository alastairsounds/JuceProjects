/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AudioProgrammer_TestPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AudioProgrammer_TestPluginAudioProcessorEditor (AudioProgrammer_TestPluginAudioProcessor&);
    ~AudioProgrammer_TestPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioProgrammer_TestPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioProgrammer_TestPluginAudioProcessorEditor)
};
