#include "Cell.h"

Cell::Cell(AbstractCell* p):
	Handle<AbstractCell>(p)
{}
void Cell::kill()
{
	get()->kill();
}
void Cell::revive()
{
	get()->revive();
}
void Cell::display(ostream& out)
{
	get()->display(out);
}
bool Cell::is_alive()
{
	return get()->is_alive();
}
char Cell::get_type()
{
	return get()->get_type();
}
AbstractCell* Cell::clone()
{
	return get()->clone();
}
int Cell::get_age()
{
	return get()->get_age();
}
void Cell::mutate()
{
	AbstractCell* c= new ConwayCell(true);

	Handle<AbstractCell> h(c);
	Handle<AbstractCell>* n = this;
	*n =h;
}

