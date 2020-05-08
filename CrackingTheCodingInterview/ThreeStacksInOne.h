#pragma once
#include "MyArray.h"
using namespace std;
template<class T>
class ThreeStacksInOne {
public:
	ThreeStacksInOne() {
		this->_array = new T[this->_capacity];
	}
	~ThreeStacksInOne() {
		delete[] this->_array;
	}
	void Push1(T value) {
		if (_idx1 + 3 >= this->_capacity) {
			this->ReallocateArray();
		}
		_idx1 += 3;
		this->_array[_idx1] = value;
	}
	void Push2(T value) {
		if (_idx2 + 3 >= this->_capacity) {
			this->ReallocateArray();
		}
		_idx2 += 3;
		this->_array[_idx2] = value;
	}
	void Push3(T value) {
		if (_idx3 + 3 >= this->_capacity) {
			this->ReallocateArray();
		}
		_idx3 += 3;
		this->_array[_idx3] = value;
	}
	T Top1() {
		return this->_array[this->_idx1];
	}
	T Top2() {
		return this->_array[this->_idx2];
	}
	T Top3() {
		return this->_array[this->_idx3];
	}
	void Pop1() {
		if (this->_idx1 - 3 >= -3) {
			this->_idx1 -= 3;
		}
	}
	void Pop2() {
		if (this->_idx2 - 3 >= -2) {
			this->_idx2 -= 3;
		}
	}
	void Pop3() {
		if (this->_idx3 - 3 >= -1) {
			this->_idx3 -= 3;
		}
	}
	bool IsEmpty1() {
		return this->_idx1 < 0;
	}
	bool IsEmpty2() {
		return this->_idx2 < 1;
	}
	bool IsEmpty3() {
		return this->_idx3 < 2;
	}
private:
	void ReallocateArray() {
		
		T* tmp = new T[this->_capacity * 2];
		for (int i = 0; i < this->_capacity; i++) {
			tmp[i] = this->_array[i];
		}
		this->_capacity *= 2;
		delete[] this->_array;
		this->_array = tmp;
	}
	T* _array;
	int _capacity = 3;
	int _idx1 = -3;
	int _idx2 = -2;
	int _idx3 = -1;
};