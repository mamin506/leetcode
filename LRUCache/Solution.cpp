#inlcude "../mlibs.h"

using namespace std;

class LRUCache {
private:
    int cap;
    unordered_map<int, list<pair<int, int> >::iterator> map;
    list<pair<int, int> > lst;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        lst.push_front(*it->second);
        lst.erase(it->second);
        it->second = lst.begin();
        return it->second->second;
    }

    void set(int key, int value) {
        auto it = map.find(key);
        if (it == map.end()) {
            while (map.size() >= cap) {
                map.erase(lst.crbegin()->first);
                lst.pop_back();
            }
        } else {
            lst.erase(it->second);
        }
        lst.push_front({key, value});
        map[key] = lst.begin();
    }

};

int main(int argc, char *argv[]) {
    Solution sol1;
    return 0;
}

