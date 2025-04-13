// Check notes for more details

int Solution::firstMissingPositive(vector<int> &A) {
    int ans;

    int N = A.size();

    // min possible answer = 1
    // max possible answer = N+1

    // range of possible answer = [1,N+1]
    // N+2 can't ever be the answer

    // normalize the array to contain only values in the range
    for(int i=0;i<N;i++){
        if(A[i]<=0) A[i] = N+2;
    }

    // Now, we can assume that in the input array, all the integers are positive.
    
    // So, we can use the -ve sign at index i to
    // denote that a particular positive integer (i+1) is present in the array
    for(int i=0;i<N;i++){
        int cur = abs(A[i]);
        if(cur>=1 && cur<=N) {
            A[cur-1] = abs(A[cur-1]) * -1;
        }
    }

    // Now, the lowest positive index will be the answer, as it is unmarked
    for(int i=0;i<N;i++){
        if(A[i] > 0) return i+1;
    }

    return N+1;
}
