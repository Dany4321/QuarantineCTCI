#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "StringPermutationsSearch.h"

  void StringPermutationsSearch:: Search(string s, string b)
	{
		multimap<char, char> charMap;
		for (char c : s) 
		{
			charMap.insert(pair <char, char>(c, c));
		}
		vector<pair<int, int>> positions;
		multimap<char, char> tmpCharMap;
		for (int i = 0; i < b.length(); i++) 
		{
			tmpCharMap = charMap;
			typedef multimap<char, char>::iterator MapIt;
			pair<MapIt, MapIt> result = tmpCharMap.equal_range(b[i]);
			MapIt it = result.first;
			if (it->first == b[i])
			{
				tmpCharMap.erase(it);
				int j = i+1;
				pair<MapIt, MapIt> result2 = tmpCharMap.equal_range(b[j]);
				MapIt it2 = result2.first;
				while (j < b.length() && !tmpCharMap.empty() && (it2)->first == b[j])
				{
					tmpCharMap.erase(it2);
					++j;
					result2 = tmpCharMap.equal_range(b[j]);
					it2 = result2.first;
				}
				if (tmpCharMap.empty()) {
					positions.push_back(pair<int, int>(i, j - i ));
					i = j - 1;
				}
			}
		}
		for (int k = 0; k < positions.size(); k++) {
			cout << b.substr(positions[k].first, positions[k].second) << std::endl;
		}
	}