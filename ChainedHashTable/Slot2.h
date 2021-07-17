#ifndef __SLOT_H__
#define __SLOT_H__
#include "Person.h"
#include <iostream>

typedef int Key;
typedef Person* Value;

class Slot
{
public:
	Key key;
	Value val;

	Slot(Key k = 0, Value v = NULL) : key(k), val(v)
	{}
};

#endif // !__SLOT_H__

