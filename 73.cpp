#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (!matrix.size()) {
            return;
        }
        int N=matrix.size()-1,M=matrix[0].size()-1;
        unordered_map<int,int> n;
        unordered_map<int,int> m;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                if (matrix[i][j] == 0) {
                    n[i]++;
                    m[j]++;
                }
            }
        }
        for (int i = 0; i <= N; i++) {
            if (n[i]!=0) {
                for (int j = 0; j <= M; j++) {
                    matrix[i][j]=0;
                }
            }
        }
        for (int j = 0; j <= M; j++) {
            if (m[j] != 0) {
                for (int i = 0; i <= N; i++) {
                    matrix[i][j]=0;
                }
            }
        }
    }
};

int main() {

    return 0;
}