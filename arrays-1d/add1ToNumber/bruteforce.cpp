vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> result;

    int carry = 0;
    int addend = 1;
    for(int i=A.size()-1;i>=0;i--) {
        int cur_dig = (A[i] + addend + carry) % 10;
        carry = (A[i] + addend + carry) / 10;
        addend = 0;
        A[i] = cur_dig;
        result.push_back(cur_dig);
    }

    if(carry!=0) {
        result.push_back(carry);
    } else {
        int t = result.size()-1;
        while(t>=0 && result[t]==0) {
            result.pop_back();
            t--;
        }
    }

    reverse(result.begin(), result.end());

    return result;
}
