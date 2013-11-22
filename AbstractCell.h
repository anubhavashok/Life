#ifndef AbstractCell_h
#define AbstractCell_h

#include<iostream>
using namespace std;
/**
 * @class AbstractCell
 * An abstract base class for Cells to inherit
 */
class AbstractCell
{
	protected: 
	bool alive;
	public:

	// --------
	// AbstractCell
	// --------
	/**
	 * Constructor for AbstractCell
	 * @param _alive a bool representing the state of the cell
	 */
	AbstractCell(bool);
	// --------
	// AbstractCell
	// --------
	/**
	 * Copy Constructor for AbstractCell
	 * @param c an AbstractCell& representing the object to be copied
	 */
	AbstractCell(AbstractCell&);

	// --------
	// ~AbstractCell
	// --------
	/**
	 * Destructor for AbstractCell
	 */
	~AbstractCell();

	// --------
	// display
	// --------
	/**
	 * Displays the state of the cell
	 * @param out an ostream& containing a reference to the output stream
	 */
	virtual void display(ostream&);

	// --------
	// kill
	// --------
	/**
	 * Changes the state of the cell to not alive
	 */
	virtual void kill();

	// --------
	// revive
	// --------
	/**
	 * Changes the state of the cell to alive
	 */
	virtual void revive();


	// --------
	// clone
	// --------
	/**
	 * Clones itself
	 * @return an AbstractCell* to a new cloned object
	 */
	virtual AbstractCell* clone();

	// --------
	// mutate
	// --------
	/**
	 * Changes a FredkinCell to a ConwayCell
	 */
	virtual void mutate();

	// --------
	// is_alive
	// --------
	/**
	 * indicates if a cell is alive
	 * @return a bool indicating if cell is alive
	 */
	virtual bool is_alive(); 

	// --------
	// get_type
	// --------
	/**
	 * Returns a character indicating the type of cell it is
	 * 'C' for ConwayCell and 'F' for FredkinCell
	 * @return a char indicating type of cell
	 */
	virtual char get_type();

	// --------
	// get_age
	// --------
	/**
	 * returns the current age of the cell
	 * @return an int representing the age of the cell
	 */
	virtual int get_age();
};
#endif // AbstractCell_h	
