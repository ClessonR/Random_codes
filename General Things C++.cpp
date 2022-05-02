//
// Created by Clesson Roberto on 26/05/2021.
//

/*  Comments C++
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* First Class
#include <iostream>

 iostream: iostream stands for standard input-output stream. This header file contains definitions to objects like cin, cout, cerr etc. ...
 This header file is used to handle the data being read from a file as input or data being written into the file as output


The main() function is a basic function in C++, which indicates that an input/output it's going to be happen.

int main() {
    std::cout << "Hello World" <<std::endl;
    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* Second Class


#include <iostream> // It indicates input and output of strings ( Header of Libraries )

using namespace std;

// The main() function is a basic function in C++, which indicates that an input/output it's going to be happen.

int main() {

    // Basic data types!!

    int number = 10;
    float number_2 = 10.5;
    double bigger_number = 99999999999999999999999999999999999999999999999999.99999999999999999999999; // Used for numbers that takes lot's of space

    char letter = 'a';



    cout << "The number is: "<< number << endl;
    cout << "Now we have a floating number: " << number_2 << endl;
    cout << "The big number is: " << bigger_number << endl;

    cout << "The char is: " << letter << endl;

    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* Third Class

#include <iostream>   iostream: iostream stands for standard input-output stream. This header file contains definitions to objects like cin, cout, cerr etc. ...
This header file is used to handle the data being read from a file as input or data being written into the file as output
        ( Header of Libraries )

#include <string>   // It includes the string object in c++.


using namespace std;

// The main() function is a basic function in C++, which indicates that an input/output it's going to be happen.

int main() {

    // Basic data types!!

    int number = 10;
    float number_2 = 10.5; // It has a precision of 4 decimal places after the decimal point.
    double bigger_number = 99999999999999999999999999999999999999999999999999.99999999999999999999999; // Used for numbers that takes lot's of space, and has a precision of 10 decimal places.

    char letter = 'a';
    string name = "David"; // An array of char's.



    cout << "The number is: "<< number << endl; // The most basic printing format
    cout << "Now we have a floating number: " << number_2 << endl;
    cout << "The big number is: " << bigger_number << endl;
    cout << "The char is: " << letter << endl;

    cout << "The name is: " << name << endl;

    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

* Class 4 Data Input

#include <iostream>

using namespace std;

int main() {

    int value;

    cout << "What's the value? ";

    cin >> value; // Basic input

    cout << "The inputted value was: " << value << endl;


    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* Class 5 Cin/Cout Basic Applications

 #include <iostream>

using namespace std;

int main() {


    int a, b;

    cout << "Give a value for A:";
    cin >> a;

    cout << "Give a value for B:";
    cin >> b;

    cout << "The A value is: " << a << endl;
    cout << "The B value is: " << b << endl;



    return 0;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Class 6 Arithmetics Operators

#include <iostream>

// * Basic Arithmetics Operators

using namespace std;

int main() {

    int a, b;

    a = 9;
    b = 2;

    int adicao, subtracao, multiplicacao, modulo;

    float divisao;

    adicao = a + b;
    subtracao = a - b;
    multiplicacao = a * b;
    divisao = a / b;

    modulo = a % b;


    cout << "The value of the sum is:" << adicao << ", and the value of the subtraction is:" << subtracao << ", and the multiplied value is: " << multiplicacao << ", and the division is: " << divisao << endl;
    cout << "The module is:" << modulo << endl;



    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Class 7 If and else

 #include <iostream>
// * If and else;

using namespace std;

int main() {

    int numero = 5;

    if(numero == 5) {
        cout << "The number is 5"<< endl;
        numero = 9;
        cout << "The number is " << numero;
    }
    else
        cout << "The number is not 5";

    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
// * Switch case and break;

using namespace std;

int main() {

    int numero = 0;
    bool test = true;


    while (test) {

        if (numero == 5)
            test = false;


        switch (numero) {
            case 1:
                cout << "one"<< endl;
                break;
            case 2:
                cout << "two"<< endl;
                break;
            case 3:
                cout << "three"<<endl;
                break;
            case 4:
                cout << "four"<<endl;
                break;
            default: cout<<"I don't know bitch";
        }

        numero += 1;
    }

    return 0;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
// * For Loop ;

using namespace std;

int main() {



    for(int i=10; i>0; i--){
        cout<< i<<" - ";

        for(int j =0; j<10; j++){
            cout<<j<<
            " ";
        }
        cout << endl;
    }

    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
// * Arrays and Vectors;

using namespace std;

int main() {

    char matriz[10] = {'P', 'E', 'I', 'D', 'E', 'I'};

    cout << "Tamanho do array: " << sizeof(matriz)<< endl;

    // First Option = for(char i : matriz)
    //    cout << i;

    // Second Option:

    for(int i=0; i<sizeof(matriz)-4;i++)
        cout <<matriz[i] << endl;



    return 0;
}


------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 #include <iostream>
// * Structure; Similar to the __init__ function in python

using namespace std;

struct clients {
    int cliente_id;
    string nome;
    int idade;
};



int main() {

    clients my_client[10];

    my_client[1] = {2,"Nelson",98};

    my_client[0] = {1,"Daves", 30};

    cout << "Qual o seu nome?"<<endl;
    cin >> my_client[0].nome;




    cout << my_client[0].cliente_id<<endl;
    cout << my_client[0].idade<<endl;
    cout << my_client[0].nome<<endl;

    cout << my_client[1].cliente_id<<endl;
    cout << my_client[1].idade<<endl;
    cout << my_client[1].nome<<endl;

    return 0;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 #include <iostream>
#include <string>
// * Function ; Function are always after the main function!!

using namespace std;



// Function Prototype

int sum(int a, int b);
void print(string mensagem);
void calculator(int numero);

int main() {



    cout << sum(10, 10);
    print("string de teste para printar");
    calculator(3);
    return 0;
}


// The function definition;

int sum(int a, int b){
    return a+b;
}

void calculator(int numero) {
    for(int i=1; i<=10; i++){
        cout << numero << " X " << i << " = " << (numero*i) << endl;
    }

}

void print(string message){
    cout << endl;
    cout << "Message: "<< message <<endl;
    cout << endl;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
// * Templates

using namespace std;

template<class DATATEST>

DATATEST funcao(DATATEST a);


int main() {

    cout << funcao(10);
    cout << funcao(3.14);


    return 0;
}

template<class DATATEST>
DATATEST funcao(DATATEST a) {

    if (typeid(a).name() == typeid(int).name() ) {
        cout << "Inteiro ";
    }
    if (typeid(a).name() == typeid(double).name() ) {
        cout << " Double   " ;
    }

    return ++a;
}
 ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>

// * Pointers


using namespace std;

// Types of memory
// HEAP(pointer) = The heap is a memory used by programming languages to store global variables. By default, all global variable are stored in heap memory space. It supports Dynamic memory allocation.
//
//The heap is not managed automatically for you and is not as tightly managed by the CPU. It is more like a free-floating region of memory.;
//
// STACk = LIFO type of memory;
//
//

int main() {

    int number = 5;

    int *pointer; // Attributing the pointer function to the object

    pointer = &number; // Assigning the pointing to another object



    cout << "Valor da variavel numero: " << number << endl;
    cout << "Memory position: " << pointer <<endl;
    cout << "Memory position value: " << *pointer <<endl;

    return 0;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <stdarg.h>
// * Functions with variable arguments;


using namespace std;

int sum(const int count, ...);


int main() {
    int number1 = 1;
    int number2 = 2;
    int number3 = 3;


    while (1){
        cin >> number1;
        cin >> number2;
        cin >> number3;
        cout << sum(3 ,number1,number2,number3); // The first element in the funciton always must correspond to the number of elements that will be called in the funcion
    }



    return 0;
}


int sum(const int count, ...) {

    va_list lista;
    int total = 0;

    va_start(lista, count);

    for (int i = 0; i < count; ++i) {
        total += va_arg(lista, int);

    }
    va_end(lista);
    return total;

}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
// * Factorial Functions (Recursion)



using namespace std;

int fatorial(int n);


int main() {

    for (int i = 0; i < 20; ++i) {
        cout << "Fatorial de " << i<<": ";
        cout << fatorial(i)<<endl;
    }


    return 0;
}

int fatorial(int n) {
    if (n < 2) {
        return 1;
    }
    else
        return fatorial(n - 1) * n;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 #include <iostream>
//  * Parameter info by pointer or reference


using namespace std;

void number_viewer( int &);

int main() {

    int number = 9;
    number_viewer(number);

    cout << "Number from the main() function: " << number;
    return 0;
}

void number_viewer( int &number ){
    number++;
    cout << "Number: " << number << endl;

}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
//  * Object Oriented Programming ( Classes) Part 1.


using namespace std;

class Person{
    public: // It turns the properties visible globally;
        int id;  // Properties or attributes of the class ( They are private to the class)
        string name;
        int age;
    void show_name(){
        cout << "Das ist mein name: "<<name<<endl;
    }




};

int main() {

    Person nelson;

    nelson.id = 2;  // Setting the data
    nelson.name = "Nelson";
    nelson.age = 30;

    cout << nelson.id << endl;  // Class Gather
    nelson.show_name();
    cout << nelson.age << endl;




    return 0;
}



------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 #include <iostream>
#include <string>
//  * Object Oriented Programming ( Classes) Part 2.


using namespace std;

class Person{
    private:
        int id;  // Properties or attributes of the class ( They are private to the class)
        string name;
        int age;
    public: //  It turns the properties visible globally;

        Person(int _id, string _nome, int _age);


        ~Person();

        void name_att( string _name );

        void show_name();

        void id_att( int _identifier );

        void age_att( int _age );

};

// Class Methods comes right after the class

void Person::id_att( int _identifier ){
    id = _identifier;
}

void Person::age_att( int _age ){
    age = _age;
}

void Person::name_att(string _name) {
    name = _name;
}

void Person::show_name(){
    cout << "Das ist mein name: "<< name<<endl;
}

? Person::Person(int _id, string _name, int _age){  The Class Constructor, it doesn't return anything;
    id = _id;
    name = _name;
    age = _age;
}
Person::~Person() { // The Class Destructor, it destroys the memorry occupied by the class;
    cout << "Class Destroyed ";
}

int main() {

    Person nelson = Person( 1, "Nelson", 30);

    nelson.~Person();






    return 0;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * Monitoria Parte 1, coisas gerais.
#include "iostream"
#define endl as "\n";

using namespace std;

int main(){
    signed int a = 3; // Long long for negative numbers;
    int e;
    long long int c; // A bigger int;
    float b;
    double d; // A bigger float;
    int *ptr;


    ios_base::sync_with_stdio(false); // It makes the Cin and Cout command faster;
    cin.tie(nullptr);

    ptr = &a;


    cout << ptr << "\nLine jumped";



    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 #include "iostream"
#define endl "\n";

// * Dynamic memmory alloc


using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int * V = ( int *)malloc(sizeof ( int )*10);
    int * F = new int[100];


    free(V);
    delete F;


    return 0;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 #include "iostream"
#include <bits/stdc++.h>

#define endl "\n";

// * Dynamic memmory alloc resume


using namespace std;

int main() {

    ios_base::sync_with_stdio(false); //! It makes the Cin and Cout function faster;
    cin.tie(nullptr);


    //! int *V = (int *) malloc(sizeof(int) * 10); //! Dynamic allocation in C; malloc() allocates memory
    //! block of given size (in bytes) and returns a pointer to the
    //! beginning of the block. malloc() doesn’t initialize the allocated memory.
    //! If we try to access the content of memory block(before initializing)
    //! then we’ll get segmentation fault error(or maybe garbage values).
    //
    // * calloc() allocates the memory and also initializes the allocated memory block to zero. If we try to access the content of these blocks then we’ll get 0.
    // * void* calloc(size_t num, size_t size);
    //free(V);

    int *arr = (int*)calloc(10,sizeof(int ));



    int *F = new int[10]; //! Dynamic allocation in C++;
    delete[] F;

    //? Important Functions:

    memset(F, 0, sizeof(int) * 10);
    //! memcpy(array_destino, array_fonte, sizeof(tipo)*numero_de); This function copies an array into another;

    for (int i = 0; i < 10; ++i) {
        cout << F[i] << endl;
    }



    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 #include "iostream"
#define endl "\n";

//! Implementing LinkedList

using namespace std;


// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------
struct Node {
    int value;
    Node * next;

    Node(int initial_value, Node *initial_next) {
        value = initial_value;
        next = initial_next;
    }
};

// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class LinkedList {
private:
    Node *head, *tail;
    unsigned int n_elements;
public:

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        n_elements = 0;
    }

    void push_back(int val) { //? Adds an item in the end of the linked list;
        if (head == nullptr) {
            head = new Node(val, nullptr);
            tail = head;
        } else {
            tail->next = new Node(val, nullptr);
            tail = tail->next;
        }
        n_elements ++;

    }

    void show() {  //? Print out all elements of the list
        Node *cur = head;
        while (cur != nullptr) {
            cout << cur->value<< ' ';
            cur = cur->next;
        }
        cout << endl;

    }


    void push_front(int val){  //? Adds an item in the beginning of the linked list
        Node * new_node = new Node(val, head);
        head = new_node;
        n_elements++;
    }

    unsigned lenght(){ //? Number of elements/
        return n_elements;

    }
    int pop_back(){ //? Removes the last element of the list and returns the Node

        if(head == nullptr){
            cout<< "Empty List";
            return -1;
        }
        else if(head->next == nullptr){
            int val = head->value;
            head = nullptr;
            tail = nullptr;
            return val;
        }

        else{
            Node * cur = head;
            while(cur->next->next != nullptr){ //? Penultimo Nó
                cur = cur->next;
            }
            Node * last = cur->next;
            int last_v = last->value;
            cur->next = nullptr;
            delete last;
            tail = cur;
            return last_v;
        }

    }

    Node *findElement(int val); //? Returns the node with a given index
};
// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------



int main() {
    LinkedList * main_list = new LinkedList();

    int esteiras;

    cin >> esteiras;

    while( int i < esteiras)


    for (int i = 0; i < 10; ++i) {
        my_list->push_back(rand() % 100); //? Inserting 10 random numbers in the end of the list
    }


    my_list->push_front(-20); //! The -> operator is used to access a value from a class that is being pointed by a pointer; (*obj). == obj ->
    my_list->push_front(-9);

    while(my_list->pop_back() != -1) {
        my_list->show();
    }

    delete my_list;
    return 0;
}


 //! from the list code
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
        Node * new_node = new Node(val, head_1);
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
            Node * cur = head_1;
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


        if (command == "END") {
            continue;
        }

        if (command == "NEW") {  //? Adds an item to the end of the main queue;
            queue_array[0]->push_front(item_id);
        }
        if (command ==
            "MOV") { //? Moves an item from the beginning of the main queue to the end of the designated queue;
            int popped = queue_array[0]->pop_end();
            queue_array[item_id]->push_front(popped);
        }
        if (command ==
            "DEF") { //? Removes the defective item from the beginning of the queue and put at the top of the correspondent stack;
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



 */

// *------------------------------------------------------------------------------------------------------------------------------------------------------------------------












/* Comments C
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Class 1

#include <stdio.h>

int main( void ) {
    puts("Hello World");
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Class 2


#include <stdio.h>

int main( void ) {

    char name[30] = "David";

    printf("The value of the name is: %s", name);

    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 Class 3

 #include <stdio.h>
#include <conio.h>

int main(void) {

    char name[30];
    char

    printf("Qual o seu nome? ");
    gets(name);

    printf("O nome digitado foi %s", name );

    return 0;
}




 */
