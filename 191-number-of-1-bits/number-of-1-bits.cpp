class Solution {
public:
    int hammingWeight(int n) {
        uint32_t un = n; 
        int count = 0;
        while (un > 0) {
            un = un & (un - 1); 
            count++;
        }
        return count;
    }
};
