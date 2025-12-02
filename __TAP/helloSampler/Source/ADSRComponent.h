#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

//==============================================================================
/*
*/
class ADSRComponent : public juce::Component
{
public:
    ADSRComponent (HelloSamplerAudioProcessor& p);
    ~ADSRComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider mAttackSlider;
    juce::Slider mDecaySlider;
    juce::Slider mSustainSlider;
    juce::Slider mReleaseSlider;
    juce::Label mAttackLabel;
    juce::Label mDecayLabel;
    juce::Label mSustainLabel;
    juce::Label mReleaseLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mAttackAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mDecayAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mSustainAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mReleaseAttachment;

    HelloSamplerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};
