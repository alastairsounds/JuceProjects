#pragma once

#include <JuceHeader.h>
#include "Voice.h"
#include "NoiseGenerator.h"

class Synth
{
public:
    Synth();

    void allocateResources(double sampleRate, int samplesPerBlock);
    void deallocateResources();
    void reset();
    void render(float** outputBuffers, int sampleCount);
    void midiMessage(uint8_t data0, uint8_t data1, uint8_t data2);

    float noiseMix;

    float envAttack, envDecay, envSustain, envRelease;

    float oscMix;
    float detune;
    float tune;

    static constexpr int MAX_VOICES = 8;
    int numVoices;
    float volumeTrim;
    juce::LinearSmoothedValue<float> outputLevelSmoother;

private:
    void noteOn(int note, int velocity);
    void noteOff(int note);
    float calcPeriod(int v, int note) const;
    void startVoice(int v, int note, int velocity);
    int findFreeVoice() const;
    void controlChange(uint8_t data1, uint8_t data2);

    float sampleRate;
    std::array<Voice, MAX_VOICES> voices;
    NoiseGenerator noiseGen;

    float pitchBend;
    bool sustainPedalPressed;
};
