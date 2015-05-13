# Story #1: Build a motor control that can handle the larger fan that I bought.

This fan is from Thermaltake cand cost about $20 from Radio Shack:
![imag0112](https://cloud.githubusercontent.com/assets/5296671/7376441/67c410ea-eda5-11e4-80fe-4a7aac588304.jpg)

## Tasks

* Try to build the MOSFET/Diode Circuit mentioned on the Sparkfun site http://bildr.org/2012/03/rfp30n06le-arduino/ (I think I have all the components for this.) -- done, with a stepper motor (not my new fan).
* Buy two 6-V lantern batteries in order to test my ability to do this at 6V and 12V (final installation is expected to be 12V.) -- done
* Now try to drive the new fan with the lantern batteries.
* Okay, this is now working.  Basically I use this circuit:

http://bildr.org/blog/wp-content/uploads/2012/03/rfp30n06le-arduino-motor.png

With a 6volt lantern battery.  Unfortunately, the fan I bought does NOT work with 12 V! Curses, I bought the wrong fan!  I tried to hook up two lantern batteries in series, but couldn't run the fan that way.  However, I am confident the MOSFET switching will let us switch a 12 V or higher power supply. [Correction: The fan does work with 12V, I had a bad battery.

Here is a photo of the set up:

![imag0113](https://cloud.githubusercontent.com/assets/5296671/7384273/51a079ca-edf5-11e4-8dd8-c86ff535c83b.jpg)

## Story #2: Hook Same Circuit up to the Gas Sensor

This will wait until tomorrow!

Tasks:
* First make it work with the pressure sensor as before.
* Then try to actually get the Methane sensor to work again.
* If I can get that working (or if I can't!) consider: Getting a 12V fan to prove that we can do that. Also possibly solder the circuit in place for better packaging that what we have now.
* Consider getting some sort of enclosure.

Note: I drained a 9 volt battery overnight using this circuit.  This should not be a problem in our actual installation, but this is still unfortunate.  I think it would be nice to save energy by polling less commonly and turning off the onboad LEDs.  I saw an article on this somewhere, I believe it is a low priority.

Note: Try as I might and try as I may, I cannot get the MQ4 methane sensor to react to natural gas, a butane cigarette lighter, or ethanl fumes.  I don't know if I damaged my unit installing it, but in theory it should be sensitive to all of those gases, though not as sensitive as to pure methane.  I have ordered other sensors which I will also test.

## May 12, 2015

I now have this working with the "flammable gas sensor" but not the Methane sensor.  As far as I can tell, the Methane sensor doesn't work at all.  I have burned it in properly.  I think it may have been damaged in my soldering escapades, or the breakout board doesn't work.  I don't think it is worth continuing to investigate this.  For the Austin Mini Maker Faire, I will use the gas one.  My goal now is to get that pacakgaged up in some way.






