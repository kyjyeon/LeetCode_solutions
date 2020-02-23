class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		// sort the intervals
        sort(std::begin(intervals), std::end(intervals));
        
        vector<vector<int>> result {};
        
		// iterate through intervals
        for (const auto& i : intervals) {
			// check for intersection:
			// if current interval start value is smaller or equal to
			// the previous interval end value, they intersect 
            if (!result.empty() && i[0] <= result.back()[1]) {
                result.back()[1] = std::max(i[1], result.back()[1]);
            } else {
                result.emplace_back(i);
            }
        }
        
        return result;
    }
};
