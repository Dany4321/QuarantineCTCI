#include "MyStringBuilder.h";

MyStringBuilder::MyStringBuilder() {
	this->_last = nullptr;
	this->_root = nullptr;
	this->_size = 0;
}
MyStringBuilder::~MyStringBuilder() {
	this->Clear();
}

MyStringBuilder* MyStringBuilder::Append(string s) {
	if (this->_root == nullptr && this->_last == nullptr) {
		this->_root = new CustomString(s);
		this->_last = _root;
	}
	else {
		this->_last = this->_last->AddString(s);
	}
	this->_size += this->_last->GetSize();
	return this;
}

void MyStringBuilder::Clear() {
	CustomString* current = this->_root;
	while (current != nullptr) {
		CustomString* next = current->GetNext();
		delete current;
		current = nullptr;
		current = next;
	}
	this->_last = nullptr;
	this->_root = nullptr;
}
string MyStringBuilder::ToString() {
	CustomString* current = this->_root;
	char* finalString = new char[this->_size];
	int index = 0;
	if (current != nullptr) {
		while (current != nullptr) {
			string val = current->GetValue();
			for (char c : val) {
				finalString[index++] = c;
			}
			current = current->GetNext();
		}
		return string(finalString,this->_size);
	}
	return "";
}