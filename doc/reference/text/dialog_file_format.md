Dialog file format
==================

File name extension: isd (for "Invisible Spirit Dialog")

Description
-----------

This file puts one or more texts into dialogs. The dialog file uses text identifiers defined in text files (see [Text file format](/doc/reference/text/text_file_format.md)).
Like texts, dialogs can be defined in a global.isd file or by map using the name of the map (example: MAP_ALPHA_ZONE.isd)

File format
-----------

Dialogs are like texts, they have identifiers but not values. Dialogs bind texts within a list:

identifier1=text1;text2;text3;...
identifier2=text4;text5;text6;...

Example:

norya_first_start=norya_time_and_space;norya_wonder;norya_pride;norya_pride2;norya_price;