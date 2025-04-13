class Solution:
    # @param A : list of integers
    # @return a list of integers
    def solve(self, A):
        # prefix product
        P = [1] * len(A) 
        P[0] = A[0]
        for i in range(1,len(A)):
            P[i] = A[i]*P[i-1]

        # suffix product
        S = [1] * len(A)
        S[len(A)-1] = A[len(A)-1]
        for i in range(len(A)-2,-1,-1):
            S[i] = A[i] * S[i+1]

        R = [0] * len(A)

        for i in range(len(R)):
            if i==0:
                R[i] = S[i+1]
            elif i==len(R)-1:
                R[i] = P[i-1]
            else:
                R[i] = P[i-1] * S[i+1]
        
        # print(P,",,",S,"**",R)

        return R 

