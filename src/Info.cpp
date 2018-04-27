#include "Info.h"

// C'tor
Info::Info(int producerNumber, int category, int serial) 
{
	this->producerNumber = producerNumber;
	this->category = category;
	this->serial = serial;
}

// Print info details
void Info::print() 
{
	switch (this->category) 
	{
	case NEWS:
		cout << "PRODUCER " << this->producerNumber << " NEWS " << this->serial << endl;
		break;
	case SPORTS:
		cout << "PRODUCER " << this->producerNumber << " SPORTS " << this->serial << endl;
		break;
	case WHEATHER:
		cout << "PRODUCER " << this->producerNumber << " WHEATHER " << this->serial << endl;
		break;
	default:
		break;
	}
}

// Get-functions
int Info::getProducerNumber()
{
	return this->producerNumber;
}
int Info::getCategory()
{
	return this->category;
}
int Info::getSerial()
{
	return this->serial;
}

// D'tor
Info::~News() 
{
}
