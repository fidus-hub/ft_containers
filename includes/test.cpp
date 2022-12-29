#include <iostream>
#include <iterator>
//#include "./Map.hpp"
//#include "./vector.hpp"
//#include "./stack.hpp"
#include <map>
using namespace std;

//  int main()
//  {
// 	map<int, string> x;
// 	x.insert(pair<int, string>(3, "Amine"));
// 	x.insert(pair<int, string>(1, "Ayoub"));
// 	x.insert(pair<int, string>(2, "HAMID"));
// 	x.insert(pair<int, string>(6, "HAMID"));
// 	x.insert(pair<int, string>(10, "HAMID"));
// 	x.insert(pair<int, string>(-5, "HAMID"));


// 	map<int, string>::iterator it;

// 	if (x.find(10) != x.end()) {
// 		cout << "I FOUND IT" << endl;
// 	} else {
// 		cout << " I DIDNT FIND IT" << endl;
// 	}


	// for (it = x.begin(); it != x.end(); ++it) {
	// 	cout << it->first << ' ' << it->second << endl;
	// }

	//  ft::vector<int> copy_amine;
	//  copy_amine(amine.begin(),  amine.end());
	//  amine.push_back(10);
	//  ft::vector<int>::iterator it;

// }



// int		main(void)
// {
// 	ft::Map<int, int>	a;

// 	for(int i = 0; i < 6; i++)
// 		a.insert(ft::make_pair<int, int>(i, i*10));
// 	a.erase(3);
// 	while (1);
// 	return (0);
// }


// int main()
// {
// 	ft::Vector<int> x;
// 	ft::Vector<int> y;
// 	ft::Vector<int>::iterator it;
// 	for(int i = 0; i < 5; i++)
// 		x.push_back(i);
// 	x.swap(y);
// 	it = y.begin();
// 	for(; it != y.end(); it++) 
// 		std::cout<< *it << std::endl;
// }

// int main()
// {
// 	ft::Map<int, int>::iterator it;
// 	ft::Map<int, int> a;

// 	a[4] = 5;
// 	a[4] = 6;
// 	a[1] = 6;
// 	a[45] = 6;
// 	a[-1] = 6;

	
// 	it = a.begin();
// 	for(; it != a.end(); it++) 
// 		std::cout<< it->first << ' ' << it->second  << std::endl;

// 	a[4] = 0;
// 	it = a.begin();
// 	for(; it != a.end(); it++) 
// 		std::cout<< it->first << ' ' << it->second  << std::endl;
// }


// int main()
// {
// 	ft::Map<int, string> mp;
// 	mp.insert(ft::make_pair<int, string>(1, "amine"));
// 	mp.insert(ft::make_pair<int, string>(2, "rachid"));
// 	mp.insert(ft::make_pair<int, string>(13, "hamid"));
// 	mp.insert(ft::make_pair<int, string>(-4, "ilyass"));

// 	ft::Map<int, string>::iterator it01 ;

// 	for(it01 = mp.begin(); it01 != mp.end(); it01++)
// 		std::cout << it01->first << ": " << it01->second << "\n"; 

// 	ft::Map<int, string>::iterator it1 = mp.begin();
// 	ft::Map<int, string>::iterator it2 = mp.end();

// 	mp.erase(it1, it2);
// 	mp.erase(13);
// 	mp.erase(it2);
// 	std::cout << "erased\n" ;
// 	for(it01 = mp.begin(); it01 != mp.end(); it01++)
// 	std::cout << it01->first << ": " << it01->second << "\n";
// 	while(1);
// }

// int main()
// {
// 	ft::Vector<std::string> vc;
	

// 	vc.push_back("amine");
// 	vc.push_back("grissen");
// 	vc.push_back("1337");
// 	vc.push_back("rachid");

// 	std::cout << "vector size: "<< vc.size() << "\n" ;
// 	std::cout << "before content: \n" ;
// 	for(int i = 0; i < vc.size(); i++)
// 		std::cout << vc[i] << "\n" ;

// 	vc.push_back("42");
// 	std::cout << "after size: "<< vc.size() << "\n" ;
// 	std::cout << "after content: \n" ;
// 	for(int j = 0; j < vc.size(); j++)
// 		std::cout << vc[j] << "\n" ;
// 	ft::Vector<std::string>::iterator it_bg = vc.begin();
// 	ft::Vector<std::string>::iterator it_end = vc.end();
// 	vc.erase(it_bg, it_end);
// 	std::cout << "after erase size: "<< vc.size() << "\n" ;
// 	std::cout << "after erase content: \n" ;
// 	for(int j = 0; j < vc.size(); j++)
// 		std::cout << vc[j] << "\n" ;
// 	//while(1);

// }

