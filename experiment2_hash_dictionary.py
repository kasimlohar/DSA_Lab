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
                return
        self.table[index].append((key, value))

    def find(self, key):
        index = self.hash_function(key)
        for k, v in self.table[index]:
            if k == key:
                return v
        return None

    def delete(self, key):
        index = self.hash_function(key)
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                del self.table[index][i]
                return

    def display(self):
        for i, bucket in enumerate(self.table):
            print(f"Bucket {i}: {bucket}")


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
            hd.insert(key, value)
            print(f"Inserted ({key}, {value}) successfully.")
        elif choice == 2:
            key = input("Enter key to find: ")
            value = hd.find(key)
            if value is not None:
                print(f"Value for key '{key}': {value}")
            else:
                print(f"Key '{key}' not found.")
        elif choice == 3:
            key = input("Enter key to delete: ")
            hd.delete(key)
            print(f"Deleted key '{key}' successfully.")
        elif choice == 4:
            hd.display()
        elif choice == 5:
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    test_hash_dictionary()
