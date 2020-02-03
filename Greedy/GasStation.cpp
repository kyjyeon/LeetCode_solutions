class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length = gas.size();
        for (int i = 0; i < length; i++) {
            int tank = gas[i];
            if (tank - cost[i] < 0)//if moving to another point is impossible, continue
                continue;
            int start = i;
            int travel = 0;
            int count = 0;
            int curIndex = 0;
            while (count <= length) {
                curIndex = (start + count) % length;
                travel = (start + count + 1) % length;
                tank = tank - cost[curIndex];
                if (tank < 0)
                    break;
                else {
                    if (count == length && tank >= 0) //if the all circled and the tank gas is not minus, return the start index
                        return start;
                    tank = tank + gas[travel];
                }
                ++count;
            }
        }
        return -1;
    }
};