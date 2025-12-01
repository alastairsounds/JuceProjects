#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

//==============================================================================
/**
*/
class HelloSamplerAudioProcessorEditor : public juce::AudioProcessorEditor,
                                         public juce::FileDragAndDropTarget,
                                         public juce::Slider::Listener
{
public:
    HelloSamplerAudioProcessorEditor (HelloSamplerAudioProcessor&);
    ~HelloSamplerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    bool isInterestedInFileDrag (const juce::StringArray& files) override;
    void filesDropped (const juce::StringArray& files, int x, int y) override;

    void sliderValueChanged (juce::Slider* slider) override;

private:
    juce::TextButton mLoadButton { "Load" };
    std::vector<float> mAudioPoints;
    bool mShouldBePainting { false };

    juce::Slider mAttackSlider;
    juce::Slider mDecaySlider;
    juce::Slider mSustainSlider;
    juce::Slider mReleaseSlider;
    juce::Label mAttackLabel;
    juce::Label mDecayLabel;
    juce::Label mSustainLabel;
    juce::Label mReleaseLabel;

    HelloSamplerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelloSamplerAudioProcessorEditor)
};
