// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall AbstractCell.c++ Cell.c++ ConwayCell.c++ FredkinCell.c++ -o RunLife
    % valgrind RunLife > RunLife.out

To configure Doxygen:
    doxygen -g
That creates the file Doxyfile.
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <fstream>
#include <stdexcept> // invalid_argument, out_of_range
#include "ConwayCell.h"
#include "Cell.h"
#include "Life.h"
#include "AbstractCell.h"

// ----
// main
// ----

int main () {
    using namespace std;

    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;
		ifstream in("RunLifeConway.in");
		Life<ConwayCell> l(in);
		//grid in life is created at this point
		for(int i=0; i< 283; i++)
		{
			if(i<=10)
				l.display(cout);
			l.simulate(1,1);
		}
		l.display(cout);
		for(int i=0; i<40; i++)
			l.simulate(1,1);
		l.display(cout);
		for(int i=0; i<2177; i++)
			l.simulate(1,1);
		l.display(cout);
        /*
        read RunLifeConway.in // assume all Conway cells
        Simulate 283 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        Print the 283rd grid.
        Simulate 40 moves.
        Print the 323rd grid.
        Simulate 2177 moves.
        Print the 2500th grid.
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
		ifstream in("RunLifeFredkin.in");
		Life<FredkinCell> l(in);
		for(int i=0; i<=5; i++)
		{
			l.display(cout);
			l.simulate(1,1);
		}
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
		ifstream in("RunLifeCell.in");
		Life<Cell> l(in);
		for(int i=0; i<=5; i++)
		{
			l.display(cout);
			l.simulate(1,1);
		}
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

