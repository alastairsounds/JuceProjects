/*
  ==============================================================================
    MidiProcessor.h
    Created: 10 May 2025 7:24:35am
    Author:  Alastair Scheuermann
  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

constexpr int INTERVAL = 4;

class MidiProcessor
{
public:
    void process(juce::MidiBuffer& midiMessages)
    {
        processedBuffer.clear(); // clear buffer, just in case buffer contains data
        processMidiInput(midiMessages);
        midiMessages.swapWith(processedBuffer);
    }

    void processMidiInput(juce::MidiBuffer& midiMessages)
    {
        juce::MidiMessage m;
        int samplePos;
        for(const juce::MidiMessageMetadata metadata : midiMessages)
        {
            m = metadata.getMessage();
            samplePos = metadata.samplePosition;
            if(m.isNoteOnOrOff())
                addTransposedNode(m, samplePos);
            processedBuffer.addEvent(m, samplePos);
            // DBG(m.getDescription());
        }
    }

    void addTransposedNode(juce::MidiMessage messageToTranspose, int samplePos)
    {
        auto oldNoteNum = messageToTranspose.getNoteNumber();
        messageToTranspose.setNoteNumber(oldNoteNum + INTERVAL);
        processedBuffer.addEvent(messageToTranspose, samplePos);
    }

    juce::MidiBuffer processedBuffer;
};
