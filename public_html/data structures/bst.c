
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
   char *word;
   struct treenode *left, *right;
} TNODE;

TNODE *makenode(char *w);
TNODE *maketree(FILE *fd);
void decorate(TNODE *t, char *w);
int   inorder(TNODE *t);
int finds_word(TNODE *t, char *key);
int byLevel(TNODE *t);
int calls = 0;
int count = 0;
int main(int argc, char *argv[])
{
   TNODE *root;
   char buffer[MAXLEN];
   FILE *fd;

   fd = fopen(DICTIONARY,"r");
   if(!fd){
      fprintf(stderr,"cannot open dictionary: %s\n", DICTIONARY);
      exit(0);
   }

   root = maketree(fd);
   /*printf("? ");
   while(fgets(buffer,MAXLEN,stdin) != NULL){
      buffer[strlen(buffer)-1] = 0;
      if(finds_word(root,buffer))
         printf("yes\n");
      else
         printf("no\n");
   }*/
   
   //Call functions here 
  int heig = inorder(root);
   printf("No of Nodes %d\n", heig);
   //Until here
     
}
TNODE *maketree(FILE *fd)
{
   TNODE *root;
   char buffer[MAXLEN];

   root = NULL;       // empty tree
   while(fgets(buffer,MAXLEN,fd) != NULL){
      buffer[strlen(buffer)-1] = 0;
      if(root == NULL){
         root = makenode(buffer);
      } else {
         decorate(root,buffer);
      }
   }
   return root;
}
TNODE *makenode(char *w)
{
   TNODE *p;

   p = malloc(sizeof(TNODE));
   p->left = p->right = NULL;
   p->word = strdup(w);
   return p;
}
void decorate(TNODE *t, char *w)
{
   int rv;

   for(;;){
      rv = strcmp(w, t->word);
      if(rv == 0)
         return;
      if(rv < 0){
         if(t->left != NULL){
            t = t->left;
         } else {                // rv->left is NULL
            t->left = makenode(w);
            return;
         }
      } else {               // rv > 0
         if(t->right != NULL){
            t = t->right;
         } else {                // rv->right is NULL
            t->right = makenode(w);
            return;
         }
      }
   }
}
//code goes here
/*int cont=0;
int inorder(TNODE *root){
if(root==NULL){
        return 0;
}
inorder(root->left);
printf("left node:%d\n",cont);
cont ++;
inorder(root->right);
printf("right node:%d\n",cont);
return cont;        
}
*/

/* int inorder(TNODE *root,int min,int max){
        if(root==NULL){
        return 0;        
        }
       inorder(root -> left,min,max);
       if(root->data <= min && root->data => max){
      printf("%d\n",root->data);
       }
       inorder(root->right,min,max);

}
*/
/* int max=0;
int inorder(TNODE *root){
	if(root == NULL) return 0;
        inorder(root->left);
        if(root->left && root ->right!=NULL){
                max++;

          
	

        inorder(root->right);	
}
return max;
}
*/
//count number of letters in total words......
/*
int cou=0;
int inorder(TNODE *root){
        if(root==NULL)
                return 0;
                inorder(root->left);
                cou=cou+strlen(root->data);
                inorder(root->right);
                
return cou;
}
*/
//pointer of smallest word node

char mix;
int coun=0;
int  inorder(TNODE *root){
                if(root==NULL)
                 return ;
                 inorder(root->left);
                 mix=strcat(root->left->word,root->right->word);
                inorder(root->right);
printf("concated:%s\n",mix);
coun++;
return coun;
 }

//til here
int finds_word(TNODE *t, char *key)
{
   int rv;

   for(;;){
      rv = strcmp(key, t->word);
      if(rv == 0)
         return 1;
      if(rv < 0){
         if(t->left != NULL){
            t = t->left;
         } else {                // rv->left is NULL
            return 0;
         }
      } else {               // rv > 0
         if(t->right != NULL){
            t = t->right;
         } else {                // rv->right is NULL
            return 0;
         }
      }
   }
}

/* count total nodes 
int byLevel(TNODE *root){
  if(root == NULL){
     return 0;  
  }
  
//  byLevel(root->left);
  count++;
   byLevel(root->right);
return count;
} */
