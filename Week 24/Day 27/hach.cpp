#include <iostream>
using namespace std;

int divisionMethod(int key, int tableSize) {
return key % tableSize; // Returns the index using the division method
}

void readKeys(int keys[], int numKeys) {
for (int i = 0; i < numKeys; i++) {
cin >> keys[i]; // Read customer IDs into the keys array
}
}

void initializeHashTable(int hashTable[], int tableSize) {
for (int i = 0; i < tableSize; i++) {
hashTable[i] = -1; // Initialize the hash table with -1 (empty slots)
}
}

void insertKeys(int hashTable[], int tableSize, int keys[], int numKeys) {
for (int i = 0; i < numKeys; i++) {
int key = keys[i];
int index = divisionMethod(key, tableSize); // Compute the hash index

// Linear probing to resolve collisions
while (hashTable[index] != -1) {
index = (index + 1) % tableSize; // Move to the next slot (wrap around if needed)
}

hashTable[index] = key; // Insert the key into the available slot
}
}

void printHashTable(int hashTable[], int tableSize) {
for (int i = 0; i < tableSize; i++) {
if (hashTable[i] != -1) {
cout << "Table number " << i << ": Customer ID " << hashTable[i] << endl;
}
}
}

int main() {
const int tableSize = 10;
int numKeys;
cin >> numKeys; // Read the number of customer IDs

int keys[numKeys];
readKeys(keys, numKeys); // Read the customer IDs

int hashTable[tableSize];
initializeHashTable(hashTable, tableSize); // Initialize the hash table

insertKeys(hashTable, tableSize, keys, numKeys); // Insert the customer IDs into the table

printHashTable(hashTable, tableSize); // Print the hash table

return 0;
}