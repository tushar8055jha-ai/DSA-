class Solution {
public:
    int reverseBits(int n) {
        uint32_t un = n; 
        uint32_t res = 0;
        
        for (int i = 0; i < 32; ++i) {
            res <<= 1;          
            res |= (un & 1);    
            un >>= 1;         
        }
        
        return res;
        }
};