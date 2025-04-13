int Solution::trap(const vector<int> &A) {
    vector<int> left_max(A.size());
    vector<int> right_max(A.size());

    for(int i=0;i<A.size();i++){
        if(i==0) left_max[i] = A[i];
        else {
            if(A[i] < left_max[i-1]) left_max[i] = left_max[i-1];
            else left_max[i] = A[i];
        }
    }

    for(int i=A.size()-1;i>=0;i--){
        if(i==A.size()-1) right_max[i] = A[i];
        else {
            if(A[i] < right_max[i+1]) right_max[i] = right_max[i+1];
            else right_max[i] = A[i];
        }
    }

    int total = 0;
    for(int i=0;i<A.size();i++){
        int cur_water_contrib = max(0, min(left_max[i],right_max[i]) - A[i]);
        total += cur_water_contrib;
    }

    return total;
}
