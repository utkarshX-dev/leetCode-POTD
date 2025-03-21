#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            vector<bool>flip(n,false);
            int res = 0;
            int flipCount = 0;
            for(int i=0; i<n; i++){
                if(i >= 3 && flip[i-3] == true) flipCount--;
                if(flipCount % 2 == nums[i]){
                    if(i + 3 > n) return -1;
                    flipCount++;
                    res++;
                    flip[i] = true;
                } 
            }
            return res;
        }
    };