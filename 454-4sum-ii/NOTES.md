class Solution {
public:
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
int count = 0;
unordered_map<int,int> sumAB;
for(int a : A) for(int b : B) sumAB[a + b]++;
for(int c : C) for(int d : D) count += sumAB[0-c-d];
return count;
}
};