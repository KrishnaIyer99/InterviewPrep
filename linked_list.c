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
		while(temp->next != NULL){
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
void delete(struct Node** head_ref, int position){
	struct Node* temp = *head_ref;
	if(*head_ref == NULL){
		printf("Empty list, there are no nodes");
		return;
	}else if(position == 0){//delete head node
		*head_ref = temp->next;
		free(temp);
		return;
	}else{
		for(int i = 0; i < position - 1; i++){
			temp = temp->next;
		}
		temp->next = temp->next->next;
		free(temp->next);
	}
}
			

int main(){
	struct Node* head = NULL;
	push(0, 7, &head);//7
	printList(head);
	push(0, 35, &head);//35 7
	printList(head);
	push(-1, 12, &head);//35 7 12
	printList(head);
	push(2, 85, &head);// 35 7 85 12
	printList(head);
	delete(&head, 0);//7 85 12
	printList(head);
	delete(&head, 2);//7 85
	printList(head);
	push(-1, 6, &head);//7 85 6
	printList(head);
	push(-1, 23, &head);//7 85 6 23
	printList(head);
	push(3, 0, &head);//7 85 6 0 23
	printList(head);
	delete(&head, 2);
	printList(head);
	return 0;
}

