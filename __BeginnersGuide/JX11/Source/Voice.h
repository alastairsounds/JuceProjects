#pragma once

#include "Envelope.h"
#include "Oscillator.h"

struct Voice
{
    int note;
    float saw;
    Oscillator osc;
    Envelope env;

    void reset()
    {
        note = 0;
        saw = 0.0f;
        osc.reset();
    }

    float render(float input)
    {
        float sample = osc.nextSample();
        saw = saw * 0.997f + sample;

        float output = saw + input;

        float envelope = env.nextValue();
        return saw * envelope;
    }
};
