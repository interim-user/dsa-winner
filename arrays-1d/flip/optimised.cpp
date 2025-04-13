// Kadane's algo based approach

vector<int> Solution::flip(string A) {
    int curSum = 0, maxSum = 0, l = 0, r = 0;
    vector<int> ans;

    for(int i=0;i<A.length();i++){
        A[i] == '1' ? --curSum : ++curSum ;
        if(curSum > maxSum) {
            maxSum = curSum;
            if(ans.size()>0) {
                ans[0] = l+1; // +1, as answer is required in 1-based indexing
                ans[1] = r+1;
            } else {
                ans.push_back(l+1);
                ans.push_back(r+1);
            }
        }

        if(curSum<0) {
            curSum = 0;
            l = i+1;
            r = i+1;
        } else {
            r++;
        }
    }

    return ans;
}
