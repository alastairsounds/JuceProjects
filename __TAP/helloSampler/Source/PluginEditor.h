#pragma once

#include "ADSRComponent.h"
#include "PluginProcessor.h"
#include "WaveThumbnail.h"
#include <JuceHeader.h>

//==============================================================================
/**
*/
class HelloSamplerAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    HelloSamplerAudioProcessorEditor (HelloSamplerAudioProcessor&);
    ~HelloSamplerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    WaveThumbnail mWaveThumbnail;
    ADSRComponent mADSR;

    HelloSamplerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelloSamplerAudioProcessorEditor)
};
