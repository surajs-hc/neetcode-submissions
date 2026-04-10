class Solution {
private:
    const char DELIM = '#';
public:
    string encode(vector<string>& strs) {
        string builder = "";
        for (const auto& str : strs) {
            builder += to_string(str.size());
            builder += DELIM;
            builder += str;
        }
        return builder;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int ptr = 0;
        while (ptr < s.size()) {
            string num = "";
            while (s[ptr] != DELIM) {
                num += s[ptr];
                ++ptr;
            }
            ++ptr;
            int num_val = stoi(num);

            string builder = "";
            for (int lim = ptr + num_val; ptr < lim; ++ptr) {
                builder += s[ptr];
            }
            strs.push_back(builder);
        }

        return strs;
    }
};
