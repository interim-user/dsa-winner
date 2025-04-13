// TC: O(n*log(m))

int findLowerBound(vector<int>& arr, int val) {
    // printf("findLowerBound --");
    // returns the index for the first occurence of val in the array
    int s = 0, e = arr.size() - 1;
    while(s<=e) {
        int m = s + (e-s)/2;
        if(arr[m]==val) {
            // check if val exists to left as well
            if(m>0 && arr[m-1]==val) {
                e = m-1;
            } else {
                return m;
            }
        } else if(arr[m]>val) {
            // go left
            e = m-1;
        } else {
            // go right
            s = m+1;
        }
    }

    return -1;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int ans_count = -1;
    int ans_row = INT_MIN;
    for(int i=0;i<n;i++){
        int lb = findLowerBound(A[i], 1);
        int cur = 0;
        if(lb != -1) {
            cur = ((n-1)-(lb))+1;
        } 
        // printf("cur = %d, ",cur);
        if(cur>ans_count) {
            ans_count = cur;
            ans_row = i;
        }
    }
    return ans_row;
}
