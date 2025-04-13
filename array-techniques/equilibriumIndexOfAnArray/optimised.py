class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        pre = [0]*len(A)
        suf = [0]*len(A)

        pre[0] = A[0]
        for i in range(1,len(A)):
            pre[i] = pre[i-1] + A[i]
        
        suf[len(A)-1] = A[len(A)-1]
        for i in range(len(A)-2,-1,-1):
            suf[i] = suf[i+1] + A[i]
        
        for i in range(len(A)):
            if i==0:
                if suf[i+1] == 0:
                    return 0
            elif i==len(A)-1:
                if pre[i-1] == 0:
                    return len(A)-1
            else:
                if pre[i-1] == suf[i+1]:
                    return i

        return -1
