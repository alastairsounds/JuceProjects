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
class Virtual_InstrumentAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Virtual_InstrumentAudioProcessorEditor (Virtual_InstrumentAudioProcessor&);
    ~Virtual_InstrumentAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::TextButton mLoadButton { "Load" };

    Virtual_InstrumentAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Virtual_InstrumentAudioProcessorEditor)
};
