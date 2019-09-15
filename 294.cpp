#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canWin(string s) {    //朴素递归回溯
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+' && !canWin(s.substr(0, i - 1) + "--" + s.substr(i + 1))) {
                return true;
            }
        }
        return false;
    }
};
/*
class Solution {    //记录中间结果
public:
    bool canWin(string s) {    //记录中间结果，39MS
        int len=s.size();
        if(len<=1) return false;
        if(Memory_Map.find(s)!=Memory_Map.end()) {
            return Memory_Map[s];
        }
        for(int i=0;i<len-1;i++) {
            string tmp=s;
            if(s[i]=='+'&&s[i+1]=='+') {
                tmp[i]='-';tmp[i+1]='-';
                bool f=canWin(tmp);
                if(!f) {
                    Memory_Map[s]=true;
                    return true;
                }
            }
        }
        Memory_Map[s]=false;
        return false;
    }
private:
    unordered_map<string,bool> Memory_Map;
};
 */
int main() {
    return 0;
}