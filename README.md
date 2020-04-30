# trie (prefix tree)
c++ pure header template implementation 

# usage 1
husky::trie<int> m_trie;
m_trie.insert("dummy_key", strlen("dummy_key"), 12345);
int result = m_trie.search("dummy_key", strlen("dummy_key"));

# usage 2
struct xyz {
  int a;
  double b;
};
husky::trie<xyz> m_trie;
m_trie.insert("dummy_key", strlen("dummy_key"), {1, 2.0});
xyz& result = m_trie.search("dummy_key", strlen("dummy_key"));
