/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

 

Example 1:

Input: a = 2, b = [3]
Output: 8
Example 2:

Input: a = 2, b = [1,0]
Output: 1024*/
//fentoyal
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(a == 1 || b.empty())return 1;
        int last_digit = b.back();
        b.pop_back();
        return pow(superPow(a, b), 10)*pow(a, last_digit)%base;
    }
private:
    const int base = 1337;
    int pow(int a, int k){
        a %= base;
        int result =1;
        for(int i = 0; i < k; i++){
            result = (result*a)%base;
        }
        return result;
    }
};

//alternative, base on good old Euler theorem
int superPow(int a, vector<int>& b) {
    if (a % 1337 == 0) return 0; // this line could also be removed
    int p = 0;
    for (int i : b) p = (p * 10 + i) % 1140;
    if (p == 0) p += 1140;
    return power(a, p, 1337);
}
int power(int x, int n, int mod) {
    int ret = 1;
    for (x %= mod; n; x = x * x % mod, n >>= 1) if (n & 1) ret = ret * x % mod;
    return ret;
}