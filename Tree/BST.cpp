#include<iostream>
#include <cstdlib>
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
		BST* deleteNode(int key,BST* root);
		void search(int key,BST *root);
		
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


BST* BST ::deleteNode(int key,BST* root){
	BST *prev=NULL,*curr=root;
	while (curr!=NULL && curr->data!=key){
		prev=curr;
		if(key<curr->data){
			curr=curr->left;
		}
		else{
			curr=curr->right;
		}
	}
	if(curr==NULL){
		cout<<"key"<<key<<"not found in BST"<<endl;
		return root;
	}
	if(curr->left==NULL || curr->right==NULL){
		BST *newcurr;
		if(curr->left==NULL){
			newcurr=curr->right;
		}
		else{
			newcurr=curr->left;
		}
		if(prev==NULL){
			return newcurr;
		}
		if(curr==prev->left){
			prev->left=newcurr;
		}
		else{
			prev->right=newcurr;
		}
		free(curr);
	}
	else{
		BST *p=NULL;
		BST *temp=curr->right;
		while(temp->left!=NULL){
			p=temp;
			temp=temp->left;
		}
		if(p!=NULL){
			p->left=temp->right;
		}
		else{
			curr->right=temp->right;
		}
		curr->data=temp->data;
		free(temp);
	}
	return root;
}
void BST::search(int key,BST *root){
	while (root!=NULL){
		if (key<root->data)
			root=root->left;
		else if(key>root->data)
			root=root->right;
		else{
			cout<<"key "<<key<<" found"<<endl;
			return;
		}
	}
	cout<<"key not found"<<endl;
}
	

int main(){
BST b,*root=NULL;
int choice,m;
do{
	printf("1. insert element\n");
	printf("2. delete element\n");
	printf("3. delete element\n");
	printf("4. preorder traversal\n");
	printf("5. Inorder traversal\n");
	printf("6. postorder traversal\n");
	printf("7. Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter the element you want to enter:");
			scanf("%d",&m);
			root=b.insert(m,root);
			break;
		case 2:
			printf("Enter the element you want to enter:");
			scanf("%d",&m);
			root=b.deleteNode(m,root);
			break;
		case 3:
			printf("Enter the element you want to enter:");
			scanf("%d",&m);
			b.search(m,root);
			break;			
		case 4:
			b.preorder(root);printf("\n");break;
		case 5:
			b.inorder(root);printf("\n");break;
		case 6:
			b.postorder(root);printf("\n");break;
		case 7:
			break;
		default:
			printf("Enter invalid input\n");
			break;
	}
}while(choice!=7);
return 0;	
}
