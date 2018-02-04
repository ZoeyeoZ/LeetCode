class Solution {
public:
	bool isvalid(int x, int y, int m, int n){
		return x >= 0 && x < m && y >= 0 && y < n;
	}
	//DFS
	void helper(vector<vector<char>>& board, int x, int y){
		int m = board.size(), n = board[0].size();
		if (!isvalid(x,y,m,n))
			return;
		vector<vector<int>> moves = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
		int cnt = 0;
		if (board[x][y]=='E'){
			for (auto move:moves)
				if (isvalid(x+move[0],y+move[1],m,n) && board[x+move[0]][y+move[1]]=='M')
					cnt++;
			if (cnt>0)
				board[x][y] = '0'+cnt;
			else {
				board[x][y] = 'B';
				for (auto move:moves)
					helper(board, x+move[0], y+move[1]);
			}
		}
	}
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    	if (board[click[0]][click[1]]=='M'){
    		board[click[0]][click[1]]='X';
    		return board;
    	}
    	helper(board,click[0],click[1]);
    	return board;
    }
};
/*22
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        const int m = board.size();
        if( !m )
            return board;
        const int n = board[0].size();
        if( !n )
            return board;
        
        if( board[click[0]][click[1]] == 'M' ){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        queue<int> q;
        q.push( click[0] * n + click[1] );
        
        unordered_set<int> visited;
        visited.insert( click[0] * n + click[1] );
        
        while( q.size() ){
            auto t = q.front();
            q.pop();
            
            int i = t / n;
            int j = t % n;
            
            int bomb = 0;
            for( int a = -1 ; a <= 1 ; ++a ){
                for( int b = -1 ; b <= 1 ; ++b ){
                    if( a == 0 && b == 0 )
                        continue;
                    
                    int ni = i + a;
                    int nj = j + b;
                    if( ni < 0 || ni >= m || nj < 0 || nj >= n )
                        continue;
                    bomb += board[ni][nj] == 'M';
                }
            }
            
            if( !bomb ){
                board[i][j] = 'B';
                for( int a = -1 ; a <= 1 ; ++a ){
                    for( int b = -1 ; b <= 1 ; ++b ){
                        if( a == 0 && b == 0 )
                            continue;

                        int ni = i + a;
                        int nj = j + b;
                        if( ni < 0 || ni >= m || nj < 0 || nj >= n || board[ni][nj] != 'E' )
                            continue;
                        if( visited.count( ni * n + nj ) == 0 ){
                            q.push( ni * n + nj );
                            visited.insert( ni * n + nj );
                        }
                    }
                }
            }else
                board[i][j] = '0' + ( bomb );
        }
        return board;
    }
};
*/