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

    void processMidiInput(juce::MidiBuffer &midiMessages)
    {
        // Juce uses linked lists to manipulate MidiBuffers
        juce::MidiBuffer::Iterator it(midiMessages);
        juce::MidiMessage currentMessage;
        int samplePos;
        
        while (it.getNextEvent(currentMessage, samplePos))
        {
            if (currentMessage.isNoteOnOrOff())
                addTransposedNode(currentMessage, samplePos);
            
            processedBuffer.addEvent(currentMessage, samplePos);
        }
    }

    void addTransposedNode(juce::MidiMessage messageToTranspose, int samplePos) {
        auto oldNoteNum = messageToTranspose.getNoteNumber();
        messageToTranspose.setNoteNumber(oldNoteNum + INTERVAL);
        
        processedBuffer.addEvent(messageToTranspose, samplePos);
    }


    juce::MidiBuffer processedBuffer;
};
