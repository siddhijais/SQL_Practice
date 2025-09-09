class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> current;
        backtrack(0, s, current, result);
        return result;
    }

private:
    void backtrack(int start, const string& s, vector<string>& current, vector<string>& result) {
        // If we already have 4 parts
        if (current.size() == 4) {
            // If we've consumed the entire string → valid IP
            if (start == s.size()) {
                result.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
            }
            return;
        }

        // Try segments of length 1 to 3
        for (int len = 1; len <= 3; len++) {
            if (start + len > s.size()) break;

            string segment = s.substr(start, len);

            // Check if segment is valid
            if (isValid(segment)) {
                current.push_back(segment);
                backtrack(start + len, s, current, result);
                current.pop_back();  // backtrack
            }
        }
    }

    bool isValid(const string& seg) {
        // Can't have leading zeros unless segment is "0"
        if (seg.size() > 1 && seg[0] == '0') return false;

        // Must be <= 255
        int val = stoi(seg);
        return val >= 0 && val <= 255;
    }
};
