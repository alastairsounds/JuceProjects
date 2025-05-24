/*
  ==============================================================================

    Parameters.h
    Created: 23 May 2025 7:48:30pm
    Author:  Alastair Scheuermann

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
const juce::ParameterID gainParamID { "gain", 1 };

class Parameters {
    public:
    Parameters(juce::AudioProcessorValueTreeState& apvts);
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    juce::AudioParameterFloat* gainParam;
};
