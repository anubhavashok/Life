#include "ConwayCell.h"

ConwayCell::ConwayCell(bool _alive):AbstractCell(_alive),type('C'){}
ConwayCell::ConwayCell(const ConwayCell& c):AbstractCell(c.alive),type('C'){}

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
void ConwayCell::kill()
{
	alive =0;
}
void ConwayCell::revive()
{
	alive =1;
}
bool ConwayCell::is_alive()
{
	return alive;
}
char ConwayCell::get_type()
{
	return type;
}
ConwayCell* ConwayCell::clone()
{
	return (new ConwayCell(alive));
}
void ConwayCell::mutate(){}
