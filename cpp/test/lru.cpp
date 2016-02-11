#include <iostream>
#include <cstring>
#include <map>
class LRUCache{
public:
    int *key_list;
    int max_capacity;
    int now_capacity;
	std::map<int,int> mymap;

    LRUCache(int capacity) {
        max_capacity = capacity;
        now_capacity = 0;
        key_list = new int[capacity];
        for(int i = 0; i < capacity; i++){
            key_list[i] = -1;
        }
    }

    int get(int key) {
        int result = -1;
		if(mymap.count(key)>0){ // check exist
			result = mymap[key];
			for(int i = 0; i < now_capacity; i++){ // find key location
				if(key_list[i] == key){ // found
					memcpy(key_list+1, key_list, sizeof(int)*i); // move key
					key_list[0] = key;
					break;
				}
			}
		}
        std::cout << key << ' ' << result << std::endl;
        return result;
    }

    void set(int key, int value) {
		if(mymap.count(key)>0){ // check exist
			for(int i = 0; i < now_capacity; i++){ // find key location
				if(key_list[i] == key){ // found
					memcpy(key_list+1, key_list, sizeof(int)*i); // move key
					key_list[0] = key;
					break;
				}
			}
			mymap[key] = value;
		}
		else{
            now_capacity++;
            if(now_capacity > max_capacity) {
                now_capacity = max_capacity;
                mymap.erase(key_list[max_capacity-1]);
            }
            memcpy(key_list+1, key_list, sizeof(int)*(now_capacity-1));
            key_list[0] = key;
			mymap[key] = value;
		}
    }
};
