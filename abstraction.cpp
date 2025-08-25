#include <iostream>
#include <vector>

using namespace std;

class abstraction {
    private:
        int a;
        int b;
    public:
        void set(int i1, int i2) { a = i1; b = i2; }
        void get(int *i1, int *i2) { *i1 = a; *i2 = b; }
        vector<int> getVector(void) { return vector<int> (a, b); } // (size, default_value)
        vector<int> getVector1(void) { return vector<int> {a, b}; }
};

int main(void)
{
    abstraction obj;
    obj.set(5, 3);
    int a;
    int b;

    obj.get(&a, &b);
    cout << "a: " << a << "; b: " << b << ";" << endl;
    vector<int> newVector = obj.getVector();
    cout << "a: " << newVector[0] << "; b: " << newVector[1] << ";" << endl;
    for (auto x:newVector) cout << x << " " ;
    cout << endl;
    
    // can access like below only if a and b are public.
    // cout << "obj.a: " << obj.a << "; obj.b: " << obj.b << ";" << endl;

    vector<int> newVector1 = obj.getVector1();
    cout << "a: " << newVector1[0] << "; b: " << newVector1[1] << ";" << endl;
    for(auto x:newVector1) cout << x << " " ;
    cout << endl;
    return 0;
}