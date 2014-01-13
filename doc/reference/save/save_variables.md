Save variables
==============

This file enumerates all save file variables associating integers identifiers with a human-readable description

Legend
------

* [i] Integer
* [s] String
* [b] Boolean

Primitive info
--------------

* 1 [s]: Slot name (not used for the moment)
* 2 [i]: Difficulty Level (1, 2, 3)

Map info
--------

* 11 [i]: Current Map Id 
* 12 [s]: Current Map Name 

Time info
---------

* 21 [i]: Total game time (in seconds)
* 22 [i]: World time (from 0 to 1439, 720 = 12pm)

Player info
-----------

* 101 [i]: Current HP (from 0 to 9999)
* 102 [i]: Current max HP (from 0 to 9999)
* 103 [i]: Current spirit power value (from 0 to 1000)
* 104 [i]: Experience points
* 105 [i]: Current level (from 0 to 999)

Trophy info
-----------

* 201 [b]: Test trophy
* 299 [b]: Final trophy