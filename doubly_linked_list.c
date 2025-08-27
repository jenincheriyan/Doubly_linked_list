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
        return 1;
    }
    return 0;

}

void insert_beginning(int value){

    struct Node* new_node= (struct Node*) malloc(sizeof(struct Node));
    new_node->data=value;
    new_node->prev=NULL;
    new_node->next=head;

    if (isempty()){
        head = tail = new_node;
    }
    else{
        head->prev = new_node;
        head= new_node;
    }
}
void insert_end(int value){
    struct Node* new_node= (struct Node*) malloc(sizeof(struct Node));
    new_node->data=value;
    new_node->next=NULL;
     if (isempty()){
        new_node->prev= NULL;
        head= new_node;
        tail=new_node;
    }
    else{
    new_node->prev=tail;
    tail->next=new_node;
    tail=new_node;
    }
    
}
void insert_specific_point( int value,int position){
    struct Node* new_node= (struct Node*) malloc(sizeof(struct Node));
    new_node->data=value;
    new_node->next=NULL;
    new_node->prev=NULL;
    struct Node* temp=head;
    int i=1;
    
    if(isempty()&&position!=1){
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
    if (temp->next== NULL){
        insert_end(value);
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
void search(int value){
    if (isempty()){
        printf("The list is empty\n");
        return;
    }
    struct Node* temp;
    temp=head;
    int position=1;
    while(temp!=NULL&&temp->data!=value){
        temp=temp->next;
        position++;
    }
    if (temp==NULL){
        printf("Not Found");
        return;
    }
    printf("%d found at %d\n", temp->data , position);
}
void delete_at_beginning(){
    if (isempty()){
        printf("The list is Empty\n");
        return;
    }
    
    struct Node* temp = head;
    if (head==tail){
        head= tail=NULL;
    }
    else{
        head=temp->next;
        head->prev=NULL;
    }
    printf("%d removed\n", temp->data);
    free(temp);
    
}
void delete_at_end(){
    if (isempty()){
        printf("The list is Empty\n");
        return;
    }
    struct Node* temp= tail;
    if (head == tail) {
        head = tail = NULL;
    }
    else{
        tail=temp->prev;
        tail->next = NULL;
    }
    printf("%d removed\n", temp->data);
    free(temp);
    return;

}
void delete_at_value(int value){
    if(isempty()){
        printf("The list is empty\n");
        return;
    }
    if(head==tail&&head->data==value){
        printf("%d removed\n",head->data); 
        free(head);
        head=tail=NULL;
        return;
    }
    struct Node* temp= head;
    if(head->data==value){
        head= head->next;
        head->prev=NULL;
        printf("%d removed\n",temp->data);
        free(temp);
        return;
    }
    
    //find node
    while(temp!=NULL&&temp->data!=value){
        temp=temp->next;
    }
    //value not found
    if(temp==NULL){
        printf("Value not found\n");
        return;
    }
    
    
    else if(temp->next==NULL){
        tail=temp->prev;
        tail->next=NULL;
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    printf("%d removed\n", temp->data);   
    free(temp);
}
void main(){
    int value;
    int choice=0;
    int position;
    while(choice!=5){

        printf("Enter Your Choice\n");
        printf("1 Insert at beginning\n"
        "2 To insert at the end\n3 To display\n4 To insert at a specific position\n5 To exit\n" 
        "6 To search by value\n7 To delete at the beginning\n8 To delete at the end\n9 To delete by value: ");
        if (scanf("%d",&choice)!=1){
            printf("Invalid input, Enter a integer\n");
            while (getchar() !='\n');
        }


        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert_beginning(value);
            break;

        case 2:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert_end(value);
            break;

        case 3:
            display();
            break;
        
        case 4:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert_specific_point(value,position);
            break;
        case 5:
            choice=5;
            break;
        case 6:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 7:
            delete_at_beginning();
            break;
        case 8:
            delete_at_end();
            break;
        case 9:
            printf("Enter the value to remove: ");
            scanf("%d", &value);
            delete_at_value(value);
            break;
        default:
            printf("Invalid option selected\n");
            break;

        }
    }
}