#include <bits/stdc++.h>
using namespace std;

string convertTo12Hour(const string& time24) {
    // extract hour and minute using substr
    int hour = stoi(time24.substr(0, 2));
    int minute = stoi(time24.substr(3, 2));

    string period = "AM";

    if (hour == 0) {        // midnight
        hour = 12;
        period = "AM";
    }
    else if (hour == 12) {  // noon
        period = "PM";
    }
    else if (hour > 12) {
        hour -= 12;
        period = "PM";
    }

    // format with leading zeros
    char buffer[10];
    sprintf(buffer, "%02d:%02d %s", hour, minute, period.c_str());

    return string(buffer);
}

int main() {
    string time24;
    cout << "Enter time in 24-hour format (HH:MM): ";
    cin >> time24;

    cout << "12-hour format: " << convertTo12Hour(time24) << endl;
    return 0;
}
