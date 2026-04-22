/*
Intution: Use hashmap to check if 2 strings are anagram to each other

Approach:
    1. str in strs
        1. if anagram with res[i][0] -> append
        2. else res.pb({str})

Complexity:
    Time: O(strs.size() * max(str[i].size())), iterate all string and through hashmap
    Space: Worst case, all of them not anagram to each other, then in different hashmap, O(strs.size() * max(str[i].size())
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> anagram;

        for (string &str : strs) {
            const string fStr = convertFreqStr(str);
            anagram[fStr].push_back(str);
        }

        for (auto it : anagram) {
            res.push_back(it.second);
        }

        return res;
    }

    // convert stop to p1o1s1t1 encoded
    string convertFreqStr(const string& s) {
        int freq[26] = {0};
        // anagram if <char -> freq> is the same
        for (char c : s) {
            freq[c - 'a']++;
        }

        string freqStr;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) {
                continue;
            }
            freqStr.append(1, i + 'a');
            freqStr.append(to_string(freq[i]));
        }

        return freqStr;
    }
};
