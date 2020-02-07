//reference
//first time learning how to use sort std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;//use unordered map to categorize anagrams
        for (string s : strs) {//
            string t = s; //keep the original label of spelling before sorting in t variable
            sort(t.begin(), t.end());//sort each word as ascending order
            mp[t].push_back(s);//ex- aet : [eat, tea, ate]
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) {
            anagrams.push_back(p.second);//get unordered_map elements to put it in vector
        }
        return anagrams;
    }
};