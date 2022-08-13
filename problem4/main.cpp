#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
void RecPermute(string soFar, string rest)
{
	if (rest == "") // No more characters
		cout << soFar << endl; // Print the word
	else // Still more chars
	// For each remaining char
		for (int i = 0; i < rest.length(); i++) {

			string next = soFar + rest[i]; // Glue next char

			string remaining = rest.substr(0, i) + rest.substr(i + 1);
			if (!mp.count(next)) {
				mp.insert({ next,1 });
				RecPermute(next, remaining);
			}
		}
}
// "wrapper" function
void ListPermutations(string s) {
	RecPermute("", s);
}
int main()
{
	ListPermutations("Makka");

	return 0;
}