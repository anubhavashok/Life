#include "FredkinCell.h"
#include <stdlib.h>

// --------
// FredkinCell
// --------
FredkinCell::FredkinCell(bool _alive, char c):AbstractCell(_alive),type('F')
{
		if(c!='+')
		{
			int _age= c-(int)'0';
			assert(_age<10);
			assert(_age>=0);
			age=_age;
		}
		else
		{
			age =11;
		}
}
FredkinCell::FredkinCell(bool _alive):AbstractCell(_alive),age(0),type('F'){}
FredkinCell::FredkinCell(const FredkinCell& c):AbstractCell(c.alive),age(c.age),type('F'){}

// --------
// display
// --------
void FredkinCell::display(ostream& out)
{
	if(alive)
	{
		if(age<10)
			out<<age;
		else
			out<<"+";
	}
	else
	{
		out<<"-";
	}
}

// --------
// kill
// --------
void FredkinCell::kill()
{
	alive =0;
}

// --------
// revive
// --------
void FredkinCell::revive()
{
	if(alive==1)
	{
		age++;
	}
	alive =1;
}

// --------
// is_alive
// --------
bool FredkinCell::is_alive()
{
	return alive;
}

// --------
// get_type
// --------
char FredkinCell::get_type()
{
	return type;
}

// --------
// clone
// --------
FredkinCell* FredkinCell::clone()
{
		if(age<10)
		{
			char c=(char)((int)'0'+age);
			return (new FredkinCell(alive,c));
		}
		return (new FredkinCell(alive,'+'));
}

// --------
// get_age
// --------
int FredkinCell::get_age()
{
	return age;
}
void FredkinCell::mutate(){}
