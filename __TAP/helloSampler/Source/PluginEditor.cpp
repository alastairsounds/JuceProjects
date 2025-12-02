#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
HelloSamplerAudioProcessorEditor::HelloSamplerAudioProcessorEditor (HelloSamplerAudioProcessor& p)
    : AudioProcessorEditor (&p), mWaveThumbnail (p), mADSR (p), processor (p)
{
    juce::Image logo = juce::ImageCache::getFromMemory (BinaryData::Logo_png, BinaryData::Logo_pngSize);

    if (!logo.isNull())
        mImageComponent.setImage (logo, juce::RectanglePlacement::stretchToFit);
    else
        jassert (!logo.isNull());

    addAndMakeVisible (mWaveThumbnail);
    addAndMakeVisible (mADSR);
    addAndMakeVisible (mImageComponent);

    startTimerHz (30);

    setSize (600, 400);
}

HelloSamplerAudioProcessorEditor::~HelloSamplerAudioProcessorEditor()
{
    stopTimer();
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
    mImageComponent.setBoundsRelative (0.0f, 0.0f, 0.30f, 0.25f);
}

void HelloSamplerAudioProcessorEditor::timerCallback()
{
    repaint();
}
