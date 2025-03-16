#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
    private: bool ispossible(long long mid , vector<int>& ranks, int cars){
        int n = ranks.size();
        int c = 0;
        for(int i = 0 ; i<n;i++){
            c += sqrt(mid/ranks[i]);
            if(c >= cars) return true;
        }
        return false;
    }
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            int minRank = *min_element(ranks.begin(), ranks.end());
            long long s = 0;
            long long e = (long long)minRank * cars * cars;
            long long ans = e;
            while(s<=e){
                long long mid = s+(e-s)/2;
                if(ispossible(mid,ranks,cars)){
                    ans = mid;
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            return ans;
        }
    };