#ifndef FredkinCell_h
#define FredkinCell_h

#include "AbstractCell.h"
#include <iostream>
#include <stdlib.h>
#include <cassert>

using namespace std;
class FredkinCell: public AbstractCell
{
	private:
	int age;
	char type;
	public:
	FredkinCell(bool);
	FredkinCell(bool, char);
	FredkinCell(const FredkinCell& c);
	void display(ostream&);
	void kill();
	void revive();
	bool is_alive();
	char get_type();
	int get_age();
	FredkinCell* clone();
	void mutate();
};
#endif // FredkinCell_h
