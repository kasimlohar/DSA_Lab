# Experiment 11: Sequential File Handling for Student Records

## Objective

To implement basic sequential file operations (add, search, display) for student records using text files in C++.

## Concept

**Sequential file handling** involves storing and accessing records in a file one after another, in the order they are written. This is the simplest form of file organization and is suitable for applications where records are mostly processed in sequence.

### Why Sequential Files?

- Simple to implement and understand.
- Efficient for applications where most operations are appends or sequential reads.
- Commonly used for logs, simple databases, and archival storage.

## Implementation Details

- **Student Structure:** Each record contains roll number, name, division, and address.
- **File Format:** Each student record is stored as a single line in a text file, with fields separated by commas.
- **Add Record:** Appends a new student record to the file.
- **Search Record:** Reads the file line by line and displays the record if the roll number matches.
- **Display All Records:** Reads and prints all records from the file.

## Code Flow

1. User selects an operation: add, search, display all, or exit.
2. For add, user enters student details, which are appended to the file.
3. For search, user enters a roll number, and the program searches and displays the matching record.
4. For display all, the program prints all records in the file.

## Sample Output

```
1. Add
2. Search
3. Display All
4. Exit
Enter choice: 1
Enter Roll No: 101
Enter Name: Alice
Enter Division: A
Enter Address: Pune
Record added.

1. Add
2. Search
3. Display All
4. Exit
Enter choice: 3
All Records:
101,Alice,A,Pune
...
```

## Complexity Analysis

- **Add Record:** O(1) (appending to file).
- **Search/Display:** O(n), where n is the number of records (must read file sequentially).

## Key Points to Explain

- **Sequential Access:** Records are processed in the order they appear in the file.
- **No In-Place Deletion:** Deletion is not implemented in this simple version; would require rewriting the file.
- **Use Cases:** Suitable for simple databases, logs, and archival data.

## Viva Questions

- What is sequential file organization?
- How do you add/search/display records in a sequential file?
- What are the limitations of sequential files?
- How would you implement deletion or modification?
- What are the real-world applications of sequential files?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

