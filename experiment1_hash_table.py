# Name : Kasim Lohar
# Roll No : B-32

class HashTableLinearProbing:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        original_index = index
        while self.table[index] is not None:
            index = (index + 1) % self.size
            if index == original_index:  # Table is full
                raise Exception("Hash table is full")
        self.table[index] = (key, value)

    def search(self, key):
        index = self.hash_function(key)
        original_index = index
        comparisons = 0
        while self.table[index] is not None:
            comparisons += 1
            if self.table[index][0] == key:
                return self.table[index][1], comparisons
            index = (index + 1) % self.size
            if index == original_index:  # Key not found
                break
        return None, comparisons


class HashTableChaining:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        self.table[index].append((key, value))

    def search(self, key):
        index = self.hash_function(key)
        comparisons = 0
        for k, v in self.table[index]:
            comparisons += 1
            if k == key:
                return v, comparisons
        return None, comparisons


# Sample test cases to compare performance
def test_hash_tables():
    size = int(input("Enter the size of the hash table: "))
    n = int(input("Enter the number of records: "))
    data = []
    for _ in range(n):
        name = input("Enter name: ")
        phone = input("Enter phone number: ")
        data.append((name, phone))

    # Linear Probing
    print("\nTesting Linear Probing:")
    ht_linear = HashTableLinearProbing(size)
    for name, phone in data:
        ht_linear.insert(name, phone)

    total_comparisons_linear = 0
    for name, _ in data:
        _, comparisons = ht_linear.search(name)
        total_comparisons_linear += comparisons
        print(f"Lookup {name}: {comparisons} comparisons")

    print(f"Total comparisons (Linear Probing): {total_comparisons_linear}\n")

    # Chaining
    print("Testing Chaining:")
    ht_chaining = HashTableChaining(size)
    for name, phone in data:
        ht_chaining.insert(name, phone)

    total_comparisons_chaining = 0
    for name, _ in data:
        _, comparisons = ht_chaining.search(name)
        total_comparisons_chaining += comparisons
        print(f"Lookup {name}: {comparisons} comparisons")

    print(f"Total comparisons (Chaining): {total_comparisons_chaining}")


if __name__ == "__main__":
    test_hash_tables()
