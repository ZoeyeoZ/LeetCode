/**
 * @param {number} m
 * @param {number} n
 * @param {number} N
 * @param {number} i
 * @param {number} j
 * @return {number}
 */
var findPaths = function(m, n, N, i, j) {
	var dp = new Array();
	var k1 = 0, k2 = 0;
	for (var k = 0; k < 2; k++){
		dp[k] = new Array();
		for (var ii = 0; ii < m; ii++){
			dp[k][ii] = new Array();
			for (var jj = 0; jj < n; jj++)
				dp[k][ii][jj] = 0;
		}
	}
	for (var k = 0; k < N; k++)
		for (var ii = 0; ii < m; ii++)
			for (var jj = 0; jj < n; jj++){
				k1 = k % 2;
				k2 = 1 - k1;
				dp[k1][ii][jj] = ((((ii==0 ? 1 : dp[k2][ii-1][jj])
								 + (ii==m-1 ? 1 : dp[k2][ii+1][jj])) % 1000000007
								 + (jj==0 ? 1 : dp[k2][ii][jj-1])) % 1000000007
								 + (jj==n-1 ? 1 : dp[k2][ii][jj+1])) % 1000000007;
			}
    return dp[k1][i][j];
};
  
console.log(findPaths(10,10,0,5,5));	  
//console.log(findPaths(1,3,3,0,1));	
