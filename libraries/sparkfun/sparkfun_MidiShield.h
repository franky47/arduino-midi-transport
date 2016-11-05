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

#pragma once

#include "sparkfun.h"
#include "ark_Utility.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif

BEGIN_SPARKFUN_NAMESPACE

struct MidiShield
{
public:
    enum
    {
        // Buttons
        buttonLeft      = 2,
        buttonMiddle    = 3,
        buttonRight     = 4,

        // Pots
        potLeft         = 0,
        potRight        = 1,

        // LEDs
        ledGreen        = 6,
        ledRed          = 7,
    };

public:
    struct ButtonsState
    {
        bool mLeft;
        bool mMiddle;
        bool mRight;
    };
    struct PotsState
    {
        int mLeft;
        int mRight;
    };

public:
    static inline void setupButtons()
    {
        pinMode(buttonLeft,     INPUT_PULLUP);
        pinMode(buttonMiddle,   INPUT_PULLUP);
        pinMode(buttonRight,    INPUT_PULLUP);
    }
    static inline void setupLeds()
    {
        pinMode(ledGreen,   OUTPUT);
        pinMode(ledRed,     OUTPUT);
    }
    static inline void setup()
    {
        setupButtons();
        setupLeds();
    }

public:
    static inline bool readButtons(ButtonsState& ioState)
    {
        bool changed = false;
        changed |= ark::updateIfDifferent(ioState.mLeft,   bool(digitalRead(buttonLeft)));
        changed |= ark::updateIfDifferent(ioState.mMiddle, bool(digitalRead(buttonMiddle)));
        changed |= ark::updateIfDifferent(ioState.mRight,  bool(digitalRead(buttonRight)));
        return changed;
    }
    static inline void readPots(PotsState& ioState)
    {
        ioState.mLeft   = analogRead(potLeft);
        ioState.mRight  = analogRead(potRight);
    }

public:
    static inline void setGreenLedState(bool inState)
    {
        digitalWrite(ledGreen, inState ? HIGH : LOW);
    }
    static inline void setRedLedState(bool inState)
    {
        digitalWrite(ledRed, inState ? HIGH : LOW);
    }
};

END_SPARKFUN_NAMESPACE
