# Reaction Game

A simple 2-player reaction speed game built with an Arduino. Watch the light sequence, then be the first to hit your button when the white "go" lights come on.

## How It Works

1. **Green → Yellow → Red** LEDs light up in sequence, each with a short buzzer beep, like a countdown.
2. After red turns off, there's a **random delay** (0.9–4.9 seconds) before the "go" signal — keeps players from jumping the gun.
3. Both **white LEDs** turn on — that's the signal to go.
4. Whoever presses their button first wins: their white LED stays on, the other player's turns off.
5. A short victory tune plays, then the game resets for another round.

## Hardware

| Component | Arduino Pin |
|---|---|
| White LED (Player 1) | 4 |
| Green LED | 9 |
| Yellow LED | 10 |
| Red LED | 11 |
| White LED (Player 2) | 12 |
| Buzzer | 7 |
| Button (Player 1) | 3 |
| Button (Player 2) | 13 |

- Buttons are wired with `INPUT_PULLUP`, so connect each button between its pin and GND (no external resistor needed).
- LEDs and the buzzer connect through the usual current-limiting resistors to their pins and GND.

## Setup

1. Wire up the components as listed above.
2. Open `reac_game.ino` in the Arduino IDE.
3. Select your board and port, then upload.
4. Power it up and play.

## Notes

- The random delay uses `randomSeed(analogRead(A0))`, so leave analog pin A0 unconnected (floating) for better randomness.