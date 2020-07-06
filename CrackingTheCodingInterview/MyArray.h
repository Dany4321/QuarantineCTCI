#ifndef MyArray_H
#define MyArray_H
using namespace std;
template<class T>
class MyArray {
public:
	MyArray() {
		this->_array = new T[1];
		this->_size = 0;
		this->_capacity = 1;
	}
	~MyArray() {
		delete[] this->_array;
	}
	void Add(T element) {
		this->ReallocateArrayIfNeeded();
		this->_array[(this->_size)++] = element;
	}
	void RemoveAt(int index) {
		if (this->_size > index && index >= 0) {
			for (int i = index + 1; i < this->_size; i++) {
				this->_array[i - 1] = this->_array[i];
			}
			--this->_size;
		}
	}
	void RemoveFirst(T value) {
		for (int i = 0; i < this->_size; i++) {
			if (this->_array[i] == value) {
				this->RemoveAt(i);
				return;
			}
		}
	}
	void InsertAt(T element, int index) {
		if (index < this->_size && index >=0) {
			this->ReallocateArrayIfNeeded();
			for (int i = this->_size - 2; i >= index; i--) {
				this->_array[i + 1] = this->_array[i];
			}
			this->_array[index] = element;
		}
		else {
			throw  std::invalid_argument("Index out of bounds");
		}
	}
	T& operator[](int index) {
		return this->_array[index];
	}
	int GetSize() const {
		return this->_size;
	}
	int GetCapacity() const {
		return this->_capacity;
	}
private:
	T* _array;
	int _size;
	int _capacity;
	void ReallocateArrayIfNeeded() {
		if (this->_size == this->_capacity) {
			this->_capacity *= 2;
			T* tmp = new T[this->_capacity];
			for (int i = 0; i < this->_capacity / 2; i++) {
				tmp[i] = this->_array[i];
			}
			delete[] this->_array;
			this->_array = tmp;
		}
	}
};
#endif
