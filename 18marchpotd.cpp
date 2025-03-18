#include <bits/stdc++.h>
using namespace std;
//key concept of bit mask + sliding window 
//Usin XOR for shrinking window
class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int i = 0;
            int j = 0;
            int n = nums.size();
            int mask = 0;
            int result = 1;
            while (j < n) {
                while ((mask & nums[j]) != 0){
                    mask = mask^nums[i];
                    i++;
                }
                result = max(result, j - i + 1);
                mask = (mask | nums[j]);
                j++;
            }
            return result;
        }
    };