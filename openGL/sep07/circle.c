#include <stdio.h>
#include <math.h>
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

void drawcircle(int xc, int yc, int x1, int y1);

int main(int argc, char *argv[])
{
  XEvent ev;
  int xc,yc,x1,y1,toggle = 0;

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
              xc = ev.xbutton.x;
              yc = ev.xbutton.y;
            } else {
              x1 = ev.xbutton.x;
              y1 = ev.xbutton.y;
              drawcircle(xc,yc,x1,y1);
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
void putpixel(int x, int y, int xc, int yc)
{
    XDrawPoint(disp,win,gc, x+xc, y+yc);
    XDrawPoint(disp,win,gc, y+xc, x+yc);
    XDrawPoint(disp,win,gc,-y+xc, x+yc);
    XDrawPoint(disp,win,gc,-x+xc, y+yc);
    XDrawPoint(disp,win,gc,-x+xc,-y+yc);
    XDrawPoint(disp,win,gc,-y+xc,-x+yc);
    XDrawPoint(disp,win,gc, y+xc,-x+yc);
    XDrawPoint(disp,win,gc, x+xc,-y+yc);
}
void drawcircle(int xc, int yc, int x1, int y1)
{
  int des,x,y,dx,dy;
  double rad,ystop;

  dx = x1 - xc;
  dy = y1 - yc;
  rad = sqrt(dx*dx+dy*dy);
  ystop = rad*sqrt(1.0/2.0);
  des = 0;
  x = (int) rad;
  y = 0;
  while(y <= (int) ystop){
    putpixel(x,y,xc,yc);
    if(des > 0){
      --x;
      des += 2*y - 2*x + 3;
    } else {
      des += 2*y + 1;
    }
    y++;
  }
}
