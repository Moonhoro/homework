class Solution {
public:
    string join(vector<string>& words) {
        string ret = "";
        for (auto &s : words) {
            ret += s;
        }
        return ret;
    }
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
return join(word1)==join(word2);
    }
};