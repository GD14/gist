#ifndef RONG_COUNTDOWNLATCH_H
#define RONG_COUNTDOWNLATCH_H

#include <condition_variable>
#include <mutex>

namespace rong {
//计数类,线程同步
class CountDownLatch {
public:
    CountDownLatch(int n)
        : count_(n)
    {
    }
    ~CountDownLatch()
    {
    }

    // blocking call
    void wait()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] { return this->count_ == 0; });
    }

    // count-=1
    void countDown()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        count_--;
        condition_.notify_all();
    }

    int getCount() const
    {
        std::unique_lock<std::mutex> lock(mutex_);
        return count_;
    }

private:
    int count_;
    mutable std::mutex mutex_;
    std::condition_variable condition_;
};
} // namespace rong

#endif