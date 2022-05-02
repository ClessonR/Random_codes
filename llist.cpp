#include <bits/stdc++.h>
#define endl "\n";

//! Implementing Queue and Stack based on a linked list;

using namespace std;


// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Node {
public:
    int value;
    Node *next;

    Node(int node_value, Node *node_pointer) {
        value = node_value;
        next = node_pointer;
    }
};
// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Queue {
private:
    Node *head_1;
    Node *tail_1;
public:
    Queue() {
        head_1 = nullptr;
        tail_1 = nullptr;

    }

    void push_front(int val) {  //? Adds an item in the beginning of the Queue
        Node *new_node = new Node(val, head_1);
        head_1 = new_node;
    }
    int pop_end() { //? Removes the last element of the Queue and returns its number;

        if (head_1 == nullptr) {
            return -1;
        } else if (head_1->next == nullptr) {
            int val = head_1->value;
            head_1 = nullptr;
            tail_1 = nullptr;
            return val;
        } else {
            Node *cur = head_1;
            while (cur->next->next != nullptr) {
                cur = cur->next;
            }
            Node *last = cur->next;
            int last_v = last->value;
            cur->next = nullptr;
            delete last;
            tail_1 = cur;
            return last_v;
        }
    }

};

// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Stack {
private:
    Node *head_2;
    Node *tail_2;
public:
    Stack() {
        head_2 = nullptr;
        tail_2 = nullptr;
    }

    void push_top(int val) { //? Adds an item in the top of a Stack;
        if (head_2 == nullptr) {
            head_2 = new Node(val, nullptr);
            tail_2 = head_2;
        } else {
            tail_2->next = new Node(val, nullptr);
            tail_2 = tail_2->next;
        }

    }

    int pop_back() { //? Removes the element on the top of the Stack and returns its number;

        if (head_2 == nullptr) {
            return -1;
        } else if (head_2->next == nullptr) {
            int val = head_2->value;
            head_2 = nullptr;
            tail_2 = nullptr;
            return val;
        } else {
            Node *cur = head_2;
            while (cur->next->next != nullptr) {
                cur = cur->next;
            }
            Node *last = cur->next;
            int last_v = last->value;
            cur->next = nullptr;
            delete last;
            tail_2 = cur;
            return (last_v);
        }
    }
    
};

// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Algorithm Construction;
int main() {
    
    string command;
    int item_id;


    int queue_total;

// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    auto *main_queue = new Queue();
    auto *main_stack = new Stack();

    cin >> queue_total;
// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Allocating the strucs (Empty);
    Queue *queue_array[queue_total];
    Stack *stack_array[queue_total];

    queue_array[0] = main_queue;
    stack_array[0] = main_stack;

    for (int i = 1; i < queue_total + 1; ++i) {
        queue_array[i] = new Queue();
        stack_array[i] = new Stack();
    }
// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//! Main loop;
    while (command != "END") {


        cin >> command;
        cin >> item_id;




        if (command == "END"){
            continue;
        }

        if (command == "NEW") {  //? Adds an item to the end of the main queue;
            queue_array[0]->push_front(item_id);
        }
        if (command == "MOV") { //? Moves an item from the beginning of the main queue to the end of the designated queue;
            int popped = queue_array[0]->pop_end();
            queue_array[item_id]->push_front(popped);
        }
        if (command == "DEF") { //? Removes the defective item from the beginning of the queue and put at the top of the correspondent stack;
            int def = queue_array[item_id]->pop_end();
            stack_array[item_id]->push_top(def);
        }
        if (command ==
            "FIX") { //? Pop out the top item of a given stack, then puts at the end of its correspondent queue;
            int fixed = stack_array[item_id]->pop_back();
            queue_array[item_id]->push_front(fixed);
        }
        if (command == "TSH") { //? Pop out the top of a stack and deletes it;
            int bad_item = stack_array[item_id]->pop_back();
            cout << bad_item << " BAD" << endl;
        }
        if (command == "RDY") { //? Pops out the top of a stack, then display a message that the item is ready;
            int item = queue_array[item_id]->pop_end();
            cout << item << " OK" << endl;
        }

    }
// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//! Memory dispensers;
    for (int i = 1; i < queue_total; ++i) {
        delete queue_array[i];
        delete stack_array[i];
    }
    delete main_queue;
    delete main_stack;
    return 0;
}
// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------

