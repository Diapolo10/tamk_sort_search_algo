// I've decided to try and use Timsort for this,
// which combines insertion sort and merge sort.

#pragma once
#include <algorithm>
#include <vector>

namespace non_std {

    const int RUN = 32;

    template <typename K, typename V>
    struct Node {
        K key;
        V value;
    };

    template <typename K, typename V>
    void insertion_sort(std::vector<Node<K, V>>& vec, int left, int right) {

        for (int i{left + 1}; i <= right; ++i) {

            Node<K, V> temp = vec.at(i);
            int j{i - 1};

            while (j >= left && vec.at(j).key > temp.key) {
                vec.at(j+1) = vec.at(j);
                --j;
            }

            vec.at(j+1) = temp;
        }
    }
 
    template <typename K, typename V>
    void merge(std::vector<Node<K, V>>& vec, int l, int m, int r) {
     
        // Original vector is broken into two parts,
        // left and right array
        int len1 = m - l + 1, len2 = r - m;
        Node<K, V> left[len1], right[len2];
        for (int i{}; i < len1; ++i)
            left[i] = vec.at(l + i);
        for (int i{}; i < len2; ++i)
            right[i] = vec.at(m + 1 + i);
 
        int i{};
        int j{};
        int k{l};
 
        // After comparing, we
        // merge those two arrays
        // back into the vector
        while (i < len1 && j < len2) {

            if (left[i].key <= right[j].key) {
                vec.at(k) = left[i];
                ++i;
            }
            else {
                vec.at(k) = right[j];
                ++j;
            }
            ++k;
        }
 
        // Copy remaining elements of left, if any
        while (i < len1)
        {
            vec.at(k) = left[i];
            ++k;
            ++i;
        }
 
        // Copy remaining element of right, if any
        while (j < len2)
        {
            vec.at(k) = right[j];
            ++k;
            ++j;
        }
    }
 
    template <typename K, typename V>
    void tim_sort(std::vector<Node<K, V>>& vec) {
        /*
         * A Timsort implementation
         *
         * Combines insertion sort
         * and merge sort to make
         * the algorithm faster
         * 
         * In theory, has
         * O(n log n) worst-case
         */
    
        auto n{vec.size()};

        for (unsigned long i{}; i < n; i += RUN)
            insertion_sort(vec, i, std::min((i+RUN-1), (n-1)));
 
        for (unsigned long size{RUN}; size < n; size *= 2) {
         
            for (unsigned long left = 0; left < n; left += 2*size) {
             
                unsigned long mid{left + size - 1};
                unsigned long right{std::min((left + 2*size - 1), (n-1))};
 
                if(mid < right)
                    merge(vec, left, mid, right);
            }
        }
    }
}
