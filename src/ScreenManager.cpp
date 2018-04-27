#include "ScreenManager.h"

// C'tor
ScreenManager::ScreenManager(int queueSize) 
{
	readyToBroadcastQueue = new boundedBuffer(queueSize);
	finished = 0;
	this->counter = 0;
}

// Inset new Info to queue
void ScreenManager::insertNewsForBroadCast(Info* news) 
{
	readyToBroadcastQueue->insert(news);
}

// Start ScreenManager work
void ScreenManager::run() 
{
	while (true) 
	{
		Info* news = readyToBroadcastQueue->remove();
		if (news->getCategory() == DONE) 
		{
			finished++;
			if (finished == 3)
				break;
			else
				continue;
		}
		handleNews(news);
	}
}

// Print Info details
void ScreenManager::handleNews(Info* news) 
{
	if (news != NULL) 
	{
		counter++;
		cout << counter << ")  ";
		news->print();

	} 
	
	else
		cout << "NULL NEWS - ScreenManager::handleNews" << endl;
}

// D'tor
ScreenManager::~ScreenManager() 
{
}