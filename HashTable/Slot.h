#ifndef __SLOT_H__
#define __SLOT_H__
#include "Person.h"

typedef int Key;
typedef Person* Value;

enum SlotStatus { EMPTY, DELETED, INUSE };

class Slot
{
public:
	Key key;
	Value val;
	enum SlotStatus status;
};


#endif // !__SLOT_H__

