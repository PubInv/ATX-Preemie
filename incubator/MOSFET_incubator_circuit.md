Here is my initial circuit design:

![imag0121](https://cloud.githubusercontent.com/assets/5296671/7460466/dabb2da0-f268-11e4-8c81-094e832be392.jpg)

In this case an interesting question is to use 12 V vs. 6V power. 

The heating blanket has 8.7 Ohms of resistance.  At 6V, this povides (6^2)/8.7 = 4.13 W of heating power. At 12 V: (12^12)/8.7 ~= 16 Watts.

We (as a team) haven't done enough research into what is appropriate, but the MOSFET I am using, the Fairchild 
FQP30N06NL, goes up to 32A and 60 V:
https://www.fairchildsemi.com/products/discretes/fets/mosfets/FQP30N06L.html

Our problem here is just to make sure that we keep the power circuit different from the Arduino circuit.

Battery power is summarized here:

http://www.allaboutbatteries.com/Energy-tables.html

I have a 6V Zinc-Chorlide lantern battery.  A D-Cell has 5 watt hours.  I'll assume this battery has 20 Watt hours of
power --- it is not goin to last long at full power!  And this will certainly be a problem in the intended use case
of an underdeveloped country.  But nonetheless I will push forward with my breadboarding.

Note: The thing really noticably puts out at 10V.  On a weak 5.5 V it barely makes a noticable heat.

Here is the breadboard for this circuit:

![imag0122](https://cloud.githubusercontent.com/assets/5296671/7463435/017b8ea6-f27f-11e4-9f11-51d559c9581b.jpg)

# MAJOR FLAW

So a major flaw with this design for its inteded purpose is that if the Arduino is off full power flows to the heating element.  This could cook the baby!  We obviously have to redesign that.  I don't know if that means we use a P-Channel MOSFET, or pull-down reistor on the gate in some way.


