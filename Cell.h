#ifndef Cell_h
#define Cell_h

#include "Handle.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
class Cell : public Handle<AbstractCell>
{
	public:
	Cell(AbstractCell*);
	void kill();
	void revive();
	void display(ostream&);
	bool is_alive();
	AbstractCell* clone();
	char get_type();
	void mutate();
	int get_age();
};

#endif // Cell_h
