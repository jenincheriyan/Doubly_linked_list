#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head= NULL;
struct Node*tail= NULL;

int isempty(){
    if (head==NULL){
        return -1;
    }

}

void insert_beginning(int value){

    struct Node* new_node= (struct Node*) malloc(sizeof(struct Node));
    new_node->data=value;
    new_node->prev=NULL;

    if (isempty()==-1){
        new_node->next= NULL;
        head= new_node;
        tail=new_node;
    }
    new_node->next=head;
    head= new_node;
    tail->next= NULL;
    printf("%d %d",head->data,tail->data);

}
void insert_end(int value){
    struct Node* new_node= (struct Node*) malloc(sizeof(struct Node));
    new_node->data=value;
    new_node->next=NULL;
     if (isempty()==-1){
        new_node->next= NULL;
        head= new_node;
        tail=new_node;
    }
    new_node->prev=tail;
    tail->next=new_node;
    tail=new_node;
    printf("%d %d",head->data,tail->data);
}
void insert_specific_point( int value,int position){
    struct Node* new_node= (struct Node*) malloc(sizeof(struct Node));
    new_node->data=value;
    new_node->next=NULL;
    new_node->prev=NULL;
    struct Node* temp=head;
    int i=1;
    
    if(isempty()==-1&&position!=1){
        printf("The list is empty bro\n ");
        return;
    }
    if (position==1){
        insert_beginning(value);
        return;
    }
    while(i!= position-1&&temp!=NULL){
        temp=temp->next;
        i++;
    }
    if (temp==NULL){
        printf("Out of Range\n ");
        free(new_node);
        return;
    }
    new_node->next=temp->next;
    new_node->prev=temp;
    temp->next->prev= new_node;
    temp->next=new_node;
    printf("%d inserted",new_node->data);
}
void display(){
    struct Node* temp;
    temp= head;
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp= temp->next;
    }
}
void main(){
    int value;
    int choice;
    int position;
    while(choice!=5){

        printf("Enter Your Choice\n");
        printf("1 insert at beginning\n"
        "2 to insert at the end\n3 to display\n4 to insert at a specific position\n5 to exit: " );
        scanf("%d",&choice);


        switch (choice)
        {
        case 1:
            printf("enter the value to insert: ");
            scanf("%d", &value);
            insert_beginning(value);
            break;

        case 2:
            printf("enter the value to insert: ");
            scanf("%d", &value);
            insert_end(value);
            break;

        case 3:
            display();
            break;
        
        case 4:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("enter the value to insert: ");
            scanf("%d", &value);
            insert_specific_point(value,position);
            break;
        case 5:
            choice=5;
            break;
        default:
            printf("invalid option selected");
            break;

        }
    }
}