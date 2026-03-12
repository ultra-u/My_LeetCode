#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    // 定义双向链表节点
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;  // 哈希表：key -> 节点指针
    Node* head;  // 虚拟头节点
    Node* tail;  // 虚拟尾节点
    
    // 将节点添加到头部（表示最近使用）
    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    // 删除节点
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    // 将节点移动到头部（表示最近使用）
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }
    
    // 删除尾部节点（最久未使用）
    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // 初始化虚拟头尾节点
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    ~LRUCache() {
        // 释放所有节点内存
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        // 如果存在，将该节点移动到头部（表示最近使用）
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // 如果 key 存在，更新值并移动到头部
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            // 如果 key 不存在，创建新节点
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            
            // 如果超出容量，删除尾部节点
            if (cache.size() > capacity) {
                Node* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
            }
        }
    }
};

int main() {
    cout << "LRU Cache Example:" << endl;
    cout << "==================" << endl;
    
    LRUCache lru(2);
    
    cout << "put(1, 1): 缓存为 {1=1}" << endl;
    lru.put(1, 1);
    
    cout << "put(2, 2): 缓存为 {1=1, 2=2}" << endl;
    lru.put(2, 2);
    
    cout << "get(1): 返回 " << lru.get(1) << " (应为 1)" << endl;
    
    cout << "put(3, 3): 缓存满，删除最久未使用的 2，缓存为 {1=1, 3=3}" << endl;
    lru.put(3, 3);
    
    cout << "get(2): 返回 " << lru.get(2) << " (应为 -1)" << endl;
    
    cout << "put(4, 4): 缓存满，删除最久未使用的 1，缓存为 {4=4, 3=3}" << endl;
    lru.put(4, 4);
    
    cout << "get(1): 返回 " << lru.get(1) << " (应为 -1)" << endl;
    
    cout << "get(3): 返回 " << lru.get(3) << " (应为 3)" << endl;
    
    cout << "get(4): 返回 " << lru.get(4) << " (应为 4)" << endl;
    
    return 0;
}