#include <iostream>
#include <vector>

#include "sort.hpp"
#include "find.hpp"
#include "utility.h"

template <typename K, typename V>
void print_vector(std::vector<non_std::Node<K, V>> vec) {
    std::cout << "{\n";
    for (auto &node : vec)
        std::cout << "    {" << node.key << ", " << node.value << "},\n";
    std::cout << "}\n";
}

int main() {
    auto data = std::vector<non_std::Node<int, int>>{
        {-2, 1}, {7, 2}, {15, 3}, {-14, 4}, {0, 5},
        {15, 6}, {0, 7}, {7, 8}, {-7, 9}, {-4, 10},
        {-13, 11}, {5, 12}, {8, 13}, {-14, 14}, {12, 15}
    };

    int key{5};

    std::cout << "Unsorted data:\n";
    print_vector(data);

    non_std::tim_sort(data);

    std::cout << "\nSorted data:\n";
    print_vector(data);

    auto result = non_std::binary_search(data, key);

    if (result != -1) {
        std::cout << "\nFound " << key << " at index " << result << std::endl;
    }
    else {
        std::cout << "\n" << key << " not found.";
        return not_present;
    }

    return success;
}
