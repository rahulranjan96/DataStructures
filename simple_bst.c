#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int key;
	struct Node *left;
	struct Node *right;
}node;

void max(node *root)
{
	if(root->right!=NULL)
		max(root->right);
	else printf("%d\n",root->key);
}

void min(node *root)
{
	if(root->left!=NULL)
		min(root->left);
	else printf("%d\n",root->key);
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


void search(node *root,int key)
{
	if(root==NULL)
		printf("Not Found\n");
	else if(root->key==key)
		printf("Found\n");
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
		return root;
	}
	else if(key>=root->key)
		root->right=insert(root->right,key);
	else root->left=insert(root->left,key);
	return root;
}

	int main()
{
   node *root = NULL;
   int c,key;
   while(1)
   {
   	printf("1:Insert\n2:Search\n3:Maximum\n4:Minimum\n5:Inorder\n6:Pre-Order\n7:Post-Order\n8:Exit\nEnter Choice:");
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
      case 8:return 0;
      default:printf("Enter a valid choice\n");
    }
    
   }
   return 0;
}