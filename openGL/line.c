
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>

#define RND(X) (random() % (X))

#define X 100  /* X coordinate of window */
#define Y 100  /* Y coordinate of window */
#define W 800  /* width  of window       */
#define H 600  /* height of window       */
#define B   0  /* border width           */

Display *disp;
Window win;
GC gc;
int scr;

void drawline(int x1, int y1, int x2, int y2);

int main(int argc, char *argv[])
{
  XEvent ev;
  int x1,y1,x2,y2,toggle = 0;

  disp = XOpenDisplay(NULL);
  scr  = DefaultScreen(disp);
  win  = XCreateSimpleWindow(disp,DefaultRootWindow(disp),X,Y,W,H,B,1,0);
  gc   = XCreateGC(disp,win,0,0);
  XSetForeground(disp,gc,WhitePixel(disp,scr));
  XSetBackground(disp,gc,BlackPixel(disp,scr));
  XSelectInput(disp,win, ButtonPressMask | ExposureMask);
  XMapRaised(disp,win);

  for(;;){
    XNextEvent(disp,&ev);
    switch(ev.type){
      case Expose:
        break;
      case ButtonPress:
        switch(ev.xbutton.button){
          case 1:
            if(!toggle){
              x1 = ev.xbutton.x;
              y1 = ev.xbutton.y;
            } else {
              x2 = ev.xbutton.x;
              y2 = ev.xbutton.y;
              drawline(x1,y1,x2,y2);
            }
            toggle = 1 - toggle;
            XFlush(disp);
            break;
          case 2:
          case 3:
            exit(0);
        }
    }
  }
}
void putpixel(int x, int y, int oct)
{
  switch(oct){
    case 0: XDrawPoint(disp,win,gc, x, y); break;
    case 1: XDrawPoint(disp,win,gc, y, x); break;
    case 2: XDrawPoint(disp,win,gc,-y, x); break;
    case 3: XDrawPoint(disp,win,gc,-x, y); break;
    case 4: XDrawPoint(disp,win,gc,-x,-y); break;
    case 5: XDrawPoint(disp,win,gc,-y,-x); break;
    case 6: XDrawPoint(disp,win,gc, y,-x); break;
    case 7: XDrawPoint(disp,win,gc, x,-y); break;
  }
}
void simpledrawline(int x1, int y1, int x2, int y2, int oct)
{
  int e2,x,y,dx,dy;

  dx = x2 - x1;
  dy = y2 - y1;
  e2 = 0;
  x = x1;
  y = y1;
  while(x <= x2){
    putpixel(x,y,oct);
    if(((e2+dy) << 1) < dx){
      e2 += dy;
    } else {
      e2 += dy - dx;
      y++;
    }
    x++;
  }
}
void drawline(int x1, int y1, int x2, int y2)
{
  int dx,dy;

  dx = x2 - x1;
  dy = y2 - y1;
  if(dy >= 0){
    if(dx >= 0){
      if(dy < dx)
        simpledrawline(x1,y1,x2,y2,0);
      else
        simpledrawline(y1,x1,y2,x2,1);
    } else {
      if(dy > -dx)
        simpledrawline(y1,-x1,y2,-x2,2);
      else
        simpledrawline(-x1,y1,-x2,y2,3);
    }
  } else {
    if(dx < 0){
      if(-dy < -dx)
        simpledrawline(-x1,-y1,-x2,-y2,4);
      else
        simpledrawline(-y1,-x1,-y2,-x2,5);
    } else {
      if(-dy > dx)
        simpledrawline(-y1,x1,-y2,x2,6);
      else
        simpledrawline(x1,-y1,x2,-y2,7);
    }
  }
}
