#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// 1. Insert at beginning
void insert_at_beginning(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;

    // if list is empty
    if(head == NULL) {
        newnode->next = newnode;
        head = newnode;
        return;
    }

    struct node *temp = head;

    // go to last node
    while(temp->next != head)
        temp = temp->next;

    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}

// 2. Traverse
void traverse() {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct node *temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(head)\n");
}

// Main
int main() {
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_beginning(30);

    traverse();

    return 0;
}