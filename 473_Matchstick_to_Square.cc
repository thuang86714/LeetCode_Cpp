//https://leetcode.com/problems/matchsticks-to-square/solutions/1273756/c-simple-and-clean-backtracking-commented-solution/
//a more practical solution
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4)return false;
        int sideLen = sum/4;
        int n = matchsticks.size();
        vector<bool> visited(n, false);
        sort(matchsticks.begin(), matchsticks.end());
        return backtrack(matchsticks, visited, sideLen, 0, 0, 4);
    }
private:
    bool backtrack(vector<int>& matchsticks, vector<bool>& visited, int target, int cur_sum, int index, int k){//k is the number of unfound subsets
        if(k == 1)return true;//k == 1 we have found all subsets
        if(cur_sum == target){
            return backtrack(matchsticks, visited, target, 0, 0, k-1);
        }
        for(int i = index; i < matchsticks.size(); i++){
            if(visited[i] || cur_sum + matchsticks[i] > target)continue;

            visited[i] = true;
            //we know that cur_sum + matchstick[j] <= target, but would this pick result in 4 equal subsets, do backtrack to find out
            if(backtrack(matchsticks, visited, target, cur_sum + matchsticks[i], i+1, k))return true;
            visited[i] = false;
        }
        return false;
    }
};

//the following solution leverage bitwise operation && DP 
https://leetcode.com/problems/matchsticks-to-square/solutions/95746/c-bit-masking-dp-solution-with-detailed-comments/
class Solution {
public:
    bool makesquare(vector<int>& nums) {
    int n = nums.size();

    long sum = accumulate(nums.begin(), nums.end(), 0l);
    if (sum % 4)
        return false;
    long sideLen = sum / 4;
    // need to solve the problem of partitioning nums into four equal subsets each having
    // sum equal to sideLen
    vector<int> usedMasks;
    // validHalfSubsets[i] == true iff the subset represented by bitmask i
    // has sum == 2*sideLen, AND the subset represented by i can be further partitioned into
    // two equal subsets. See below for how it is used.
    vector<bool> validHalfSubsets(1<<n, false);

    // E.g., if n = 5, (1 << 5 - 1) = 11111 represents the whole set
    int all = (1 << n) - 1;
    // go through all possible subsets each represented by a bitmask
    for (int mask = 0; mask <= all; mask++) {
        long subsetSum = 0;
        // calculate the sum of this subset
        for (int i = 0; i < 32; i++) {
	        if ((mask >> i) & 1)
		    subsetSum += nums[i];
        }
	    // if this subset has what we want
	    if (subsetSum == sideLen) {
	        for (int usedMask : usedMasks) {
	        // if this mask and usedMask are mutually exclusive
	            if ((usedMask & mask) == 0) {
		    // then they form a valid half subset whose sum is 2 * sideLen,
                    // that can be further partitioned into two equal subsets (usedMask and mask)
		        int validHalf = usedMask | mask;
		        validHalfSubsets[validHalf] = true;
		    // if in the past we concluded that the other half is also a valid
		    // half subset, DONE!
		        if (validHalfSubsets[all ^ validHalf])
		            return true;
	            }
            }
	    usedMasks.push_back(mask);
        }
    }
    return false;
}
};