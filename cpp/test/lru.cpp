#include <iostream>
#include <cstring>
#include <unordered_map>
#include <list>

class LRUCache{
public:
    int m_capacity;
    typedef std::list<std::pair<int, int>>::iterator list_iterator;
    typedef std::unordered_map<int, list_iterator>::iterator map_iterator;
    std::unordered_map<int, list_iterator> m_map; // first: key, second: list iterator
    std::list<std::pair<int, int>> m_list; // first: key, second: value

    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        map_iterator found = m_map.find(key);
        if(found == m_map.end()){ // key does not exist
            return -1;
        }
        m_list.splice(m_list.begin(), m_list, found->second); // move to begin
        return found->second->second;
    }

    void set(int key, int value) {
        map_iterator found = m_map.find(key);
        if(found != m_map.end()){ // key exists
            m_list.splice(m_list.begin(), m_list, found->second); // move to begin
            found->second->second = value;
            return;
        }

        if(m_map.size() == m_capacity){
           int del_key = m_list.back().first;
           m_list.pop_back(); //remove node in list;
           m_map.erase(del_key); //remove key in map
        }

        m_list.emplace_front(key, value); // create node at begin
        m_map[key] = m_list.begin(); // create node in map
    }
};
