#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
HelloSamplerAudioProcessorEditor::HelloSamplerAudioProcessorEditor (HelloSamplerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    mLoadButton.onClick = [&]() { processor.loadFile(); };
    addAndMakeVisible (mLoadButton);

    setSize (600, 200);
}

HelloSamplerAudioProcessorEditor::~HelloSamplerAudioProcessorEditor()
{
}

//==============================================================================
void HelloSamplerAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);

    if (mShouldBePainting)
    {
        juce::Path p;
        mAudioPoints.clear();

        auto waveform = processor.getWaveForm();
        auto ratio = waveform.getNumSamples() / getWidth();
        auto buffer = waveform.getReadPointer (0);

        // Scale audio file to window on x-axis
        for (int sample = 0; sample < waveform.getNumSamples(); sample += ratio)
        {
            mAudioPoints.push_back (buffer[sample]);
        }

        p.startNewSubPath (0, getHeight() / 2);

        // Scale on y-axis
        for (int sample = 0; sample < mAudioPoints.size(); ++sample)
        {
            auto point = juce::jmap<float> (mAudioPoints[sample], -1.0f, 1.0f, getHeight(), 0);
            p.lineTo (sample, point);
        }

        g.strokePath (p, juce::PathStrokeType (2));

        mShouldBePainting = false;
    }
}

void HelloSamplerAudioProcessorEditor::resized()
{
    // mLoadButton.setBounds (getWidth() / 2 - 50, getHeight() / 2 - 50, 100, 100);
}

bool HelloSamplerAudioProcessorEditor::isInterestedInFileDrag (const juce::StringArray& files)
{
    for (auto file : files)
    {
        if (file.contains (".wav") || file.contains (".mp3") || file.contains (".aif"))
        {
            return true;
        }
    }
    return false;
}

void HelloSamplerAudioProcessorEditor::filesDropped (const juce::StringArray& files, int x, int y)
{
    for (auto file : files)
    {
        if (isInterestedInFileDrag (file))
        {
            processor.loadFile (file);
            mShouldBePainting = true;
        }
    }
    repaint();
}
