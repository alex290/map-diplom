#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <mutex>
#include <atomic>

class safe_queue
{
public:
    safe_queue();
    ~safe_queue();

    std::atomic<bool> falg_done{ false };
    std::mutex m;

    void push(std::function<void(void)>&& f);

private:
    std::queue<std::function<void(void)>> wor_queue;
};