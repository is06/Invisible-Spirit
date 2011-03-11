#ifndef __IS06_TIMER_H__
#define __IS06_TIMER_H__

using namespace irr;
using namespace std;

class Timer {
  public:
    Timer(f32 end, boost::function<void()> callback, u32 loopLimit = 1);
    ~Timer();

    void update();

    inline void start();
    inline void stop();
    inline void reset();

    void reinit(f32 end, boost::function<void()> callback, u32 loopLimit = 1);

    inline void setTime(f32 val);
    inline f32 getTime();

  private:
    bool running;
    u32 currentLoopLimit;
    u32 currentLoop;
    f32 currentTime;
    f32 endTime;

    boost::function<void()> endCall;
};

#endif
