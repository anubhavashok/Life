#include "Cell.h"

Cell::Cell(AbstractCell* p):
	Handle<AbstractCell>(p)
{}
void Cell::mutate()
{
	get()->mutate();
}
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
void Cell::clone()
{

}

