class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (N == 1)//if size is 1, just return 1
            return 1;
        vector<vector<int>>trusted(N + 1); //labels that gained trust
        vector<bool>trusting(N + 1, false);//labels that are trusting other
        int size = trust.size();
        int i;
        for (i = 0; i < size; i++) {
            trusting[trust[i][0]] = true;
            trusted[trust[i][1]].push_back(trust[i][0]);
        }
        int len = trusted.size();
        for (i = 0; i < len; i++) {
            if (trusted[i].size() == N - 1) {//if there is a label that gained all other's trust
                if (trusting[i] == false)//And also that label is trusting no label
                    return i; // it is the town judge!!!
            }
        }

        return -1;
    }
};