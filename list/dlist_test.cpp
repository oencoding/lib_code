#include <cassert>
#include <iostream>
#include <string>
#include <initializer_list>
#include "dlist.h"

#define NAME(list) #list

template <typename T>
void insert_inorder(Dlist<T> &list, std::initializer_list<T> il)
{
    for (auto &val : il) {
        list_insert_back(list, list_new_node(val));
    }
}

template <typename T>
void insert_reverse(Dlist<T> &list, std::initializer_list<T> il)
{
    for (auto &val : il) {
        list_insert_front(list, list_new_node(val));
    }
}

template <typename T>
void remove_inorder(Dlist<T> &list, const std::string &list_name="list")
{
    std::cout << "free " << list_name << ": ";
    while (!list_is_empty(list)) {
        auto node = list_remove_front(list);
        std::cout << node->value << ", ";
       	list_free_node(node);
    }
    std::cout << std::endl;
}

template <typename T>
void remove_reverse(Dlist<T> &list, const std::string &list_name="list")
{
    std::cout << "free " << list_name << ": ";
    while (!list_is_empty(list)) {
        auto node = list_remove_back(list);
        std::cout << node->value << ", ";
       	list_free_node(node);
    }
    std::cout << std::endl;
}

template <typename T>
void print(Dlist<T> &list, const std::string &beg="", const std::string &end="")
{
    std::cout << beg;
    list_for_each(list, [](Dlist_node<T> *node) { std::cout << node->value << ", "; });
    std::cout << end;
}

template <typename T>
bool test_empty(Dlist<T> &list, const std::string &list_name="list")
{
    auto is_empty = list_is_empty(list);
    if (is_empty) {
        std::cout << list_name << " is empty!";
    } else {
        print(list, list_name+": [", "]");
    }
    std::cout << std::endl;

    return is_empty;
}

template <typename T>
bool test_replace(Dlist<T> &list, T val, T new_val, const std::string &list_name="list")
{
    auto x = list_search(list, val);
    if (x == &list.nil) {
        std::cout << "not found " << val << " in " << list_name << "!" << std::endl;
        return false;
    }

    std::cout << "found " << val << " in " 
        << list_name << "!" << std::endl;
    std::cout << "replace " << val << " with " << new_val << std::endl;
    auto t = list_new_node(new_val);
    list_insert(x, t);
    list_remove(x);
    print(list, "after replace, "+list_name+": [", "]");
    std::cout << std::endl;
    return true;
}

int main(int argc, char *argv[])
{
    typedef Dlist<int> List;
    typedef Dlist_node<int> Node;

    List list1, list2;
    list_init(list1);
    list_init(list2);

    std::cout << "---------------------------" << std::endl;
    std::cout << "after init" << std::endl;
    bool is_empty;
    is_empty = test_empty(list1, NAME(list1));
    assert(is_empty);
    is_empty = test_empty(list2, NAME(list2));
    assert(is_empty);

    insert_inorder(list1, {1, 3, 5, 7, 9});
    insert_reverse(list2, {0, 2, 4, 6, 8});

    std::cout << "---------------------------" << std::endl;
    std::cout << "after insert" << std::endl;
    is_empty = test_empty(list1, NAME(list1));
    assert(!is_empty);
    is_empty = test_empty(list2, NAME(list2));
    assert(!is_empty);

    std::cout << "---------------------------" << std::endl;
    std::cout << "test replace" << std::endl;
    int val = 3;
    int new_val = 19;
    bool is_found;
    is_found = test_replace(list1, val, new_val, NAME(list1));
    assert(is_found);
    is_found = test_replace(list2, val, new_val, NAME(list2));
    assert(!is_found);

    std::cout << "---------------------------" << std::endl;
    std::cout << "after replace" << std::endl;
    is_empty = test_empty(list1, NAME(list1));
    assert(!is_empty);
    is_empty = test_empty(list2, NAME(list2));
    assert(!is_empty);

	return 0;
}
