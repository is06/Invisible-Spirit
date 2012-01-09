/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_FONT_STYLE_H__
#define __IS06_FONT_STYLE_H__

/**
 *
 */
enum FontStyle {
  // Classic style
  FONT_STD_CLASSIC_REGULAR,
  FONT_COND_CLASSIC_REGULAR,
  FONT_EXT_CLASSIC_REGULAR,
  FONT_STD_CLASSIC_BOLD,
  FONT_COND_CLASSIC_BOLD,
  FONT_EXT_CLASSIC_BOLD,

  // Shaded
  FONT_STD_SHADED_REGULAR,
  FONT_COND_SHADED_REGULAR,
  FONT_EXT_SHADED_REGULAR,
  FONT_STD_SHADED_BOLD,
  FONT_COND_SHADED_BOLD,
  FONT_EXT_SHADED_BOLD,

  // Border + Shaded
  FONT_STD_BORDER_SHADED_REGULAR,
  FONT_COND_BORDER_SHADED_REGULAR,
  FONT_EXT_BORDER_SHADED_REGULAR,
  FONT_STD_BORDER_SHADED_BOLD,
  FONT_COND_BORDER_SHADED_BOLD,
  FONT_EXT_BORDER_SHADED_BOLD,

  // Titles
  FONT_LOCATION_TITLE_REGULAR,
  FONT_DIALOG_NAME_TITLE_REGULAR,

  FONT_COUNT
};

#endif
