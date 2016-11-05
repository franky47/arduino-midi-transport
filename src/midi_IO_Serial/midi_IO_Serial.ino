/*
 * The MIT License - Copyright (c) 2016 Francois Best
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <MIDI.h>
#include <sparkfun_MidiShield.h>

MIDI_CREATE_DEFAULT_INSTANCE();

struct State
{
    sparkfun::MidiShield::ButtonsState  mButtons;
    sparkfun::MidiShield::PotsState     mPots;
};

State sState;

// -----------------------------------------------------------------------------

void handleNoteOn(byte inChannel, byte inNote, byte inVelocity)
{
    sparkfun::MidiShield::setGreenLedState(true);
}

void handleNoteOff(byte inChannel, byte inNote, byte inVelocity)
{
    sparkfun::MidiShield::setGreenLedState(false);
}

// -----------------------------------------------------------------------------

void setup()
{
    sparkfun::MidiShield::setup();
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
    sparkfun::MidiShield::readPots(sState.mPots);
    sparkfun::MidiShield::readButtons(sState.mButtons);
    MIDI.read();
}
