class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        E = [0]*len(A)
        O = [0]*len(A)

        for i in range(len(A)):
            if i==0:
                E[i]=A[i]
                continue
            elif i==1:
                O[i]=A[i]
                continue
            else:
                if(i%2==0):
                    E[i]=A[i]+E[i-2]
                    O[i]=O[i-1]
                else:
                    O[i]=A[i]+O[i-2]
                    E[i]=E[i-1]

        special_indices_count = 0
        for i in range(len(A)):
            # at each i, we see what happens if,
            # the ith index element was removed from A 
            sum_even_before_i = E[i-1]
            sum_even_after_i = O[len(A)-1] - O[i]
            s_e = sum_even_after_i + sum_even_before_i

            sum_odd_before_i = O[i-1]
            sum_odd_after_i = E[len(A)-1] - E[i]
            s_o = sum_odd_after_i + sum_odd_before_i

            if s_e == s_o:
                special_indices_count += 1
        
        return special_indices_count
