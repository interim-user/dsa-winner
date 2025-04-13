vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> arrA(A,0);

    for(int i=0;i<B.size();i++){
        int L = B[i][0];
        int R = B[i][1];
        int X = B[i][2];

        arrA[L-1] += X;
        if(R<arrA.size()) {
            arrA[R] -= X;
        }
    }

    for(int i=1;i<arrA.size();i++){
        arrA[i] += arrA[i-1];
    }

    return arrA;
}
