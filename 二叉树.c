/*
#include<stdio.h>
#include<stdlib.h>

typedef struct BiTreeNode
{
  char data;
  struct BiTreeNode *lchild;
  struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;

void CreateBinaryTree(BiTree *T)
{
  char ch;
  scanf("%c",&ch);
  if(ch == '#')
    *T == NULL;
  else
  {
    *T = (BiTree)malloc(sizeof(BiTreeNode));
    (*T)->data=ch;
    CreateBinaryTree(&((*T)->lchild));
    CreateBinaryTree(&((*T)->rchild));
  }
}

//先序遍历
void PreOrderTraverse(BiTree T)
{
  if(T == NULL)
    return;
  else
  {
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
  }
}

//中序遍历
void InOrderTraverse(BiTree T)
{
  if(T == NULL)
    return;
  else
  {
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    InOrderTraverse(T->rchild);
  }
}

//后序遍历

void PostOrderTraverse(BiTree T)
{
  if(T == NULL)
    return;
  else
  {
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
  }
}

int main( )
{
  BiTree T;
  printf("请创建一棵二叉树：\n");
  CreateBinaryTree(&T);
  printf("\n正序遍历结果为：\n");
  PreOrderTraverse(T);
  printf("\n中序遍历结果为：\n");
  InOrderTraverse(T);
  printf("\n倒序遍历结果为：\n");
  PostOrderTraverse(T);
  return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTreeNode
{
	char data;
	struct BiTreeNode *lchild;
	struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;

void CreateBinaryTree(BiTree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTreeNode));
		(*T)->data=ch;
		CreateBinaryTree(&((*T)->lchild));
		CreateBinaryTree(&((*T)->rchild));
	}
}

//先序遍历
void PreOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	else
	{
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
//中序遍历
void InOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	else
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
}

//后序遍历
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	else
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	}
}

int main(int argc, char *argv[])
{
	BiTree T;
	printf("请创建一棵二叉树:\n");
	CreateBinaryTree(&T);
	printf("\n先序遍历的结果为：\n");
	PreOrderTraverse(T);
	printf("\n中序遍历的结果:\n");
	InOrderTraverse(T);
	printf("\n后序遍历的结果:\n");
	PostOrderTraverse(T);
	return 0;
}
