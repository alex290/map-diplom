#include "thread_pool.h"

std::queue<std::function<void(void)>> wor_queue;
void func1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "Working " << __FUNCTION__ << "...\n";
}

void func2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "Working " << __FUNCTION__ << "...\n";
}

void addF1()
{
    for (size_t i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        wor_queue.push(func1);
    }
}

void addF2()
{
    for (size_t i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        wor_queue.push(func2);
    }
}



int main(int, char**)
{
    thread_pool<std::function<void(void)>> tr_p;
    // tr_p.submit(std::thread(func1)); // Не работает
    tr_p.submit(func2);

    // tr_p.work(); // С ним возникает ошибка сборки.

    // Заполняем очередь задачами
    // tr_p.new_tread(std::move(addF1));
    // tr_p.new_tread(std::move(addF2));
    
    // std::thread th2(addF2, tr_p);
}
