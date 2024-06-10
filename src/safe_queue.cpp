#include "safe_queue.h"

safe_queue::safe_queue()
{
}

safe_queue::~safe_queue()
{
}

void safe_queue::push(std::function<void(void)>&& f)
{
    m.lock();
    wor_queue.push(f);
    m.unlock();
}

void safe_queue::pop()
{
    m.lock();
    while (!wor_queue.empty())
    {
        auto task = wor_queue.front();
        task();
        wor_queue.pop();
    }
    m.unlock();
}
