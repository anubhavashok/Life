#ifndef ConwayCell_h
#define ConwayCell_h

#include "AbstractCell.h"
#include <iostream>
#include <cassert>
using namespace std;
class ConwayCell: public AbstractCell
{
	private:
	char type;
	public:
	ConwayCell(bool);
	ConwayCell(const ConwayCell& c);
	void display(ostream&);
	void kill();
	void revive();
	bool is_alive();
	char get_type();
	ConwayCell* clone();
	void mutate();
};
#endif // ConwayCell_h
