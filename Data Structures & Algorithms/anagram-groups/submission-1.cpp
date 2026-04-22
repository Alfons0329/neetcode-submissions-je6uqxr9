/*
Intution: Encode string to char+freq, like apple be a1e1l1p2 then other with the same encode can be considered as anagram

Approach:
    1. Encode string
    2. Check if encoded string present
    3. Same endcoded string can be considered same 

Complexity:
    Time: O(str.size()), iterate all string and encode by each, or actually O(total len of chars)
    Space: Auxiliary anagram structure, same O(str.size() + 26), O(str.size())
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
