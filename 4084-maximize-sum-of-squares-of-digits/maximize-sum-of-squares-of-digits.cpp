class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       if (sum > num * 9) {
            return "";
        }
        string result = "";
        // Calculate how many 9s we can use
        int count9 = sum / 9;
        int remainder = sum % 9;
        result.append(count9, '9');
        if (remainder > 0) {
            result += to_string(remainder);
        }
        int remainingZeros = num - result.length();
        if (remainingZeros > 0) {
            result.append(remainingZeros, '0');
        }
        return result; 
    }
};