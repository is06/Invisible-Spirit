#ifndef __IS06_TIMER_H__
#define __IS06_TIMER_H__

using namespace irr;
using namespace std;

namespace is06
{
namespace nEngine
{

class CTimer
{
  public:
    CTimer(f32 end, TVoidCallback callback, s32 loopLimit = 1);

    void update();

    inline void start() { Running = true; }
    inline void stop() { Running = false; }
    inline void reset() { CurrentTime = 0.0f; }

    void reinit(f32 end, TVoidCallback callback, s32 loopLimit = 1);

    inline void setTime(f32 val) { CurrentTime = val; }
    inline f32 getTime() { return CurrentTime; }

  private:
    bool Running;
    s32 CurrentLoopLimit;
    s32 CurrentLoop;
    f32 CurrentTime;
    f32 EndTime;

    TVoidCallback EndCall;
};

}
}

#endif
