#include <assert.h>

#include "singly_linked_list.h"

int test_insert_at() {
    SinglyLinkedList list = create_list();
    append_data(&list, 1);
    append_data(&list, 2);
    append_data(&list, 3);
    assert(insert_data_at(&list, 4, 10) == 1);
    assert(list.count == 3);
    assert(insert_data_at(&list, 4, 1) == 0);
    assert(list.count == 4);
    assert(list.head->data == 1);
    assert(list.head->next->data == 4);
    assert(list.head->next->next->data == 2);
    assert(list.head->next->next->next->data == 3);
    delete_list(&list);

    return 0;
}
