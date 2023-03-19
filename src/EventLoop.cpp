#include "EventLoop.h"

EventLoop::EventLoop() {}
EventLoop::~EventLoop() {}

void EventLoop::handle_event()
{
   IEventLoop::Event *event = event_queue.front();
   event_queue.pop();

   switch (event->type) {
      case 1:
         void (*function_ptr)() = reinterpret_cast<void (*)()>(event->data);
         function_ptr();
         break;
   }
   delete event;
}

bool EventLoop::add_event(IEventLoop::Event *event)
{
   if (event_queue.size() < 50) {
      event_queue.push(event);
      return true;
   }
   else {
      return false;
   }
}

bool EventLoop::queue_pending() { return event_queue.size() > 0; }
