#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include "IEventLoop.h"
// #include <StandardCplusplus.h>
#include <queue>
#include <stdlib.h>
#include <vector>
// #include <new>
#include <func_exception>
#include <string>

inline void operator delete(void *p) { free(p); }

#if AVR
inline void *operator new(unsigned int numBytes) throw() { return malloc(numBytes); }
#endif

class EventLoop : public IEventLoop {
 public:
   EventLoop();
   ~EventLoop();
   void handle_event() override;
   bool add_event(IEventLoop::Event *event) override;
   bool queue_pending() override;

 private:
   std::queue<Event *> event_queue;
};
#endif
