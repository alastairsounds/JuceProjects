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
class AudioProgrammer_TestPluginAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                                        public juce::FileDragAndDropTarget
{
public:
    AudioProgrammer_TestPluginAudioProcessorEditor (AudioProgrammer_TestPluginAudioProcessor&);
    ~AudioProgrammer_TestPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    bool isInterestedInFileDrag (const juce::StringArray &files) override;
    void filesDropped (const juce::StringArray &files, int x, int y) override;
    
private:
    juce::TextButton mLoadButton { "Load" };
    
    AudioProgrammer_TestPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioProgrammer_TestPluginAudioProcessorEditor)
};
