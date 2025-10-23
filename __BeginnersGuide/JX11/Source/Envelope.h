#pragma once

const float SILENCE = 0.0001f;

class Envelope
{
public:
    float level;
    float multiplier;
    float target;

    float nextValue()
    {
        level = multiplier * (level - target) + target;
        return level;
    }
};