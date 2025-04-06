vector<int> Solution::solve(vector<int> &A) {
    for(int i=1;i<A.size();i++) {
        A[i] += A[i-1];
    }
    return A;
}
