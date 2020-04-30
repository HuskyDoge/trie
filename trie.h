#pragma once
#include <stdexcept>

namespace husky {
    const int KEY_SIZE = 'z' - 'a' + 1 + 10; // alphabet + number

    template<typename T>
    class trie_node {
    public:
        trie_node *children[KEY_SIZE];
        T data;

        trie_node() {
            memset(children, 0, sizeof(children));
        }

        ~trie_node() {
            for (int i = 0; i < KEY_SIZE; ++i) {
                if (children[i] != nullptr) {
                    delete children[i];
                    children[i] = nullptr;
                }
            }
        }
    };

    template<typename T>
    class trie {
    public:
        trie() {
            root = new trie_node<T>();
        }

        ~trie() {
            delete root;
            root = nullptr;
        }

        // convert char to the corresponding index
        inline static int char2idx(const int c) {
            if (c <= 57) { // number
                return c - 22;
            } else if (c <= 90) { // upper case
                return c + 32 - 'a';
            } else { // lower case
                return c - 'a';
            }
        }

        void insert(const char *s, int N, T t) {
            trie_node<T> *current = root;
            for (int i = 0; i < N; ++i) {
                int curidx = char2idx(s[i]);
                if (current->children[curidx] == nullptr) {
                    current->children[curidx] = new trie_node<T>();
                }
                current = current->children[curidx];
            }
            current->data = t;
        }

        T& search(const char *s, int N) {
            if (N == 0) throw std::runtime_error("trie N cannot be zero");
            trie_node<T> *current = root;
            for (int i = 0; i < N; ++i) {
                current = current->children[char2idx(s[i])];
                if (current == nullptr) throw std::runtime_error("cannot find key in trie");
            }
            return current->data;
        }

    private:
        trie_node<T> *root;
    };
}