class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        sort(nums.rbegin(), nums.rend());//sort in descending order
        vector<int> even;
        for(int i = size-1; i >= size/2; i--){
            even.push_back(nums[i]);
            nums.pop_back();
        }
        sort(even.rbegin(), even.rend());
        for(int i = 0; i < size; i+= 2){
            nums.insert(nums.begin()+i, even[i/2]);
        }
    }
};
//with terrible time performance