//Similar to Q473 Matchsticks to Square
class Solution {//1000ms
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //similar to Q473 Matchsitcks to Square
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k != 0)return false;
        int target = sum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> visited(nums.size(), false);
        return backtrack(nums, visited, target, 0, 0, k);
    }
private:
    bool backtrack(vector<int>& nums, vector<bool>& visited, int target, int cur_sum, int index, int k){
        if(k == 1)return true;//base case 1, since we already kno sum %k =0;
        if(index >= nums.size())return false;
        if(cur_sum == target){
            return backtrack(nums, visited, target, 0, 0, k-1);
        }
        for(int i = index; i < nums.size(); i++){
            if(visited[i] == true || nums[i] + cur_sum > target)continue;

            visited[i] = true;
            if(backtrack(nums, visited, target, cur_sum + nums[i], i+1, k))return true;
            visited[i] = false;
        }
        return false;
    }
};

//better version, 13ms
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend()); // sort in non-ascending order
        vector<int> groups(k, 0);
        return dfs(nums, groups, 0, target);
    }
    
    bool dfs(vector<int>& nums, vector<int>& groups, int idx, int target) {
        if (idx == nums.size()) {
            for (int i = 0; i < groups.size(); i++) {
                if (groups[i] != target) {
                    return false;
                }
            }
            return true;
        }
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] + nums[idx] <= target) {
                groups[i] += nums[idx];
                if (dfs(nums, groups, idx+1, target)) {
                    return true;
                }
                groups[i] -= nums[idx];
            }
            if (groups[i] == 0) {
                // early termination: if a group is empty, then it cannot be filled
                break;
            }
        }
        return false;
    }
};