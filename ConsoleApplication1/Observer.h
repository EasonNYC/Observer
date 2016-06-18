#pragma once
#include <string>
using std::string;


class Subject;
class Observer
{
	
	std::string name;
	int total;

public:
	void subscribe(Subject* s);
	void unsubscribe(Subject* s);
	void update(Subject* s);

	Observer(const std::string&);
	~Observer();
};

