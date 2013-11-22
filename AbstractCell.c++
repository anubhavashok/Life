#include "AbstractCell.h"
#include<iostream> 
using namespace std;

AbstractCell::AbstractCell(bool _alive):alive(_alive){}
AbstractCell::AbstractCell(AbstractCell& c):alive(c.alive){}
AbstractCell::~AbstractCell(){}
void AbstractCell::display(ostream&){}
void AbstractCell::kill(){}
void AbstractCell::revive(){}
AbstractCell* AbstractCell::clone(){return new AbstractCell(true);}
void AbstractCell::mutate(){}
bool AbstractCell::is_alive(){return alive;}
char AbstractCell::get_type(){return 'A';}
int AbstractCell::get_age(){return 0;}
