#include "SystemBuilder.h"

// C'tor
SystemBuilder::SystemBuilder() 
{
	producers = NULL;
	producersCopy = NULL;
	dispatcher = NULL;
	screenManager = NULL;
	newsEditor = NULL;
	sportsEditor = NULL;
    wheatherEditor = NULL;
}

// Read from config-file and create the system
void SystemBuilder::build(string configurationPath) 
{
	ifstream infile(configurationPath);
	producers = new vector<Producer*>();
	producersCopy = new vector<Producer*>();
	string line;
	int producerNum = 0, newsAmount = 0, ProducerQueueSize = 0;
	int coEditorQueueSize = 0;
	
	while (getline(infile, line)) 
	{
		if (line[0] != 'C' && line[0] != 'c' && line[0] != 'P' && line[0] != 'p')
			break;
		
		if (line[0] != 'C' && line[0] != 'c') 
		{
			line.replace(0, 9, "");
			producerNum = stoi(line);
			getline(infile, line);
			newsAmount = stoi(line);
			getline(infile, line);
			line.replace(0, 13, "");
			ProducerQueueSize = stoi(line);
			getline(infile, line);
			Producer* producer = new Producer(producerNum, newsAmount, ProducerQueueSize);
			producer->start();
			producers->push_back(producer);
			producersCopy->push_back(producer);
		} 
		
		else 
		{
			line.replace(0, 23, "");
			coEditorQueueSize = stoi(line);
			screenManager = new ScreenManager(coEditorQueueSize);
		}
	}
	
	dispatcher = new Dispatcher(producersCopy);
	sportsEditor = new CoEditor(dispatcher, screenManager, SPORTS);
	wheatherEditor = new CoEditor(dispatcher, screenManager, WHEATHER);
	newsEditor = new CoEditor(dispatcher, screenManager, NEWS);
}

// Start the system (run each part of the system)
void SystemBuilder::start() 
{
	wheatherEditor->start();
	newsEditor->start();
	sportsEditor->start();
	screenManager->start();
	dispatcher->start();
	screenManager->waitForThread();
}

// Delete (remove) each part of the system
void SystemBuilder::clean() 
{
	vector<Producer*>::iterator begin = producers->begin();
	vector<Producer*>::iterator end = producers->end();
	
	for (; begin != end; begin++) 
	{
		delete(*begin);
	}
	
	delete(producers);
	delete(producersCopy);
	delete(dispatcher);
	delete(newsEditor);
	delete(sportsEditor);
	delete(wheatherEditor);
	delete(screenManager);
}

// D'tor
SystemBuilder::~SystemBuilder() 
{
}