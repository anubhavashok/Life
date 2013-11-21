#ifndef AbstractCell_h
#define AbstractCell_h

#include<iostream>
using namespace std;
class AbstractCell
{
	protected: 
	bool alive;
	public:
	AbstractCell(bool);
	~AbstractCell();
	virtual void display(ostream&);
	virtual void kill();
	virtual void revive();
	virtual void clone();
	virtual void mutate();
	virtual bool is_alive(); 
};
#endif // AbstractCell_h	
