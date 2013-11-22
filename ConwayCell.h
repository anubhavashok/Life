#ifndef ConwayCell_h
#define ConwayCell_h

#include "AbstractCell.h"
#include <iostream>
#include <cassert>
using namespace std;

/**
 * @class ConwayCell
 * A derived class that extends AbstractCell and represents conway cells
 */
class ConwayCell: public AbstractCell
{
	private:
	char type;
	public:
	// --------
	// ConwayCell
	// --------
	/**
	 * Constructor for ConwayCell
	 * @param _alive a bool representing the state of the cell
	 */
	ConwayCell(bool);

	// --------
	// ConwayCell
	// --------
	/**
	 * Copy Constructor for ConwayCell
	 * @param c an ConwayCell& representing the object to be copied
	 */
	ConwayCell(const ConwayCell& c);

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
	// clone
	// --------
	/**
	 * Clones itself
	 * @return an ConwayCell* to a new cloned object
	 */
	ConwayCell* clone();


	void mutate();
};
#endif // ConwayCell_h
