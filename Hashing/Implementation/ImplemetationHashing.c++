#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define SIZE 13

int HashTable[SIZE];

// Hash function
int hash_function(int x) {
    return x % SIZE;
}

// Insert element
void insertEle(int x) {
    int index = hash_function(x);
    if (HashTable[index] == -1) {
        HashTable[index] = x;
        cout << "Successfully inserted." << endl;
    } else {
        cout << "Collision Occured." << endl;
    }
}

// Delete element
void deleteEle(int x) {
    int index = hash_function(x);
    if (HashTable[index] != x) {
        cout << "Element not found. So cannot delete the element." << endl;
    } else {
        HashTable[index] = -1;
        cout << "Successfully deleted." << endl;
    }
}

// Search element
void searchEle(int x) {
    int index = hash_function(x);
    if (HashTable[index] == x) {
        cout << "Element found." << endl;
    } else {
        cout << "Element not found." << endl;
    }
}

// Print hash table
void print() {
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << i << "]=>" << HashTable[i] << endl;
    }
}
