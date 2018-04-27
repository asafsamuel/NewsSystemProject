#ifndef COEDITOR_H_
#define COEDITOR_H_
#include "Dispatcher.h"
#include "ScreenManager.h"
# include "Sections.h"

class CoEditor : public MThread
{
private:
	Dispatcher* dispatcher;
	ScreenManager* screenManager;
	int handleCategory;
	
public:
	CoEditor(Dispatcher* dispatcher, ScreenManager* screenManager,int handleCategory);
	void edit(News* news);
	void run();
	virtual ~CoEditor();
};

#endif