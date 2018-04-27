#include "Producer.h"

// C'tor
Producer::Producer(int ID, int newsAmount, int queueSize) 
{
	this->ID = ID;
	this->newsAmount = newsAmount;
	this->queueSize = queueSize;
	this->queue = new ThreadSafeQueue(queueSize);
	
	newsCounter = 0;
	sportCounter = 0;
	wheatherCounter = 0;
	
	srand(time(NULL));
}

// Start Producer work
void Producer::run() 
{
	Info* news;

	for (int i = 0; i < newsAmount; i++) 
	{
		news = generateNews();
		queue->insert(news);
	}
	
	news = new Info(-1, DONE, -1);	// send Done message to queue
	queue->insert(news);
}

// Generate new Info
Info* Producer::generateNews() 
{
	Info* news = NULL;
	
	int random = rand() % 3;
	if (random < 0)
		random *= -1;
	random++;

	switch (random) 
	{
	case NEWS:
		newsCounter++;
		news = new Info(this->ID, NEWS, newsCounter);
		break;
	case SPORTS:
		sportCounter++;
		news = new Info(this->ID, SPORTS, sportCounter);
		break;
	case WHEATHER:
		wheatherCounter++;
		news = new Info(this->ID, WHEATHER, wheatherCounter);
		break;
	default:
		break;
	}
	return news;
}

// remove Info from queue and returns it
Info* Producer::produce() 
{
	return queue->remove();
}

// D'tor
Producer::~Producer() 
{
}
