#include "thread_pool.h"

void func1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "Working " << __FUNCTION__ << "...\n";
}

// void func2()
// {
//     std::this_thread::sleep_for(std::chrono::milliseconds(200));
//     std::cout << "Working " << __FUNCTION__ << "...\n";
// }

void addF1(thread_pool* tr_p, std::function<void(void)> f)
{
    for (size_t i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        tr_p->submit(std::move(f));
    }
}

// void addF2(thread_pool & tr_p, std::function<void(void)>& f)
// {
//     for (size_t i = 0; i < 5; i++)
//     {
//         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//         std::lock_guard l(safe_queue::m);
//         wor_queue.push(func2);
//     }
//     falg_done = true;
// }

int main(int, char**)
{
    thread_pool* tr_p = new thread_pool;
    // Заполняем очередь задачами
    std::thread th1(addF1, tr_p, func1);
    // std::thread th2(addF2, tr_p);

    delete tr_p;
}
