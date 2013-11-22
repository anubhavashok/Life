#ifndef Cell_h
#define Cell_h

#include "Handle.h"
#include "AbstractCell.h"
#include "ConwayCell.h"

/**
 * @class Cell
 * Class that employs polymorphism techniques to control ConwayCells and FredkinCells
 */
class Cell : public Handle<AbstractCell>
{
	public:

	// --------
	// Cell
	// --------
	/**
	 * Constructor for Cell
	 * @param c an AbstractCell* pointing to a ConwayCell or FredkinCell object
	 */
	Cell(AbstractCell*);

	// --------
	// kill
	// --------
	/**
	 * Changes the state of the cell to not alive
	 */
	void kill();

	// --------
	// revive
	// --------
	/**
	 * Changes the state of the cell to alive
	 */
	void revive();

	// --------
	// display
	// --------
	/**
	 * Displays the state of the cell
	 * @param out an ostream& containing a reference to the output stream
	 */
	void display(ostream&);

	// --------
	// is_alive
	// --------
	/**
	 * indicates if a cell is alive
	 * @return a bool indicating if cell is alive
	 */
	bool is_alive();

	// --------
	// clone
	// --------
	/**
	 * Clones itself
	 * @return an AbstractCell* to a new cloned object
	 */
	AbstractCell* clone();

	// --------
	// get_type
	// --------
	/**
	 * Returns a character indicating the type of cell it is
	 * 'C' for ConwayCell and 'F' for FredkinCell
	 * @return a char indicating type of cell
	 */
	char get_type();

	// --------
	// mutate
	// --------
	/**
	 * Changes a FredkinCell to a ConwayCell
	 */
	void mutate();

	// --------
	// get_age
	// --------
	/**
	 * returns the current age of the cell
	 * @return an int representing the age of the cell
	 */
	int get_age();
};

#endif // Cell_h
