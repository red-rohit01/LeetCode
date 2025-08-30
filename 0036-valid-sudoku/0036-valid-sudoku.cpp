class Solution {
public:
    bool checkrow(vector<vector<char>>&board)
    {
        for(int i=0;i<9;++i)
        {
            set<char>rk;
            for(int j=0;j<9;++j)
            {
                if(board[i][j]!='.' && rk.find(board[i][j])!=rk.end()) return false;

                rk.insert(board[i][j]);
            }
        }
        return true;
    }
    bool checkcol(vector<vector<char>>&board)
    {
        for(int i=0;i<9;++i)
        {
            set<char>rk;
            for(int j=0;j<9;++j)
            {
                if(board[j][i]!='.' && rk.find(board[j][i])!=rk.end()) return false;

                rk.insert(board[j][i]);
            }
        }
        return true;
    }

    bool checkmat(vector<vector<char>>&board)
    {
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                set<char>rk;
                for(int p=i;p<i+3;++p)
                {
                    for(int q=j;q<(j+3);++q)
                    {
                        if(board[p][q]!='.' && rk.find(board[p][q])!=rk.end()) return false;

                        rk.insert(board[p][q]);
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if(checkrow(board)==false) return false;

        if(checkcol(board)==false) return false;

        if(checkmat(board)==false) return false;

        return true;
    }
};