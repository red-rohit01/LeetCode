class Solution {
public:
    // Time Complexity : O(9^(N*N)) : For every unassigned index there are 9 possible options so the worst-case time
    // complexity of sudoku solver is O(9^(N*N)).
    
    bool is_safe(int i,int j,int val,vector<vector<char>>&board)
    {
        for(int k=0;k<9;++k)
        {
            if(board[k][j]==(char)(val+'0')) return false;
        }
        for(int k=0;k<9;++k)
        {
            if(board[i][k]==(char)(val+'0')) return false;
        }

        int r=i/3;
        int c=j/3;
        for(int l=3*r;l<3*r+3;++l)
        {
            for(int m=3*c;m<3*c + 3;++m)
            {
                if(board[l][m]==(char)(val+'0')) return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>&board,int i,int j)
    {
        if(i==9) return true;
        if(j==9) return helper(board,i+1,0);

        if(board[i][j]!='.') return helper(board,i,j+1);

        for(int val=1;val<=9;++val)
        {
            if(is_safe(i,j,val,board))
            {
                board[i][j]=(char)(val+'0');
                if(helper(board,i,j+1)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};