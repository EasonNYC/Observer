#pragma once
#include <vector>
using std::vector;

class Observer;
class Subject
{
	int state;
	int laststate;
	std::vector<Observer*> ovec;

public:
	void setState(const int& value);
	int getState() const;
	int lastState() const;
	Subject(const int& state);
	void attach(Observer*);
	void remove(Observer*);
	
	void notify();

	~Subject();
};

