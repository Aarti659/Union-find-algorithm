#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSet
{
    unordered_map<int, int> Parent;

public:


    void Set(vector<int> const &universe)
    {
        for (int i: universe) {
            Parent[i] = i;
        }
    }

    int Find(int k)
    {

        if (Parent[k] == k) {
            return k;
        }


        return Find(Parent[k]);
    }

    void Union(int a, int b)
    {

        int x = Find(a);
        int y = Find(b);

        Parent[x] = y;
    }
};

void printSets(vector<int> const &universe, DisjointSet &dis)
{
    for (int i: universe) {
        cout << dis.Find(i) << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> universe = { 1,2,3,4,5 };

    DisjointSet dis;
    dis.Set(universe);
    printSets(universe, dis);

    dis.Union(4, 3);
    printSets(universe, dis);

    dis.Union(2, 1);
    printSets(universe, dis);

    dis.Union(1, 3);
    printSets(universe, dis);

    return 0;
}



