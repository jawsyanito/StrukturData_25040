#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    string input;
    cout << "Masukkan string: ";
    cin >> input;

    queue<char> q;
    stack<char> s;

    // Masukkan ke queue dan stack
    for (char c : input) {
        q.push(c);
        s.push(c);
    }

    //Variabel pembanding
    bool isPalindrome = true;

    // Bandingkan elemen yang diinput
    while (!q.empty()) {
        if (q.front() != s.top()) {
            isPalindrome = false;
            break;
        }
        q.pop();
        s.pop();
    }

    // Outputnya
    if (isPalindrome)
        cout << "Queue adalah palindrome" << endl;
    else
        cout << "Queue bukan palindrome" << endl;

    return 0;
}
