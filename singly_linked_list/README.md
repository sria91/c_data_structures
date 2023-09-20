# Singly Linked List

This directory contains a C implementation of a singly linked list data structure. The implementation provides functions for creating, appending, inserting, deleting, and displaying nodes in the list.

## Usage

To use the singly linked list implementation, include the `singly_linked_list.h` header file in your C program and link against the `singly_linked_list.c` source file.

```c
#include "singly_linked_list.h"

int main() {
    SinglyLinkedList list = create_list();
    append_data(&list, 1);
    display_list(&list);
    append_data(&list, 2);
    display_list(&list);
    insert_data_at(&list, 3, 1);
    display_list(&list);
    remove_data(&list, 2);
    display_list(&list);
    remove_data_at(&list, 0);
    display_list(&list);
    delete_list(&list);
    return 0;
}
```

## API

The following functions are provided by the singly linked list implementation:

### `SinglyLinkedList create_list()`

Creates a new empty singly linked list on the stack.

### `int append_data(SinglyLinkedList * list, int data)`

Appends a new node with the given data to the end of a singly linked list.

### `int insert_data_at(SinglyLinkedList * list, int data, size_t index)`

Inserts a new node with the given data at the specified index in a singly linked list.

### `int remove_data(SinglyLinkedList * list, int data)`

Removes the first node with the given data from a singly linked list.

### `int remove_data_at(SinglyLinkedList * list, size_t index)`

Removes the node at the specified index from a singly linked list.

### `void display_list(SinglyLinkedList * list)`

Displays the contents of a singly linked list.

### `void delete_list(SinglyLinkedList * list)`

Deletes all nodes in a singly linked list and resets its head, tail, and count.

## License

This implementation is licensed under the MIT License. See the [`LICENSE`](/LICENSE) file for details.
