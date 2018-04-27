#ifndef NEWS_H_
#define NEWS_H_

#include <iostream>
#include <string>
#include "Sections.h"

using namespace std;

class Info 
{
	int producerNumber;
	int category;
	int serial;

public:
	Info(int producerNumber, int category, int serial);
	void print();
	
	int getProducerNumber()
	{
		return producerNumber;
	}
	
	int getCategory()
	{
		return category;
	}
	
	int getSerial()
	{
		return serial;
	}
	
	virtual ~Info();
};

#endif