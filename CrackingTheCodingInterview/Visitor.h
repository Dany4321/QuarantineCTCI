#pragma once
#include <functional>
using namespace std;
template <typename T> class Visited;
template<typename T>
class Visitor {
public:
	Visitor() {

	}
	Visitor(function<void(Visited<T>*)> VisitFunction) {
		this->Visit = VisitFunction;
	}
	function<void(Visited<T>*)> Visit;
};