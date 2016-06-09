#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int key;
	struct Node *left;
	struct Node *right;
        struct Node *parent;
}node;

node* max(node *root)
{
	if(root->right!=NULL)
		max(root->right);
	else {
              printf("%d\n",root->key);
              return root;
             }
}

node* min(node *root)
{
	if(root->left!=NULL)
		min(root->left);
	else {
               printf("%d\n",root->key);
               return root;
             }
}

void inorder(node *root)
{
	if(root!=NULL)
		{
			inorder(root->left);
			printf("%d ",root->key);
			inorder(root->right);
                } 
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root)
{
	if(root!=NULL)
	{
		
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->key);
	}
}


node* search(node *root,int key)
{
	if(root==NULL)
		printf("Not Found\n");
	else if(root->key==key)
		{
                  printf("Found\n");
                  return root;
                }
	else if(key<root->key)
		search(root->left,key);
	else if(key>root->key)
		search(root->right,key);
	else printf("Not Found\n");
}

node* insert(node *root,int key)
{
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->key=key;
		root->left=NULL;
		root->right=NULL;
                root->parent=NULL;
		return root;
	}
	else if(key>root->key)
		{
                 root->right=insert(root->right,key);
                 root->right->parent=root;
                }
	else {
              root->left=insert(root->left,key);
              root->left->parent=root;
            }
	return root;
}

void successor(node *root,int key)
{
  node *ans=NULL;
  node *a=search(root,key);
  if(a->right!=NULL)
   ans=min(a->right);
 else
 {
   node *b=a->parent;
   while(b!=NULL&&a==b->right)
      {
        a=b;
        b=a->parent;
      }
   ans=b;
 }
  if(ans!=NULL)
    printf("%d\n",ans->key);
}

void predecessor(node *root,int key)
{
 node *ans=NULL;
 node *a=search(root,key);
 if(a->left!=NULL)
  ans=max(a->left);
 else
{
  node *b=a->parent;
  while(b!=NULL&&a==b->left)
      {
        a=b;
        b=a->parent;
      }
 ans=b;
}
  if(ans!=NULL)
    printf("%d\n",ans->key);
}

int main()
{
   node *root = NULL;
   int c,key;
   while(1)
   {
   	printf("1:Insert\n2:Search\n3:Maximum\n4:Minimum\n5:Inorder\n6:Pre-Order\n7:Post-Order\n8:Successor\n9:Predecessor\n10:Exit\nEnter Choice:");
    scanf("%d",&c);
    switch(c)
    {
      case 1:printf("Enter the key to be inserted:");
             scanf("%d",&key);
             root = insert(root,key);
             break;
      case 2:printf("Enter the key to be searched:");
             scanf("%d",&key);
             search(root,key);
             break;
      case 3:if(root!=NULL)
             max(root);
             else printf("Empty Tree\n");
             break;
      case 4:if(root!=NULL)
             min(root);
             else printf("Empty Tree\n");
             break;
      case 5:inorder(root);
             printf("\n");
             break;
      case 6:preorder(root);
             printf("\n");
             break;
      case 7:postorder(root);
             printf("\n");
             break;
      case 8:printf("Enter the key whose successor is to be found:");
             scanf("%d",&key);
             successor(root,key);
             break;
      case 9:printf("Enter the key whose predecessor is to be found:");
              scanf("%d",&key);
              predecessor(root,key);
              break;
     case 10:return 0;

      default:printf("Enter a valid choice\n");
              break;
    }
    
   }
   return 0;
}
