#include "safe_queue.h"

safe_queue::safe_queue()
{
}

safe_queue::~safe_queue()
{
}

void safe_queue::push(std::function<void(void)>&& f)
{
    wor_queue.push(f);
}
