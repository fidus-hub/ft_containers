#include <iostream>
#include <iterator>
#include <map>
using namespace std;

 int main()
 {
	map<int, string> x;
	x.insert(pair<int, string>(3, "Amine"));
	x.insert(pair<int, string>(1, "Ayoub"));
	x.insert(pair<int, string>(2, "HAMID"));
	x.insert(pair<int, string>(6, "HAMID"));
	x.insert(pair<int, string>(10, "HAMID"));
	x.insert(pair<int, string>(-5, "HAMID"));


	map<int, string>::iterator it;

	if (x.find(10) != x.end()) {
		cout << "I FOUND IT" << endl;
	} else {
		cout << " I DIDNT FIND IT" << endl;
	}


	// for (it = x.begin(); it != x.end(); ++it) {
	// 	cout << it->first << ' ' << it->second << endl;
	// }

	//  ft::vector<int> copy_amine;
	//  copy_amine(amine.begin(),  amine.end());
	//  amine.push_back(10);
	//  ft::vector<int>::iterator it;

 }