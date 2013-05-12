//
//  main.cpp
//  freelancer
//
//  Created by Martin Skow Røed on 12.05.13.
//  Copyright (c) 2013 Martin Skow Røed. All rights reserved.
//

#include <iostream>


using namespace std;
class aaa {
	friend ostream & operator<<(ostream &, const aaa &);
public:
	aaa(void);
	aaa(int);
	aaa(const aaa &);
	virtual ~aaa();
	virtual int report(void) const;
	int f1(void ) const;
	const aaa & operator = ( const aaa &);
	bool operator == (const aaa & ) const;
private:
	int x;
};

class ccc {
	friend ostream & operator<<(ostream &, const ccc &);
public:
	ccc(void);
	ccc(char);
	ccc(const ccc &);
	~ccc();
	int lookAt(void) const;
	const ccc & operator = ( const ccc &);
	bool operator == ( const ccc &) const;
private:
	char y;
};

class qqq : public aaa {
	friend ostream & operator << ( ostream &, const qqq &);
public:
	qqq(void);

	qqq(int, char, double, const char *);

	qqq( const qqq &);

	virtual ~qqq();

	int report(void) const;    //REWRITE of inherited function
    // to return triple the value of the
    //  inherited function

	int lookAt(void) const;  //  Same return value as ccc's function

	const qqq & operator = ( const qqq &);

	bool operator == ( const qqq & ) const;  //  return true if all
    // "4" fields are equal

private:
	double pear;
	ccc a;
	char * name;
};
//                     WRITE ALL OF THE FUNCTIONS FOR THE CLASS qqq


qqq::~qqq()
{
    delete name;
}


qqq::qqq(void)
{
    name = NULL;
}


qqq::qqq(int m, char n, double o , const char * na) : aaa(m)
{
    this->name = new char(n);
    this->pear = o;
    this->a = ccc(n);
    this->name = new char(*na);
}


qqq::qqq(const qqq & r)
{
    this->pear = r.pear;
    this->name = new char(*r.name);
    this->a = r.a;
}

int qqq::report(void) const
{
    aaa temp(*this);
    return 3*temp.report();
}


ostream & operator << ( ostream & w, const qqq & r)
{
    w << "name: " << r.name; //send all you want to the ostream object
    return w;
}


const qqq & qqq::operator =( const qqq & r)
{
    if (name) delete name;
    this->pear = r.pear;
    this->a = r.a;
    this->name = new char(*r.name);
    return *this;
}


int qqq::lookAt(void) const
{
    return a.lookAt();
}


bool qqq::operator ==( const qqq & r) const
{
    return this->name == r.name && this->pear == r.pear && this->a == r.a && this->lookAt() == r.lookAt();
}
