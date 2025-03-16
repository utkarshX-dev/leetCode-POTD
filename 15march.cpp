#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    private:
        bool isValid(int mid, vector<int>& nums, int k, int n) {
            int houses = 0;
            int i = 0;
            while (i < n) {
                if (nums[i] <= mid) {
                    houses++;
                    if (houses >= k)
                        return true;
                    i += 2;
                } else {
                    i++;
                }
            }
            return false;
        }
    
    public:
        int minCapability(vector<int>& nums, int k) {
            int n = nums.size();
            int result = -1;
            int l = *min_element(nums.begin(),nums.end());
            int r = *max_element(nums.begin(),nums.end());
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (isValid(mid, nums, k, n)) {
                    result = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return result;
        }
    };