#ifndef __IS06_BAR_COUNTER_H__
#define __IS06_BAR_COUNTER_H__

class BarCounter : public Counter {
  public:
    BarCounter(s32 init = 0, s32 min = 0, s32 max = 1000, f32 x = 0, f32 y = 0, f32 w = 150, f32 h = 10, BarStyle style = BAR_STYLE_DEFAULT);
    virtual ~BarCounter();

    virtual void render();

  protected:
    Picture* bar;
    Picture* sub;

    s32 oldValue;
    f32 subValue;
    f32 initWidth;
    f32 initX;
    f32 decreaseFactor;
    f32 decreaseTimer;

    bool animate;
    bool decrease;
};

#endif
