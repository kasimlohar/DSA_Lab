# Name : Kasim Lohar
# Roll No : B-32

class HashDictionary:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                raise KeyError(f"Duplicate key '{key}' is not allowed.")
        self.table[index].append((key, value))

    def find(self, key):
        index = self.hash_function(key)
        for k, v in self.table[index]:
            if k == key:
                return v
        raise KeyError(f"Key '{key}' not found.")

    def delete(self, key):
        index = self.hash_function(key)
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                del self.table[index][i]
                return
        raise KeyError(f"Key '{key}' not found.")

    def display(self):
        for i, bucket in enumerate(self.table):
            print(f"Bucket {i}: {bucket}")


# Sample test cases
def test_hash_dictionary():
    size = int(input("Enter the size of the hash dictionary: "))
    hd = HashDictionary(size)

    while True:
        print("\nOptions:")
        print("1. Insert (key, value)")
        print("2. Find (key)")
        print("3. Delete (key)")
        print("4. Display dictionary")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            key = input("Enter key: ")
            value = input("Enter value: ")
            try:
                hd.insert(key, value)
                print(f"Inserted ({key}, {value}) successfully.")
            except KeyError as e:
                print(e)
        elif choice == 2:
            key = input("Enter key to find: ")
            try:
                value = hd.find(key)
                print(f"Value for key '{key}': {value}")
            except KeyError as e:
                print(e)
        elif choice == 3:
            key = input("Enter key to delete: ")
            try:
                hd.delete(key)
                print(f"Deleted key '{key}' successfully.")
            except KeyError as e:
                print(e)
        elif choice == 4:
            hd.display()
        elif choice == 5:
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    test_hash_dictionary()
