#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right;
}*root;

struct Q_node{
	struct node *t;
	struct Q_node *link;
}*front,*rear;

void clear(){
	while(front!=NULL){
		struct Q_node *tmp;
		tmp=front;
		//printf("deleted element is %d\n",tmp->info);
		front=front->link;
		free(tmp);
	}
}

void push(struct node *p){
	struct Q_node *tmp;
	tmp=malloc(sizeof(struct Q_node));
	tmp->t=p;
	tmp->link=NULL;
	if(front==NULL){
		front=tmp;
	}
	else{
		rear->link=tmp;
	}
	rear=tmp;
}

struct node * pop(){
	if(front==NULL){
		printf("queue underflow\n");
	}
	else{
		struct Q_node *tmp;
		struct node *p;
		tmp=front;
		//printf("deleted element is %d\n",tmp->info);
		front=front->link;
		p=tmp->t;
		free(tmp);
		return p;
	}
}

void Q_display(){
	if(front==NULL){
		printf("list is empty\n");
	}
	else{
		struct Q_node *q=front;
		while(q!=NULL){
			printf("%d\n",q->t->data);
			q=q->link;
		}                             //end of while
	}	                //end of else
}//end of display

struct node *create_node(){
	int m;
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter element : ");
	scanf("%d",&m);
	p->data=m;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void insert(){		
	struct node *temp;
	if(root==NULL){
		root=create_node();
		return;
	}
	push(root);
	while(front!=NULL){
		temp=pop();
		if (temp->left != NULL)
            push(temp->left);
        else {
            temp->left = create_node();
            break;
        }
        if (temp->right != NULL)
            push(temp->right);
        else {
            temp->right = create_node();
            break;
        }
			
		}
}

void lastnode(struct node *tmp){
	struct node *p;
	push(root);
	while(front!=NULL){
		p=pop();
		if(p==tmp){
			p = NULL; 
            free(tmp);
            return;
		}
		if(p->right){
			if(p->right==tmp){
				p->right=NULL;
				free(tmp);
				return;
			}
			else{
				push(p->right);
			}
		}
		if(p->left){
			if(p->left==tmp){
				p->left=NULL;
				free(tmp);
				return;
			}
			else{
				push(p->left);
			}
		}
		
	}
	
}

void delete_node(int key){
	struct node *tmp,*key_node=NULL;
	if(root==NULL){
		return;
	}
	if (root->left == NULL && root->right == NULL) { 
        if (root->data== key){
        	root=NULL;
		}
		return;
	}        
	push(root);
	while(front!=NULL){
		tmp=pop();
		if(tmp->data==key)
		key_node=tmp;
		if(tmp->left){
			push(tmp->left);
		}
		if(tmp->right){
			push(tmp->right);
		}
	}
	if (key_node!=NULL){
		int x=tmp->data;
		lastnode(tmp);
		key_node->data=x;
	}
	else{
		printf("%d not found\n",&key);
	}
}
	

void preorder(struct node* temp){
	if (temp == NULL)
        return;
    printf("%d  ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}
 
void inorder(struct node* temp){
    if (temp == NULL)
        return;
    inorder(temp->left);
    printf("%d  ",temp->data);
    inorder(temp->right);
}
#this is a level order search i.e bfs
void search(int key){
	struct node *tmp;
	push(root);
	while(front!=NULL){
		tmp=pop();
		if(tmp->data==key){
			printf("%d exists in the binary tree \n",key);
			return;
		}
		else{
			if(tmp->left)
			push(tmp->left);
			if(tmp->right)
			push(tmp->right);
		}
	}	
}

int main(){
	int i,m;
	struct node *p;
	do{
	printf("1.insert node\n");
	printf("2.delete node\n");
	printf("3.search node\n");
	printf("4. Inorder traversal\n");
	printf("5. Preorder Traversal\n");
	printf("6. Exit\n");
	printf("Enter your choice:");
	scanf("%d",&i);
	switch(i){
		case 1:
			insert();clear();break;
		case 2:
			printf("Enter the element to delete :");
			scanf("%d",&m);
			delete_node(m);clear();
			break;
		case 3:
			printf("Enter the element to search:");
			scanf("%d",&m);
			search(m);
			clear();
			break;
		case 4:
			inorder(root);printf("\n");break;
		case 5:
			preorder(root);printf("\n");break;
		case 6:break;
		default:printf("invalid input\n");
						
	}
	}while(i!=6);
	
	
	return 0;
	
}
