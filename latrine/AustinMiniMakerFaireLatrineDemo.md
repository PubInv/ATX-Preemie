Tony Stark, I ain't.

It took a long time to get this done and working and all packaged up, and the result is an anticlimax. I have a cardboard
box with a fan, with a little sensor hanging out of it. If you spray the sensor with gas from a cigarette lighter, 
the fan comes on.  That's it.

![imag0138](https://cloud.githubusercontent.com/assets/5296671/7643871/2aa18218-fa63-11e4-9f3e-c5d4696be52b.jpg)

In the picture, the sensor is the little mesh covered gadget on the left side of the box.

However, this box does demonstrate that we an switch almost any amount of power with an Arduino combined with a tiny MOSFET
circuit. The Fan is driven by a 6V - 12V battery, and draws far more current than the Arduino itself can provide.

This is a physical implementation of the circuit and system described in an excellent [BILDR tutorial](http://bildr.org/2012/03/rfp30n06le-arduino/), with the added complexity of a sensor circuit.

I've described the MOSFET circuit board elsewhere in this repo---here is a picture of it inside a container I bought from The Container Store and drilled out.  The container is really to big, but the MOSFET has a tall heat sink on it.

![imag0140](https://cloud.githubusercontent.com/assets/5296671/7643872/2aa1f87e-fa63-11e4-9f56-54803d608631.jpg)

The fact that we can do this with one sensor means we could easily do this with any other sensor, or combination of sensors.

Moreover, this system is very similar to the Incubator project, which I view as an advantage.




![imag0139](https://cloud.githubusercontent.com/assets/5296671/7643870/2a9f7004-fa63-11e4-83f2-9ecec59a7c63.jpg)

Note a little bit of trickiness here: I've soldered the sensor directly to a resistor connected across ground as required by this kind of sensor.  Rather than creating ANOTHER circuit board, I've jammed the resistor into both the GND and Analog Input 0 pin on the Arduino.





![imag0141](https://cloud.githubusercontent.com/assets/5296671/7643873/2aa2720e-fa63-11e4-8b0e-a919ef6a39fa.jpg)

I feel like this was an enormous amount of work for the coolness acheived, which is minimal. However, I started as a beginner.  The biggest lesson that I am learning is both the difficulty and the importance of physical packaging. As lame as this is, it is FAR better than a bread-board based solution. 

This basic hardware set up could be reused to control any number of gadgets that require far more power than the Arduino itself can provide (which is about 500 millamps for the [Arduino UNO R3](http://www.arduino.cc/en/Main/ArduinoBoardUno), but actually less than that is usable power for powering other devices.)
