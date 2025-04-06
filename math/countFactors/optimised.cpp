int Solution::solve(int A) {
    int count = 0;
    for(long i=1;i*i<=A;i++) {
        if(A%i==0) {
            if(i==A/i) {
                count += 1;
            }
            else {
                count += 2;
            }
        }
    }
    return count;
}
