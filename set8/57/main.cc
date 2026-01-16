#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

#include "semaphore/semaphore.h"   // adjust to your header name

using namespace std::chrono_literals;

int main()
{
    std::cout << "\n=== TEST A: wait blocks at 0, notify releases one ===\n";

    {
        Semaphore sem(0);
        std::atomic<bool> passed{false};

        std::thread t([&] {
            std::cout << "[T] Thread started\n";
            std::cout << "[T] Calling wait()\n";
            sem.wait();
            std::cout << "[T] Returned from wait()\n";
            passed = true;
        });

        std::cout << "[M] Sleeping 200 ms (thread should be blocked)\n";
        std::this_thread::sleep_for(200ms);

        std::cout << "[M] passed = " << passed << "\n";
        std::cout << "[M] Calling notify()\n";
        sem.notify();

        std::cout << "[M] Joining thread\n";
        t.join();

        std::cout << "[M] passed after join = " << passed << "\n";
    }

    std::cout << "\n=== TEST B: notify wakes exactly one thread ===\n";

    {
        Semaphore sem(0);
        std::atomic<int> entered{0};

        auto worker = [&](char name) {
            std::cout << "[T" << name << "] Calling wait()\n";
            sem.wait();
            std::cout << "[T" << name << "] Passed wait()\n";
            ++entered;

            std::cout << "[T" << name << "] Working 300 ms\n";
            std::this_thread::sleep_for(300ms);
            std::cout << "[T" << name << "] Finished work\n";
        };

        std::thread a(worker, 'A');
        std::thread b(worker, 'B');

        std::cout << "[M] Sleeping 200 ms (both should be blocked)\n";
        std::this_thread::sleep_for(200ms);
        std::cout << "[M] entered = " << entered << "\n";

        std::cout << "[M] Calling notify() (should wake ONE)\n";
        sem.notify();

        std::this_thread::sleep_for(200ms);
        std::cout << "[M] entered = " << entered << " (expect 1)\n";

        std::cout << "[M] Calling notify() again\n";
        sem.notify();

        a.join();
        b.join();

        std::cout << "[M] entered = " << entered << " (expect 2)\n";
    }

    std::cout << "\n=== TEST C: notify_all wakes all, but only one proceeds ===\n";

    {
        Semaphore sem(0);
        std::atomic<int> passed{0};

        auto worker = [&](int id) {
            std::cout << "[W" << id << "] Calling wait()\n";
            sem.wait();
            std::cout << "[W" << id << "] Passed wait()\n";
            ++passed;
        };

        std::thread t1(worker, 1);
        std::thread t2(worker, 2);
        std::thread t3(worker, 3);

        std::cout << "[M] Sleeping 250 ms (all should be blocked)\n";
        std::this_thread::sleep_for(250ms);
        std::cout << "[M] passed = " << passed << "\n";

        std::cout << "[M] Calling notify_all() (adds ONE permit)\n";
        sem.notify_all();

        std::this_thread::sleep_for(250ms);
        std::cout << "[M] passed = " << passed << " (expect 1)\n";

        std::cout << "[M] Calling notify() twice more\n";
        sem.notify();
        sem.notify();

        t1.join();
        t2.join();
        t3.join();

        std::cout << "[M] passed = " << passed << " (expect 3)\n";
    }

    std::cout << "\n=== TEST D: size() observation ===\n";

    {
        Semaphore sem(2);
        std::cout << "[M] Initial size = " << sem.size() << "\n";

        std::thread t1([&] {
            std::cout << "[S1] wait()\n";
            sem.wait();
            std::cout << "[S1] passed\n";
        });

        std::thread t2([&] {
            std::cout << "[S2] wait()\n";
            sem.wait();
            std::cout << "[S2] passed\n";
        });

        t1.join();
        t2.join();

        std::cout << "[M] size after two waits = "
                  << sem.size() << " (expect 0)\n";
    }

    std::cout << "\n=== ALL TESTS FINISHED ===\n";
}