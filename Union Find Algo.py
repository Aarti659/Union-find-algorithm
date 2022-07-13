class uni_find_ds:
    ParentNode = {}

    def set(self, u):
        for i in u:
            self.ParentNode[i] = i

    def find(self, k):
        if self.ParentNode[k] == k:
            return k
        return self.find(self.ParentNode[k])

    def union(self, a, b):
        x = self.find(a)
        y = self.find(b)
        self.ParentNode[x] = y


def display(u, data):
    print([data.find(i) for i in u])

u = [5,9,2,8]
data = uni_find_ds()
data.set(u)
display(u, data)
data.union(2, 5)
display(u, data)
data.union(9, 8)
display(u, data)






