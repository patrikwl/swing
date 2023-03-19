#ifndef IEVENTLOOP_H
#define IEVENTLOOP_H

// #include<new>

class IEventLoop {
 public:
   struct Event {
      int type;
      void *data;
      Event(int t, void *d) : type(t), data(d) {}
      ~Event() {}
   };
   virtual ~IEventLoop(){};
   virtual void handle_event() = 0;
   virtual bool add_event(Event *event) = 0;
   virtual bool queue_pending() = 0;
};
#endif
