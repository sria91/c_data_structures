#pragma once

#include <stddef.h>

typedef struct Node_ {
    int data;
    struct Node_ * next;
} Node;

typedef struct SinglyLinkedList_ {
    Node * head;
    Node * tail;
    size_t count;
} SinglyLinkedList;

SinglyLinkedList create_list();

int append_data(SinglyLinkedList * list, int data);

int remove_data(SinglyLinkedList * list, int data);

int remove_data_at(SinglyLinkedList * list, size_t index);

int insert_data_at(SinglyLinkedList * list, int data, size_t index);

void delete_list(SinglyLinkedList * list);

void display_list(SinglyLinkedList * list);
