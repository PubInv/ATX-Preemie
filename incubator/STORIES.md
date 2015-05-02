# Stories

(This is mostly in preparation for Mini Maker Faire.)

## Prove that heating blanket works with MOSFET

Prove that I can drive the new heating blanket with the MOSFET that I used for the fan.

## Work with remote Temperature sensor

Prove that I can read the temperature effectively with the remote transistor

## Attempt to use PID library to maintain the temperature correctly.

## Construct working prototype

## Make run on low power

This is an exclellent article: https://www.openhomeautomation.net/arduino-battery/

It talks about both the hardware and software.  For our purposes we could deal with the software first (should be almost trivial) and then deal with the hardware later.)

# Extra Credit

Build a temperature sensing test infant that let's you know when it is too cold or too hot.

Here is the working temperature circuit with a red, green, blue LED.

If I can figure out how to package this it should be usable as a model we can test with:

![imag0115](https://cloud.githubusercontent.com/assets/5296671/7426473/b4928d2e-ef8b-11e4-9f14-0166d2df42df.jpg)

### Note on packaging

One way to package this would be to solder the resistors to the protosolder board.  Then build a board with the bundles of wires:

* three wires attached to temperature sensor about 18" long (stranded)
* 4 wires attached to LED abou 18" long (stranded)
* Ground, common, signal, red, green and blue soldered on solid wire that can go into Arduino.

That would take about 2 hours to make, I reckon.

Is this worth doing?

Note: I am actually working on this.  I found some 8-strand telephone interface wire.  I am using seven of them.  I soldered the LED in place, I need to do the temperature sensor next.  I'm not sure this is a great use of my time, but at least it will be something demonstrable at the Mini Maker Faire.

