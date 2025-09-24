string timeConversion(string s) {
  int hour = stoi(s.substr(0,2));
    int min  = stoi(s.substr(3,2));
    int sec  = stoi(s.substr(6,2));
    string period = s.substr(8,2);  // AM or PM

    if (period == "AM") {
        if (hour == 12) hour = 0;  // midnight case
    } 
    else if (period == "PM") {
        if (hour != 12) hour += 12; // afternoon/evening case
    }

    // format into HH:MM:SS
    char buffer[10];
    sprintf(buffer, "%02d:%02d:%02d", hour, min, sec);

    return string(buffer);
  
}
