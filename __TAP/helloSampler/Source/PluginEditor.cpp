#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
HelloSamplerAudioProcessorEditor::HelloSamplerAudioProcessorEditor (HelloSamplerAudioProcessor& p)
    : AudioProcessorEditor (&p), mWaveThumbnail (p), mADSR (p), processor (p)
{
    addAndMakeVisible (mWaveThumbnail);
    addAndMakeVisible (mADSR);

    setSize (600, 400);
}

HelloSamplerAudioProcessorEditor::~HelloSamplerAudioProcessorEditor()
{
}

//==============================================================================
void HelloSamplerAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void HelloSamplerAudioProcessorEditor::resized()
{
    mWaveThumbnail.setBoundsRelative (0.0f, 0.25f, 1.0f, 0.5f);
    mADSR.setBoundsRelative (0.0f, 0.75f, 1.0f, 0.25f);
}
