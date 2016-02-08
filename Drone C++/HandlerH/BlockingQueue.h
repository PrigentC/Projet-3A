#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace handler {
	template <typename T>
	class BlockingQueue
	{
	public:
		T pop();
		void pop(T& item);
		void push(const T& item);

		BlockingQueue() = default;
		BlockingQueue(const BlockingQueue&) = delete;            // disable copying
		BlockingQueue& operator=(const BlockingQueue&) = delete; // disable assignment

	private:
		std::queue<T> queue_;
		std::mutex mutex_;
		std::condition_variable cond_;
	};

	template <typename T>
	T BlockingQueue<T>::pop()
	{
		std::unique_lock<std::mutex> mlock(mutex_);
		while (queue_.empty())
		{
			cond_.wait(mlock);
		}
		auto val = queue_.front();
		queue_.pop();
		return val;
	}

	template <typename T>
	void BlockingQueue<T>::pop(T& item)
	{
		std::unique_lock<std::mutex> mlock(mutex_);
		while (queue_.empty())
		{
			cond_.wait(mlock);
		}
		item = queue_.front();
		queue_.pop();
	}

	template <typename T>
	void BlockingQueue<T>::push(const T& item)
	{
		std::unique_lock<std::mutex> mlock(mutex_);
		queue_.push(item);
		mlock.unlock();
		cond_.notify_one();
	}
}
#endif
