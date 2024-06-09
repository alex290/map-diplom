#pragma once

#include <vector>
#include <thread>
#include "safe_queue.h"

class thread_pool
{
public:
    thread_pool();
    ~thread_pool();

    void work();

    void submit(std::function<void(void)>&& f);

private:
    std::vector<std::thread> vecOfThreads;
    int processor_count;
    safe_queue* s_queue;
};