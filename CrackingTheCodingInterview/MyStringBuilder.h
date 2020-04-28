#pragma once
#include <string>
using namespace std;
class MyStringBuilder {
public :
	MyStringBuilder();
	~MyStringBuilder();
	void Append(string s);
	string ToString();
	void Clear();
private:
	class CustomString {
		public:
			CustomString(string s) {
				this->_value = s;
				this->_size = this->_value.length();
			}
			CustomString* AddString(string s) {
				this->_next = new CustomString(s);
				return this->_next;
			}
			int GetSize() {
				return this->_size;
			}
			CustomString* GetNext() {
				return this->_next;
			}
			string GetValue() const{
				return this->_value;
			}
		private:
			string _value;
			int _size = 0;
			CustomString* _next = nullptr;
	};
	int _size = 0;
	CustomString* _root;
	CustomString* _last;
	friend class TestStringBuilder;
};