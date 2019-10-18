#pragma once
/*
#include<thread>
#include<vector>
#include<functional>
#include<mutex>
#include<iostream>
using namespace std;
class ThreadPool
{
public:

	using Task = function<void()>;

	ThreadPool(int number, bool isRun = true) :
		m_number(number),
		m_isRunning(isRun)
	{

	}
	~ThreadPool()
	{
		m_isRunning = false;
	}
	void Start()
	{
		for (int i = 0; i < m_number; i++)
		{

			try
			{
				
				m_threads.emplace_back(thread(&ThreadPool::Work, this));

			}
			catch (const std::exception&)
			{

			}

		}
	}

	void Stop()
	{
		{
			unique_lock<mutex> lk(m_lock);
			m_isRunning = false;
			m_condition.notify_all();
		}
		for (auto& thread : m_threads)
		{
			if (thread.joinable())
				thread.join();
		}
	}
	void Work()
	{

		while (m_isRunning)
		{
			Task task;
			{

				unique_lock<mutex> lock(m_lock);
				if (!m_tasks.empty())
				{
					task = m_tasks.front();
					
					m_tasks.pop_back();
				}
				else
				{
					m_condition.wait(lock);
				}

				
			}
			if (task)
			{
				task();

			}
		}


	}

	void AppendTask(const Task& task)
	{
		if (m_isRunning && m_tasks.size() < m_number)
		{
			unique_lock<mutex> lk(m_lock);

			m_tasks.push_back(task);
			//notify one thread;
			m_condition.notify_one();

		}
		else
			task();
	}
	
	condition_variable m_condition;
	bool m_isRunning;
	mutex m_lock;
	vector<Task> m_tasks;
	int m_number;
	vector<thread> m_threads;
};


*/
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
public:
	ThreadPool(size_t);
	template<class F, class... Args>
	auto enqueue(F&& f, Args&& ... args)
		->std::future<typename std::result_of<F(Args...)>::type>;
	~ThreadPool();
private:
	// need to keep track of threads so we can join them
	std::vector< std::thread > workers;
	// the task queue
	std::queue< std::function<void()> > tasks;

	// synchronization
	std::mutex queue_mutex;
	std::condition_variable condition;
	bool stop;
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
	: stop(false)
{
	for (size_t i = 0; i < threads; ++i)
		workers.emplace_back(
			[this]
	{
		for (;;)
		{
			std::function<void()> task;

			{
				std::unique_lock<std::mutex> lock(this->queue_mutex);
				this->condition.wait(lock,
					[this] { return this->stop || !this->tasks.empty(); });
				if (this->stop && this->tasks.empty())
					return;
				task = std::move(this->tasks.front());
				this->tasks.pop();
			}

			task();
		}
	}
	);
}

// add new work item to the pool
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&& ... args)
-> std::future<typename std::result_of<F(Args...)>::type>
{
	using return_type = typename std::result_of<F(Args...)>::type;

	auto task = std::make_shared< std::packaged_task<return_type()> >(
		std::bind(std::forward<F>(f), std::forward<Args>(args)...)
		);

	std::future<return_type> res = task->get_future();
	{
		std::unique_lock<std::mutex> lock(queue_mutex);

		// don't allow enqueueing after stopping the pool
		if (stop)
			throw std::runtime_error("enqueue on stopped ThreadPool");

		tasks.emplace([task]() { (*task)(); });
	}
	condition.notify_one();
	return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
	{
		std::unique_lock<std::mutex> lock(queue_mutex);
		stop = true;
	}
	condition.notify_all();
	for (std::thread& worker : workers)
		worker.join();
}
