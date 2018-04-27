#ifndef SYSTEMBUILDER_H_
#define SYSTEMBUILDER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Producer.h"
#include "ScreenManager.h"
#include "Dispatcher.h"
#include "CoEditor.h"

using namespace std;

class Builder 
{
private:
	vector<Producer*>* producers;
	vector<Producer*>* producersCopy;
	Dispatcher* dispatcher;
	ScreenManager* screenManager;
	CoEditor* newsEditor;
	CoEditor* sportsEditor;
	CoEditor* wheatherEditor;

public:
	Builder();
	void build(string configurationPath);
	void start();
	void clean();
	virtual ~Builder();
};

#endif