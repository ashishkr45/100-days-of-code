#include <iostream>
#include <string>
#include <map>

using namespace std;

int getSimilarKey(map<int, string>& data, int key){
	int suggested_key = key + 1;
	while (data.count(suggested_key))
	{
		suggested_key++;
	}
	return suggested_key;
}

int main(){
    map<int, string> data;

    int key;
    string value;
    int ChKey;
    string upValue;

	cout << "1. Take input and Update the Map\n";
    cout << "2. Make changes to the Key\n";
    cout << "3. Display the Map\n";
	cout << "4. Display the options again\n";
    cout << "5. Exit\n";
    while (true)
    {
        int operation;
        cout << "Choose an operation: ";
        cin >> operation;

        switch (operation)
        {
			case 1: // Taking input and data entry
				cout << "Enter key: ";
				cin >> key;
				if(data.find(key) == data.end()){
					cout << "Enter value: ";
					cin >> value;
					data[key] = value;
				}else{
					cout<<"Key is Used!\n";
					int diffKey = getSimilarKey(data, key);
					cout<<"Try this "<<diffKey<<" insted\n";
				}
				operation = 1;
				break;

			case 2: // Updating the value of an existing key
				cout << "Enter the key to update: ";
				cin >> ChKey;
				/*
				if i enter a key which is not intitially presnet in the map's keys then
				the data.find() method will return a pointer which is equal the data.end( ) 
				*/
				if (data.find(ChKey) != data.end()) {
					cout << "Enter the updated value: ";
					cin >> upValue;
					data[ChKey] = upValue;
				} else {
					cout << "Key not found!" << endl;
				}
				break;

			case 3: // Displaying the map contents
				cout << "Map contents:" << endl;
				cout << "Key " <<"\t"<< "Value " << endl;
				for (const auto& it : data) {
					cout << it.first << " \t" << it.second << endl;
				}
				break;

			case 4: //Display the options again
				cout << "1. Take input and Update the Map\n";
				cout << "2. Make changes to the Key\n";
				cout << "3. Display the Map\n";
				cout << "4. Display the options again\n";
				cout << "5. Exit\n";
				break;
				
			case 5: // Exiting the loop
				return 0;

			default:
				cout << "Invalid operation!" << endl;
				break;
        }
    }
}
