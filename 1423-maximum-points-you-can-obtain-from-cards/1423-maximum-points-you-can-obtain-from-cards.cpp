class Solution {
public:
    using VI = vector<int>;
    int maxScore(VI& A, int K) {
        int N = A.size(),
            i = 0,
            j = N - K;
        auto total = accumulate(A.begin() + j, A.end(), 0),
             best = total;
        while (K--){
            total-=A[j++];
            total+=A[i++];
            best=max(best,total);
        }  // slide window by K \U0001f449
        return best;
    }
};