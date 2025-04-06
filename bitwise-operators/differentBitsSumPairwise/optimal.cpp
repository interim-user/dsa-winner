#define MOD_VAL 1000000007

int Solution::cntBits(vector<int> &A) {
    long long sum = 0; // long long to avoid overflow during multiplication

    for(int i = 0; i < 32; i++) {
        int count_ones = 0;
        for(int j = 0; j < A.size(); j++) {
            if((A[j] >> i) & 1) count_ones++;
        }
        int count_zeroes = A.size() - count_ones;

        long long cur_contrib = (2LL * count_ones * count_zeroes) % MOD_VAL;
        sum = (sum + cur_contrib) % MOD_VAL;
    }

    return (int)sum;
}
