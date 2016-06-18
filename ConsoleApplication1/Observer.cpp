#include <stdio.h>
#include "Observer.h"
#include "Subject.h"


using std::string;
void Observer::subscribe(Subject* s)
{
	s->attach(this);
}

void Observer::unsubscribe(Subject* s)
{
	total -= s->getState();
	s->remove(this);
}

void Observer::update(Subject* s)
{
	//save
	int lasttotal = total;

	//update
	total -= s->lastState();
	total += s->getState();
	printf("observer %s now has total %d", name.c_str(), total);

	int change = total - lasttotal;
	if (change >= 0)
	{
		printf("(+%d)\n", change);
	}
	else
	{
		printf("(%d)\n", change);
	}
	
}

//constructor
Observer::Observer(const std::string& name)
	:name(name), total(0)
{
}


Observer::~Observer()
{
	delete this;
}
