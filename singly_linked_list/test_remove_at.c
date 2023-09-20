#include <assert.h>

#include "singly_linked_list.h"

int test_remove_at() {
    SinglyLinkedList list = create_list();
    append_data(&list, 1);
    append_data(&list, 2);
    append_data(&list, 3);
    assert(remove_data_at(&list, 10) == 1);
    assert(list.count == 3);
    assert(remove_data_at(&list, 1) == 0);
    assert(list.count == 2);
    assert(list.head->data == 1);
    assert(list.head->next->data == 3);
    assert(list.tail->data == 3);
    assert(list.tail->next == NULL);
    delete_list(&list);

    return 0;
}
