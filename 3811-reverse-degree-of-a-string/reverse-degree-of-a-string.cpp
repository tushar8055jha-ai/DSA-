class Solution {
public:
    int reverseDegree(string s) {
        int totalSum = 0;
        for (int i = 0; i < s.length(); i++) {
            int charValue = 26 - (s[i] - 'a');
            int position = i + 1; 
            totalSum += (long long)charValue * position;
        }
        return totalSum;
    }
};