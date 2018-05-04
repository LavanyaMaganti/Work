#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

int NMON;
int sock;
int session;
int mynumber;
struct sockaddr_in client;
fd_set set,wset;

typedef struct monster{
  int mynumber;
  float x,y,z;
}MONSTER;
MONSTER *me;

void startclient();
void listenclient();
void reportlocation();
