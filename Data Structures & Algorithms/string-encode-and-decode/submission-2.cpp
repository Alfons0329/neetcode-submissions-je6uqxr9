/*
Intuiton: Comma separator

Approach:
    Encode
    1. for str in strs:
        res += str + ','

    Decode
    1. for char in s
        if char is not ',' // keep conatenating current string
            substr += char
        else
            res.pb(substr) // finished string sepration

Complexity: 
    Time: O(M*N) since we iteratre through M strs with each of them maximum len is N
    Space: Same 

*/
class Solution {
public:

    string encode(vector<string>& strs) {
        string res("");

        int n = strs.size();
        for (string &str: strs) {
            res += (str + '\0');
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        string str("");
        for (char c : s) {
            if (c == '\0') {
            // separator, string deliminated 
                res.push_back(str);
                str.clear();
            } else {
                str += c;
            }
        }

        return res;
    }
};


/*
Dry run:

["Hello", "World"]
Encode:
    res += "hello" + ",", res = "hello,"
    res += "world", res = "hello,world,"   


Decode:
    s = "hello,world"

    c = hello -> str = "hello", res = []
    c = , -> str "hello", res = [str]
    c = world, -> str "world" res = [hello]
    c = , -> str "world" res = [hello, world]
*/