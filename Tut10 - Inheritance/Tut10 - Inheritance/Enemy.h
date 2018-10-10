#pragma once

#include "Comparable.h"

// declare enemy class

class Enemy : public Comparable{
public:
	Enemy(int hps);
	virtual ~Enemy() = 0;	//Task 4
	virtual int get_hit_points() const ;
	virtual int get_score() const;
	virtual void set_hit_points(int new_hit_points);
	virtual	void set_score(int new_score);

	virtual int compare_to(const Comparable& rhs);

protected:
	int hit_points;
	int* score;
};

