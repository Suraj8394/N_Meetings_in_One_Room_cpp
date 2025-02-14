#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct Meeting {
    int start, end, index;
};

// Custom comparator function to sort by end time
bool compare(Meeting m1, Meeting m2) {
    return m1.end < m2.end;
}

int maxMeetings(int start[], int end[], int n) {
    vector<Meeting> meetings;
    
    for (int i = 0; i < n; i++) {
        meetings.push_back({start[i], end[i], i});
    }
    
    // Sort meetings by end time
    sort(meetings.begin(), meetings.end(), compare);

    int count = 1;  // First meeting is always selected
    int lastEnd = meetings[0].end;

    for (int i = 1; i < n; i++) {
        if (meetings[i].start > lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }

    return count;
}

int main() {
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    cout << "Maximum number of meetings: " << maxMeetings(start, end, n) << endl;
    return 0;
}
