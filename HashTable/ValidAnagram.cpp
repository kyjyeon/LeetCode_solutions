class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        else{
            
            int i;
            int len = s.length();
            if(len == 1){
                if(s[0] == t[0])
                    return true;
                else
                    return false;
            }
            vector<int>vec('z'- 'a' +1, 0);
            vector<int>compare('z'- 'a' +1, 0);
            int size = vec.size();
            for(i=0; i<len; i++){
                vec[s[i]-'a']++;
                compare[t[i]-'a']++;
            }
            for(i=0; i<size; i++){
                if(vec[i] != compare[i])
                    return false;
            }
        }
        
        return true;
    }
};
