/*
Intuition: use a long-enough array with fixed size to keep track object occurrence
Appraoch:
    bool arr[1000000] = {false} initially
    1. add() toggles arr[X] = true
    2. remove toggles arr[X] = false 
    3. contains returns arr[X]

Complexity
    Time:
        Add
        Remove
        Conraines all in O(1) constant time
    Space:
        O(1000000)


Problem:
    Too sparse, can we optimize ?
*/
#include <cstring>
#define MAX_LEN 1000000
class MyHashSet {
public:
    MyHashSet() {
        memset(arr, false, sizeof(arr));
    }
    
    void add(int key) {
        arr[key] = true;
    }
    
    void remove(int key) {
        arr[key] = false;
    }
    
    bool contains(int key) {
        return arr[key];
    }
private:
    bool arr[MAX_LEN];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */