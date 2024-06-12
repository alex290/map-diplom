#include "thread_pool.h"

thread_pool::thread_pool()
{
    // s_queue = new safe_queue;
    processor_count = std::thread::hardware_concurrency();
}

thread_pool::~thread_pool()
{
    // delete s_queue;
}

void thread_pool::work()
{
    // s_queue->m.lock();
    std::cout << "Start working thread id " << std::this_thread::get_id() << std::endl;
    // s_queue->m.unlock();

    // while (!s_queue->falg_done)
    // {
    //     if (!wor_queue.empty())
    //     {
    //         auto task = wor_queue.front();
    //         task();
    //         wor_queue.pop();
    //     }
    // }
    // while (!wor_queue.empty())
    // {
    //     auto task = wor_queue.front();
    //     task();
    //     wor_queue.pop();
    // }
}

void thread_pool::new_tread(std::function<void(void)>&& f)
{
    vecOfThreads.push_back(std::thread(f));
}

void thread_pool::submit(std::function<void(void)>&& f)
{
    // метод push — записывает в начало очереди новую задачу. При этом захватывает мьютекс, а после окончания операции нотифицируется условная переменная;
    // s_queue->push(std::move(f));
}
