void dps(int i,int j,int** grid,int n,int *quene,int *tail)
{
    if(i<0||j<0||i>=n||j>=n||grid[i][j]!=1)return ;
    quene[(*tail)++]=n*i+j;
    grid[i][j]=-1;
    dps(i+1,j,grid,n,quene,tail);
    dps(i-1,j,grid,n,quene,tail);
    dps(i,j+1,grid,n,quene,tail);
    dps(i,j-1,grid,n,quene,tail);
}
int shortestBridge(int** grid, int gridSize, int* gridColSize){
int n=gridSize;
int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j]==1){
            int *quene=(int *)malloc(sizeof(int)*n*n);
            int head=0,tail=0;
            dps(i,j,grid,n,quene,&tail);
            int step=0;
            while(head!=tail){
                int sz = tail - head;
                    for (int i = 0; i < sz; i++) {
                int x= quene[head]/n;
                int y=quene[head]%n;
                head++;
                for(int k=0;k<4;k++){
                    int nx=x+dirs[k][0];
                    int ny=y+dirs[k][1];
                if(nx>=0&&ny>=0&&nx<n&&ny<n){
                    if(grid[nx][ny]==0){
                        quene[tail++]=nx*n+ny;
                        grid[nx][ny]=-1;
                    }else if(grid[nx][ny]==1){
                        free(quene);
                        return step;
                    }
                }
                }
            }
            step++;
            }
            
        }
    }
}
return 0;
}