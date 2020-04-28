/*#include "MyArray.h"
#include <exception>
using namespace std;
template<class T>
MyArray<T>::MyArray<T>() {
	this->_array = new T[1];
	this->_size = 1;
	this->_capacity = 1;
}

template<class T>
MyArray<T>::~MyArray<T>() {
	delete[] this->_array;
}

template<class T>
void MyArray<T>::ReallocateArrayIfNeeded() {
	if (this->_size == this->_capacity) {
		this->_capacity *= 2;
		T* tmp = new T[this->capacity];
		for (int i = 0; i < this->_capacity / 2; i++) {
			tmp[i] = this->_array[i];
		}
		delete[] this->_array;
		this->_array = tmp;
	}
}

template<class T>
void MyArray<T>::Add(T element) {
	this->ReallocateArrayIfNeeded();
	this->_array[++(this->_size)] = element;
}

template<class T>
int MyArray<T>::GetSize() const{
	return this->_size;
}

template<class T>
int MyArray<T>::GetCapacity() const {
	return this->_capacity;
}

template<class T>
void MyArray<T>::RemoveAt(int index) {
	if (this->_size > index && index >=0) {
		for (int i = index+1; i < this->_size; i++) {
			this->_array[i-1] = this->_array[i];
		}
		--this->_size;
	}
}

template<class T>
void MyArray<T>::InsertAt(T element, int index) {
	if (index < this->_size) {
		this->ReallocateArrayIfNeeded();
		for (int i = this->_size -2; i>= index; i--) {
			this->_array[i+1] = this->_array[i];
		}
		this->_array[index] = element;
	}
	else {
		throw  std::invalid_argument("Index out of bounds");
	}
}

template<class T>
int&  MyArray<T>::operator[](int index) {
	return this->_array[index];
}
*/