#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str1 = "jklkzjhck";
	string str2 = "JKLkzjHCK";
	std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	std::transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	cout << str1 << endl;
	cout << str2 << endl;

	cout << str1.compare(str2) << endl;
	int a;
	cin >> a;
}
