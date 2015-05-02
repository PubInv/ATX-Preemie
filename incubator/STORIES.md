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

Note: Here is how I made a little Arduino plugin.

![imag0116](https://cloud.githubusercontent.com/assets/5296671/7442051/3c631796-f0c7-11e4-911f-d299824b4876.jpg)

Use male-male breakaway headers. Score a single row or perfboard with a utitlity knife then break with a pair of pliers.  Solder the headers into the board.  Now you have a solderable place to put your sensor wires.

I didn't have time to order a "shield", I just needed get those wires from a remote LED (about 18" away in the "test baby") into the output pins 9,10, and 11.  Hopefully this is a reasonable sturdy solution.

Close-up of the RGB LED on the other end of this wire.  Note the resistor soldered in-line to prevent burning out the LED --- don't forget that or you waste an LED!

![imag0117](https://cloud.githubusercontent.com/assets/5296671/7442080/261e49b4-f0c8-11e4-8549-3448a1482c87.jpg)


Finished Arduino Connectors:

![imag0118](https://cloud.githubusercontent.com/assets/5296671/7442635/b8ebe6e6-f0de-11e4-8b23-eeaf36906224.jpg)

Connectors plugged into Arduino:

![imag0119](https://cloud.githubusercontent.com/assets/5296671/7442633/99336824-f0de-11e4-80e2-ecff54ab45ed.jpg)

Finished baby ready for testing (showing loose heating fabric below it.)

![imag0120](https://cloud.githubusercontent.com/assets/5296671/7442632/7a99009a-f0de-11e4-9ade-ce61a629c64e.jpg)



