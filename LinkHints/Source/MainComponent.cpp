#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
}

MainComponent::MainComponent()
{
    // Add buttons and search bar to the component
    addAndMakeVisible (playButton);
    addAndMakeVisible (stopButton);
    addAndMakeVisible (searchBar);

    // Button click behavior
    playButton.onClick = [this]()
    { juce::Logger::writeToLog ("Play button clicked!"); };
    stopButton.onClick = [this]()
    { juce::Logger::writeToLog ("Stop button clicked!"); };

    // Configure the search bar
    searchBar.setTextToShowWhenEmpty ("Search...", juce::Colours::grey);
    searchBar.setMultiLine (false);

    setSize (400, 300); // Default size
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::FontOptions (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // Define layout: button size and positioning
    auto area = getLocalBounds().reduced (10); // Margin
    auto buttonHeight = 40;

    playButton.setBounds (area.removeFromTop (buttonHeight).removeFromLeft (area.getWidth() / 2).reduced (5));
    stopButton.setBounds (area.removeFromTop (buttonHeight).reduced (5));
    searchBar.setBounds (area.removeFromTop (buttonHeight).reduced (5));
}
