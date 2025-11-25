#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

//==============================================================================
/**
*/
class HelloSamplerAudioProcessorEditor : public juce::AudioProcessorEditor,
                                         public juce::FileDragAndDropTarget
{
public:
    HelloSamplerAudioProcessorEditor (HelloSamplerAudioProcessor&);
    ~HelloSamplerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    bool isInterestedInFileDrag (const juce::StringArray& files) override;
    void filesDropped (const juce::StringArray& files, int x, int y) override;

private:
    juce::TextButton mLoadButton { "Load" };

    HelloSamplerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelloSamplerAudioProcessorEditor)
};
