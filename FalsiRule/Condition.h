#ifndef _CONDITION_H_
#define _CONDITION_H_

class Condition {
public:
	virtual bool check();
};

class Epsilon : public Condition
{
public:
	Epsilon(double &f, double &e);
	double * epsilon;
	double * fo;
	virtual bool check();
};

class Iteration : public Condition
{
public:
	Iteration(int &i, int &m);
	int * counter;
	int * max;
	virtual bool check();
};

#endif // !_CONDITION_H_
