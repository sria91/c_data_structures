#include <stdlib.h>
#include <stdio.h>

#include "singly_linked_list.h"

/**
 * @brief Creates a new node for a singly linked list on the heap.
 *
 * @param data The value to be stored in the node.
 * @param next A pointer to the next node in the list.
 * @return A pointer to the newly created node, or `NULL` if out of memory.
 *
 * This function creates a new node for a singly linked list on the heap. 
 * The node contains the specified data and a pointer to the next node in 
 * the list. If the function runs out of memory while creating the new node, 
 * it returns `NULL`.
 */
static inline Node * create_node(int data, Node * next) {
    Node * node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

/**
 * @brief Creates a new empty singly linked list on the stack.
 *
 * @return The newly created singly linked list.
 *
 * This function creates a new empty singly linked list on the stack. The list 
 * has no nodes and its head and tail are set to `NULL`, and count is set to `0`. 
 * The function returns the newly created list.
 */
SinglyLinkedList create_list() {
    SinglyLinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.count = 0;
    return list;
}

/**
 * @brief Appends a new node with the given data to the end of a singly linked list.
 *
 * @param list A pointer to the singly linked list to append to.
 * @param data The value to be stored in the new node.
 * @return `0` if the node was successfully appended, `-1` if out of memory.
 *
 * This function appends a new node with the given data to the end of a singly linked list. 
 * If the function runs out of memory while creating the new node, it returns `-1`. 
 * If the list is empty, the function sets both the head and tail pointers to the new node. 
 * Otherwise, the function sets the `next` pointer of the current tail node to the new node, 
 * and updates the tail pointer to point to the new node. The function increments the list's count 
 * and returns `0` to indicate success.
 */
int append_data(SinglyLinkedList * list, int data) {
    Node * node = create_node(data, NULL);
    if (node == NULL) return -1;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->count++;
    return 0;
}

/**
 * @brief Removes the first node with the given data from a singly linked list.
 *
 * @param list A pointer to the singly linked list to remove from.
 * @param data The value to be removed from the list.
 * @return `0` if the node was successfully removed, `1` if the data was not found.
 *
 * This function removes the first node with the given data from a singly 
 * linked list. If the node is found and removed, the function returns `0`. 
 * If the node is not found, the function returns `1` and the list is not 
 * modified. If the node to be removed is the head of the list, the function 
 * updates the head pointer to point to the next node in the list. If the node 
 * to be removed is the tail of the list, the function updates the tail pointer 
 * to point to the previous node in the list. The function frees the memory 
 * used by the removed node and decrements the list's count. If the list is 
 * empty, the function does nothing and returns `1`.
 */
int remove_data(SinglyLinkedList * list, int data) {
    Node * node = list->head;
    Node * prev = NULL;
    while (node != NULL) {
        if (node->data == data) {
            if (prev == NULL) {
                list->head = node->next;
            } else {
                prev->next = node->next;
            }
            if (node->next == NULL) {
                list->tail = prev;
            }
            free(node);
            list->count--;
            return 0;
        }
        prev = node;
        node = node->next;
    }
    return 1;
}

/**
 * @brief Removes the node at the specified index from a singly linked list.
 *
 * @param list A pointer to the singly linked list to remove from.
 * @param index The index of the node to remove.
 * @return `0` if the node was successfully removed, `1` if the index is out of range.
 *
 * This function removes the node at the specified index from a singly linked list. 
 * If the index is out of range, the function returns `1` and the list is not modified. 
 * If the node to be removed is the head of the list, the function updates the head 
 * pointer to point to the next node in the list. If the node to be removed is the tail 
 * of the list, the function updates the tail pointer to point to the previous node in 
 * the list. The function frees the memory used by the removed node and decrements the 
 * list's count. If the list is empty, the function does nothing and returns `1`.
 */
int remove_data_at(SinglyLinkedList * list, size_t index) {
    if (index >= list->count) {
        return 1;
    }
    if (index == 0) {
        Node * node = list->head;
        list->head = node->next;
        if (node->next == NULL) {
            list->tail = NULL;
        }
        free(node);
        list->count--;
        return 0;
    }
    Node * node = list->head;
    for (size_t i = 0; i < index - 1; i++) {
        node = node->next;
    }
    Node * next_node = node->next;
    node->next = next_node->next;
    if (next_node->next == NULL) {
        list->tail = node;
    }
    free(next_node);
    list->count--;
    return 0;
}

/**
 * @brief Inserts a new node with the given data at the specified index in a singly linked list.
 *
 * @param list A pointer to the singly linked list to insert into.
 * @param data The value to be stored in the new node.
 * @param index The index at which to insert the new node. Indexing starts at `0`.
 * @return `0` if the node was successfully inserted, `-1` if out of memory and `1` if the index is out of bounds.
 *
 * This function inserts a new node with the given data at the specified index in a singly linked list. 
 * If the function runs out of memory while creating the new node, it returns `-1`. 
 * If the index is out of bounds (greater than the list's count), the function returns `1` and the 
 * list is not modified. If the index is `0`, the function inserts the new node at the head of the list. 
 * If the index is equal to the list's count, the function appends the new node to the end of the list. 
 * Otherwise, the function traverses the list to find the node at the specified index, and inserts 
 * the new node after that node. The function increments the list's count and returns `0` to indicate success.
 */
int insert_data_at(SinglyLinkedList * list, int data, size_t index) {
    if (index > list->count) {
        return 1;
    }
    if (index == 0) {
        Node * node = create_node(data, list->head);
        if (node == NULL) return -1;
        list->head = node;
        if (list->tail == NULL) {
            list->tail = node;
        }
        list->count++;
        return 0;
    }
    if (index == list->count) {
        return append_data(list, data);
    }
    Node * node = list->head;
    for (size_t i = 0; i < index - 1; i++) {
        node = node->next;
    }
    Node * new_node = create_node(data, node->next);
    if (new_node == NULL) return -1;
    node->next = new_node;
    list->count++;
    return 0;
}

/**
 * @brief Deletes all nodes in a singly linked list and resets its head, tail, and count.
 *
 * @param list A pointer to the singly linked list to delete.
 *
 * This function deletes all nodes in a singly linked list and resets its head, tail, and 
 * count. If the list is already empty, the function does nothing. The function frees the 
 * memory used by each node in the list by traversing the list and calling `free()` on each 
 * node. After all nodes have been freed, the function sets the head and tail pointers to 
 * `NULL` and the count to `0`.
 */
void delete_list(SinglyLinkedList * list) {
    Node * node = list->head;
    if (node == NULL) return;
    while (node != NULL) {
        Node * next = node->next;
        free(node);
        node = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

/**
 * @brief Displays the values of all nodes in a singly linked list.
 *
 * @param list A pointer to the singly linked list to display.
 *
 * This function displays the values of all nodes in a singly linked list. 
 * If the list is empty, the function prints "[]" to the console. Otherwise, 
 * the function prints the values of all nodes in the list, separated by commas 
 * and enclosed in square brackets. The function does not modify the list in any way.
 */
void display_list(SinglyLinkedList * list) {
    Node * node = list->head;
    if (node == NULL) {
        printf("[]\n");
        return;
    }
    printf("[");
    while (node->next != NULL) {
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("%d]\n", node->data);
    fflush(stdout);
}
