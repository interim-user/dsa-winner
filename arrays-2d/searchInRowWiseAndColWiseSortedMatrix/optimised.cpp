int Solution::solve(vector<vector<int> > &A, int B) {
    // start from the top right element
    int rows = A.size();
    int cols = A[0].size();

    int cur_row = 0;
    int cur_col = cols-1;

    int ans = -1;

    while(cur_row>=0 && cur_row<rows && cur_col>=0 && cur_col<cols) {
        int cur_element = A[cur_row][cur_col];
        if(B == cur_element) {
            // found
            ans = (cur_row+1)*1009 + (cur_col+1);

            // check for multiple occurences
            if(A[cur_row][cur_col-1] == B) {
                cur_col--;
            } else {
                break;
            }
        } else if(B > cur_element) {
            // go down
            cur_row++;
        } else {
            // go left
            cur_col--;
        }
    }

    return ans;
}
