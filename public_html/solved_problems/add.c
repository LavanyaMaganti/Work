#include<stdio.h>

main()  {
  
  scanf("%d",&a);
  scanf("%d",&b);
 int &c = &a+&b;
  printf("%d",&c);
}
