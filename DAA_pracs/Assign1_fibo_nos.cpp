#include<iostream>
#include<vector>
using namespace std;

//Recursive method
int fibRecursive(int n){
    if(n<=1)
        return n;
    return fibRecursive(n-1) + fibRecursive(n-2);
}

//Non-recursive method
int fibIterative(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0 || n > 46) {
        cout << "Enter n between 0 and 46.\n";
        return 0;
    }

    vector<int> dp(n + 1, -1);

    cout << "Recursive: " << fibRecursive(n) << endl;
    cout << "Non-recursive: " << fibIterative(n) << endl;
    return 0;
}