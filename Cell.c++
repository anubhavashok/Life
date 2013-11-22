#include "Cell.h"

// --------
// Cell
// --------
Cell::Cell(AbstractCell* p):
	Handle<AbstractCell>(p)
{}

// --------
// kill
// --------
void Cell::kill()
{
	get()->kill();
}

// --------
// revive
// --------
void Cell::revive()
{
	get()->revive();
}

// --------
// display
// --------
void Cell::display(ostream& out)
{
	get()->display(out);
}

// --------
// is_alive
// --------
bool Cell::is_alive()
{
	return get()->is_alive();
}

// --------
// get_type
// --------
char Cell::get_type()
{
	return get()->get_type();
}

// --------
// clone
// --------
AbstractCell* Cell::clone()
{
	return get()->clone();
}

// --------
// get_age
// --------
int Cell::get_age()
{
	return get()->get_age();
}

// --------
// mutate
// --------
void Cell::mutate()
{
	AbstractCell* c= new ConwayCell(true);

	Handle<AbstractCell> h(c);
	Handle<AbstractCell>* n = this;
	*n =h;
}

