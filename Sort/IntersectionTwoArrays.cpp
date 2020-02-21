//Reference
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s(nums1.begin(), nums1.end());   //Use set container to get keys from nums1 without duplicate
    vector<int> out;          //vector for intersection values
    for (int x : nums2) 
        if (s.erase(x))       //if a value from num2 vector can also be erased in s set
            out.push_back(x); //it means this value is an intersection between two arrays, so push_back the value to 'out' vector
    return out;
}
