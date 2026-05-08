#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:

    int key;
    int val;

    Node* next;
    Node* prev;

    Node(int k, int v) {

        key = k;
        val = v;

        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {

        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void insertNode(Node* node) {

        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    }

    void deleteNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {

        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        deleteNode(node);
        insertNode(node);

        return node->val;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {

            Node* existingNode = mp[key];

            deleteNode(existingNode);

            mp.erase(key);
        }

        if(mp.size() == capacity) {

            Node* lru = tail->prev;

            deleteNode(lru);

            mp.erase(lru->key);
        }

        Node* newNode =
            new Node(key, value);

        insertNode(newNode);

        mp[key] = newNode;
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1,1);
    cache.put(2,2);

    cout << cache.get(1) << endl;

    cache.put(3,3);

    cout << cache.get(2) << endl;

    cache.put(4,4);

    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}