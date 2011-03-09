#ifndef __IS06_TIMER_H__
#define __IS06_TIMER_H__

using namespace irr;
using namespace std;

typedef void (*Callback)(void);

class Timer {
  public:
    Timer(f32 end, Callback function);
    ~Timer();

    void update();

    void start();
    void stop();
    void reset();
    void reinit(f32 end, Callback function);

    void setTime(f32 val);
    f32 getTime();

  private:
    bool running;
    f32 currentTime;
    f32 endTime;
    Callback endCallback;
};

#endif
