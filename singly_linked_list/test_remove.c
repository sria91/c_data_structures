#include <assert.h>

#include "singly_linked_list.h"

int test_remove() {
    SinglyLinkedList list = create_list();
    append_data(&list, 1);
    append_data(&list, 2);
    append_data(&list, 3);
    assert(remove_data(&list, 0) == 1);
    assert(list.count == 3);
    assert(list.head->data == 1);
    assert(list.head->next->data == 2);
    assert(list.head->next->next->data == 3);
    assert(remove_data(&list, 2) == 0);
    assert(list.count == 2);
    assert(list.head->data == 1);
    assert(list.head->next->data == 3);
    assert(list.head->next->next == NULL);
    assert(list.tail->data == 3);
    assert(list.tail->next == NULL);
    assert(remove_data(&list, 1) == 0);
    assert(list.count == 1);
    assert(list.head->data == 3);
    assert(list.head->next == NULL);
    assert(list.tail->data == 3);
    assert(list.tail->next == NULL);
    assert(remove_data(&list, 3) == 0);
    assert(list.count == 0);
    assert(list.head == NULL);
    assert(list.tail == NULL);
    delete_list(&list);

    return 0;
}
