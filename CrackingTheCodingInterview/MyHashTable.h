#pragma once
#include <map>
#include <list>
#include <functional>
using namespace std;
template< typename U, typename T>
// Not tested yet
class MyHashTable {
public:

	MyHashTable(function<int(U)> hashFunction) {
		this->_HashFunction = hashFunction;
	}

	~MyHashTable() {
		for (typename std::map<int, list<pair<U, T*>>*>::iterator iter = this->_dictionnary.begin();
			iter != this->_dictionnary.end(); ++iter)
		{
			delete iter->second;
			iter->second = nullptr;
		}
	}

	void Insert(U key, T* value) {
		int index = this->_HashFunction(key);
		typename std::map<int, list<pair<U, T>>*>::iterator it = this->_dictionnary.find(index);
		if (it == this->_dictionnary.end()) {
			this->_dictionnary.insert(index, new list<pair<U, T*>>());
		}
		this->_dictionnary[index]->push_back(value);
	}

	void Remove(U key) {
		int index = this->_HashFunction(key);
		typename std::map<int, list<pair<U, T*>>*>::iterator it = this->_dictionnary.find(index);
		if (it != this->_dictionnary.end()) {
			this->_dictionnary[index]->remove_if(isPresent(key));
		}
	}

	T* Get(U key) {
		int index = this->_HashFunction(key);
		typename std::map<int, list<pair<U, T*>>*>::iterator it = this->_dictionnary.find(index);
		if (it != this->_dictionnary.end()) {
			for (typename std::list<pair<U, T*>*>::iterator it2 = it->second->begin(); it2 != it->second->end(); ++it2) {
				if (it2->first == hey) {
					return it2->second;
				}
			}
		}
		return nullptr;
	}

	bool ContainsKey(U key) {
		int index = this->_HashFunction(key);
		typename std::map<int, list<pair<U, T*>>*>::iterator it = this->_dictionnary.find(index);
		return (it == this->_dictionnary.end());
	}

	list<pair<U, T*>>& operator[](U key) {
		int index = this->_HashFunction(key);
		typename std::map<int, list<pair<U, T*>>*>::iterator it = this->_dictionnary.find(index);
		if (it != this->_dictionnary.end()) {
			return it->second;
		}
	}

private:
	map<int,list<pair<U,T*>>*> _dictionnary;
	function<int(U)> _HashFunction;
	struct isPresent {
		bool operator() (const pair<U, T*>& value, U key) { return (value.first) == key; }
	};
};