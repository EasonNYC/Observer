
#include "Subject.h"
#include "Observer.h"

//example usage
int main()
{
	Subject* one = new Subject(3);
	Subject* two = new Subject(5);
	Subject* three = new Subject(9);

	Observer* o1 = new Observer("one");
	Observer* o2 = new Observer("two");

	o1->subscribe(one);
	o1->subscribe(two);
	o1->subscribe(three);
	o2->subscribe(two);
	o2->subscribe(three);

	one->setState(2);

}