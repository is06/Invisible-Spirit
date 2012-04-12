#ifndef __IS06_TIMER_H__
#define __IS06_TIMER_H__

using namespace irr;
using namespace std;

namespace is06
{
namespace engine
{

typedef boost::function<void()> TVoidCallback;

class CTimer
{
  public:
    CTimer(f32 end, TVoidCallback callback, s32 loopLimit = 1);

    void update();

    inline void start();
    inline void stop();
    inline void reset();

    void reinit(f32 end, TVoidCallback callback, s32 loopLimit = 1);

    inline void setTime(f32 val);
    inline f32 getTime();

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
