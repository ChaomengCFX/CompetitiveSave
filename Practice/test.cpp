#include <bits/stdc++.h>
using namespace std;

struct node {
    node(int v) : val(v) {}
    int val;
    node *next, *prev;
};

int main() {
    node *head = nullptr, *last = nullptr;
    node** nxt = &head;

    auto add = [&](int val) -> void {
        *nxt = new node(val);
        (*nxt)->prev = last;
        last = *nxt;
        nxt = &(last->next = nullptr);
    };

    add(51);
    add(3);
    add(235);
    add(-44);

    node* p = head;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }

    p = last;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->prev;
    }
}
