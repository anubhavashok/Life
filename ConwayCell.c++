#include "ConwayCell.h"

// --------
// ConwayCell
// --------
ConwayCell::ConwayCell(bool _alive):AbstractCell(_alive),type('C'){}
ConwayCell::ConwayCell(const ConwayCell& c):AbstractCell(c.alive),type('C'){}

// --------
// display
// --------
void ConwayCell::display(ostream& out)
{
	if(alive)
	{
		out<<"*";
	}
	else
	{
		out<<".";
	}
}

// --------
// kill
// --------
void ConwayCell::kill()
{
	alive =0;
}

// --------
// revive
// --------
void ConwayCell::revive()
{
	alive =1;
}

// --------
// is_alive
// --------
bool ConwayCell::is_alive()
{
	return alive;
}

// --------
// get_type
// --------
char ConwayCell::get_type()
{
	return type;
}

// --------
// clone
// --------
ConwayCell* ConwayCell::clone()
{
	return (new ConwayCell(alive));
}


void ConwayCell::mutate(){}
