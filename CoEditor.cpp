#include "CoEditor.h"

// C'tor
CoEditor::CoEditor(Dispatcher* dispatcher, ScreenManager* screenManager,int handleCategory) 
{
	this->dispatcher = dispatcher;
	this->screenManager = screenManager;
	this->handleCategory = handleCategory;
}

// Edit time - sleep for 100000 milisec
void CoEditor::edit(News* news) 
{
	usleep(100000);
}

// Start CoEditor work
void CoEditor::run() 
{
	switch (handleCategory) 
	{
	case NEWS:
		while (true) 
		{
			Info* news = dispatcher->getNewsQueueNews();
			if (news != NULL) 
			{
				edit(news);
				screenManager->insertNewsForBroadCast(news);
				if (news->getCategory() == DONE)
					break;
			}
		}
		break;
		
	case SPORTS:
		while (true) 
		{
			Info* news = dispatcher->getSportsQueueNews();
			if (news != NULL) 
			{
				edit(news);
				screenManager->insertNewsForBroadCast(news);
				if (news->getCategory() == DONE)
					break;
			}
		}
		break;
		
	case WHEATHER:
		while (true) 
		{
			Info* news = dispatcher->getWheatherQueueNews();
			if (news != NULL) 
			{
				edit(news);
				screenManager->insertNewsForBroadCast(news);
				if (news->getCategory() == DONE)
					break;
			}
		}
		break;
		
	default:
		break;
	}
}

// D'tor
CoEditor::~CoEditor() 
{
}