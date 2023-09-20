#include <assert.h>

#include "singly_linked_list.h"

int test_append() {
    SinglyLinkedList list = create_list();
    assert(append_data(&list, 1) == 0);
    assert(list.head != NULL);
    assert(list.head == list.tail);
    assert(list.count == 1);
    assert(append_data(&list, 2) == 0);
    assert(list.count == 2);
    assert(append_data(&list, 3) == 0);
    assert(list.count == 3);
    assert(list.head->data == 1);
    assert(list.head->next->data == 2);
    assert(list.head->next->next->data == 3);
    delete_list(&list);

    return 0;
}
