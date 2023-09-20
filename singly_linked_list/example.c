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
