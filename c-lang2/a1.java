public class Bubble{
  int x, y;
  int radius;
  int col;

  Bubble(int startX, int startY, int rad, int c){
     x = startX;
     y = startY;
     radius = rad;
     col = c;
   }

  public void drawBubble(){
    noFill();
    stroke(col);
    ellipse(x, y, radius, radius);
  }
  
  public void floatUp(){
    drawBubble();
  
    if(y < 0){
      y = height;
    }
      y--;
      int wobble = (int)random(0, 1000);
      wobble = wobble % 2;
    
    switch(wobble){
      case 0:
             x+=2;
             break;
      case 1:
             x-=2;
             break;
    }
  }
}
