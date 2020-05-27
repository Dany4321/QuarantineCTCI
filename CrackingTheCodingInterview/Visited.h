#pragma once
#include "Visitor.h"
template<class T>
class Visited {
protected:
	void Accept(Visitor<T> visitor) {
		visitor.Visit(this);
	}
};
