#include <iostream>
#include <list>

int main() {
    // Create two lists
    std::list<int> list1 = {1, 2, 3};
    std::list<int> list2 = {4, 5, 6};

    // Assume iter1 is an iterator pointing to a position in list1
    auto iter1 = list1.begin();  // iterator in list1

    // Insert elements from list2 behind the elements pointed to by iter1 in list1
    list1.insert(++iter1, list2.begin(), list2.end());

    // Display the modified list1 and list2
    std::cout << "Modified list1: ";
    for (const auto& value : list1) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Original list2: ";
    for (const auto& value : list2) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
