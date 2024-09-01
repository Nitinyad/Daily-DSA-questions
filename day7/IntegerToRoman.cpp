class Solution {
public:
    string intToRoman(int num) {
        // Define the values and their corresponding Roman numerals in descending order.
        vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };
        string ans = "";
        
        // Iterate over each value starting from the highest.
        for (const auto& [value, symbol] : values) {
            // Append the corresponding Roman numeral symbols while the value can be subtracted from num.
            while (num >= value) {
                ans += symbol;
                num -= value;
            }
        }
        
        return ans;
    }
};
