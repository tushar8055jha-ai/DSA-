class Solution {
private:
    void backtrack(int index, string& currentStr, string& digits, const vector<string>& mapping, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(currentStr);
            return;
        }
        int digit = digits[index] - '0';
        string letters = mapping[digit];
        for (char letter : letters) {
            currentStr.push_back(letter);                              
            backtrack(index + 1, currentStr, digits, mapping, result); 
            currentStr.pop_back();                                     
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result; 
        }
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string currentStr = "";
        backtrack(0, currentStr, digits, mapping, result);
        return result;
    }
};