#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

void add_in_beginning(int value) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = value;
    if (head == NULL){
        head = newnode;
        newnode->next = newnode;
    }
    else{
        struct Node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void add_in_end(int value){
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = value;
    if (head == NULL){
        head = newnode;
        newnode->next = newnode;
    }
    else{
        struct Node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void add_in_specific_position(int position, int value){
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = value;
    if (head == NULL){
        head = newnode;
        newnode->next = newnode;
    }
    if (head->next == head){
        newnode->next = head;
        head->next = newnode;
        head = newnode;
    }
    else {
        struct Node *temp = head;
        while(temp->next->data != position){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delete_from_beginning(){
    if (head == NULL){
        printf("the list is empty");
    }
    if (head->next == head){
        struct Node *temp0 = head;
        free(temp0);
    }
    struct Node *temp = head;
    struct Node *temp2 = head;
    while(temp->next != head){
        temp = temp->next;
    }
    head = temp2->next;
    temp->next = head;
    free(temp2);
}

void delete_from_end(){
    if (head == NULL){
        printf("the list is empty");
    }
    struct Node *temp = head;
    struct Node *temp2;
    while(temp->next != head){
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = head;
    free(temp);
}

void delete_from_specific_position(int position) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("the list is empty");
    }
    else if (head->next == head && head->data == position) {
        struct Node *temp0 = head;
        free(temp0);
        head = NULL;
    }
    while(temp->next->data != position){
        temp = temp->next;
    }
    if(temp->next->next == head){
        struct Node *templast = temp->next;
        temp->next = head;
        free(templast);
    }
    else{
        struct Node *templast = temp->next;
        temp->next = templast->next;
        free(templast);
    }
}

void display(struct Node *traverse){
    if(head == NULL)
        printf("there are no nodes here");
    while(traverse->next != head){
        printf("(%d) ->", traverse->data);
        traverse = traverse->next;
    }
    printf("(%d) -> ", traverse->data);
}

int main(void){
    head = (struct Node*)malloc(sizeof (struct Node));
    head = NULL;
    int choice, sub_choice;
    int value, position;
    again:
    printf("________________________\n");
    printf("what do you want to do: \n1.Add\n2.Delete\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("1.Beginning\n2.End\n3.In Between(position, value)\n");
            scanf("%d", &sub_choice);
            switch (sub_choice) {
                case 1:
                    printf("enter the value to be inserted in the beginning\n");
                    scanf("%d", &value);
                    add_in_beginning(value);
                    display(head);
                    break;
                case 2:
                    printf("enter the value to be inserted in the end\n");
                    scanf("%d", &value);
                    add_in_end(value);
                    display(head);
                    break;
                case 3:
                    printf("enter the value position and the value\n");
                    scanf("%d %d",&position, &value);
                    add_in_specific_position(position, value);
                    display(head);
                    break;
                default:
                    break;
            }
            break;
        case 2:
            printf("1.Beginning\n2.End\n3.In Between(position, value)\n");
            scanf("%d", &sub_choice);
            switch (sub_choice) {
                case 1:
                    printf("first value deleted\n");
                    delete_from_beginning();
                    display(head);
                    break;
                case 2:
                    printf("last value deleted\n");
                    delete_from_end();
                    display(head);
                    break;
                case 3:
                    printf("deleted\n");
                    scanf("%d",&position);
                    delete_from_specific_position(position);
                    display(head);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    printf("\ntype 0 if you are done: ");
    int zero;
    scanf("%d", &zero);
    if(zero != 0){
        goto again;
    }
}
