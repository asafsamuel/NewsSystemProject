#include "boundedBuffer.h"

// C'tors
boundedBuffer::boundedBuffer(unsigned int capacity) 
{
	this->capacity = capacity;
}
boundedBuffer::boundedBuffer() 
{
	this->capacity = 100;
}

// return buffer's size
int boundedBuffer::size() 
{
	return newsQueue.size();
}

// Insert new Info to queue
void boundedBuffer::insert(Info* news) 
{
	unique_lock<mutex> lock(key); // lock mutex
	
	while (newsQueue.size() >= capacity) // queue is full
		not_full_condition.wait(lock); // wait for notification

	newsQueue.push(news); // insert news to buffer
	not_empty_condition.notify_one(); // notify waiting threads for insertion queues
	lock.unlock(); // unlock mutex
}

// Remove Info from the queue
Info* boundedBuffer::remove() 
{
	unique_lock<mutex> lock(key); // lock mutex
	while (newsQueue.empty()) // queue is empty
		not_empty_condition.wait(lock); // wait for notification

	Info* news = newsQueue.front();
	newsQueue.pop(); // remove first item from queue
	not_full_condition.notify_one(); // notify waiting threads for item removal
	lock.unlock(); // unlock mutex
	return news;
}

// D'tor
ThreadSafeQueue::~ThreadSafeQueue() 
{
}
