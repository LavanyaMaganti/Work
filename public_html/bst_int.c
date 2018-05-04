
/*
 * binary search tree
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN  256

#define DICTIONARY "words"

typedef struct treenode {
	int		data;
	struct treenode *left, *right;
}		TNODE;

TNODE          *makenode(int data);
TNODE          *maketree(FILE * fd);
void		decorate  (TNODE * t, int data);
int            *height(TNODE * t);
int inorder(TNODE* root,int value);
int		calls = 0;
int		count = 0;
int		neg = 0,	pos = 0;
int		arr[2];
int 
main(int argc, char *argv[])
{
	TNODE          *root;
	FILE           *fd;
	printf("%s\n", argv[1]);
	fd = fopen(argv[1], "r");
	if (!fd) {
		fprintf(stderr, "cannot open dictionary: %s\n", DICTIONARY);
		exit(0);
	}
	root = maketree(fd);

	//Call functions here
		inorder(root);
	//printf("No of Nodes.. %d\n", dep);
	//Until here

}
TNODE* maketree(FILE * fd)
{
	TNODE          *root;
	char		ch;
	int		data;

	root = NULL;
	//empty tree
		while (fscanf(fd, "%d", &data) == 1) {
		//buffer[strlen(buffer) - 1] = 0;
		if (root == NULL) {
			root = makenode(data);
		} else {
			decorate(root, data);
		}
	}
	return root;
}
TNODE*
makenode(int w)
{
	TNODE          *p;

	p = malloc(sizeof(TNODE));
	p->left = p->right = NULL;
	p->data = w;
	return p;
}
void 
decorate(TNODE* t, int w)
{
	int		rv;

	for (;;) {
//rv = (w < t->data):;
		if (w == t->data)
			return;
		if (w < t->data) {
			if (t->left != NULL) {
				t = t->left;
			} else {
				//rv->left is NULL
					t->left = makenode(w);
				return;
			}
		} else {
			//rv > 0
				if (t->right != NULL) {
				t = t->right;
			} else {
				//rv->right is NULL
					t->right = makenode(w);
				return;
			}
		}
	}
}				


int inorder(TNODE* root,int value){
	if(root==NULL) return 0 ;

	
	
inorder(root->left,value);
 inorder(root->right,value);

}






















