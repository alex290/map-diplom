#include "thread_pool.h"

void func1()
{
    std::cout << "Working " << __FUNCTION__ << "…\n";
}

// void func2()
// {
//     std::cout << "Working " << __FUNCTION__ << "…\n";
// }

void addF1(thread_pool<std::function<void(void)>>* tr_p, std::function<void(void)> &f)
{
    for (size_t i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        tr_p->submit(std::move(f));
    }
}

// void addF2(thread_pool<std::function<void(void)>>* tr_p)
// {
//     for (size_t i = 0; i < 5; i++)
//     {
//         std::this_thread::sleep_for(std::chrono::milliseconds(500));
//         tr_p.submit(func2);
//     }
// }

void work()
{
    // tr_p.work();
}

int main(int, char**)
{
    thread_pool<std::function<void(void)>>* tr_p = new thread_pool<std::function<void(void)>>;
    std::thread t1(addF1, tr_p, func1);
    // std::thread t2(addF2, tr_p);
    // // std::thread t3(work);
    t1.join();
    // t2.join();
    // t3.join();
    delete tr_p;
}