#include<stdio.h>
#include<math.h>

void getCo(int x1,int y1,int x2,int y2);

void main() {

  int x1,x2,y1,y2,x,y;
  
    printf("Enter first co-ordinates\n");
    printf("X1 = ");
    scanf("%d", &x1);
    printf("y1 = ");
    scanf("%d", &y1);
    printf("x2 = ");
    scanf("%d", &x2);
    printf("y2 = ");
    scanf("%d", &y2);

    getCo(x1,y1,x2,y2);
}


void getCo(int x1,int y1,int x2,int y2) {

  int x3 =0,y3 =0,x4=0,y4 =0;
  int  dx,dy,dx3,dx4,dy3,dy4,slope,sloperight,slopedown;
    dx = x2-x1;
    dy = y2-y1;
    slope = dy/dx;
    
//    printf("slope= %d\n",slope); 
        
    while((x3!=x2 && y3!=y2) || (x4!=x2 && y4!=y2)) {           
//  for(int i=0;i<4;i++) {
          x3 = x1+1;
          y3 = y1;
          x4 = x1;
          y4 = y1+1;
    
          dx3 = x2-x3;
          dy3 = y2-y3;
          sloperight = dy3/dx3;
          
          dx4 = x2-x4;
          dy4 = y2-y4;
          slopedown = dy4/dx4;
          
          
            if (sloperight == slope)
              {
                printf("new co-ordinates: (%d,%d), (%d,%d)\n",x3,y3,x2,y2);
              x1 = x3;
              y1 = y3;
              }
            else if(slopedown == slope)
              {
                printf("new co-ordinates: (%d,%d), (%d,%d)\n",x4,y4,x2,y2);
                x1 = x4;
                y1 = y4;
              }
              else { break;}              
}
}
