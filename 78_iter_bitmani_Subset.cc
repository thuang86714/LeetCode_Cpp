//credit to in-jianchao-li we trust;
/*
Iterative:
Using [1, 2, 3] as an example, the iterative process is like:

Initially, one empty subset [[]]
Adding 1 to []: [[], [1]];
Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
}; 
/*
Bit-Manipulation:
To give all the possible subsets, we just need to exhaust all the possible combinations 
of the numbers. And each number has only two possibilities: either in or not in a subset.
 And this can be represented using a bit.

Using [1, 2, 3] as an example, 1 appears once in every two consecutive subsets, 
2 appears twice in every four consecutive subsets, and 3 appears four times in every 
eight subsets (initially all subsets are empty):
[], [ ], [ ], [    ], [ ], [    ], [    ], [       ]
[], [1], [ ], [1   ], [ ], [1   ], [    ], [1      ]
[], [1], [2], [1, 2], [ ], [1   ], [2   ], [1, 2   ]
[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};