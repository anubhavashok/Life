#include "FredkinCell.h"
#include <stdlib.h>

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
void FredkinCell::kill()
{
	alive =0;
}
void FredkinCell::revive()
{
	if(alive==1)
	{
		age++;
	}
	alive =1;
}
bool FredkinCell::is_alive()
{
	return alive;
}
char FredkinCell::get_type()
{
	return type;
}
FredkinCell* FredkinCell::clone()
{
		if(age<10)
		{
			char c=(char)((int)'0'+age);
			return (new FredkinCell(alive,c));
		}
		return (new FredkinCell(alive,'+'));
}
int FredkinCell::get_age()
{
	return age;
}
void FredkinCell::mutate(){}
