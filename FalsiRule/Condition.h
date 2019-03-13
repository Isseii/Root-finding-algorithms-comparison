#ifndef _CONDITION_H_
#define _CONDITION_H_

class Condition {
public:
	virtual bool check(void *addr) = 0;
};

class Epsilon : public Condition
{
public:
	Epsilon(double &e);
	double * epsilon;
	virtual bool check(void* addr);
};

class Iteration : public Condition
{
public:
	Iteration(int &m);
	int * max;
	virtual bool check(void *addr);
};

#endif // !_CONDITION_H_
