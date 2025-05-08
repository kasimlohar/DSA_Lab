# Experiment 12: Index Sequential File Handling for Employee Records

## Objective

To implement basic index sequential file operations (add, search, display) for employee records using text files in C++.

## Concept

**Index Sequential File Organization** combines the advantages of sequential and direct access. Records are stored sequentially, but an index is maintained to allow faster searching. In this simplified version, we focus on sequential access, but the concept can be extended to maintain an index for faster lookups.

### Why Index Sequential Files?

- Allows both sequential and direct access to records.
- Efficient for applications where records are mostly processed in order, but occasional fast lookups are needed.
- Commonly used in databases and large file systems.

## Implementation Details

- **Employee Structure:** Each record contains employee ID, name, designation, and salary.
- **File Format:** Each employee record is stored as a single line in a text file, with fields separated by commas.
- **Add Record:** Appends a new employee record to the file.
- **Search Record:** Reads the file line by line and displays the record if the employee ID matches.
- **Display All Records:** Reads and prints all records from the file.

## Code Flow

1. User selects an operation: add, search, display all, or exit.
2. For add, user enters employee details, which are appended to the file.
3. For search, user enters an employee ID, and the program searches and displays the matching record.
4. For display all, the program prints all records in the file.

## Sample Output

```
1. Add
2. Search
3. Display All
4. Exit
Enter choice: 1
Enter Employee ID: 201
Enter Name: Bob
Enter Designation: Manager
Enter Salary: 50000
Record added.

1. Add
2. Search
3. Display All
4. Exit
Enter choice: 3
All Records:
201,Bob,Manager,50000
...
```

## Complexity Analysis

- **Add Record:** O(1) (appending to file).
- **Search/Display:** O(n), where n is the number of records (must read file sequentially).

## Key Points to Explain

- **Index Sequential Access:** Combines sequential and indexed access for efficiency.
- **Simple Implementation:** This experiment demonstrates the sequential part; index can be added for faster search.
- **Use Cases:** Used in payroll systems, databases, and large record-keeping applications.

## Viva Questions

- What is index sequential file organization?
- How do you add/search/display records in an index sequential file?
- What are the advantages over pure sequential files?
- How would you implement deletion or modification?
- What are the real-world applications of index sequential files?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

