#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    fstream data;
    data.open("data.csv", ios::in);

    if (!data.is_open())
    { // Check if the file opened successfully
        cout << "Error: Could not open the file!" << endl;
        return 1; // Exit the program if the file could not be opened
    }

    string line, word;

    vector<vector<string>> feed; // 2D vector to store the CSV data

    while (getline(data, line))
    {
        vector<string> row;
        stringstream s(line);

        /* Separating the words wherever there's a comma */
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        feed.push_back(row);
    }

    // Close the file
    data.close();

    // Display the content of the CSV file with proper formatting
    cout << "CSV File Content:\n";
    int columnWidth = 15; // Set column width for better visibility

    for (const auto &row : feed)
    {
        for (const auto &word : row)
        {
            cout << left << setw(columnWidth) << word;
        }
        cout << endl;
    }
    return 0;
}
