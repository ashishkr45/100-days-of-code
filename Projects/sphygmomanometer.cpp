#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct BloodPressureReading {
    int systolic;
    int diastolic;
};

string categorizeBloodPressure(int systolic, int diastolic) {
    if (systolic < 120 && diastolic < 80)
        return "Normal";
    else if (systolic < 130 && diastolic < 80)
        return "Elevated";
    else if ((systolic <= 139 && systolic >= 130) || (diastolic <= 89 && diastolic >= 80))
        return "Hypertension Stage 1";
    else if (systolic <= 140 || diastolic <= 90)
        return "Hypertension Stage 2";
    else if (systolic >= 180 || diastolic >= 120)
        return "Hypertensive Crisis - Seek Immediate Medical Attention";
    return "Unknown Category";
}

void displayReading(const BloodPressureReading& reading) {
    string category = categorizeBloodPressure(reading.systolic, reading.diastolic);
    cout << "Systolic: " << reading.systolic << " mm Hg\n";
    cout << "Diastolic: " << reading.diastolic << " mm Hg\n";
    cout << "Category: " << category << "\n\n";
}

int main() {
    vector<BloodPressureReading> readings;

    char choice;
    do {
        BloodPressureReading reading;
        cout << "Enter systolic pressure (mm Hg): ";
        cin >> reading.systolic;
        cout << "Enter diastolic pressure (mm Hg): ";
        cin >> reading.diastolic;

        readings.push_back(reading);
        displayReading(reading);

        cout << "Would you like to enter another reading? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Display all readings entered
    cout << "\nAll Blood Pressure Readings:\n";
    for (const auto& reading : readings) {
        displayReading(reading);
    }

    return 0;
}
