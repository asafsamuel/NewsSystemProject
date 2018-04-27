#include "MThread.h"
#include <stdio.h>

// C'tor
MThread::MThread() 
{
	this->threadId = 0;
}

// Thread start the arg function
void* worker(void* arg) 
{
	MThread* threadObj = (MThread*) arg;
	threadObj->run();
	threadObj->threadId = 0;
	return NULL;
}

// Start thread work
void MThread::start() 
{
	pthread_create(&threadId, NULL, worker, (void*) this);
}

// For for thread to end
void MThread::waitForThread() 
{
	pthread_join(threadId, NULL);
}

// D'tor
MThread::~MThread() 
{
	if (threadId > 0)
		pthread_cancel(threadId); //kill the thread if exists
}
