// 2D Contribution Technique based approach

int Solution::solve(vector<vector<int> > &A) {
    int total = 0;
    int n = A.size();
    int m = A[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int top_left_ways = (i-0+1) * (j-0+1);
            int bottom_right_ways = (n-1-i+1) * (m-1-j+1);
            int count = top_left_ways * bottom_right_ways;
            int cur_contrib = count * A[i][j];
            total += cur_contrib;
        }
    }

    return total;
}
