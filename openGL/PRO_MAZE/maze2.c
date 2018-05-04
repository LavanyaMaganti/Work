
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <sys/time.h>

#define WID   400
#define HGT   300

#define BORD   10
#define NCELL  20
#define WCELL  20
#define HCELL  15

#define NORTH   1
#define SOUTH   2
#define EAST    0
#define WEST    3

#define VMASK   0x10
#define BMASK   0x20

#define REVERSE(X)  (3-X)

#define RND(X)  (random() % (X))

typedef
  unsigned char
uchar;

typedef struct ball {
  int x,y;
  int dir;
  uchar alive;
} BALL;

BALL ball;
uchar map[NCELL][NCELL];

int leftturn[]={NORTH,WEST,EAST,SOUTH};
int rightturn[]={SOUTH,EAST,WEST,NORTH};

void do_press(GtkWidget *wid, GdkEventButton *ev, gpointer p);
void do_release(GtkWidget *wid, GdkEventButton *ev, gpointer p);
void do_motion(GtkWidget *wid, GdkEventButton *ev, gpointer p);
gboolean do_draw(GtkWidget *wid, cairo_t *gc, gpointer p);
void makemaze();
gint animate(gpointer p);

int main(int argc, char *argv[])
{
  GtkWidget *win, *dar;

  srandom(getpid());

  gtk_init(&argc, &argv);
  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(win), "Maze");
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
  g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), 0);

  dar = gtk_drawing_area_new();
  gtk_widget_set_size_request(dar,WID,HGT);
  gtk_container_add(GTK_CONTAINER(win), dar);
  gtk_widget_add_events(dar,
    GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_POINTER_MOTION_MASK);
  g_signal_connect(dar,"button-press-event",G_CALLBACK(do_press), 0);
  g_signal_connect(dar,"button-release-event",G_CALLBACK(do_release), 0);
  g_signal_connect(dar,"motion-notify-event",G_CALLBACK(do_motion), 0);
  g_signal_connect(dar,"draw",G_CALLBACK(do_draw), 0);

  makemaze();
  ball.alive = 0;
  gtk_widget_show_all(win);
  gtk_main();
}
void do_press(GtkWidget *wid, GdkEventButton *ev, gpointer p)
{
  int tid;

  ball.x = RND(NCELL);
  ball.y = RND(NCELL);
  ball.dir = RND(4);
  ball.alive = 1 - ball.alive;
  tid = g_timeout_add(1000.0/30.0, animate, (gpointer) wid);
  gtk_widget_queue_draw(wid);
}
void do_release(GtkWidget *wid, GdkEventButton *ev, gpointer p)
{
}
void do_motion(GtkWidget *wid, GdkEventButton *ev, gpointer p)
{
}
void randsig(int sig[])
{
  int i,j,k;

  for(i=0;i<4;i++)
    sig[i] = i;
  for(i=0;i<4;i++){
    j = RND(4);
    if(i != j){
      k = sig[i]; sig[i] = sig[j]; sig[j] = k;
    }
  }
}
int inbounds(int x, int y, int dir)
{
  if(x == 0 && dir == WEST) return 0;
  if(y == 0 && dir == NORTH) return 0;
  if(x == NCELL-1 && dir == EAST) return 0;
  if(y == NCELL-1 && dir == SOUTH) return 0;
  return 1;
}
void visit(int x, int y)
{
  int nx,ny;
  int i,j,dir,revdir;
  int sig[4];

  randsig(sig);
  map[x][y] |= VMASK;
  for(i=0;i<4;i++){
    dir = sig[i];
    if(map[x][y] & (1 << dir)){
      if(!inbounds(x,y,dir)) continue;
      switch(dir){
        case  EAST: nx = x + 1; ny = y; break;
        case  WEST: nx = x - 1; ny = y; break;
        case NORTH: ny = y - 1; nx = x; break;
        case SOUTH: ny = y + 1; nx = x; break;
      }
      revdir = REVERSE(dir);
      if(map[nx][ny] & VMASK) continue;
      map[x][y] ^= (1 << dir);
      map[nx][ny] ^= (1 << revdir);
      visit(nx,ny);
    }
  }
}
void makemaze()
{
  memset(map,0xf,NCELL*NCELL);
  visit(RND(NCELL),RND(NCELL)); 
}
gboolean do_draw(GtkWidget *wid, cairo_t *gc, gpointer p)
{
  int k;
  int x,y,ix,iy,dx,dy;

  cairo_set_source_rgb(gc, 0.9, 0.9, 0.6);
  cairo_paint(gc);

  cairo_set_line_width(gc, 2.0);
  cairo_set_source_rgb(gc, 0.1, 0.1, 0.1);

  for(x=0;x<NCELL;x++){
    for(y=0;y<NCELL;y++){
      for(k=0;k<4;k++){
        if(map[x][y] & (1 << k)){
          switch(k){
            case  EAST: ix = WCELL; iy =     0; dx = 0; dy = HCELL; break;
            case  WEST: ix =     0; iy =     0; dx = 0; dy = HCELL; break;
            case NORTH: ix =     0; iy =     0; dx = WCELL; dy = 0; break;
            case SOUTH: ix =     0; iy = HCELL; dx = WCELL; dy = 0; break;
          }
          cairo_move_to(gc,BORD+x*WCELL+ix   ,BORD+y*HCELL+iy   );
          cairo_line_to(gc,BORD+x*WCELL+ix+dx,BORD+y*HCELL+iy+dy);
          cairo_stroke(gc);
        }
      }
    }
  }
  cairo_set_source_rgb(gc, 0.9, 0.3, 0.3);
  for(x=0;x<NCELL;x++)
    for(y=0;y<NCELL;y++)
      if(map[x][y] & BMASK){
        cairo_arc(gc, BORD+WCELL*x+WCELL/2,
                      BORD+HCELL*y+HCELL/2,
                      4.0, 0.0, 2.0*M_PI);
        cairo_fill(gc);
      }
  if(ball.alive){
    cairo_set_source_rgb(gc, 0.3, 0.3, 0.9);
    cairo_arc(gc, BORD+WCELL*ball.x+WCELL/2,
                  BORD+HCELL*ball.y+HCELL/2,
                  12.0, 0.0, 2.0*M_PI);
    cairo_fill(gc);
  }
  return FALSE;
}
void move_ball()
{
  map[ball.x][ball.y] |= BMASK;
  switch(ball.dir){
    case  EAST: ball.x++; break;
    case  WEST: ball.x--; break;
    case NORTH: ball.y--; break;
    case SOUTH: ball.y++; break;
  }
}
gint animate(gpointer p)
{
  GtkWidget *dar;
  int t;

  dar = (GtkWidget *) p;

  t = 0;
  while(map[ball.x][ball.y] & (1 << ball.dir)){
    ball.dir = rightturn[ball.dir];
    if(++t == 5){
      fprintf(stderr,"WTF in animate: %d,%d,%d,%x\n",
        ball.x,ball.y,ball.dir,(~map[ball.x][ball.y] & 0xf));
      return FALSE;
    }
  }
  move_ball();
  ball.dir = leftturn[ball.dir];
  gtk_widget_queue_draw(dar);
  return TRUE;
}
