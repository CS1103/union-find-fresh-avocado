#ifndef UNIONFIND_UNIONFIND_H
#define UNIONFIND_UNIONFIND_H

#include <queue>
#include <vector>

struct Node{
    bool is_blocked;
    Node* parent;
    int rank = 0;
    std::vector<Node*> childs;
    int id = 0;
    explicit Node(int id): parent{nullptr}, childs{nullptr}, is_blocked{false}, id{0}{};
    friend void operator>>(Node& hijo, Node& padre){
        hijo.parent = &padre;
        padre.childs.push_back(&hijo);
        if (padre.parent == nullptr)
            padre.rank++;
        else {
            while(padre.parent != nullptr)
                padre = *padre.parent;
            padre.rank++;
        }
    };
    void set_parent(Node* padre);
    Node find_parent(Node* child);
};

class UnionFind {
    std::vector<Node*> nodes;
public:
    explicit UnionFind(int num);
    ~UnionFind();
    Node* findParent(Node* child);
    void normal_union(Node* node1, Node* node2);
    void rank_union(Node* node1, Node* node2);
    Node* operator[] (int i){
        return nodes[i];
    }

};


#endif
