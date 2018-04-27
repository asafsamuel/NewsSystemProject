#ifndef DISPATCHER_H_
#define DISPATCHER_H_

#include "MThread.h"
#include "Producer.h"
#include "Sections.h"
#include <vector>
#include <iostream>
#include "boundedBuffer.h"

using namespace std;

class Dispatcher: public MThread 
{
private:
	vector<Producer*>* producers;
	boundedBuffer* newsQueue;
	boundedBuffer* sportsQueue;
	boundedBuffer* wheatherQueue;
	int removedCounter;
	int producersAmount;
	void pushNews(Info* news);
	
public:
	Dispatcher(vector<Producer*>* producers);
	void run();
	Info* getNewsQueueNews();
	Info* getSportsQueueNews();
	Info* getWheatherQueueNews();
	virtual ~Dispatcher();
};

#endif