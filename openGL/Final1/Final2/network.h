
#ifndef SEND_REPORT

#ifndef	_STDIO_H
#include <stdio.h>
#endif

#ifndef	_STDLIB_H
#include <stdlib.h>
#endif

#define MAXPLAYERS      64

#define SET_MY_X(X)        _position_.x = X
#define SET_MY_Y(X)        _position_.y = X
#define SET_MY_Z(X)        _position_.z = X
#define SET_MY_HEADING(X)  _position_.h = X

#define GET_MY_X        GET_X(_my_id)
#define GET_MY_Y        GET_Y(_my_id)
#define GET_MY_Z        GET_Z(_my_id)
#define GET_MY_HEADING  GET_HEADING(_my_id)

#define GET_X(T)        _plist_[T].x
#define GET_Y(T)        _plist_[T].y
#define GET_Z(T)        _plist_[T].z
#define GET_HEADING(T)  _plist_[T].h

#define SERVER_SETUP  \
    _my_id = _connection_setup(& _position_); \
    if(_my_id < 0){ \
      fprintf(stderr,"unable to begin game.\n"); \
      exit(1); \
    } 

#define SEND_REPORT  _send_position(& _position_)
#define RECV_REPORT  _recv_message(_plist_)

typedef struct position {
  int id;
  float x,y,z,h;
} POSITION;

int _my_id;
POSITION _position_;
POSITION _plist_[MAXPLAYERS];

int _connection_setup(POSITION *p);
int _send_position(POSITION *p);
int _recv_message(POSITION *p);

#endif
