#include "AbstractCell.h"
#include<iostream> 
using namespace std;

// --------
// AbstractCell
// --------
AbstractCell::AbstractCell(bool _alive):alive(_alive){}
AbstractCell::AbstractCell(AbstractCell& c):alive(c.alive){}

// --------
// ~AbstractCell
// --------
AbstractCell::~AbstractCell(){}

// --------
// display
// --------
void AbstractCell::display(ostream&){}

// --------
// kill
// --------
void AbstractCell::kill(){}

// --------
// revive
// --------
void AbstractCell::revive(){}

// --------
// clone
// --------
AbstractCell* AbstractCell::clone(){return new AbstractCell(true);}

// --------
// mutate
// --------
void AbstractCell::mutate(){}

// --------
// is_alive
// --------
bool AbstractCell::is_alive(){return alive;}

// --------
// get_type
// --------
char AbstractCell::get_type(){return 'A';}

// --------
// get_age
// --------
int AbstractCell::get_age(){return 0;}
