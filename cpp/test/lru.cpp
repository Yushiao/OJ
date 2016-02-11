// #include <iostream>
#include <cstring>
#include <map>
#include <vector>
class LRUCache{
public:
    // int *key_list;
    int max_capacity;
    int now_capacity;
	std::map<int,int> mymap;
	std::vector<int> mykey;

    LRUCache(int capacity) {
        max_capacity = capacity;
		now_capacity = 0;
    }

    int get(int key) {
        int result = -1;
		if(mymap.count(key)>0){ // check exist
			result = mymap[key];
			for(int i = 0; i < now_capacity; i++){ // find key location
				if(mykey[i] == key){ // found
					mykey.erase(mykey.begin() + i);
					mykey.push_back(key);
					break;
				}
			}
		}
        // std::cout << key << ' ' << result << std::endl;
        return result;
    }

    void set(int key, int value) {
		if(mymap.count(key)>0){ // check exist
			for(int i = 0; i < now_capacity; i++){ // find key location
				if(mykey[i] == key){ // found
					mykey.erase(mykey.begin() + i);
					mykey.push_back(key);
					break;
				}
			}
			mymap[key] = value;
		}
		else{
			mykey.push_back(key);
			mymap[key] = value;
			now_capacity++;
            if(now_capacity > max_capacity) {
                mymap.erase(mykey[0]);
				mykey.erase(mykey.begin());
				now_capacity--;
            }
		}
    }
};
