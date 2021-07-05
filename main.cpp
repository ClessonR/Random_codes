#include <string>
#include <iostream>


#define endl "\n";
using namespace std;

unsigned long int key_translator(string word, int size);

class Node {
public:
    string kmer;
    long int *position_array;
    long int array_sz;
    long int last_item_index;


    Node() {//! Constructor
        kmer = "";
        array_sz = 5;
        position_array = (long int *) calloc(array_sz, sizeof(long int));
        last_item_index = -1;
    }


    string correspondent_kmer() {
        return kmer;
    }

    long int get_position(int i) {
        return position_array[i];
    }

    void show_arr_items() { //! Print all the items inside the array
        for (int i = 0; i < last_item_index + 1; ++i) {
            cout << get_position(i) << " ";
        }
    }

    void push_back(
            long int position) { //? It adds a new item into the end of the array, and if the array is full it. (All the added items will have the index added by one.);
        if (last_item_index == -1) {
            position_array[0] = position;
            last_item_index = 0;
        } else if (last_item_index + 1 == array_sz) {
            resize((array_sz * 2));
            array_sz = (array_sz * 2);
            position_array[last_item_index + 1] = (position);
            last_item_index = last_item_index + 1;
        } else {
            position_array[last_item_index + 1] = (position);
            last_item_index = last_item_index + 1;
        }

    }

    void resize(long int size) { //? Resizing the node array to a given size and copying its elements;
        long int *temp_array = (long int *) calloc(size, sizeof(long int));

        for (int i = 0; i < (last_item_index +1); ++i) { // The last item index is added by one because it's "pointing" to the last element in the array, the reason is because if not added by one 'i' would go only to the pre-last element and would miss an element in the array;
            temp_array[i] = position_array[i];
        }

        swap(temp_array, position_array);

        free(temp_array);
        temp_array = nullptr;
        return;
    }

};


class Hashtable {
public:
    Node *Hash_array;
    long int table_sz;
    long int num_elt;

    Hashtable(long int initial_sz) {//! Constructor
        Hash_array = new Node[initial_sz];

        num_elt = 0;
        table_sz = initial_sz;
    }


    void hashtable_add(string kmer, long int current_position, unsigned long int key) {//! Adds a kmer to the table;
        //? Check if the kmer is already inserted in the table before adding it to a new position;
        unsigned long int ind;
        long int attemp = 0;
        bool added = false;

        for (int i = 0; i < table_sz; ++i) { //! If the item is already inserted in the hashtable;
            if (Hash_array[i].correspondent_kmer() == kmer) {
                Hash_array[i].push_back(current_position);
                return;
            }
        }
        //? If not inserted search for an empty position and adds a new kmer;
        while (!added) {
            ind = (key + attemp) % table_sz;
            if (Hash_array[ind].correspondent_kmer() == "") {
                Hash_array[ind].kmer = kmer;
                Hash_array[ind].push_back(current_position);
                added = true;
                num_elt ++;
                return;
            } else {
                attemp++;
            }
        }

    }


    void rehash(int kmer_size) {
        //? Creates a temp table with the double of the size
        long int new_table_size = (table_sz *2) +1;
        unsigned long int key = 0;
        unsigned long int ind= 0;


        string kamer;
        Node *temp_table;
        temp_table = new Node[new_table_size];
        //? copy its elements applying the node_copy
        for (int i = 0; i < table_sz; ++i) {
            bool added = false;
            long int attempt= 0;

            if (Hash_array[i].correspondent_kmer()!=""){
                kamer = Hash_array[i].correspondent_kmer();
                key = key_translator(kamer,kmer_size);

                while (!added) {
                    ind = (key + attempt) % new_table_size;
                    if (temp_table[ind].correspondent_kmer() == "") {
                        temp_table[ind].kmer = kamer;
                        temp_table[ind].last_item_index = Hash_array[i].last_item_index;
                        temp_table[ind].array_sz = Hash_array[i].array_sz;
                        swap(temp_table[ind].position_array,Hash_array[i].position_array);
                        added = true;
                    }
                    else {
                        attempt++;
                    }
                }
            }
        }

        table_sz = new_table_size;
        swap(temp_table,Hash_array);
        delete[] temp_table;

    }


    bool load_factor() { //! It returns the load factor of the table, and if it's bigger than 0.5 returns true.
        double factor = double(num_elt) / double(table_sz);
        if (factor >= 0.5) {
            return true;
        } else {
            return false;
        }
    }

    long int biggest_sequence(){
        long int sequence = 0;
        long int biggest_sequence = 0;
        for (int i = 0; i <table_sz ; ++i) {
            if (!Hash_array[i].correspondent_kmer().empty()){
                sequence ++;
                if (sequence > biggest_sequence){
                    biggest_sequence = sequence;
                }
            }
            else{
                sequence = 0;
            }
        }
        return biggest_sequence;
    }

    long int in_table(string kmer){
        for (int i = 0; i < table_sz ; ++i) {
            if (Hash_array[i].correspondent_kmer() == kmer){
                return i;
            }
        }
        return (-2);
    }

};






int main() {

    int kmer_size; //? Initial kmer size
    int table_size; //? Initial table size

    cin >> kmer_size;
    cin >> table_size;

    string dispenser;
    int text_lines; //? Number of lines in the text

    cin >> dispenser;
    cin >> text_lines;

    cin.ignore();
    string text;
    string temp;


    for (int i = 0; i < text_lines; ++i) {
        getline(cin, temp);
        if (i == 0) {
            text += temp;
        }
        else {
            text += +"\n" + temp;
        }
    }


    Hashtable *My_table = new Hashtable(table_size);


    for (int i = 0; i < (text.size() - kmer_size); ++i) {//? MAIN loop of the hashtable; Which creates the hashtable and add the items in the text;
        string temp_string;
        bool load_factor = false;

        temp_string = text.substr(i, kmer_size);
        unsigned long int key;

        load_factor = My_table->load_factor();

        if (load_factor) {
            My_table->rehash(kmer_size);
            //? Implement the rehash function
        }


        key = key_translator(temp_string, kmer_size);

        My_table->hashtable_add(temp_string, i, key);


    }

    string dispenser_2;
    cin >> dispenser_2;

    long int consultas;
    cin >> consultas;

    cin.ignore();

    string temp_2;
    string kamer;
    string find_in_txt;
    long int index;
    long int dif;

    for (int i = 0; i < consultas; ++i) {
        string check = "";
        string positions = "";
        getline(cin,temp_2);
        kamer = temp_2.substr(0,kmer_size);
        find_in_txt = temp_2.substr(kmer_size,temp_2.size());
        index = My_table->in_table(kamer);
        dif = temp_2.size() - kmer_size;

        if (index != (-2)){
            cout << i<< ":";
            for (int j = 0; j < (My_table->Hash_array[index].last_item_index+1); ++j) {
                check = text.substr(My_table->Hash_array[index].get_position(j)+kmer_size,dif);
                if (check == find_in_txt){
                    cout <<" "<<My_table->Hash_array[index].get_position(j);
                }
            }
            cout << endl;

        }
        else{
            cout<< i << ": ";
            cout<< endl;
        }


    }


    cout << My_table->num_elt<< " ";
    cout << My_table->table_sz<< " ";
    cout << My_table->biggest_sequence();


    cout<< endl;

    delete My_table;

}


unsigned long int key_translator(string word, int size) {
    unsigned long int key = 0;
    for (int i = 0; i < size; ++i) {
        key = (key * 128) + word[i];
    }
    return key;

}
