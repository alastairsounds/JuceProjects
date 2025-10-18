#pragma once

const float SILENCE = 0.0001f;

class Envelope
{
public:
    float level;
    float multiplier;

    float nextValue()
    {
        level *= multiplier;
        return level;
    }
};