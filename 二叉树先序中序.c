#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct node
{
  char data;
  struct node* lchild;
  struct node* rchild;
}BiTNode,*BiTree;

void midprecreat(BiTree* root,char mid[],char pre[],int lm,int rm,int lp,int rp)
{
  *root = (BiTree)malloc(sizeof(BiTNode));
  (*root)->data = pre[lp];
  (*root)->lchild = NULL;
  (*root)->rchild = NULL;
  int pos = lm;
  while(mid[pos] != pre[lp])
    pos++;
  int childlen = pos - lm;
  if(pos > lm)
    midprecreat((&((*root)->lchild)),mid,pre,lm,pos - 1,lp + 1,lp + childlen);
  if(pos < rm)
    midprecreat((&((*root)->rchild)),mid,pre,pos + 1,rm,lp + childlen + 1,rp);
}

void post_traverse(BiTree p)
{
  if(p != NULL)
  {
      post_traverse(p->lchild);
      post_traverse(p->rchild);
      printf("%c",p->data);
  }
}

int main( )
{
  char pre[100];
  char mid[100];
  int n;
  BiTree root;
  gets(pre);
  n = strlen(pre);
  gets(mid);
  midprecreat(&root,mid,pre,0,n - 1,0,n - 1);
  post_traverse(root);
  printf("\n");
  
  return 0;
}
