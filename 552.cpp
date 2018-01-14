/*
T(n) is the total number of all possible attendance records with length n.

P(n) possible ans, end with 'P'
A(n) possible ans, end with 'A'
L(n) possible ans, end with 'L'
T(n) = P(n)+A(n)+L(n)

P(n) = P(n-1)+A(n-1)+L(n-1)
A(n) = noAP(n-1)+noAL(n-1)
L(n) = P(n-1)+A(n-1)+P(n-2)+A(n-2)

noAP(n) = noAP(n-1)+noAL(n-1)
noAL(n) = noAP(n-1)+noAP(n-2)

A(n-1) = noAP(n-2)+noAL(n-2) = noAP(n-1)
A(n) = noAP(n-1)+noAL(n-1) = A(n-1) + noAP(n-2)+noAP(n-3) = A(n-1) + A(n-2) + A(n-3)

P(n) = P(n-1)+A(n-1)+L(n-1)
A(n) = A(n-1)+A(n-2)+A(n-3)
L(n) = P(n-1)+A(n-1)+P(n-2)+A(n-2)

n = 1, P[0] = A[0] = L[0] = 1
n = 2, A[1] = PA,LA = 2, L[1] = LL,AL,PL = 3
n = 3, A[2] = PPA,PLA,LPA,LLA = 4
*/
class Solution {
public:
    int checkRecord(int n) {
    	vector<int> P(n,0), A(n,0), L(n,0);
    	P[0] = A[0] = L[0] = 1;
    	P[1] = 3, A[1] = 2, L[1] = 3;
    	P[2] = 8, A[2] = 4, L[2] = 7;
    	const int m = 1000000007;
    	if (n<=3)
    		return P[n-1]+A[n-1]+L[n-1];
    	for (int i=3; i<n; i++){
    		A[i-1] %= m;
    		P[i] = ((P[i-1]+A[i-1])%m+L[i-1])%m;
    		A[i] = ((A[i-1]+A[i-2])%m+A[i-3])%m;
    		L[i] = ((P[i-1]+P[i-2])%m+(A[i-1]+A[i-2])%m)%m;
    	}
        return ((P[n-1]+A[n-1])%m+L[n-1])%m;
    }
};