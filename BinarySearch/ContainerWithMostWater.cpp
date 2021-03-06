//Reference
int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}



//My code(Wrong Answer)
//(Maybe was thinking too much... Thought I had to consider a lot about the width size also... Making codes too complicated...)
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 2)
            return min(height[0], height[1]);
        
        int size = height.size();
        int left = 0;
        int right = size-1;
        int curWater = (size-1)*min(height[left], height[right]);
        int leftChanged = false;
        int rightChanged = false;
        int leftCheck = 1;
        int rightCheck = 1;
        int newWater=0;
        while(right-rightCheck > left+leftCheck){
            if(height[left+leftCheck] >= height[left]+leftCheck){
                leftChanged = true;
                newWater = max(newWater, (right-left+1) * min(height[left+1] , height[right]));
            }
            if(height[right-rightCheck] >= height[right]+rightCheck){
                if(right-rightCheck != left){
                    rightChanged = true;
                    curWater = max(newWater, (right-1-left) * min(height[left] , height[right-1]));
                }
            }
            if(leftChanged == false || rightChanged == false){
                if(leftChanged == false)
                    leftCheck++;
                if(rightChanged == false)
                    rightCheck++;
            }
            if(leftChanged == true || rightChanged == true){
                if(leftChanged == true){
                    leftChanged = false;
                    ++left;
                    leftCheck = 1;
                }
                if(rightChanged == true){
                    rightChanged = false;
                    ++right;
                    rightCheck = 1;
                }
                curWater = max(curWater, newWater);
            }
            
        }
        return curWater;
    }
};
