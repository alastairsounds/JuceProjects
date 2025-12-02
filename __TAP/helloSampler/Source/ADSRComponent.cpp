#include "ADSRComponent.h"
#include <JuceHeader.h>

//==============================================================================
ADSRComponent::ADSRComponent (HelloSamplerAudioProcessor& p) : processor (p)
{
    // Attack Slider
    mAttackSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    mAttackSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 40, 20);
    mAttackSlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::red);
    addAndMakeVisible (mAttackSlider);
    // Attack Text
    mAttackLabel.setFont (10.0f);
    mAttackLabel.setText ("Attack", juce::NotificationType::dontSendNotification);
    mAttackLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::green);
    mAttackLabel.setJustificationType (juce::Justification::centredTop);
    mAttackLabel.attachToComponent (&mAttackSlider, false);
    mAttackAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.getAPVTS(), "ATTACK", mAttackSlider);
    // Decay Slider
    mDecaySlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDecaySlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 40, 20);
    mDecaySlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::red);
    addAndMakeVisible (mDecaySlider);
    // Decay Text
    mDecayLabel.setFont (10.0f);
    mDecayLabel.setText ("Decay", juce::NotificationType::dontSendNotification);
    mDecayLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::green);
    mDecayLabel.setJustificationType (juce::Justification::centredTop);
    mDecayLabel.attachToComponent (&mDecaySlider, false);
    mDecayAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.getAPVTS(), "DECAY", mDecaySlider);
    // Sustain Slider
    mSustainSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    mSustainSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 40, 20);
    mSustainSlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::red);
    addAndMakeVisible (mSustainSlider);
    // Sustain Text
    mSustainLabel.setFont (10.0f);
    mSustainLabel.setText ("Sustain", juce::NotificationType::dontSendNotification);
    mSustainLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::green);
    mSustainLabel.setJustificationType (juce::Justification::centredTop);
    mSustainLabel.attachToComponent (&mSustainSlider, false);
    mSustainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.getAPVTS(), "SUSTAIN", mSustainSlider);
    // Release Slider
    mReleaseSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    mReleaseSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 40, 20);
    mReleaseSlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::red);
    addAndMakeVisible (mReleaseSlider);
    // Release Text
    mReleaseLabel.setFont (10.0f);
    mReleaseLabel.setText ("Release", juce::NotificationType::dontSendNotification);
    mReleaseLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::green);
    mReleaseLabel.setJustificationType (juce::Justification::centredTop);
    mReleaseLabel.attachToComponent (&mReleaseSlider, false);
    mReleaseAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.getAPVTS(), "RELEASE", mReleaseSlider);
}

ADSRComponent::~ADSRComponent()
{
}

void ADSRComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void ADSRComponent::resized()
{
    // clang-format off
    const float startX     = 0.6f;
    const float startY     = 0.2f;
    const float dialWidth  = 0.1f;
    const float dialHeight = 0.75f;
    mAttackSlider.setBoundsRelative  (startX,                   startY, dialWidth, dialHeight);
    mDecaySlider.setBoundsRelative   (startX + (dialWidth * 1), startY, dialWidth, dialHeight);
    mSustainSlider.setBoundsRelative (startX + (dialWidth * 2), startY, dialWidth, dialHeight);
    mReleaseSlider.setBoundsRelative (startX + (dialWidth * 3), startY, dialWidth, dialHeight);
    // clang-format on
}
