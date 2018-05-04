
#include "main.h"

#define NDIRS   6

extern int map[MAP][MAP][MAP];

int delta[NDIRS][3]={
  { 2, 0, 0},
  { 0, 2, 0},
  {-2, 0, 0},
  { 0,-2, 0},
  { 0, 0, 2},
  { 0, 0,-2},
};

int getneighbors(int li[], int row, int col, int lev)
{
  int i,r,c,l,n;

  n = 0;
  for(i=0;i<NDIRS;i++){
    r = row + delta[i][0];
    c = col + delta[i][1];
    l = lev + delta[i][2];
    if(map[r][c][l] == 0)
      li[n++] = i;
  }
  return n;
}
void shuffle(int li[], int n)
{
  int i,j,k,t;

  for(i=0;i<n;i++){
    j = lrand48() % n;
    k = lrand48() % n;
    if(j != k){
      t = li[j]; li[j] = li[k]; li[k] = t;
    }
  }
}
void dfs(int row, int col, int lev)
{
  int i,j,r,c,l,n,dr,dc,dl;
  int li[NDIRS];

  map[row][col][lev] = 1;
  n = getneighbors(li,row,col,lev);
/*
  if(n > 1)
    shuffle(li,n);
*/
  for(i=0;i<n;i++){
    j = li[i];
    dr = delta[j][0];
    dc = delta[j][1];
    dl = delta[j][2];
    r = row + dr;
    c = col + dc;
    l = lev + dl;
    if(map[r][c][l] == 0){
      map[row+dr/2][col+dc/2][lev+dl/2] = 1;
      dfs(row+dr,col+dc,lev+dl);
    }
  }
}
void makemaze()
{
  int i,j,k,t;

  memset(map,0,MAP*MAP*MAP*sizeof(int));
  t = MAP-1;
  for(i=0;i<MAP;i++){
    for(j=0;j<MAP;j++){
      map[i][j][0] = 2;
      map[i][j][t] = 2;
      map[i][0][j] = 2;
      map[i][t][j] = 2;
      map[0][i][j] = 2;
      map[t][i][j] = 2;
    }
  }
  dfs(2,2,2);
  for(i=0;i<MAP;i++){
    for(j=0;j<MAP;j++){
      for(k=0;k<MAP;k++)
        printf("%3d",map[i][j][k]);
      printf("\n");
    }
    printf("---------------\n");
  }
}

