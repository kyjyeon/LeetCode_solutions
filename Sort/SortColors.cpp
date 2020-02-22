//Used classic quickSort
//Read statistically giving pivot index randomly is faster than fixing pivot location at a certain area
class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) { //check if size>1
            int pivot = left;
            int j = right;
            int i = left + 1;
            while (i <= j) { //loop until i,j crosses each other. If crossed that location is the new pivot
                while (i <= right && nums[i] <= nums[pivot])
                    i++;
                while (j > left&& nums[j] > nums[pivot])
                    j--;
                if (i < j)
                    swap(nums, i, j);
            }
            swap(nums, pivot, j);

            quickSort(nums, left, j - 1);
            quickSort(nums, j + 1, right);
        }
    }


    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};
