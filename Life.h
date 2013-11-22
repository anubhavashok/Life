#ifndef Life_h
#define Life_h
#include <cassert>
#include <iostream>
#include <vector>
#include "ConwayCell.h"
#include "FredkinCell.h"
using namespace std;

template <typename T>

class Life
{
	private:
	int x;
	int y;
	vector< vector<T> > _grid; 
	int generation;
	int population;

	public:
	Life(istream& in)
	{
		generation =0;
		population=0;
		in >> y;
		in >> x;

		//add extra row [x +2] of dummies
		vector<T> dummies(x+2,(new ConwayCell(false)));
		_grid.push_back(dummies);

		for(int i=0; i<y; i++)
		{
			vector<T> r;

			//add start dummy
			r.push_back((new ConwayCell(false)));

			for(int j =0 ; j < x; j++)
			{
				char c;
				in >> c;
				if(c=='.')
					r.push_back((new ConwayCell(false)));
				else if(c=='*')
				{
					population++;
					r.push_back((new ConwayCell(true)));
				}
				else if(c=='-')
					r.push_back((new FredkinCell(false)));
				else
				{
					population++;
					cout<<"Character in FredkinCell Constructor: "<<c<<endl;
					r.push_back((new FredkinCell(true,c)));				
				}
			}

			//add end dummy
			r.push_back((new ConwayCell(false)));

			_grid.push_back(r);
		}

		//add extra row [x +2] of dummies
		_grid.push_back(dummies);

	}

	void simulate(int i, int j)
	{
		if((i==1) && (j==1))
		{
			generation++;
			population=0;
		}

		T& c = _grid[i][j];
		bool change_state = false;

		if(c.is_alive())
		{
			int neighbors;
			
			if(c.get_type()=='F')
			{
				neighbors=alive_neighbors_fredkin(i,j);
				assert(neighbors<=4);
				if(neighbors%2==0)
					change_state=true;
				else
					c.revive();
				if(c.get_age()==2)
				{
					c.mutate();
				}
			}

			if(c.get_type()=='C')
			{
				neighbors = alive_neighbors_conway(i,j);
				if(!((neighbors==2) || (neighbors==3)))
					change_state=true;
			}
		}		
		else
		{
			if(c.get_type()=='F')
			{
				if(alive_neighbors_fredkin(i,j)%2==1)
					change_state=true;
			}

			if(c.get_type()=='C')
			{
				if(alive_neighbors_conway(i,j)==3)
					change_state=true;
			}
		}
	
		//next spot
		if(! ( (i==(int)_grid.size()-2) && (j==(int)_grid[0].size()-2) ) )
		{
			if(j==(int)_grid[0].size()-2)
			{
				simulate(i+1,1);
			}
			else
			{
				simulate(i,j+1);
			}
		}

		if(change_state)
		{
			if(c.is_alive())
				c.kill();
			else
				c.revive();
		}
		if(c.is_alive()) population++;
		return;
	}

	int alive_neighbors_fredkin(int i, int j)
	{
		int count=0;
		if(_grid[i+1][j].is_alive())
			count++;
		if(_grid[i-1][j].is_alive())
			count++;
		if(_grid[i][j+1].is_alive())
			count++;
		if(_grid[i][j-1].is_alive())
			count++;
		return count;
	}

	int alive_neighbors_conway(int i, int j)
	{
		int count=alive_neighbors_fredkin(i,j);
		if(_grid[i+1][j+1].is_alive())
			count++;
		if(_grid[i-1][j-1].is_alive())
			count++;
		if(_grid[i-1][j+1].is_alive())
			count++;
		if(_grid[i+1][j-1].is_alive())
			count++;
		return count;
	}

	void display(ostream& out)
	{
		cout<<"Generation = "<<generation<<", Population = "<<population<<"."<<endl;
		for(int i=1; i<y+1; i++)
		{
			for(int j=1; j< x+1; j++)
			{
				_grid[i][j].display(out);
			}
			cout<<endl;
		}
		cout<<endl;
	}
};
template<>
Life<ConwayCell>::Life(istream& in)
{
	generation =0;
	population=0;
	in >> y;
	in >> x;

	//add extra row [x +2] of dummies
	vector<ConwayCell> dummies(x+2,false);
	_grid.push_back(dummies);

	for(int i=0; i<y; i++)
	{
		vector<ConwayCell> r;

		//add start dummy
		r.push_back(false);

		for(int j =0 ; j < x; j++)
		{
			char c;
			in >> c;
			assert(c=='.'||c=='*');
			if(c=='.')
				r.push_back(*(new ConwayCell(false)));
			else if(c=='*')
			{
				population++;
				r.push_back(*(new ConwayCell(true)));
			}
		}

		//add end dummy
		r.push_back(false);

		_grid.push_back(r);
	}

	//add extra row [x +2] of dummies
	_grid.push_back(dummies);

}
template<>
Life<FredkinCell>::Life(istream& in)
{
	generation =0;
	population=0;
	in >> y;
	in >> x;

	//add extra row [x +2] of dummies
	vector<FredkinCell> dummies(x+2,false);
	_grid.push_back(dummies);

	for(int i=0; i<y; i++)
	{
		vector<FredkinCell> r;

		//add start dummy
		r.push_back(false);

		for(int j =0 ; j < x; j++)
		{
			char c;
			in >> c;
			if(c=='-')
				r.push_back(*(new FredkinCell(false)));
			else
			{
				population++;
				r.push_back(*(new FredkinCell(true,c)));				
			}
		}

		//add end dummy
		r.push_back(false);

		_grid.push_back(r);
	}

	//add extra row [x +2] of dummies
	_grid.push_back(dummies);

}

#endif // Life_h
