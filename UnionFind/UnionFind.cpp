#include "UnionFind.h"

UnionFind::UnionFind(int num) {
    for (int i = 0; i < num; i++){
        nodes.push_back(new Node(i));
        short y = rand()%2;
        if (y == 1)
            nodes[i]->is_blocked = true;
        nodes[i]->id = i;
    }
}

UnionFind::~UnionFind() {
    for (auto& node: nodes)
        delete node;
}

Node* UnionFind::findParent(Node *child) {
    if (child->parent == nullptr)
        return nullptr;

    while(child->parent != nullptr)
        child = child->parent;

    return child;
}

void UnionFind::normal_union(Node *node1, Node *node2) {
    auto parent1 = findParent(node1);
    auto parent2 = findParent(node2);

    if (parent1 == nullptr)
        parent1 = node1;
    if (parent2 == nullptr)
        parent2 = node2;

    parent1->parent = parent2;
}

void UnionFind::rank_union(Node *node1, Node *node2) {
    /// No entendi este tipo de union
}

void Node::set_parent(Node *padre) {
    parent = padre;
}

Node Node::find_parent(Node* child) {

    while(child->parent != nullptr)
        child = child->parent;

    return *child;
}
