#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// 1. Insert at end
void insert_at_end(int data) {
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

    temp->next = newnode;
    newnode->next = head;
}

// 2. Delete node with given data
void delete_node(int data) {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    // if only one node
    if(head->next == head && head->data == data) {
        free(head);
        head = NULL;
        return;
    }

    // if head node is to be deleted
    if(head->data == data) {
        // find last node
        struct node *last = head;
        while(last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
        return;
    }

    // search for node
    do {
        prev = temp;
        temp = temp->next;
    } while(temp != head && temp->data != data);

    if(temp->data != data) {
        printf("Data not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// (Optional) Traverse for checking
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
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_end(40);

    traverse();

    delete_node(10);
    traverse();

    delete_node(30);
    traverse();

    return 0;
}