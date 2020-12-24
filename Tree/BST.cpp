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
				printf("%d",root->data);
				inorder(root->right);
			}
		}
		void insert(int key,BST **root);
		BST(int key){
			left=NULL;
			right=NULL;
			data=key;
		}
		
};
void BST::insert(int key,BST **root){
	if(root==NULL){
		root=new BST(key);
		return;	
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
	}	
}
int main(){
BST b,*root=NULL;
printf("%d",root);
b.insert(45,&root);
printf("%d",root);
/*
printf("%d",root->data);
b.insert(43,root);b.insert(47,root);b.insert(4,root);
b.insert(45,root);
b.insert(5,root);
b.inorder(root);
*/
return 0;	
}
