#include <iostream>
#include <string>

using namespace std;

class KeyValuePair {
public:
    string key;
    string value;
        KeyValuePair(){
        key = "";
        value = "";
    }
    KeyValuePair(const string& key, const string& value){
        this->key = key;
        this->value = value;
    }
};

class Dictionary {
private:
    static const int SIZE = 100;
    KeyValuePair hashTable[SIZE];

    int hashingFunction(const string& key) {
        int count = 0;
        int len = key.length();
        for (int i = 0; i < len; i++) {
            count += (key[i] - 'a');
        }

        return (count % SIZE);
    }

public:
    Dictionary() {
        for (int i = 0; i < SIZE; i++) {
            hashTable[i] = KeyValuePair("", "");
        }
    }

    void insert(const string& key, const string& value) {
        int index = hashingFunction(key);
        while (index < SIZE) {
            if (hashTable[index].key == "") {
                hashTable[index] = KeyValuePair(key, value);
                cout << "Key-value pair inserted successfully." << endl;
                return;
            }
            index++;
            if (index == SIZE) {
                index = index % SIZE;
            }
        }
        cout << "Dictionary is full. Cannot insert key-value pair." << endl;
    }

    string find(const string& key) {
        int index = hashingFunction(key);
        while (index < SIZE) {
            if (hashTable[index].key == key) {
                return hashTable[index].value;
            }
            index++;
            if (index == SIZE) {
                index = index % SIZE;
            }
        }
        return "";
    }

    void remove(const string& key) {
        int index = hashingFunction(key);
        while (index < SIZE) {
            if (hashTable[index].key == key) {
                hashTable[index] = KeyValuePair("", "");
                cout << "Key-value pair deleted successfully." << endl;
                return;
            }
            index++;
            if (index == SIZE) {
                index = index % SIZE;
            }
        }
        cout << "Key not found." << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            if (hashTable[i].key != "") {
                cout << "Key: " << hashTable[i].key << ", Value: " << hashTable[i].value << endl;
            }
        }
    }
};

void print_menu() {
    cout << "1. Insert a key-value pair" << endl;
    cout << "2. Find a value by key" << endl;
    cout << "3. Delete a key-value pair" << endl;
    cout << "4. Display dictionary" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    Dictionary dictionary;

    while (true) {
        print_menu();
        string choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            string key, value;
            cout << "Enter the key: ";
            cin >> key;
            cout << "Enter the value: ";
            cin >> value;
            dictionary.insert(key, value);
        }
        else if (choice == "2") {
            string key;
            cout << "Enter the key to find the corresponding value: ";
            cin >> key;
            string result = dictionary.find(key);
            if (result != "") {
                cout << "Value: " << result << endl;
            }
            else {
                cout << "Key not found." << endl;
            }
        }
        else if (choice == "3") {
            string key;
            cout << "Enter the key to delete the corresponding key-value pair: ";
            cin >> key;
            dictionary.remove(key);
        }
        else if (choice == "4") {
            dictionary.display();
        }
        else if (choice == "5") {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
