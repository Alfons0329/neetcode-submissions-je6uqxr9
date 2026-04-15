/*
Intution: Use t to cecncel s


Approach:
    1. for char in s
        hash_map[char]++
    2. for char in t // cancel from the first one
        hash_map[char]--
    3. hash_map.empty() ??

Complexity:
    Time: O(len(s) + len(t)) since we iterate 2 stirngs, and hashmap insert / serach is O(1)
    Space: O(len(s)), insert on 1st string

*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq; // count char -> frequency
        // step 1
        for(char c : s) {
            freq[c]++;
        }

        // step 2
        for(char c : t) {
            freq[c]--;
            if (freq[c] == 0) {
                // remove that element as "cancel"
                freq.erase(c);
            } 
        }

        return freq.empty();
    }
};


/*
Dry run:
    s = "racecar", t = "carrace"
    // step 1
    r [<r, 1>]
    a [<r, 1>, <a, 1>]
    c [<r, 1>, <a, 1>, <c, 1>]
    e [<r, 1>, <a, 1>, <c, 1>, <e, 1>]
    c [<r, 1>, <a, 1>, <c, 2>, <e, 1>]
    a [<r, 1>, <a, 2>, <c, 2>, <e, 1>]
    r [<r, 2>, <a, 2>, <c, 2>, <e, 1>]
    
    // step 2, cancel
    c [<r, 2>, <a, 2>, <c, 1>, <e, 1>]
    a [<r, 2>, <a, 1>, <c, 1>, <e, 1>]
    r [<r, 1>, <a, 1>, <c, 1>, <e, 1>]
    r [(r removed), <a, 1>, <c, 1>, <e, 1>]
    a [(r removed), (a removed), <c, 1>, <e, 1>]
    c [(r removed), (a removed), (c removed), <e, 1>]
    e [(r removed), (a removed), (c removed), (e removed)]

    return true
    
    s = "jar", t = "jam"
    // step 1
    [<j, 1>, <a, 1>, <r, 1>]

    // step 2
    [<r, 1>]

    return false

*/
