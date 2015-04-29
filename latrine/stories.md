# Story #1: Build a motor control that can handle the larger fan that I bought.

This fan is from Thermaltake cand cost about $20 from Radio Shack:
![imag0112](https://cloud.githubusercontent.com/assets/5296671/7376441/67c410ea-eda5-11e4-80fe-4a7aac588304.jpg)

## Tasks

* Try to build the MOSFET/Diode Circuit mentioned on the Sparkfun site http://bildr.org/2012/03/rfp30n06le-arduino/ (I think I have all the components for this.) -- done, with a stepper motor (not my new fan).
* Buy two 6-V lantern batteries in order to test my ability to do this at 6V and 12V (final installation is expected to be 12V.) -- done
* Now try to drive the new fan with the lantern batteries.
* Okay, this is now working.  Basically I use this circuit:

http://bildr.org/blog/wp-content/uploads/2012/03/rfp30n06le-arduino-motor.png

With a 6volt lantern battery.  Unfortunately, the fan I bought does NOT work with 12 V! Curses, I bought the wrong fan!  I tried to hook up two lantern batteries in series, but couldn't run the fan that way.  However, I am confident the MOSFET switching will let us switch a 12 V or higher power supply.



