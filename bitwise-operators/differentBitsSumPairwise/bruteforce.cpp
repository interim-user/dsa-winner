#define MOD_VAL 1000000007

int countDiffBits(int val1, int val2) {
    int count = 0;
    while(val1 || val2) {
        if((val1&1) != (val2&1)) count++;
        val1>>=1;
        val2>>=1;
    }
    // printf("%d", count);
    return count;
}

int Solution::cntBits(vector<int> &A) {
    int sum = 0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
            // printf("%d, %d -> ", A[i], A[j]);
            sum = ( sum % MOD_VAL + countDiffBits(A[i],A[j]) % MOD_VAL ) % MOD_VAL;
            // printf(" , ");
        }
    }
    return sum;
}
