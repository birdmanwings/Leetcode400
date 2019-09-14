#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (int i = 0; i < magazine.size(); i++) {
            m[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (m.find(ransomNote[i]) == m.end() || --m[ransomNote[i]] < 0) {   //注意这里要先减否则会判断不到
                return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}