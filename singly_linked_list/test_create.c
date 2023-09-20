#include <assert.h>

#include "singly_linked_list.h"

int test_create() {
    SinglyLinkedList list = create_list();
    assert(list.head == NULL);
    assert(list.tail == NULL);
    assert(list.count == 0);
    delete_list(&list);

    return 0;
}
