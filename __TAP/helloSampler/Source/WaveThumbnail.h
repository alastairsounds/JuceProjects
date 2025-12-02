#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

//==============================================================================
/*
*/
class WaveThumbnail : public juce::Component,
                      public juce::FileDragAndDropTarget
{
public:
    WaveThumbnail (HelloSamplerAudioProcessor& p);
    ~WaveThumbnail() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    bool isInterestedInFileDrag (const juce::StringArray& files);
    void filesDropped (const juce::StringArray& files, int x, int y);

private:
    std::vector<float> mAudioPoints;

    juce::String mFileName { "" };

    HelloSamplerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveThumbnail)
};
