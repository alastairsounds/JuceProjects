#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
HelloSamplerAudioProcessorEditor::HelloSamplerAudioProcessorEditor (HelloSamplerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    mLoadButton.onClick = [&]() { processor.loadFile(); };
    addAndMakeVisible (mLoadButton);

    // Attack Slider
    mAttackSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    mAttackSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 40, 20);
    mAttackSlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::red);
    mAttackSlider.setRange (0.0f, 0.5, 0.01f);
    mReleaseSlider.addListener (this);
    addAndMakeVisible (mAttackSlider);
    // Attack Text
    mAttackLabel.setFont (10.0f);
    mAttackLabel.setText ("Attack", juce::NotificationType::dontSendNotification);
    mAttackLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::green);
    mAttackLabel.setJustificationType (juce::Justification::centredTop);
    mAttackLabel.attachToComponent (&mAttackSlider, false);
    // Decay Slider
    mDecaySlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDecaySlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 40, 20);
    mDecaySlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::red);
    mDecaySlider.setRange (0.0f, 0.5, 0.01f);
    mSustainSlider.addListener (this);
    addAndMakeVisible (mDecaySlider);
    // Decay Text
    mDecayLabel.setFont (10.0f);
    mDecayLabel.setText ("Decay", juce::NotificationType::dontSendNotification);
    mDecayLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::green);
    mDecayLabel.setJustificationType (juce::Justification::centredTop);
    mDecayLabel.attachToComponent (&mDecaySlider, false);
    // Sustain Slider
    mSustainSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    mSustainSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 40, 20);
    mSustainSlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::red);
    mSustainSlider.setRange (0.0f, 0.5, 0.01f);
    mDecaySlider.addListener (this);
    addAndMakeVisible (mSustainSlider);
    // Sustain Text
    mSustainLabel.setFont (10.0f);
    mSustainLabel.setText ("Sustain", juce::NotificationType::dontSendNotification);
    mSustainLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::green);
    mSustainLabel.setJustificationType (juce::Justification::centredTop);
    mSustainLabel.attachToComponent (&mSustainSlider, false);
    // Release Slider
    mReleaseSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    mReleaseSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 40, 20);
    mReleaseSlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::red);
    mReleaseSlider.setRange (0.0f, 0.5, 0.01f);
    mAttackSlider.addListener (this);
    addAndMakeVisible (mReleaseSlider);
    // Release Text
    mReleaseLabel.setFont (10.0f);
    mReleaseLabel.setText ("Release", juce::NotificationType::dontSendNotification);
    mReleaseLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::green);
    mReleaseLabel.setJustificationType (juce::Justification::centredTop);
    mReleaseLabel.attachToComponent (&mReleaseSlider, false);

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

    // clang-format off
    const float startX     = 0.6f;
    const float startY     = 0.6f;
    const float dialWidth  = 0.1f;
    const float dialHeight = 0.4f;
    mAttackSlider.setBoundsRelative  (startX,                   startY, dialWidth, dialHeight);
    mDecaySlider.setBoundsRelative   (startX + (dialWidth * 1), startY, dialWidth, dialHeight);
    mSustainSlider.setBoundsRelative (startX + (dialWidth * 2), startY, dialWidth, dialHeight);
    mReleaseSlider.setBoundsRelative (startX + (dialWidth * 3), startY, dialWidth, dialHeight);
    // clang-format on
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

void HelloSamplerAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    if (slider == &mAttackSlider)
    {
        processor.getADSRParams().attack = mAttackSlider.getValue();
    }
    else if (slider == &mDecaySlider)
    {
        processor.getADSRParams().decay = mDecaySlider.getValue();
    }
    else if (slider == &mSustainSlider)
    {
        processor.getADSRParams().sustain = mSustainSlider.getValue();
    }
    else if (slider == &mReleaseSlider)
    {
        processor.getADSRParams().release = mReleaseSlider.getValue();
    }

    processor.updateADSR();
    return;
}
