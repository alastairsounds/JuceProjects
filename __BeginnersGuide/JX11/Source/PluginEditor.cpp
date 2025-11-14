/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JX11AudioProcessorEditor::JX11AudioProcessorEditor (JX11AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    juce::LookAndFeel::setDefaultLookAndFeel(&globalLNF);
    outputLevelKnob.label = "Level";
    addAndMakeVisible(outputLevelKnob);
    filterResoKnob.label = "Reso";
    addAndMakeVisible(filterResoKnob);
    polyModeButton.setButtonText("Poly");
    polyModeButton.setClickingTogglesState(true);
    addAndMakeVisible(polyModeButton);

    setSize (600, 400);
}

JX11AudioProcessorEditor::~JX11AudioProcessorEditor()
{
}

//==============================================================================
void JX11AudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void JX11AudioProcessorEditor::resized()
{
    outputLevelKnob.setBounds(20, 20, 100, 120);
    filterResoKnob.setBounds(120, 20, 100, 120);
    polyModeButton.setBounds(240, 20, 80, 30);
}
