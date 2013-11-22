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
	AbstractCell(AbstractCell&);
	~AbstractCell();
	virtual void display(ostream&);
	virtual void kill();
	virtual void revive();
	virtual AbstractCell* clone();
	virtual void mutate();
	virtual bool is_alive(); 
	virtual char get_type();
	virtual int get_age();
};
#endif // AbstractCell_h	
