# 📅 N Meetings in One Room (C++)  

A **greedy algorithm** to find the **maximum number of non-overlapping meetings** that can be scheduled in a single room, given their start and end times.  

---

## 🚀 Features  
✔️ **Schedules maximum non-overlapping meetings**  
✔️ **Uses sorting and greedy approach for efficiency**  
✔️ **Optimized time complexity: O(N log N)**  
✔️ **Works for any number of meetings**  



---

## 🛠 How It Works  

The program takes **N meetings** with their **start and end times** and finds the **maximum number of non-overlapping meetings** that can be scheduled in one room.

### **📌 Step 1: Define Meeting Structure**  
A structure `Meeting` is used to store the **start time, end time, and index** of each meeting.  

```cpp
struct Meeting {
    int start, end, index;
};
```

### **📌 Step 2: Sorting Meetings by End Time**  
To maximize the number of meetings, we **sort** them by **end time**.  
The earlier a meeting ends, the sooner another meeting can start.  

```cpp
bool compare(Meeting m1, Meeting m2) {
    return m1.end < m2.end; // Sorting by end time
}
```

### **📌 Step 3: Selecting Maximum Meetings**  
1. The first meeting is **always selected**.  
2. For each remaining meeting, **select it only if its start time is after the last selected meeting ends**.  

```cpp
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
```

### **📌 Step 4: Running the Program**  
```cpp
int main() {
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    cout << "Maximum number of meetings: " << maxMeetings(start, end, n) << endl;
    return 0;
}
```

---

## 📈 Time Complexity  
- **Sorting Meetings:** `O(N log N)`  
- **Selecting Meetings:** `O(N)`  
- **Total Complexity:** `O(N log N)`

---

## 📊 Example Usage  

### **🔹 Input**  
```cpp
start[] = {1, 3, 0, 5, 8, 5};
end[]   = {2, 4, 6, 7, 9, 9};
n = 6;
```

### **✅ Output**  
```
Maximum number of meetings: 4
```

### **📌 Selected Meetings:**  
1. (1,2)  
2. (3,4)  
3. (5,7)  
4. (8,9)  



---

## 📧 Contact  
📩 surajpratap469@gmail.com  

⭐ If you found this project useful, please **star the repository** on GitHub! 🚀  
