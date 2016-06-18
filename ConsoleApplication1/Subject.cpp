
#include <algorithm>
#include <stdio.h>
#include "Subject.h"
#include "Observer.h"

template <typename T>
struct pointer_values_equal
{
	const T* to_find;

	bool operator()(const T* other) const
	{
		return to_find == other;
	}
};



//constructor
Subject::Subject(const int& state)
	:state(state), laststate(0)
{
}



void Subject::setState(const int& value)
{
	laststate = state;
	state = value;
	notify();
}

int Subject::getState() const
{
	return state;
}

int Subject::lastState() const
{
	return laststate;
}


void Subject::attach(Observer* o)
{
	Observer* findme = o;
	pointer_values_equal<Observer> eq = { findme };

	if (find_if(ovec.begin(), ovec.end(), eq) == ovec.end())
	{
		ovec.push_back(o);
		o->update(this);
	}
	else
	{
		printf("error attaching observer.\n");
	}
}


void Subject::remove(Observer* o)
{
	Observer* findme = o;
	pointer_values_equal<Observer> eq = { findme };

	auto it = find_if(ovec.begin(), ovec.end(), eq);
	
	if (it != ovec.end()) 
	{

		ovec.erase(it);
	}
	else
	{
		printf("erasing error. subject could not find object\n");
	}
}


void Subject::notify()
{
	//notify all observers
	for (auto& it : ovec)
	{
		it->update(this);
	}
		
}


Subject::~Subject()
{
	state = 0;
	laststate = 0;
	for (auto& o : ovec)
	{
		
		o->update(this);
		o->unsubscribe(this);
		
	}
	
	//delete me?
	delete this;
}
