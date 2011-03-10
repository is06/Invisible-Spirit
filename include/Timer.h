#ifndef __IS06_TIMER_H__
#define __IS06_TIMER_H__

using namespace irr;
using namespace std;

template <class T> class Timer {
  public:
    Timer(f32 end = 1.0f, T object = NULL, TimerCallback function = TIMER_CALLBACK_DEFAULT, u32 loopLimit = 1) {
      callbackObject = object;
      callbackFunction = function;
      running = true;
      reinit(end, object, function, loopLimit);
    }

    ~Timer() {
      callbackObject = NULL;
    }

    void update() {
      if(running && currentLoop < currentLoopLimit) {
        currentTime += (1.0f / Game::getFramerate());
        if(currentTime >= endTime) {
          bool called = true;
          switch(callbackFunction) {
            case TIMER_CALLBACK_HELLO: callbackObject->hello(); break;
            case TIMER_CALLBACK_NEXT_CHAR: callbackObject->nextChar(); break;
            default: called = false; break;
          }
          if(called) {
            if(currentLoopLimit > 0) {
              currentLoop++;
              currentTime = 0.0f;
            } else {
              stop();
            }
          }
        }
      }
    }

    inline void start() {
      running = true;
    }

    inline void stop() {
      running = false;
    }

    inline void reset() {
      currentTime = 0.0f;
    }

    void reinit(f32 end = 1.0f, T object = NULL, TimerCallback function = TIMER_CALLBACK_DEFAULT, u32 loopLimit = 1) {
      callbackObject = object;
      callbackFunction = function;
      currentTime = 0.0f;
      endTime = end;
      currentLoop = 0;
      currentLoopLimit = loopLimit;
      start();
    }

    inline void setTime(f32 val) {
      currentTime = val;
    }

    inline f32 getTime() {
      return currentTime;
    }

  private:
    bool running;
    u32 currentLoopLimit;
    u32 currentLoop;
    f32 currentTime;
    f32 endTime;

    T callbackObject;
    TimerCallback callbackFunction;
};

typedef Timer<Scene*> TimerOnScene;
typedef Timer<Text*> TimerOnText;

#endif
