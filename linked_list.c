#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
void printList(struct Node* n){
	while(n != NULL){
		printf("%d ", n->data);
		n = n->next;
	}
	printf("\n");
}
void push(int position, int new_data, struct Node** head_ref){//insert at tail when position = -1
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = new_data;
	new->next = NULL;
	if(*head_ref==NULL){//empty list case
		(*head_ref) = new;
		return;
	}
	else if(position == 0){//place new node at beginning
		new->next = (*head_ref);
		(*head_ref) = new;
		return;
	}
	else if(position == -1){
		struct Node* temp = *head_ref;
		while(temp != NULL){
			temp = temp->next;
		}
		temp->next = new;
		return;
	}
	else{//insert in between nodes
		struct Node* temp = *head_ref;
		for(int i = 0; i < position-1; i++){
			temp = temp->next;
		}
		new->next = temp->next;
		temp->next = new;
		return;
	}
			
}
int main(){
	struct Node* head = NULL;
	push(0, 7, &head);//7
	push(0, 35, &head);//35 7
	push(1, 12, &head);//35 12 7
	push(2, 85, &head);// 35 12 85 7
	printList(head);
	return 0;
}

