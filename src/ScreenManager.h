#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include <unistd.h>
#include "boundedBuffer.h"
#include "MThread.h"

class ScreenManager: public MThread 
{
private:
	boundedBuffer* readyToBroadcastQueue;
	int finished;
	int counter;
	void handleNews(Info* news);
	
public:
	ScreenManager(int queueSize);
	void run();
	void insertNewsForBroadCast(Info* news);
	virtual ~ScreenManager();
};

#endif