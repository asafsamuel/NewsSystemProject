#ifndef BOUNDEDBUFFER_H_
#define BOUNDEDBUFFER_H_

#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <cassert>
#include "Info.h"

using namespace std;

class boundedBuffer
{
private:
	queue<Info*> newsQueue;
	mutex key;
	condition_variable not_empty_condition;
	condition_variable not_full_condition;
	unsigned int capacity;
	
public:
	boundedBuffer(unsigned int capacity);
	boundedBuffer();

	void insert(Info* news);
	Info* remove();
	int size();
	virtual ~boundedBuffer();
};

#endif	