class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int curSum = nums[0];
        int size = nums.size();
        for(int i =1; i<size; i++){
            curSum = max((curSum + nums[i]), nums[i]);//get the higher number between current Sum and, currentSum + nextIdxValue
            if(curSum > sum) //if the current new sum is higher than original sum, sum = currentSum
                sum = curSum;
        }
        return sum;
    }
};
