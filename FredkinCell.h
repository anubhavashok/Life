#ifndef FredkinCell_h
#define FredkinCell_h

#include "AbstractCell.h"
#include <iostream>
#include <stdlib.h>
#include <cassert>

using namespace std;

/**
 * @class FredkinCell
 * A derived class that extends AbstractCell and represents fredkin cells
 */
class FredkinCell: public AbstractCell
{
	private:
	int age;
	char type;
	public:
	// --------
	// FredkinCell
	// --------
	/**
	 * Constructor for FredkinCell
	 * @param _alive a bool representing the state of the cell
	 */
	FredkinCell(bool);
	// --------
	// FredkinCell
	// --------
	/**
	 * Constructor for FredkinCell
	 * @param _alive a bool representing the state of the cell
	 * @param c a char representing the age of the cell
	 */
	FredkinCell(bool, char);

	// --------
	// FredkinCell
	// --------
	/**
	 * Copy Constructor for FredkinCell
	 * @param c an FredkinCell& representing the object to be copied
	 */
	FredkinCell(const FredkinCell& c);

	// --------
	// display
	// --------
	/**
	 * Displays the state of the cell
	 * @param out an ostream& containing a reference to the output stream
	 */
	void display(ostream&);

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
	// is_alive
	// --------
	/**
	 * indicates if a cell is alive
	 * @return a bool indicating if cell is alive
	 */
	bool is_alive();

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
	// get_age
	// --------
	/**
	 * returns the current age of the cell
	 * @return an int representing the age of the cell
	 */
	int get_age();

	// --------
	// clone
	// --------
	/**
	 * Clones itself
	 * @return an AbstractCell* to a new cloned object
	 */
	FredkinCell* clone();
	void mutate();
};
#endif // FredkinCell_h
