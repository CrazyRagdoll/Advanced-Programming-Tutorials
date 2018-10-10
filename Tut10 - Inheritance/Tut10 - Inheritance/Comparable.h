#pragma once

class Comparable
{
public:
	Comparable();
	~Comparable();

	virtual int compare_to(const Comparable& rhs) = 0 {	return 0; };

};

