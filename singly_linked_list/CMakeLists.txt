add_library(singly_linked_list singly_linked_list.c)

create_test_sourcelist(
    singly_linked_list_tests
    singly_linked_list_tests.c
    test_create.c
    test_append.c
    test_remove.c
    test_insert_at.c
    test_remove_at.c
)

add_executable(test_singly_linked_list ${singly_linked_list_tests})
target_link_libraries(test_singly_linked_list singly_linked_list)

set(tests ${singly_linked_list_tests})
remove(tests singly_linked_list_tests.c)

foreach(test ${tests})
    get_filename_component(test_name ${test} NAME_WE)
    add_test(singly_linked_list/${test_name} test_singly_linked_list ${test_name})
endforeach()

add_executable(singly_linked_list_example example.c)
target_link_libraries(singly_linked_list_example singly_linked_list)
