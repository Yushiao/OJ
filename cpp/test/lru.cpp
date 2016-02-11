// #include <iostream>
class LRUCache{
public:
    int *key_list;
    int *value_list;
	int max_capacity;
	int now_capacity;

    LRUCache(int capacity) {
		max_capacity = capacity;
		now_capacity = 0;
        key_list = new int[capacity];
        value_list = new int[capacity];
		for(int i = 0; i < capacity; i++){
			key_list[i] = -1;
		}
    }

    int get(int key) {
        int result = -1;
		for(int i = 0; i < now_capacity; i++){ // find
			if(key_list[i] == key){
				result = value_list[i];
				for(; i > 0; i--){ // LRU
					value_list[i] = value_list[i-1];
					key_list[i] = key_list[i-1];
				}
				value_list[0] = result;
				key_list[0] = key;
				break;
			}
		}
		// std::cout << key << ' ' << result << std::endl;
		return result;
    }

    void set(int key, int value) {
        int result = -1;
		for(int i = 0; i < now_capacity; i++){ // find key
			if(key_list[i] == key){
				for(; i > 0; i--){ // LRU
					value_list[i] = value_list[i-1];
					key_list[i] = key_list[i-1];
				}
				result = key;
				value_list[0] = result;
				key_list[0] = key;
				break;
			}
		}
		if(result == -1){
			now_capacity++;
			if(now_capacity > max_capacity) now_capacity = max_capacity;
			for(int i = now_capacity-1; i > 0; i--){ // LRU
				value_list[i] = value_list[i-1];
				key_list[i] = key_list[i-1];
			}
			key_list[0] = key;
			value_list[0] = value;
			// if(now_capacity == max_capacity){
				// key_list[now_capacity-1] = key;
				// value_list[now_capacity-1] = value;
			// }
			// else{
				// key_list[now_capacity] = key;
				// value_list[now_capacity] = value;
				// now_capacity++;
			// }
		}
    }

};
