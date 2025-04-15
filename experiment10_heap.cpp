// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void findMaxAndMinMarks(const vector<int>& marks, int& maxMark, int& minMark) {
    // Max-heap for maximum mark
    priority_queue<int> maxHeap(marks.begin(), marks.end()); // O(n) to build the heap

    // Min-heap for minimum mark
    priority_queue<int, vector<int>, greater<int>> minHeap(marks.begin(), marks.end()); // O(n) to build the heap

    // Extract maximum and minimum marks
    maxMark = maxHeap.top(); // O(1)
    minMark = minHeap.top(); // O(1)
}

int main() {
    // Sample list of student marks
    vector<int> marks = {85, 92, 78, 90, 88, 76, 95, 89};

    cout << "Student marks: ";
    for (int mark : marks) {
        cout << mark << " ";
    }
    cout << endl;

    int maxMark, minMark;
    findMaxAndMinMarks(marks, maxMark, minMark);

    cout << "Maximum mark: " << maxMark << endl;
    cout << "Minimum mark: " << minMark << endl;

    // Complexity analysis
    cout << "\nComplexity Analysis:" << endl;
    cout << "1. Building the heaps: O(n) for both max-heap and min-heap." << endl;
    cout << "2. Extracting max and min: O(1) for each operation." << endl;
    cout << "3. Overall time complexity: O(n) for heap construction + O(1) for extraction." << endl;

    return 0;
}
