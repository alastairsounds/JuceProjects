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
        env.reset();
    }

    float render(float input)
    {
        float sample = osc.nextSample();
        saw = saw * 0.997f + sample;

        float output = saw + input;

        float envelope = env.nextValue();
        return output * envelope;
        // return envelope; //* DEBUG to see envelope
    }

    void release()
    {
        env.release();
    }
};
