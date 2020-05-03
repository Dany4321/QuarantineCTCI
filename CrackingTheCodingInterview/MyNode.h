#pragma once
template<class T>
class MyNode {
public:
	MyNode(T value) :_value(value) {

	}
	~MyNode() {
		this->_next = nullptr;
		this->_previous = nullptr;
	}
	MyNode* GetNext() const {
		return this->_next;
	}
	MyNode* GetPrevious() const {
		return this->_previous;
	}
	void SetNext(MyNode* node) {
		this->_next = node;
	}
	void SetPrevious(MyNode* node) {
		this->_previous = node;
	}
	T GetValue()const {
		return _value;
	}
	void SetValue(T value) {
		this->_value = value;
	}
	bool HasNext() {
		return (this->_next != nullptr);
	}
	bool HasPrevious() {
		return (this->_previous != nullptr);
	}
private:
	T _value;
	MyNode* _next = nullptr;
	MyNode* _previous = nullptr;
};