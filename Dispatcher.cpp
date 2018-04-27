#include "Dispatcher.h"

// C'tor
Dispatcher::Dispatcher(vector<Producer*>* producers)
{
	this->producers = producers;
	newsQueue = new ThreadSafeQueue();
	sportsQueue = new ThreadSafeQueue();
	wheatherQueue = new ThreadSafeQueue();
	this->removedCounter = 0;
	this->producersAmount = producers->size();
}

// Start Dispatcher work
void Dispatcher::run()
{
	while (true) 
	{
		bool prdoucersAreDone = true;
		vector<vector<Producer*>::iterator> toErase;
		vector<Producer*>::iterator begin = producers->begin();
		vector<Producer*>::iterator end = producers->end();
		
		for (; begin != end; begin++) 
		{
			prdoucersAreDone = false;
			Info* news = (*begin)->produce();
			
			if (news->getCategory() == DONE) 
			{
				removedCounter++;
				toErase.push_back(begin);
				
				if (removedCounter == producersAmount) 
				{
					prdoucersAreDone = true;
					break;
				}
				continue;
			}
			
			if (news != NULL)
				pushNews(news);

		}
		
		if (prdoucersAreDone)
			break;

		vector<vector<Producer*>::iterator>::iterator beginn = toErase.begin();
		vector<vector<Producer*>::iterator>::iterator endd = toErase.end();
		for (; beginn != endd; beginn++) 
		{
			if (producers->size() > 1)
				producers->erase(*beginn);
		}
	}
	
	// Push Done messages to queues
	Info *news1 = new Info(-1, DONE, -1);
	Info *news2 = new Info(-1, DONE, -1);
	Info *news3 = new Info(-1, DONE, -1);
	newsQueue->insert(news1);
	sportsQueue->insert(news2);
	wheatherQueue->insert(news3);
}

// sort news and push them in the corrent queue
void Dispatcher::pushNews(Info* news) 
{
	switch (news->getCategory()) 
	{
	case NEWS:
		newsQueue->insert(news);
		break;
	case SPORTS:
		sportsQueue->insert(news);
		break;
	case WHEATHER:
		wheatherQueue->insert(news);
		break;
	default:
		cout << "error in Dispatcher::pushNews" << endl;
		break;
	}
}

// Get functions
Info* Dispatcher::getNewsQueueNews() 
{
	return this->newsQueue->remove();
}
Info* Dispatcher::getSportsQueueNews() 
{
	return this->sportsQueue->remove();
}
Info* Dispatcher::getWheatherQueueNews() 
{
	return this->wheatherQueue->remove();
}

// D'tor
Dispatcher::~Dispatcher() 
{
}