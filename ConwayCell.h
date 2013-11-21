#ifndef ConwayCell_h
#define ConwayCell_h

#include "AbstractCell.h"
#include <iostream>
using namespace std;
class ConwayCell: AbstractCell
{
	public:
	ConwayCell(bool);
	ConwayCell(const ConwayCell& c);
	void display(ostream&);
	void kill();
	void revive();
	bool is_alive();
	void clone();
	void mutate();
};
#endif // ConwayCell_h
