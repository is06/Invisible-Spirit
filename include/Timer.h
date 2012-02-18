#ifndef __IS06_TIMER_H__
#define __IS06_TIMER_H__

using namespace irr;
using namespace std;

typedef boost::function<void()> VoidCallback;

class Timer
{
  public:
    Timer(f32 end, VoidCallback callback, s32 loopLimit = 1);

    void update();

    inline void start();
    inline void stop();
    inline void reset();

    void reinit(f32 end, VoidCallback callback, s32 loopLimit = 1);

    inline void setTime(f32 val);
    inline f32 getTime();

  private:
    bool running;
    s32 currentLoopLimit;
    s32 currentLoop;
    f32 currentTime;
    f32 endTime;

    VoidCallback endCall;
};

#endif
