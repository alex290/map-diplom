#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <atomic>

template <typename T>

class safe_queue
{
public:
    // safe_queue();
    // ~safe_queue();

    std::mutex m;

    void push(T&& f)
    {
        std::lock_guard<std::mutex> lk(m);
        wor_queue.push(std::move(f));
        data_cond.notify_one();
    }
    void pop()
    {
        std::lock_guard<std::mutex> lk(m);

        data_cond.wait(lk, [this] {
            auto task = wor_queue.front();
            wor_queue.pop();
            return task();
        });
    };

private:
    std::queue<T> wor_queue;
    std::condition_variable data_cond;
};