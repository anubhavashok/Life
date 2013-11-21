#ifndef Life_h
#define Life_h
#include <cassert>
#include <iostream>
#include <vector>
#include "ConwayCell.h"
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
		vector<T> dummies(x+2,false);
		_grid.push_back(dummies);

		for(int i=0; i<y; i++)
		{
			vector<T> r;

			//add start dummy
			r.push_back(false);

			for(int j =0 ; j < x; j++)
			{
				char c;
				in >> c;
				assert(c=='.'||c=='*');
				if(c=='.')
					r.push_back(false);
				else if(c=='*')
				{
					population++;
					r.push_back(true);
				}
				//else if(c=='-')
				//	r.push_back(new FredkinCell(0));
				//else
				//	r.push_back(new FredkinCell(1,c));				
			}

			//add end dummy
			r.push_back(false);

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
		//cout<<"REACHED grid["<<i<<"]["<<j<<"]: ";
		T& c = _grid[i][j];
		bool to_kill = false;
		bool to_revive = true;	
		bool die = false;
		//cout<<"Neighbors - "<<alive_neighbors_conway(i,j)<<endl;
		if(alive_neighbors_conway(i, j) !=3)
			die = true;
		if((alive_neighbors_conway(i,j)==4)&&(c.is_alive()))
		{
				die=false;
		}

		if(! ( (i==_grid.size()-2) && (j==_grid[0].size()-2) ) )
		{
			if(j==_grid[0].size()-2)
			{
				simulate(i+1,1);
			}
			else
			{
				simulate(i,j+1);
			}
		}

		assert(!(to_kill && to_revive));
		if(!die)
			c.revive();
		else
			c.kill();	
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
		if(_grid[i][j].is_alive())
			count++;
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
#endif // Life_h
