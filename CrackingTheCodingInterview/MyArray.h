#pragma once
using namespace std;
template<typename T>
class MyArray {
public:
	MyArray();
	~MyArray();
	void Add(T elem);
	void RemoveAt(int index);
	void InsertAt(T element, int index);
	int& operator[](int index);
	int GetSize() const;
	int GetCapacity() const;
private:
	T* _array;
	int _size;
	int _capacity;
	void ReallocateArrayIfNeeded();
};