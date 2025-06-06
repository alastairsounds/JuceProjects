/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioProgrammer_TestPluginAudioProcessorEditor::AudioProgrammer_TestPluginAudioProcessorEditor (AudioProgrammer_TestPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    mLoadButton.onClick = [&] { audioProcessor.loadFile(); };
    addAndMakeVisible(mLoadButton);
    
    setSize (200, 200);
}

AudioProgrammer_TestPluginAudioProcessorEditor::~AudioProgrammer_TestPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioProgrammer_TestPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    
    // New file dropped?
        // if yes
        //
    
//    g.setColour(juce::Colours::white);
//    g.setFont(15.0f);
//    
//    if (audioProcessor.getNumSamplerSounds())
//    {
//        g.fillAll (juce::Colours::red);
//        g.drawText("Sound Loaded", getWidth() / 2 - 50, getHeight() / 2 - 10, 100, 20, juce::Justification::centred);
//    }
//    else
//    {
//        g.drawText("Load a Sound", getWidth() / 2 - 50, getHeight() / 2 - 10, 100, 20, juce::Justification::centred);
//    }
}

void AudioProgrammer_TestPluginAudioProcessorEditor::resized()
{
//    mLoadButton.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 50, 100, 100);
}

bool AudioProgrammer_TestPluginAudioProcessorEditor::isInterestedInFileDrag (const juce::StringArray &files)
{
    for (auto file : files)
    {
        if (file.contains(".wav") || file.contains(".mp3") || file.contains (".aif"))
        {
            return true;
        }
    }
    
    return false;
}

void AudioProgrammer_TestPluginAudioProcessorEditor::filesDropped(const juce::StringArray &files, int x, int y)
{
    for (auto file : files)
    {
        if (isInterestedInFileDrag(file))
        {
            audioProcessor.loadFile(file);
        }
    }
    
    repaint();
}
