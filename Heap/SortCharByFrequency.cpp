/*
Runtime: 8 ms, faster than 99.15% of C++ online submissions for Sort Characters By Frequency.
Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Sort Characters By Frequency.
:))))))))))
*/

//Used map, sort, copy and lambda function
class Solution {
public:
	string frequencySort(string s) {
		vector<int>dupCount(127, 0);
		int len = s.length();
		int i, j;
		for (i = 0; i < len; i++) {
			dupCount[s[i]]++;
		}
		int size = dupCount.size();

		map<int, int>ordered;
		for (i = 0; i < size; i++) {
			if (dupCount[i] > 0)
				ordered.insert({ i, dupCount[i] });
		}
		vector<pair<int, int>>vec;
		copy(ordered.begin(), ordered.end(), back_inserter<vector<pair<int, int>>>(vec));
		sort(vec.begin(), vec.end(), [](const pair<int, int>& lhs,
			const pair<int, int>& rhs) {
				if (lhs.second != rhs.second)
					return lhs.second > rhs.second;
				return lhs.first > rhs.first;
			});

		string sorted = "";
		for (auto it = vec.begin(); it != vec.end(); it++) {
			for (j = 0; j < it->second; j++) {
				sorted += it->first;
			}
		}
		return sorted;
	}
};