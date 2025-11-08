#pragma once

#include "Oscillator.h"
#include "Envelope.h"
#include "Filter.h"

struct Voice
{
    int note;
    float saw;
    float period;
    float target;

    float glideRate;

    Oscillator osc1;
    Oscillator osc2;
    Envelope env;
    Filter filter;

    float panLeft, panRight;
    float cutoff;
    float filterMod;
    float filterQ;
    float pitchBend;

    void reset()
    {
        note = 0;
        saw = 0.0f;

        osc1.reset();
        osc2.reset();
        env.reset();
        filter.reset();

        panLeft = 0.707f;
        panRight = 0.707f;
    }

    float render(float input)
    {
        float sample1 = osc1.nextSample();
        float sample2 = osc2.nextSample();
        saw = saw * 0.997f + sample1 - sample2;

        float output = saw + input;
        output = filter.render(output);
        float envelope = env.nextValue();
        return output * envelope;
    }

    void updatePanning()
    {
        float panning = std::clamp((note - 60.0f) / 24.0f, -1.0f, 1.0f);
        panLeft = std::sin(PI_OVER_4 * (1.0f - panning));
        panRight = std::sin(PI_OVER_4 * (1.0f + panning));
    }

    void updateLFO()
    {
        float modulatedCutoff = cutoff * std::exp(filterMod) / pitchBend;
        modulatedCutoff = std::clamp(modulatedCutoff, 30.0f, 20000.0f);
        filter.updateCoefficients(modulatedCutoff, filterQ);
    }

    void release()
    {
        env.release();
    }
};
