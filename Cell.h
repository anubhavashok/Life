#ifndef Cell_h
#define Cell_h

#include "Handle.h"
#include "AbstractCell.h"
class Cell : Handle<AbstractCell>
{
	public:
	Cell(AbstractCell*);
	void mutate();
	void kill();
	void revive();
	void display(ostream&);
	bool is_alive();
	void clone();
};

#endif // Cell_h
