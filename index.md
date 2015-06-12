---
layout: default
title: ATX Preemie Warmer Main Page
---

# ATX Preemie Warmer v 0.1 Alpha

<a title="By Polihale (Own work) [CC BY-SA 3.0 (http://creativecommons.org/licenses/by-sa/3.0) or GFDL (http://www.gnu.org/copyleft/fdl.html)], via Wikimedia Commons" href="http://commons.wikimedia.org/wiki/File%3AMom_and_Premature_Baby_at_Kapiolani.jpg"><img width="512" alt="Mom and Premature Baby at Kapiolani" src="//upload.wikimedia.org/wikipedia/commons/2/20/Mom_and_Premature_Baby_at_Kapiolani.jpg"/></a>

## Purpose

Every year across the world, many low-birth weight babies die, in part because they do not have access to advanced medicine.

The ATX Preemie Warmer project is an open-source hardware and software project to try to address this problem. All work here is sharable under the GPL (for source code) or the Creative Commons Share Alike license (for hardware designs).

The ATX Preemie Warmer may be valuable:

* When [Kangaroo Care](https://en.wikipedia.org/wiki/Kangaroo_care) is impossible or as a temporary complement to Kangaroo Care,
* As an open-source example from which other low-cost, low-power medical projects may be developed, and
* As an example of using inexpensive technology to address other real world problems, such as a petrifilm incubator.

## Approach and History

An Arduino-based, heating pad-style solution was originally suggested by Stewart Holloway of the Austin Chapter of Engineers without Borders.

Robert L. Read developed a prototype, and then led a team to improve it a the [ATX Hack for Change](http://publicinvention.blogspot.com/2015/06/report-atx-hack-for-change-2015-preemie.html) Hackathon.

<IMG src="https://cloud.githubusercontent.com/assets/5296671/8139635/c4ecdfe8-111a-11e5-9b13-d6a04c1e1871.jpg" width="500"
     alt="The ATX Preemie Warmer v 0.1 Physical Components">

The photo above depicts all the components of the ATX Preemie Warmer.  The cloth swaddle is easily made from cotton
cloth or even old t-shirts and a shoestring.  The Arduino uses a temperature sensor to control battery power to the a heating cloth.  As little as 6 Volts is sufficient.  We are aiming for the level of battery power that people in the developing world use to charge cell phones.
Two simple pieces of foam core placed beneath the heating cloth in the plaid pocket insulate the back of the system, making it far more power efficient.

We use the doll as a test object, as well as baggies full of water to represent realistic thermal masses.

## Status

Version 0.1 Alpha of the ATX Preemie Warmer:

* Is able to maintain body temperature of realistic masses with 6-12 Volt battery power,
* Currently has a $49 Bill-of-materials that can be decreased with further development,
* Is constructable with basic, commonly available tools and materials, and
* Is potentially applicable to other problems, such as incubating Petrifilm for water quality testing.

Although partically successful in the sense that it is working and inexpensive, many obstacles exist to deploying this in a way that actually saves lives.
We have spoken to three medical professionals with experience in developing nations. They are somewhat skeptical of the usefulness of this device.  Our most pressing need right now is for more discussion with experienced health professionals to learn if, and how, the ATX Preemie Warmer could be a practical benefit. If you have relevant knowledge or experience, please contact us.

We may not actively work on the next version (0.2 Alpha) until we get validation from medical personnel or additional volunteers excited about the project---so if you are interested in this project, please contact us.

## Duplication and Getting Involved

In the [ATX-Preemie repo](https://github.com/PIFAH/ATX-Preemie), you will find a wealth of information about both the hardware, sewing, and software components of the project.  We are currently endeavoring to make it entirely possible to completely reproduce this version of the Warmer. As with all open source projects, please contribute by contacting us, or by making a [pull-request](https://help.github.com/articles/using-pull-requests/).

* Complete [Bill of Materials](https://github.com/PIFAH/ATX-Preemie/blob/master/BillOfMaterials.md).
* Sewing [instructions](https://github.com/PIFAH/ATX-Preemie/blob/master/ATXPreemieWarmerSwaddleInstructions.md) for making the swaddle.
* Arduino [code](https://github.com/PIFAH/ATX-Preemie/blob/master/IncubatorRelayV0.4.ino) for the Incubator.
* Arduino [code](https://github.com/PIFAH/ATX-Preemie/blob/master/Artificial_Infant.ino) for Artificial Test Preemie.
* Python [code](https://github.com/PIFAH/ATX-Preemie/blob/master/arduino_read.py) for recording temperature over time.
* [Notes](https://github.com/PIFAH/ATX-Preemie/blob/master/MOSFET_incubator_circuit.md) on the construction of the MOSFET power control circuit
* [Notes](https://github.com/PIFAH/ATX-Preemie/blob/master/heat_swaddle_experiment_notes.md) on our experiments keeping a heat mass at body temperature with low power.
* [Configuration](https://github.com/PIFAH/ATX-Preemie/blob/master/Incubator_node_red_flow.txt) file for NodeRed, used during our hackathon to record data.
* [Research](https://github.com/PIFAH/ATX-Preemie/blob/master/battery_research.md) into batteries.
* [Ideas](https://github.com/PIFAH/ATX-Preemie/blob/master/ideas.md), especially for the next version.

If you want to potentially save lives, empower people with limited resources, and have fun building Arduino projects, please contact me (Robert L. Read, <read.robert@gmail.com>, @RobertLRead) and lets figure out how you can have fun helping with this project. The [issues](https://github.com/PIFAH/ATX-Preemie/issues) represent a variety of valuble ways to hack this project forward.

## Other Solutions

### Kangaroo Care

[Kangaroo Care](https://en.wikipedia.org/wiki/Kangaroo_care) is an approach that emphasized early and continuous skin-to-skin contact with the parent. We do not wish this project to discourage Kangaroo Care. Hopefully our project provides a helpful alternative when Kangaroo Care is not possible.


### Embrace

The project is begin addressed by [Embrace Global](http://embraceglobal.org). However, that project supports a for-profit company, and it is not an open-source solution. 

### IncuBaby

A team of students at Rice University has designed a low-cost (< $250) box-style [incubator](http://oedk.rice.edu/Sys/PublicProfile/25543138/3637470) that can be inexpensively shipped.  This approach is more expensive but perhaps complementary to the ATX Preemie Warmer. It is unclear if their design is open source, and if it uses grid-based power or battery power. I would like a member of this team to contact me.

### Image Attributions

"Mom and Premature Baby at Kapiolani" --
By Polihale (Own work) [CC BY-SA 3.0 (http://creativecommons.org/licenses/by-sa/3.0) or GFDL (http://www.gnu.org/copyleft/fdl.html)], via Wikimedia Commons

<ul>
  {% for post in site.posts %}
    <li>
      <a href="{{ post.url }}">{{ post.title }}</a>
    </li>
  {% endfor %}
</ul>

