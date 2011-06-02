#ifndef __IS06_COLOR_PROPERTY_H__
#define __IS06_COLOR_PROPERTY_H__

using namespace irr;

class ColorProperty {
  public:
    ColorProperty(const video::SColor& initialColor = video::SColor(0, 0, 0, 0));
    ~ColorProperty();

    void events();

  private:
    core::stringw convertIntToString(u32 value);

    gui::IGUIWindow* mainWindow;

    gui::IGUIStaticText* compRText;
    gui::IGUIStaticText* compGText;
    gui::IGUIStaticText* compBText;
    gui::IGUIStaticText* compAText;

    gui::IGUIScrollBar* compRBar;
    gui::IGUIScrollBar* compGBar;
    gui::IGUIScrollBar* compBBar;
    gui::IGUIScrollBar* compABar;

    gui::IGUIEditBox* compREdit;
    gui::IGUIEditBox* compGEdit;
    gui::IGUIEditBox* compBEdit;
    gui::IGUIEditBox* compAEdit;

    gui::IGUIButton* cancelButton;
    gui::IGUIButton* okButton;
};

#endif
