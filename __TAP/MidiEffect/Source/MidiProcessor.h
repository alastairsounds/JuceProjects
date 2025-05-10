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
        processedBuffer.clear();
        // Juce uses linked lists to manipulate MidiBuffers
        juce::MidiBuffer::Iterator it(midiMessages);
        juce::MidiMessage currentMessage;
        int samplePos;

        while (it.getNextEvent(currentMessage, samplePos))
        {
            if (currentMessage.isNoteOnOrOff())
            {
                auto transposedMessage = currentMessage;
                auto oldNoteNum = transposedMessage.getNoteNumber();
                transposedMessage.setNoteNumber(oldNoteNum + INTERVAL);
                
                processedBuffer.addEvent(transposedMessage, samplePos);
            }
            processedBuffer.addEvent(currentMessage, samplePos);
        }
        
        midiMessages.swapWith(processedBuffer);
    }
    
    juce::MidiBuffer processedBuffer;
};
