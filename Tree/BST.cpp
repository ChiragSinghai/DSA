#include<iostream>
using namespace std;
class BST{
	public:
	int data;
	BST *left,*right;
	
		BST(){
			left=NULL;
			right=NULL;
		}
		void inorder(BST *root){
			if(root!=NULL){
				inorder(root->left);
				printf("%d ",root->data);
				inorder(root->right);
			}
		}
		void postorder(BST *root){
			if(root!=NULL){
				postorder(root->left);
				postorder(root->right);
				printf("%d ",root->data);
			}
		}
		void preorder(BST *root){
			if(root!=NULL){
				printf("%d ",root->data);
				preorder(root->left);
				preorder(root->right);
			}
		}
		BST* insert(int key,BST* root);
		BST(int key){
			left=NULL;
			right=NULL;
			data=key;
		}
		
};
BST* BST::insert(int key,BST* root){
	if(root==NULL){
		return new BST(key);	
	}
	else{
		BST *p,*tmp=root;
		while(tmp!=NULL){
			p=tmp;
			if(tmp->data<key){
				tmp=tmp->right;
			}
			else{
				tmp=tmp->left;
			}
		}
		if(p->data<key){
			p->right=new BST(key);
		}
		else{
			p->left=new BST(key);
		}
		return root;
	}	
}
int main(){
BST b,*root=NULL;
int choice,m;
do{
	printf("1. insert element\n");
	printf("2. delete element\n");
	printf("3. preorder traversal\n");
	printf("4. Inorder traversal\n");
	printf("5. postorder traversal\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter the element you want to enter:");
			scanf("%d",&m);
			root=b.insert(m,root);
			break;
		case 2:
			break;
		case 3:
			b.preorder(root);printf("\n");break;
		case 4:
			b.inorder(root);printf("\n");break;
		case 5:
			b.postorder(root);printf("\n");break;
		case 6:
			break;
		default:
			printf("Enter invalid input\n");
			break;
	}
}while(choice!=6);
return 0;	
}
