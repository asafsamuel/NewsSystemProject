#ifndef PRODUCER_H_
#define PRODUCER_H_

#include <thread>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include "Info.h"
#include "MThread.h"
#include "Sections.h"
#include "boundedBuffer.h"

using namespace std;

class Producer : public MThread
{
private:
	boundedBuffer* queue;
	int queueSize;
	int newsAmount;
	int ID;
	int newsCounter;
	int sportCounter;
	int wheatherCounter;

public:
	Producer(int ID, int newsAmount, int queueSize);
	Info* generateNews();
	void run();
	Info* produce();
	virtual ~Producer();
};

#endif