#include <EventLoop.h>
#include <cstddef>
#include <functional>
#include <gtest/gtest.h>
#include <something.h>

namespace TestSpace {
class Spy {
 public:
   Spy(){};
   ~Spy(){};
   void testFunc()
   {
      counter++;
      return;
   }
   uint8_t counter = 0;
};
} // namespace TestSpace

class TestEventLoop : public ::testing::Test {
 public:
   ~TestEventLoop() {}
   EventLoop theLoop;
};

TEST_F(TestEventLoop, queueIsNotPending) { ASSERT_EQ(theLoop.queue_pending(), false); }

void callLambda(void *funcPtr)
{
   auto lambda = reinterpret_cast<std::function<void()> *>(funcPtr);
   (*lambda)();
}

TEST_F(TestEventLoop, itAddsAndConumesTheQueue)
{
   TestSpace::Spy mySpy;
   // EventLoop::Event *anEvent = new EventLoop::Event{1, reinterpret_cast<void*>(&mySpy.testFunc)};
   // auto testFuncWrapper = [&mySpy](){ mySpy.testFunc(); };
   // EventLoop::Event *anEvent = new EventLoop::Event{1, reinterpret_cast<void *>(&testFunc)};
   theLoop.add_event(&mySpy, &TestSpace::Spy::testFunc);
   ASSERT_EQ(theLoop.queue_pending(), true);
   theLoop.handle_event();
   ASSERT_EQ(theLoop.queue_pending(), false);
}
