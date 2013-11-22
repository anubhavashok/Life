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

	//ofstream out("RunLife.out2");
    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;
                ifstream in("RunLifeConway.in");
                Life<ConwayCell> l(in);
                //grid in life is created at this point
                for(int i=0; i< 283; i++)
                {
                        if(i<10)
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
			//Test by asm2262
		cout << "*** Life<ConwayCell> 70x2 ***" << endl;
			Life<ConwayCell> m(in);
			for(int i=0; i<=5; i++)
			{
				m.display(cout);
				m.simulate(1,1);
			}
	
			//Test by bchean
		cout << "*** Life<ConwayCell> 22x22 ***" << endl;
			Life<ConwayCell> n(in);
			for(int i=0; i<=5; i++)
			{
				n.display(cout);
				n.simulate(1,1);
			}
			
		
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
		//Test by andrews
		cout << "*** Life<FredkinCell> 18x5 ***" << endl;
			Life<FredkinCell> m(in);
			for(int i=0; i<=5; i++)
			{
				m.display(cout);
				m.simulate(1,1);
			}
		//Test by austind
		cout << "*** Life<FredkinCell> 22x14 ***" << endl;
			Life<FredkinCell> n(in);
			for(int i=0; i<=5; i++)
			{
				n.display(cout);
				n.simulate(1,1);
			}
		
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
		cout << "*** Life<Cell> 4x2 ***" << endl;
				Life<Cell> m(in);
                for(int i=0; i<=5; i++)
                {
                        m.display(cout);
                        m.simulate(1,1);
                }

		cout << "*** Life<Cell> 5x5 ***" << endl;
				Life<Cell> n(in);
                for(int i=0; i<=5; i++)
                {
                        n.display(cout);
                        n.simulate(1,1);
                }

		cout << "*** Life<Cell> 5x5 ***" << endl;
				Life<Cell> o(in);
                for(int i=0; i<=5; i++)
                {
                        o.display(cout);
                        o.simulate(1,1);
                }

		cout << "*** Life<Cell> 30x100 ***" << endl;
				Life<Cell> p(in);
                for(int i=0; i<=5; i++)
                {
                        p.display(cout);
                        p.simulate(1,1);
                }

		cout << "*** Life<Cell> 30x100 ***" << endl;
				Life<Cell> q(in);
                for(int i=0; i<=5; i++)
                {
                        q.display(cout);
                        q.simulate(1,1);
                }

		cout << "*** Life<Cell> 30x100 ***" << endl;
				Life<Cell> r(in);
                for(int i=0; i<=5; i++)
                {
                        r.display(cout);
                        r.simulate(1,1);
                }

		cout << "*** Life<Cell> 50x50 ***" << endl;
				Life<Cell> s(in);
                for(int i=0; i<=5; i++)
                {
                        s.display(cout);
                        s.simulate(1,1);
                }

		cout << "*** Life<Cell> 20x30 ***" << endl;
				Life<Cell> t(in);
                for(int i=0; i<=50; i++)
                {
						if(i%5==0)
                        	t.display(cout);
                        t.simulate(1,1);
                }
		cout << "*** Life<Cell> 12x20 ***" << endl;
				Life<Cell> u(in);
                for(int i=0; i<=10; i++)
                {
						if(i%2==0)
                        	u.display(cout);
                        u.simulate(1,1);
                }

		//Test by carillo
		cout << "*** Life<Cell> 12x20 ***" << endl;
				Life<Cell> v(in);
                for(int i=0; i<=5; i++)
                {
                        v.display(cout);
                        v.simulate(1,1);
                }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
