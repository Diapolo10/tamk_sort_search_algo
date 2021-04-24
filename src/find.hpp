#pragma once

#include <iostream>
#include "sort.hpp"

namespace non_std {

    template <typename K, typename V>
    long binary_search(std::vector<Node<K, V>> vec, K key) {
        long left{};
        long right{vec.size()-1};

        while (left <= right) {
            std::cout << left << ' ' << right << std::endl;
            long middle{(left + right) / 2};
            
            if (vec.at(middle).key == key) {
                return middle;
            }

            if (vec.at(middle).key < key) {
                left = middle + 1;
            }

            else {
                right = middle - 1;
            }
        }

        return -1; // Not found
    }

}
