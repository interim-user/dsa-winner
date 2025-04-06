string Solution::solve(vector<int> &A) {
    int c = 0;
    for(int num: A) {
        if(num&1) c++;
    }
    return c&1 ? "No" : "Yes";
}
