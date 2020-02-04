//My solution (Accepted but didn't use binary search)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i, duplicate;
        int size = nums.size();
        vector<int>vec(size + 1, 0);
        for (i = 0; i < size; i++) {
            vec[nums[i]]++;
        }
        for (i = 0; i < size; i++) {
            if (vec[i] > 1)
                duplicate = i;
        }
        return duplicate;
    }
};



//proper solution (reference)
int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1;
    int low = 1;
    int high = n;
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        int count = 0;
        for (int num : nums) {
            if (num <= mid) count++;
        }
        if (count > mid) high = mid;
        else low = mid + 1;
    }
    return low;
}