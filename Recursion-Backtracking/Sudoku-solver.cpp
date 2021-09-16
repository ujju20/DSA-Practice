bool isValid(int mat[9][9],int i,int j,int no,int n)
{
    for(int x=0;x<n;x++)
    {
        if(mat[x][j]==no)
            return false;
        
    }
    for(int y=0;y<n;y++)
    {
        if(mat[i][y]==no)
            return false;
    }
    
    int x=(i/3)*3;
    int y=(j/3)*3;
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(mat[i][j]==no)
                return false;
        }
    }
    return true;
}
bool solveSudoku(int mat[9][9],int i,int j,int n)
{
    //Base Cases
    if(i==n)
    {
        return true;
    }
    if(j==n)
    {
        return solveSudoku(mat,i+1,0,n);
    }
    if(mat[i][j]!=0)
    {
        return solveSudoku(mat,i,j+1,n);
    }
    //Recursive Cases
    //We will try every possibility
    for(int no=1;no<=9;no++)
    {
        if(isValid(mat,i,j,no,n))
        {
            mat[i][j]=no;
            bool subProblem=solveSudoku(mat,i,j+1,n);
            if(subProblem)
                return true;
        }
    }
    //Backtracking Step
    mat[i][j]=0;
    return false;
    
    
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solveSudoku(matrix,0,0,9);
}
