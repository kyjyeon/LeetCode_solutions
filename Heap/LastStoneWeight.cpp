//First time to get 100% memory, 100% runtime by own code... :)))))))))
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end()); //sort stones by ascending order
        int xStone, yStone;
        while (1) {
            if (stones.size() == 1)
                return stones[0];
            if (stones.size() == 0)
                break;
            //Get x,y stone and use pop_back() to erase top 2 heaviest stones
            xStone = stones.back();
            stones.pop_back();
            yStone = stones.back();
            stones.pop_back();
            //if the weight is not same, use push_back() and abs() to push x-y absolute integer stone
            if (xStone != yStone)
                stones.push_back(abs(xStone - yStone));
            //sort the stones again to put newly pushed stone into proper location
            sort(stones.begin(), stones.end());
        }

        return 0;
    }
};