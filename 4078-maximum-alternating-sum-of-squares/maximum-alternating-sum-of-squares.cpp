class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });
        long long maxScore = 0;
        int n = nums.size();
        int positiveTermsCount = (n + 1) / 2; 
        for (int i = 0; i < n; i++) {
            long long square = 1LL * nums[i] * nums[i];
            if (i < positiveTermsCount) {
                maxScore += square;
            } else {
                maxScore -= square;
            }
        }
        return maxScore;
    }
};