#include "ConwayCell.h"

ConwayCell::ConwayCell(bool _alive):AbstractCell(_alive)
{
	//if(_alive) {cout<<"*";}
	//else {cout<<".";}
}
ConwayCell::ConwayCell(const ConwayCell& c):AbstractCell(c.alive)
{
}

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
void ConwayCell::clone()
{
}
void ConwayCell::mutate()
{}
