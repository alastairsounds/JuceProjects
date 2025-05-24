/*
  ==============================================================================

    Parameters.cpp
    Created: 23 May 2025 7:48:30pm
    Author:  Alastair Scheuermann

  ==============================================================================
*/

#include "Parameters.h"

Parameters::Parameters(juce::AudioProcessorValueTreeState& apvts)
{
    auto* param = apvts.getParameter(gainParamID.getParamID());
    gainParam = dynamic_cast<juce::AudioParameterFloat*>(param);
}

juce::AudioProcessorValueTreeState::ParameterLayout Parameters::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add(std::make_unique<juce::AudioParameterFloat>
    (
     gainParamID,
     "Output Gain",
     juce::NormalisableRange<float> { -12.0f, 12.0f },
     0.0f
    ));
    return layout;
}
