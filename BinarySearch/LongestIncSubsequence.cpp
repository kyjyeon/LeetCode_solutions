int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);  //use auto to shorten iterator calling code
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];     //*it calls iterator current location
    }
    return res.size();
}


/*
The algo is O(nlogn) because lower_bound() is logarithmic on a sorted input. We keep our vector res sorted, so the search in dp is logarithmic.
Res is composed to be:
sorted
having a length of the longest found increasing sub-sequence
So it doesn't contain that subsequence. Only it's length is valid.
So what algo is doing? For each number we have 2 options:
if it's the highest found value, we push it back, since a high value obviously makes our increasing sequence longer
if it's not the highest found value, then it could be a nice start (or continuation) of a shorter sequence. And we keep that sequence in place. Merging all found and possible sequences into one dp
See how res is changing when we go through the numbers:

[1,2,7,8,3,4,5,9,0]
1 -> [1]
2 -> [1,2]
7 -> [1,2,7]
8 -> [1,2,7,8]
3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence we need only the last number and 1,2,3 is our new shorter sequence
4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but 4 has more chances for longer sequence
5 -> [1,2,3,4,5]
9 -> [1,2,3,4,5,9]
0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence
So in the end our res contains [0,2,3,4,5,9] which is not a found sequence, but it has the length of the valid answer = 6.
*/
