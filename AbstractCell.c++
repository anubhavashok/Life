#include "AbstractCell.h"
#include<iostream> 
using namespace std;

AbstractCell::AbstractCell(bool _alive):alive(_alive){}
AbstractCell::~AbstractCell(){}
void AbstractCell::display(ostream&){}
void AbstractCell::kill(){}
void AbstractCell::revive(){}
void AbstractCell::clone(){}
void AbstractCell::mutate(){}
bool AbstractCell::is_alive(){return alive;}
