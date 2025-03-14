class Solution {
    private:
        bool isValid(vector<int>& candies, int mid, int n, long long k) {
            for (int i = 0; i < n; i++) {
                k -= candies[i] / mid;
                if (k <= 0)
                    return true;
            }
            return false;
        }
    
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int n = candies.size();
            long long totalCandies = 0;
            int ans = 0;
            int s = 1;
            int e = 0;
    
            for (int i = 0; i < n; i++) {
                totalCandies += candies[i];
                e = max(e, candies[i]);
            }
    
            if (totalCandies < k)
                return 0;
                
            //T.c   = (NLog(Maxcandies));
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (isValid(candies, mid, n, k)) {
                    ans = mid;
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
            return ans;
        }
    };