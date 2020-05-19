# trie (prefix tree)
c++ pure header template implementation 

# introdution
if you want a structure to store key-value and the key is combined with [a-zA-Z] or [0-9], trie is actually faster than map or unordered_map.

# usage 1
```
husky::trie<int> m_trie;
m_trie.insert("dummy_key", strlen("dummy_key"), 12345);
int result = m_trie.search("dummy_key", strlen("dummy_key"));
```

# usage 2
```
struct xyz {
  int a;
  double b;
};
husky::trie<xyz> m_trie;
m_trie.insert("dummy_key", strlen("dummy_key"), {1, 2.0});
xyz& result = m_trie.search("dummy_key", strlen("dummy_key"));
```
