#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head;

void printList()
{


    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }


}

void count()
{
    int count = 0;
    struct node* temp = head;
    while (temp != NULL)
    {
        count = count + 1;
        temp = temp->next;
    }
    printf("\n **Task 3**\n");
    printf("Number of nodes in this linked list is %d\n", count);
}

struct node* insertAtFirst(struct node* head, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    return temp;
}

struct node* insertAtLast(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    newnode->data=value;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->next=NULL;
    return head;
}
struct node* insertAtPosition(struct  node* head,int value,int pos)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    int count=0;
    while( count!=pos-1)
    {
        temp=temp->next;
        count++;
    }
    newnode->data=value;
    newnode->next=temp->next;
    temp->next=newnode;
    return  head;

}

struct node* deleteFirstNode(struct node* head) {

    struct node* temp=head;
    head=head->next;
    free(temp);
    return head;

}
struct node* deleteBetween(struct node* head,int pos) {

    struct node* temp=head;
    struct node* q=head->next;
    for(int i=0; i<pos-1; i++) {
        temp=temp->next;
        q=q->next;
    }
    temp->next=q->next;
    free(q);
    return head;

}
struct node* deleteLastNode(struct node* head) {

    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=NULL) {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;

}
struct node* sortList(struct node* head) {
    struct node* p;
    struct node* q;
    int temp;

    p = head;
    while (p->next != NULL) {
        q = p->next;
        while (q != NULL) {
            if (p->data > q->data) {
                temp = p->data;
                p->data = q->data;
                q->data= temp;
            }
            q = q->next;
        }
        p = p->next;
    }

    return head;
}
struct node* Inverse(struct node* head) {

    struct node* prev=NULL;
    struct node* current=head;
    struct node* nextNode=NULL;
    while(current !=NULL) {

        nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;

    }

    return prev;

}
struct node* Index(struct node* head,int pos,int data) {

    int i=0;
    struct node* temp=head;
    while (temp!=NULL) {
        if(i==pos) {
            printf("value of index  %d=%d",pos,temp->data);
        }
        temp=temp->next;
        i++;



    }

    return head;
}
struct node* ValueIndex(struct node* head,int data,int pos) {

    int i=0;
    struct node* temp=head;
    while (temp!=NULL) {
        if(i==pos) {
            printf("value of index  %d=%d",temp->data,pos);
        }
        temp=temp->next;
        i++;



    }

    return head;
}

struct node* searchValue(struct node* head,int data,int pos) {

    int i=0;
    struct node* temp=head;
    while (temp!=NULL) {
        if(i==pos) {
            printf("%d is found in index = %d",temp->data,pos);
        }
        temp=temp->next;
        i++;



    }

    return head;
}

int main()
{
    struct node* firstNode = (struct node*)malloc(sizeof(struct node));
    firstNode->data = 10;
    firstNode->next = NULL;
    struct node* secondNode = (struct node*)malloc(sizeof(struct node));
    secondNode->data = 40;
    secondNode->next = NULL;
    struct node*third=(struct node*)malloc(sizeof(struct node));
    third->data=30;
    third->next=NULL;
    firstNode->next = secondNode ;
    secondNode->next=third;
    head = firstNode;

    printf("\n ***Task 1 and 2***\n");
    printList();
    printf("\n");
    count();
    printf("\n");
    printf("\nInsert in the first node\n");
    head = insertAtFirst(head, 600);
    printList();
    printf("\n");
    printf("\nInsert in the last node\n");
    head=insertAtLast(700);
    printList();
    printf("\n");
    printf("\n insert between\n");
    head=insertAtPosition(head,777,3);
    printList();
    printf("\n");
    printf("\nDelete from first node\n");
    head=deleteFirstNode(head);
    printList();
    printf("\n");
    printf("\n Delete a node between a linked list\n");
    head=deleteBetween(head,2);
    printList();
    printf("\n");
    printf("\n Delete last node from a linked list\n");
    head=deleteLastNode(head);
    printList();

    printf("\n");
    printf("\n sort the linkedlist with ascending order\n");
    head=sortList(head);
    printList();
    printf("\n");
    printf("\nInverse Linked List\n");
    head=Inverse(head);
    printList();
    printf("\n");
    printf("\nindex value\n");
    head=Index(head,1,10);
    printf("\n");
    printf("\nvalue of index\n");
    head=ValueIndex(head,10,2);
    printf("\n");
    printf("\nsearch value\n ");
    head=searchValue(head,10,2);

    return 0;
}
