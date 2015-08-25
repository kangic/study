#include <chrono>
#include <cstdio>
#include <condition_variable>
#include <thread>
#include <random>
#include <unistd.h>

std::mutex m;
std::condition_variable cv;

void work(int id) {
  while (1) {
    {
      std::unique_lock<std::mutex> lk(m);
      cv.wait(lk);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    int dice_roll = dis(gen);
    printf("wakeup : thread %d - work for %d seconds\n", id, dice_roll);

    sleep(dice_roll);
  }
}

int main() {
  std::thread ths[10];

  for (int i=0; i<10; ++i)
    ths[i] = std::thread(work, i);

  while (1) {
    {
      std::unique_lock<std::mutex> lk(m);
    }
    cv.notify_one();

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }

  for (auto& th : ths)
    th.join();

  return 0;
}
