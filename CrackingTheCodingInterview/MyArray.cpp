#include "MyArray.h"
#include <exception>
using namespace std;
template<typename T>
MyArray<T>::MyArray<T>() {
	this->_array = new T[1];
	this->_size = 1;
	this->_capacity = 1;
}

template<typename T>
MyArray<T>::~MyArray<T>() {
	delete[] this->_array;
}

template<typename T>
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

template<typename T>
void MyArray<T>::Add(T element) {
	this->ReallocateArrayIfNeeded();
	this->_array[++(this->_size)] = element;
}

template<typename T>
int MyArray<T>::GetSize() const{
	return this->_size;
}

template<typename T>
int MyArray<T>::GetCapacity() const {
	return this->_capacity;
}

template<typename T>
void MyArray<T>::RemoveAt(int index) {
	if (this->_size > index && index >=0) {
		for (int i = index+1; i < this->_size; i++) {
			this->_array[i-1] = this->_array[i];
		}
		--this->_size;
	}
}

template<typename T>
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

template<typename T>
int&  MyArray<T>::operator[](int index) {
	return this->_array[index];
}