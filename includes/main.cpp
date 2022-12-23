#include "random_access_iterator.hpp"
#include "utils.hpp"
#include "vector.hpp"
#include <vector>

#include <iterator>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <signal.h>
#include <map>
#include <sys/time.h>
#include <unistd.h>
#include <random>
#include "Map.hpp"

// #define TIME_FAC 4 // the ft::Set methods can be slower up to std::set methods * TIME_FAC (MAX 20)

// #define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

// time_t get_time(void)
// {
//     struct timeval time_now;

//     gettimeofday(&time_now, NULL);
//     time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
//     return (msecs_time);
// }
# include "utils.hpp"
#define TIME_FAC 20
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))


time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

// int main()
// {
    // ft::node<int, int>* root;
    // std::pair<int, int> p2(2, 2);
    // std::pair<int, int> p3(3, 3);
    // std::pair<int, int> p1(1, 1);
    // std::pair<int, int> p4(4, 4);
    // std::pair<int, int> p5(5, 5);
    // std::pair<int, int> p6(10, 10);
    // root = NULL;
    // ft::avl<int, int> a;
    // // Function call to insert the nodes
    // root = a.Insert(root, NULL, &p1);
    // root = a.Insert(root, NULL, &p2);
    // root = a.Insert(root, NULL, &p3); 
    // root = a.Insert(root, NULL, &p4);
    // root = a.Insert(root, NULL, &p5);
    // root = a.Insert(root, NULL, &p6);

 
    // // Print the tree before deleting node
    // std::cout << "Before deletion:\n";
    // a.printpreorder(root);
 
    // // Function Call to delete node 10
    // root = a.Delete(root, &p6);
 
    // // Print the tree after deleting node
    // std::cout << "After deletion:\n";
    // a.printpreorder(root);
//       ft::Map<int, char> my_m;
//         for (int i = 0; i < 1e2; i++)
//             my_m.insert(ft::make_pair(i, 'A'));

//         //ft::Map<int, char>::reverse_iterator my_rit2(my_m.end());
//         //ft::Map<int, char>::const_reverse_iterator c_it, c_ob(my_m.end());
//         ft::Map<int, char>::reverse_iterator my_rit2(my_m.end());
//         ft::Map<int, char>::const_reverse_iterator c_it, c_ob(my_m.end());
      
//         c_it = my_rit2;
//         if (my_rit2->first)
//             std::cout << "OK" << std::endl;
//         else
//             std::cout << "KO" << std::endl;
// }
// std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator "
//               << "] --------------------]\t\t\033[0m";
//     {
//         /*--------------- std::map-------------------- */
//         std::map<int, std::string> m;
//         ft::Map<int, std::string> my_m;

//         for (int i = 0; i < 5; ++i)
//         {
//             m.insert(std::make_pair(13, "HELLO"));
//             my_m.insert(ft::make_pair(13, "HELLO"));
//         }

//         ft::Map<int, std::string>::iterator my_it = my_m.begin();
//         std::map<int, std::string>::iterator it = m.begin();
//         /*---------------------------------------------- */
//         EQUAL(it->second.length() == my_it->second.length());
//     }
// }

// std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++it operator "
//               << "] --------------------]\t\t\033[0m";
//     {
//         /*---------------------------------- time limit test --------------------------------------------*/
//         {
//             time_t start, end, diff;

//             std::map<int, std::string> m;
//             ft::Map<int, std::string> ft_m;
//             for (size_t i = 0; i < 1e6; ++i)
//             {
//                 m.insert(std::make_pair(i, "value"));
//                 ft_m.insert(ft::make_pair(i, "value"));
//             }
//             start = get_time();
//             for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
//                 ;
//             end = get_time();
//             diff = end - start;
//             diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

//             ualarm(diff * 1e3, 0);
//             for (ft::Map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
//                 ;
//             ualarm(0, 0);
//         }
//     }
// }
// int main () {
//     //RAAAANDOOOOOOM ACCCEEEEESSSSS ITEEEERATOOOOOOOOOOOR
     //std::cout << "Parametre Constructor of random_access_iterator\n" << std::endl;
  //  ft::random_access_iterator<int> p1(tab);
  //   ft::random_access_iterator<int> p2(tab + 5);
  //   // ft::random_access_iterator<int> p3(tab + 10);


  //   std::cout << "p1 address " << p1.get_pointer() << std::endl;
  //   std::cout << "p2 address " << p2.get_pointer() << std::endl;
  //   std::cout << "p2 - p1\n" << p2 - p1 << std::endl;
    // std::cout << "p3 address " << p3.get_pointer() << "\n\n";

    // std::cout << "Copy Constructor p4(p1) of random_access_iterator\n" << std::endl;
    // ft::random_access_iterator<int> p4(p1);
    // std::cout << "expected p4 " << p4.get_pointer() << std::endl;
    // std::cout << "expected p1 " << p1.get_pointer() << "\n\n";

    // std::cout << "Assignment Operator of p4 '=' p2 random_access_iterator\n" << std::endl;
    // p4 = p2;
    // std::cout << "expected p4 " << p4.get_pointer() << std::endl;
    // std::cout << "expected p2 " << p2.get_pointer() << std::endl;


    // std::cout << "Increment Operator of ++p1; random_access_iterator\n" << std::endl;
    // ++p1;
    // std::cout << "expected p1 " << p1.get_pointer() << "\n\n";

    // std::cout << "Decrement Operator of --p1; random_access_iterator\n" << std::endl;
    // --p1;
    // std::cout << "expected p1 " << p1.get_pointer() << "\n\n";

    // std::cout << "Addition Operator of 'p1 += 5' random_access_iterator\n" << std::endl;
    // p1 += 5;
    // std::cout << "expected p1 " << p1.get_pointer() << "\n\n";

    // std::cout << "Substraction Operator of 'p1 -= 5' random_access_iterator\n" << std::endl;
    // p1 -= 5;
    // std::cout << "expected p1 " << p1.get_pointer() << "\n\n";

    // std::cout << "Comparison Operator of random_access_iterator\n" << std::endl;
    // const ft::random_access_iterator<int> p9(tab);
    // if (p9 == p1)
    //     std::cout << "p9 == p1\n";
    // else
    //     std::cout << "p9 != p1\n";
    // return 0;

    // std::Vector<int> v(50);
    // v.push_back(1);
    // std::Vector<int> v2(102);
    // if (v2 > v)
    //     std::cout << "v2 > v\n";
    // else if (v2 == v)
    //     std::cout << "v2 == v\n";
    // else
    //     std::cout << "v2 < v\n";
    // ft::Vector<int>::reverse_iterator my_rit2(v.end());
    // ft::Vector<int>::const_reverse_iterator c_it, c_ob(v.end());
    //     c_it = my_rit2;
      //  ft::Vector<int> v(4, 5);

      //  ft::Vector<int>::reverse_iterator it;

      //  it = v.rbegin();
      //  it += 2;
        //ft::Vector<int>::reverse_iterator my_rit2(v.end());
        //ft::Vector<int>::const_reverse_iterator c_it(v.end());
      //   c_it = my_rit2;
      //   EQUAL(&(*my_rit2) == &(*c_it) );


    //REVEEEEEERSEEEEEE ITERATOOOOOOOOOO
   // ft::reverse_iterator<ft::random_access_iterator<int> > p1(tab);
   
            // time_t start, end, diff;
            // /*------------------ std::vectors ---------------------*/
            // // std::Vector<std::string> v1(1e6, "string1");
            // // std::Vector<std::string> v2(1e6, "string2");
            // // start = get_time();
            // // v1 = v2;
            // // end = get_time();
            // // diff = end - start;
            // // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*-----------------------------------------------------*/
            // /*------------------ ft::vectors ---------------------*/
            // ft::Vector<std::string> ft_v1(10, "string1");
            // ft::Vector<std::string> ft_v2(10, "string2");
            // //ualarm(diff * 10, 0);
            // ft_v1 = ft_v2;
            // //ualarm(0, 0);
            // time_t start, end, diff;
            // /*
            //  * test with n greater than Vector capacity
            //  */
            // /*------------------ std::vectors ---------------------*/
            // std::Vector<std::string> v1(10, "string2");
            // start = get_time();
            // v1.resize(100000);
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*------------------ ft::vectors ---------------------*/
            // ft::Vector<std::string> ft_v1(10, "string2");
            // ualarm(diff * 1e3, 0);
            // ft_v1.resize(100000);
            // ualarm(0, 0);
            /*----------------------------------------------------*/
            /*
             *	test with n lesser than capacity and greater than size
             */
            // /*------------------ std::vectors ---------------------*/
            // v1.resize(20);
            // start = get_time();
            // v1.resize(1e5);
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*------------------ ft::vectors ---------------------*/
            // ft_v1.resize(20);
            // ualarm(diff * 1e3, 0);
            // ft_v1.resize(1e5);
            // ualarm(0, 0);
            // /*----------------------------------------------------*/
            // /*
            //  * test with n lesser than capacity and lesser an size
            //  */
            // /*------------------ std::vectors ---------------------*/
            // v1.resize(100);
            // start = get_time();
            // v1.resize(50);
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*------------------ ft::vectors ---------------------*/
            // ft_v1.resize(100);
            // ualarm(diff * 1e3, 0);
            // ft_v1.resize(50);
            // ualarm(0, 0);
            // /*----------------------------------------------------*/


//LAAATEEEEEEEEEEEEERR
            // std::Vector<std::string> v;
            // ft::Vector<std::string> ft_v;

            // std::Vector<std::string>::iterator it;
            // ft::Vector<std::string>::iterator ft_it;

            // size_t s;
            // size_t ft_s;

            // size_t c;
            // size_t ft_c;

            // bool cond;
            // it = v.insert(v.begin(), "hello");
            // ft_it = ft_v.insert(ft_v.begin(), "hello");
            // ft_it->length();

            // s = v.size();
            // ft_s = ft_v.size();
            // c = v.capacity();
            // ft_c = ft_v.capacity();
            // std::string str;
            // std::string ft_str;
            // for (size_t i = 0; i < v.size(); ++i)
            //     str += v[i];
            // for (size_t i = 0; i < ft_v.size(); ++i)
            //     ft_str += ft_v[i];
            // cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (*ft_it == *it));

            /*------------------ std::vectors ---------------------*/
        // std::Vector<std::string> v1(10, "string2");
        // std::Vector<std::string> v2;
        // v1 = v2;
        // /*-----------------------------------------------------*/
        // /*------------------ ft::vectors ---------------------*/
        // ft::Vector<std::string> ft_v1(10, "string2");
        // ft::Vector<std::string> ft_v2;
        // ft_v1 = ft_v2;
        // /*----------------------------------------------------*/
        // /*------------------ strings to store the results ----*/
        // std::string res, ft_res;
        // /*----------------------------------------------------*/
        // for (std::Vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
        //     res += *it;

        // for (ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
        //     ft_res += *it;

        // EQUAL(res == ft_res);
    
    /*---------------------------------------------------------------------------------------------------------------------
    // ----------------------------------*/
    //  std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " pop_back method "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     /*------------------ std::vectors ---------------------*/
    //     std::Vector<std::string> v(20, "string");
    //     /*------------------ std::vectors ---------------------*/
    //     ft::Vector<std::string> ft_v(20, "string");
    //     /*
    //      * Strings to store the results
    //      */
    //     std::string s1, ft_s1;
    //     /*
    //      * Var to store the size and the capacity
    //      */
    //     size_t z1, ft_z1;
    //     size_t c1, ft_c1;
    //     v.pop_back();
    //     ft_v.pop_back();
    //     z1 = v.size();
    //     ft_z1 = ft_v.size();
    //     c1 = v.capacity();
    //     ft_c1 = ft_v.capacity();
    //     for (size_t i = 0; i < v.size(); ++i)
    //         s1 += v[i];
    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         ft_s1 += ft_v[i];
    //     EQUAL(z1 == ft_z1 && c1 == ft_c1 && s1 == ft_s1);
    // }
    // std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method (single element) "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     /*
    //      * strings to store the resutls
    //      */
    //     std::string str, ft_str;
    //     /*
    //      * var to store the size and the capacity
    //      */
    //     ft::Vector<std::string>::size_type s, ft_s;
    //     ft::Vector<std::string>::size_type c, ft_c;
    //     ft::Vector<std::string>::iterator ft_it;
    //     std::Vector<std::string>::iterator it;
    //     /*
    //      * bool to store the comparison
    //      */
    //     bool cond;

    //     /*------------------------------- test 1: empty Vector ----------------------------------------*/
    //     // insert at the begin
    //     {
    //         std::Vector<std::string> v;
    //         ft::Vector<std::string> ft_v;
    //         it = v.insert(v.begin(), "hello");
    //         ft_it = ft_v.insert(ft_v.begin(), "hello");
    //         ft_it->length();

    //         s = v.size();
    //         ft_s = ft_v.size();
    //         c = v.capacity();
    //         ft_c = ft_v.capacity();
    //         for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];
    //         cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (*ft_it == *it));
    //     }
    
    //  std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method (single element) "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     /*
    //      * strings to store the resutls
    //      */
    //     std::string str, ft_str;
    //     /*
    //      * var to store the size and the capacity
    //      */
    //     ft::Vector<std::string>::size_type s, ft_s;
    //     ft::Vector<std::string>::size_type c, ft_c;
    //     ft::Vector<std::string>::iterator ft_it;
    //     std::Vector<std::string>::iterator it;
    //     /*
    //      * bool to store the comparison
    //      */
    //     bool cond;

    //     /*------------------------------- test 1: empty Vector ----------------------------------------*/
    //     // insert at the begin
    //     {
    //         std::Vector<std::string> v;
    //         ft::Vector<std::string> ft_v;
    //         it = v.insert(v.begin(), "hello");
    //         ft_it = ft_v.insert(ft_v.begin(), "hello");
    //         std::cout <<  "********* " << *ft_it << std::endl;

    //         s = v.size();
    //         ft_s = ft_v.size();
    //         c = v.capacity();
    //         ft_c = ft_v.capacity();
    //         for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];
    //         cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (*ft_it == *it));
    //     }
    //     // insert at the end
    //     {
    //         std::Vector<std::string> v;
    //         ft::Vector<std::string> ft_v;

    //         it = v.insert(v.end(), "hello");
    //         ft_it = ft_v.insert(ft_v.end(), "hello");
    //         ft_it->length();

    //         str.clear();
    //         ft_str.clear();

    //         s = v.size();
    //         ft_s = ft_v.size();
    //         c = v.capacity();
    //         ft_c = ft_v.capacity();
    //         for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];
    //         cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it));
    //     }
    //     /*---------------------------------------------------------------------------------------------------*/
    //     /*------------------------------- test 2: the Vector capacity >= size + the new element ----------------------------------------*/
    //     {
    //         std::Vector<std::string> v(20, "string");
    //         ft::Vector<std::string> ft_v(20, "string");
    //         ft::Vector<std::string>::iterator valid_it;

    //         v.reserve(30);
    //         ft_v.reserve(30);
    //         valid_it = ft_v.begin();
    //         it = v.insert(v.begin() + 10, "hello");
    //         ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
    //         ft_it->length();

    //         str.clear();
    //         ft_str.clear();
    //         s = v.size();
    //         ft_s = ft_v.size();
    //         c = v.capacity();
    //         ft_c = ft_v.capacity();
    //         for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];
    //         cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it) && (&(*valid_it) == &(*ft_v.begin())));
    //     }
    //     /*---------------------------------------------------------------------------------------------------*/
    //     /*------------------------------- test 3: the Vector capacity < size + the new element ----------------------------------------*/
    //     {
    //         std::Vector<std::string> v(20, "string");
    //         ft::Vector<std::string> ft_v(20, "string");

    //         it = v.insert(v.begin() + 10, "hello");
    //         ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
    //         ft_it->length();

    //         str.clear();
    //         ft_str.clear();
    //         s = v.size();
    //         ft_s = ft_v.size();
    //         c = v.capacity();
    //         ft_c = ft_v.capacity();
    //         for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];
    //         cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it));
    //     }
    //     /*---------------------------------------------------------------------------------------------------*/
    //     EQUAL(cond);
    // }

            //NECESSERRYY TEEEST !!!
            
// //             ft::Vector<int> myvector (3,100);
// //             ft::Vector<int>::iterator it;

// //             it = myvector.begin();
// //             it = myvector.insert ( it , 200 );

// //             myvector.insert (it,2,300);

// //             // "it" no longer valid, get a new one:
// //             it = myvector.begin();

// //             ft::Vector<int> anothervector (2,400);
// //             myvector.insert (it+2,anothervector.begin(),anothervector.end());

// //             int myarray [] = { 501,502,503 };
// //             myvector.insert (myvector.begin(), myarray, myarray+3);

// //             std::cout << "myvector contains:";
// //             for (it=myvector.begin(); it<myvector.end(); it++)
// //                 std::cout << ' ' << *it;
// //             std::cout << '\n';
// int main()
// {
// ft::Map<int, char>::iterator my_it, my_it1, tmp;
//  std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++it operator "
//               << "] --------------------]\t\t\033[0m";
//     {
//         /*---------------------------------- time limit test --------------------------------------------*/
        
//             time_t start, end, diff;

//             std::map<int, std::string> m;
//             ft::Map<int, std::string> ft_m;
//             for (size_t i = 0; i < 2; ++i)
//             {
//                 m.insert(std::make_pair(i, "value"));
//                 ft_m.insert(ft::make_pair(i, "value"));
//             }
//             start = get_time();
//             // for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
//             //    {
//             //          std::cout << it->first << std::endl;
//             //         std::cout << it->second << std::endl;
//             //    }
//             end = get_time();
//             diff = end - start;
//             diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

//            // ualarm(diff * 2, 0);
//             for (ft::Map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
//             ;
//             std::cout << "wech bro" << std::endl;
//            //  ualarm(0, 0);
//         }
        
//         bool cond(false);
//         {
//             int res(0);
//             int myints[] = {12, 82, 37, 64, 15};
//             ft::Map<int, int> m;
//             for (size_t i = 0; i < 5; ++i)
//                 m.insert(ft::make_pair(myints[i], i));
//             for (ft::Map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
//                 res += it->first;
//             cond = res == 210;
//         }
//         {
//             int res(0), tmp;
//             int myints[] = {12, 82, 37, 64, 15};
//             ft::Map<int, int> m;
//             for (size_t i = 0; i < 5; ++i)
//                 m.insert(ft::make_pair(myints[i], i));
//             ft::Map<int, int>::iterator it = m.begin(), eit = --m.end();
//             tmp = eit->first;
//             m.erase(eit);
//             for (; it != m.end(); ++it)
//                 res += it->first;
//             cond = cond && (res == (210 - tmp));
//         }
// //         ++my_it; // I incremented here to make sure that the object changes
// //         EQUAL(*my_it == *my_it1);
    
    
// }

// int main ()
// {
//     ft::Map<int, char> mymap;
//     ft::Map<int, char>::iterator it;
    
//     // insert some values:
//     mymap.insert(ft::make_pair(10,'a'));
//     mymap.insert(ft::make_pair(20,'b'));
//     mymap.insert(ft::make_pair(30,'c'));
//     mymap.insert(ft::make_pair(40,'d'));
//     mymap.insert(ft::make_pair(50,'e'));
//     mymap.insert(ft::make_pair(60,'f'));
//     mymap.insert(ft::make_pair(70,'g'));
    
//    it = mymap.begin();
//     ++it;                       // "it" points now to 20
    
//     mymap.erase ( it );        // erasing by iterator
    
//     mymap.erase ( 40 );        // erasing by key
    
//     it = mymap.find (60);
//     mymap.erase ( it, mymap.end() ); // erasing by range
    
//     // show content:
//    mymap.printTree(mymap.get_root(), (Trunk)NU, false);
    
//     return 0;
// }


// Driver Code
// int main()
// {
// 	ft::Map<int, int> mymap;
// 	std::map<int, int> o_map;
// 	// mymap[6] = 100;
// 	// mymap[3] = 200;
// 	// mymap[9] = 200;
// 	// mymap[5] = 200;
// 	// mymap[8] = 200;
// 	// std::map<int, int>::iterator it2 = mymap.end();
	
// 	// //it2 = mymap.begin();
// 	// std::cout << "it2 is " << it2->first << std::endl;
// 	// it2--;
// 	// std::cout << "it2 is " << it2->first << std::endl;
// 	// ft::map<int, int> m;
// 	ft::pair<int, int> planet1;
// 	std::pair<int,int> planetx;
// 	ft::pair<int, int> planet3;
// 	ft::pair<int, int> planet4;
// 	ft::pair<int, int> planet5;
// 	ft::pair<int, int> planet6;
// 	ft::pair<int, int> planet7;
// 	ft::pair<int, int> planet8;
// 	ft::pair<int, int> planet9;
// 	ft::pair<int, int> planet10;
// 	ft::pair<int, int> planet11;
// 	ft::pair<int, int> planet12;
//     ft::pair<int, int> planet13;
//     ft::pair<int, int> planet14;
//     ft::pair<int, int> planet15;
//     ft::pair<int, int> planet16;
//     ft::pair<int, int> planet17;
//     ft::pair<int, int> planet18;
//     ft::pair<int, int> planet19;
//     ft::pair<int, int> planet20;
//     ft::pair<int, int> planet21;
//     ft::pair<int, int> planet22;

	
// 	// //it = m.begin();
// 	// //std::cout << "it 1 is " << it->first << std::endl;
// 	// //std::cout << "*it = " << *it << std::endl;

// 	planet1 = ft::make_pair(1, 1);
// 	planet3 = ft::make_pair(3, 2);
// 	planet4 = ft::make_pair(4, 2);
// 	planet5 = ft::make_pair(5, 3);
// 	planet6 = ft::make_pair(6, 4);
// 	planet7 = ft::make_pair(7, 4);
// 	planet9 = ft::make_pair(9, 5);
// 	planet8 = ft::make_pair(8, 6);
// 	// planet10 = ft::make_pair(10, 6);
// 	// planet11 = ft::make_pair(11, 6);
// 	// planet12 = ft::make_pair(12, 6);
//     // planet13 = ft::make_pair(13, 6);
//     // planet14 = ft::make_pair(14, 6);
//     // planet15 = ft::make_pair(15, 6);
//     // planet16 = ft::make_pair(16, 6);
//     // planet17 = ft::make_pair(17, 6);
//     // planet18 = ft::make_pair(18, 6);
//     // planet19 = ft::make_pair(19, 6);
//     // planet20 = ft::make_pair(20, 6);
//     // planet21 = ft::make_pair(21, 6);
//     // planet22 = ft::make_pair(22, 6);
// 	//std::cout << "first int is "<< planet1.first << "second int is " << planet1.second << std::endl;
// 	//std::pair<std::map<char,int>::iterator,bool> ret;

// 	// mymap.insert(planet7);
// 	// mymap.insert(planet9);
// 	// mymap.insert(planet8);
// 	// mymap.insert(planet3);
// 	// mymap.insert(planet1);
// 	// mymap.insert(planet10);
// 	// mymap.insert(planet11);
// 	// mymap.insert(planet12);
// 	// mymap.insert(planet6);
// 	// mymap.insert(planet5);
//     // mymap.insert(planet4);
//     // mymap.insert(planet13);
//     // mymap.insert(planet14);
//     // mymap.insert(planet15);
//     // mymap.insert(planet16);
//     // mymap.insert(planet17);
//     // mymap.insert(planet18);
//     // mymap.insert(planet19);
//     // mymap.insert(planet20);
//     // mymap.insert(planet21);
//     // mymap.insert(planet22);
//     mymap.insert(planet1);
//     mymap.insert(planet3);
//     mymap.insert(planet4);
//     mymap.insert(planet5);
//     mymap.insert(planet6);
//     mymap.insert(planet7);
//     mymap.insert(planet9);
//     mymap.insert(planet8);
// 	//mymap.erase(3);
// 	//mymap.insert(planet1);
// 	//mymap.erase(6);
// 	//mymap.printTree(mymap.get_root(), nullptr, false);	
// 	// // root = m.insert(root, planet7, root);
// 	// // root = m.insert(root, planet3, root);
// 	// // root = m.insert(root, planet9, root);
// 	// // root = m.insert(root, planet5, root);
// 	// // root = m.insert(root, planet8, root);
// 	// m.insert(planet6);
// 	// m.insert(planet3);
// 	// m.insert(planet9);
// 	// m.insert(planet5);
// 	// m.insert(planet8);
// 	// //m.erase(planet9.first);
// 	// //m.erase(9);
// 	// ft::map<int, int>::const_iterator it;
// 	// ft::map<int, int>::iterator it1;
// 	// // ft::map<int, int>::reverse_iterator rit;

// 	// // rit = m.rbegin();
// 	// // std::cout << "rbegin is " << rit->first << std::endl;
// 	// it = m.begin();
// 	// std::cout << "test const iterator " << it->first << std::endl;
// 	// // std::cout << "o_lower_bound " << mymap.lower_bound(10)->first << std::endl;
// 	// // std::cout << mymap.end()->first << std::endl;
// 	// // std::cout << "lower_bound " << m.lower_bound(10)->first << std::endl;
// 	// //it = m.find(0);
// 	// // /* The constructed AVL Tree would be
// 	// // 			30
// 	// // 		/ \
// 	// // 		20 40
// 	// // 		/ \ \
// 	// // 	10 25 50
// 	// // */
// 	// // std::cout << "Preorder traversal of the "
// 	// // 		"constructed AVL tree is \n";
// 	// //m.preOrder(root);
// 	mymap.printTree(mymap.get_root(), nullptr, false);
// 	return 0;
// }
template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

// int main()
// {
    // std::cout << "\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator [] "
    //           << "] --------------------]\t\t\033[0m\n";
    // {
    //     {
    //         time_t start, end, diff;
    //         /*------------------ std::maps ---------------------*/
    //         std::map<int, std::string> m1;
    //         ft::Map<int, std::string> ft_m1;

    //         for (size_t i = 0; i < 10; i++)
    //         {
    //             m1.insert(std::make_pair(i, "string2"));
    //             ft_m1.insert(ft::make_pair(i, "string2"));
    //         }
    //         for(std::map<int,std::string>:: iterator it = m1.begin(); it != m1.end(); it++)
    //             std::cout << it->first << " " << it->second << std::endl;
    //         std::cout << "\nmy map :: \n" << std::endl;

    //         for(ft::Map<int,std::string>:: iterator it = ft_m1.begin(); it != ft_m1.end(); it++)
    //             std::cout << it->first << " " << it->second << std::endl;
    //         m1[10] = "string";
    //         ft_m1[10] = "string";
    //         std::cout << "std:: m1 ::" << m1.size() << " " << "ft::my_map ::" << ft_m1.size() << std::endl;
    //         /*-----------------------------------------------------*/
    //         /*------------------ ft::Maps ---------------------*/
    //         /*----------------------------------------------------*/
    //         /*------------------ std::maps ---------------------*/
    //         m1[10 - 2] = "string";
           
    //         /*-----------------------------------------------------*/
    //         /*------------------ ft::Maps ---------------------*/
    //         ft_m1[10 - 2] = "string";
    //         /*----------------------------------------------------*/
    //         /*------------------ std::maps ---------------------*/
    //         m1[10 - 2] = m1[9];
    //         /*-----------------------------------------------------*/
    //         /*------------------ ft::Maps ---------------------*/
    //         ft_m1[10 - 2] = ft_m1[9];
    //         /*----------------------------------------------------*/
    //     }
    //     std::map<char, std::string> m;
    //     ft::Map<char, std::string> ft_m;

    //     // m['a'] = "an element";
    //     // m['b'] = "??????";
    //     // m['c'] = "achraf";

    //     ft_m['a'] = "an element";
    //      ft_m['b'] = "?????";
    //     // ft_m['c'] = "achraf";
    //     // ft_m['d'] = "ss";
    //     // ft_m['e'] = "d";
    //     // ft_m['f'] = "w";
    //     // ft_m['g'] = "q";
    //     // std::cout << m['a'] << std::endl;
    //     // ft_m['c'] = "achraf";
    //     // ft_m['d'] = "ni";

 

    //     std::cout << "" << ft_m['a'] << std::endl;
    //      std::cout << "" << ft_m['b'] << std::endl;
    //     // std::cout << "" << ft_m['c'] << std::endl;
    //     // std::cout << "" << ft_m['d'] << std::endl;
    //     // std::cout << "" << ft_m['e'] << std::endl;

    //     // std::cout << "c = " << ft_m['c'] << std::endl;
    //     // std::cout << "d = " << ft_m['d'] << std::endl;
 



    //     ft_m.printTree(ft_m.get_root(),NULL,false);
    //     //ft_m['c'] = "fahiiid";
    //    // ft_m['a'] = "test";

    //     // std::cout << "m['a'] = " << m['a'] << std::endl;
    //     // std::cout << "m['b'] = " << m['b'] << std::endl;
        
    //     // std::cout << "my map:: " << std::endl;

    //     // std::cout << "ft_m['a'] = " << ft_m['a'] << std::endl;
    //     // std::cout << "ft_m['b'] = " << ft_m['b'] << std::endl;
    //    // std::cout << "ft_m['c'] = " << ft_m['c'] << std::endl;

    //     EQUAL(m['a'] == ft_m['a'] && m['b'] == ft_m['b'] && m['c'] == ft_m['c'] && m.size() == ft_m.size());
    // }
//       std::cout << "\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method "
//               << "] --------------------]\t\t\033[0m\n";
//     {
//         bool cond(false);
//         {
//             time_t start, end, diff;
//             /*------------------ std::maps ---------------------*/
//             std::map<int, std::string> m1;
//             ft::Map<int, std::string> ft_m1;

//             for (size_t i = 0; i < 3; i++)
//                 m1.insert(std::make_pair(i, "string2"));
//             for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
//                 std::cout << it->first << std::endl;

//             std::cout << "\nmy map\n" << std::endl;
//             /*-----------------------------------------------------*/
//             /*------------------ ft::Maps ---------------------*/
//             for (size_t i = 0; i < 3; i++)
//                 ft_m1.insert(ft::make_pair(i, "string2"));
//             for (ft::Map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); it++)
//                 std::cout << it->first << std::endl;

//             /*----------------------------------------------------*/
//             /*------------------ std::maps ---------------------*/
//             std::map<int, std::string> m_range;
//             ft::Map<int, std::string> ft_m_range;

//             /*-----------------------------------------------------*/
//             /*------------------ ft::Maps ---------------------*/
//             ft_m_range.insert(ft_m1.begin(), ft_m1.end());
//             /*----------------------------------------------------*/
//         }

//         {
//             time_t start, end, diff;
//             /*------------------ std::maps ---------------------*/
//             std::map<int, std::string> m1;
//             ft::Map<int, std::string> ft_m1;

//             m1.insert(std::make_pair(10, "string2"));
            
//             /*-----------------------------------------------------*/
//             /*------------------ ft::Maps ---------------------*/
//             ft_m1.insert(ft::make_pair(10, "string2"));
//             /*----------------------------------------------------*/
//         }

//         std::map<char, int> m;
//         ft::Map<char, int> ft_m;

//         cond = m.size() == ft_m.size() && m.empty() == ft_m.empty();

//         // first insert function version (single parameter):
//         m.insert(std::pair<char, int>('a', 100));
//         m.insert(std::pair<char, int>('z', 200));

//         ft_m.insert(ft::pair<char, int>('a', 100));
//         ft_m.insert(ft::pair<char, int>('z', 200));

//         cond = cond && (m.size() == ft_m.size() && m.empty() == ft_m.empty());

//         std::pair<std::map<char, int>::iterator, bool> ret;
//         ft::pair<ft::Map<char, int>::iterator, bool> ft_ret;

//         ret = m.insert(std::pair<char, int>('z', 500));
//         ft_ret = ft_m.insert(ft::pair<char, int>('z', 500));

//         cond = cond && ret.second == ft_ret.second;

//         // second insert function version (with hint position):
//         std::map<char, int>::iterator it = m.begin();
//         ft::Map<char, int>::iterator ft_it = ft_m.begin();
//         m.insert(it, std::pair<char, int>('b', 300));
//         m.insert(it, std::pair<char, int>('c', 400));

//         ft_m.insert(ft_it, ft::pair<char, int>('b', 300));
//         ft_m.insert(ft_it, ft::pair<char, int>('c', 400));

//         cond = cond && (m.size() == ft_m.size() && m.empty() == ft_m.empty());

//         // third insert function version (range insertion):
//         std::map<char, int> anothermap;
//         ft::Map<char, int> ft_anothermap;
//         anothermap.insert(m.begin(), m.find('c'));
//         ft_anothermap.insert(ft_m.begin(), ft_m.find('c'));
//         cond = cond && (anothermap.size() == ft_anothermap.size() && anothermap.empty() == ft_anothermap.empty());

//         cond = cond && compareMaps(ft_m.begin(), ft_m.end(), m.begin(), m.end()) && compareMaps(ft_anothermap.begin(), ft_anothermap.end(), anothermap.begin(), anothermap.end());
//         EQUAL(cond);
//     }

// }
    
            // time_t start, end, diff;
            // /*------------------ std::maps ---------------------*/
            // std::map<int, std::string> m1;
            // std::map<int, std::string>::reverse_iterator rit;
            // ft::Map<int, std::string> ft_m1;
            // ft::Map<int,std::string>::reverse_iterator ft_it;
            // // start = get_time();
            // // for (size_t i = 0; i < 10; i++)
            // // {
            // //     m1.insert(std::make_pair(i, "string2"));
            // // }
            // // end = get_time();
            // // diff = end - start;
            // // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*-----------------------------------------------------*/
            // /*------------------ ft::Maps ---------------------*/
            // for (size_t i = 2; i < 10; i++)
            // {
            //     ft_m1.insert(ft::make_pair(i, "string2"));
            // }
            // for(ft_it = ft_m1.rbegin(); ft_it != ft_m1.rend(); ft_it++)
            // {
            //     std::cout << ft_it->first << std::endl;
            // }
            // // ft_it = ft_m1.rend();
            // std::cout << ft_it->first << std::endl;
            
            // for(size_t i = 0; i < 10; i++)
            // {
            //     m1.insert(std::make_pair(i, "string2"));
            // }
            // for(rit = m1.rbegin(); rit != m1.rend(); rit++)
            // {
            //     std::cout << rit->first << std::endl;
            // }


           // end = get_time();


            /*----------------------------------------------------*/
            /*------------------ std::maps ---------------------*/
            // std::map<int, std::string> m_range;
            // ft::Map<int, std::string> ft_m_range;

            // m_range.insert(m1.begin(), m1.end());
           
            // /*-----------------------------------------------------*/

            // ft_m_range.insert(ft_m1.begin(), ft_m1.end());
            /*----------------------------------------------------*/

//    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rbegin and rend methods "
//               << "] --------------------]\t\t\033[0m";
//     {
//         /*-------------------------------------- time limit test -----------------------------------*/
//         // {
//         //     time_t start, end, diff;
//         //     /*------------------ std::maps ---------------------*/
//         //     std::map<int, std::string> m1;
//         //     ft::Map<int, std::string> ft_m1;
//         //     for (size_t i = 0; i < 1e6; i++)
//         //     {
//         //         m1.insert(std::make_pair(i, "string2"));
//         //         ft_m1.insert(ft::make_pair(i, "string2"));
//         //     }

//         //     start = get_time();
//         //     m1.rbegin();
//         //     m1.rend();
//         //     end = get_time();
//         //     diff = end - start;
//         //     diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
//         //     /*-----------------------------------------------------*/
//         //     /*------------------ ft::Maps ---------------------*/
//         //     ualarm(diff * 1e3, 0);
//         //     ft_m1.rbegin();
//         //     ft_m1.rend();
//         //     ualarm(0, 0);
//         //     /*----------------------------------------------------*/
//         // }
//         /*------------------------------------------------------------------------------------------*/
//         /*------------------ std::maps ---------------------*/
//     //     std::map<int, std::string> m1;
//     //     ft::Map<int, std::string> ft_m1;

//     //     for (size_t i = 0; i < 1; i++)
//     //     {
//     //         m1.insert(std::make_pair(i, "string2"));
//     //         ft_m1.insert(ft::make_pair(i, "string2"));
//     //     }
        
//     //     ft::Map<int , std::string>::reverse_iterator it1 = ft_m1.rbegin();
//     //     ft::Map<int , std::string>::reverse_iterator it2 = ft_m1.rend();
//     //     std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
//     //     ft::Map<int, std::string> const ft_m2(ft_m1.rbegin(), ft_m1.rend());

//     //     /*-----------------------------------------------------*/
//     //     /*------------------ ft::Maps ---------------------*/
//     //     /*----------------------------------------------------*/
//     //     /*------------------ strings to store the results ----*/
//     //     std::string res, ft_res, c_res, c_ft_res;
//     //     /*----------------------------------------------------*/
//     //     for (std::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) // fill res from m1
//     //         res += it->second;
//     //     for (std::map<int, std::string>::const_reverse_iterator rit = m2.rbegin(); rit != m2.rend(); ++rit) // fill c_res from const m1
//     //         c_res += rit->second;

//     //     for (ft::Map<int, std::string>::reverse_iterator it = ft_m1.rbegin(); it != ft_m1.rend(); ++it) // fill ft_res from ft_m1
//     //         ft_res += it->second;
//     //     for (ft::Map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin(); rit != ft_m2.rend(); ++rit) // fill c_ft_res from const ft_m1
//     //         c_ft_res += rit->second;
//     //     int arr[] = {12, 82, 37, 64, 15};
//     //     ft::Map<int, int> end_test;
//     //     for(size_t i = 0; i < 5; ++i)
//     //         end_test.insert(ft::make_pair(arr[i], i));
//     //     ft::Map<int, int>::reverse_iterator rit = end_test.rend();
//     //     rit--;
//     //     EQUAL(res == ft_res && c_res == c_ft_res && rit->first == 12);
//     // }
// }
// This code is contributed by
// // rathbhupendra
// std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " erase method "
//               << "] --------------------]\t\t\033[0m";

//     {
//         bool cond(false);
//         // erasing all the elements in the map;
//         {
//             time_t start, end, diff;
//             /*------------------ std::maps ---------------------*/
//             std::map<int, std::string> m1;
//             ft::Map<int, std::string> ft_m1;
//             for (size_t i = 0; i < 3; i++)
//             {
//                 m1.insert(std::make_pair(i, "string2"));
//                 ft_m1.insert(ft::make_pair(i, "string2"));
//             }
//             m1.erase(m1.begin(), m1.end());
        
//             /*-----------------------------------------------------*/
//             /*------------------ ft::Maps ---------------------*/
     
//             ft_m1.erase(ft_m1.begin(), ft_m1.end());
      
//             /*----------------------------------------------------*/
//         }
       
//     }
//  std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (rhs.size = 0) "
//               << "] --------------------]\t\t\033[0m";
//     {
//         /*-------------------------------------- time limit test -----------------------------------*/
//         {
//             time_t start, end, diff;
//             /*------------------ std::nap ---------------------*/
//             std::map<int, std::string> m1;
//             std::map<int, std::string> m2;
//             ft::Map<int, std::string> ft_m1;
//             ft::Map<int, std::string> ft_m2;

//             for (int i = 0; i < 10; ++i)
//             {
//                 m1.insert(std::make_pair(i, "string1"));
//                 ft_m1.insert(ft::make_pair(i, "string1"));
//             }

//             /*-----------------------------------------------------*/
//             /*------------------ ft::Map ---------------------*/
//             ft_m1 = ft_m2;
//             /*----------------------------------------------------*/
//         }
//         /*------------------------------------------------------------------------------------------*/
//         /*------------------ std::map ---------------------*/
//         std::map<int, std::string> m1;
//         std::map<int, std::string> m2;
//         ft::Map<int, std::string> ft_m1;
//         ft::Map<int, std::string> ft_m2;

//         for (int i = 0; i < 10; ++i)
//         {
//             m1.insert(std::make_pair(i, "string2"));
//             ft_m1.insert(ft::make_pair(i, "string2"));
//         }
//         m1 = m2;
//         /*-----------------------------------------------------*/
//         /*------------------ ft::Map ---------------------*/
//         ft_m1 = ft_m2;
//         /*----------------------------------------------------*/
//         /*------------------ strings to store the results ----*/
//         std::string res, ft_res;
//         /*----------------------------------------------------*/
//         for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
//             res += it->second;

//         for (ft::Map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += it->second;

//         std::cout << "\nft::map == " << ft_res << std::endl;
//         std::cout << "\nstd::map == " << res << std::endl;
//         EQUAL(res == ft_res);
//     }
// }
// }




//Vector TESTS FOR CORRECTION

// int main()
// {
//     //fill constructor Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " fill constructor withh 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         /*------------------ std::Vector ---------------------*/
//         ft::Vector<int> ft_v1(5, 10);
//         /*-----------------------------------------------------*/
//         /*------------------ ft::Vector ---------------------*/
//         /*----------------------------------------------------*/
//         /*------------------ strings to store the results ----*/
//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }


//     //range constructor Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " range constructor with 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         /*------------------ std::Vector ---------------------*/
//         ft::Vector<int> ft_v1(5, 10);
//         ft::Vector<int> ft_v2(ft_v1.begin(), ft_v1.end());
//         /*-----------------------------------------------------*/
//         /*------------------ ft::Vector ---------------------*/
//         /*----------------------------------------------------*/
//         /*------------------ strings to store the results ----*/
//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v2.begin(); it != ft_v2.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //copy constructor Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor with 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1(5, 10);
//         ft::Vector<int> ft_v2(ft_v1);
//         /*------------------ strings to store the results ----*/
//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v2.begin(); it != ft_v2.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //operator= Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator= with 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         /*------------------ std::Vector ---------------------*/
//         ft::Vector<int> ft_v1(5, 10);
//         ft::Vector<int> ft_v2;
//         ft_v2 = ft_v1;
//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v2.begin(); it != ft_v2.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //operator== Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator== with 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1(5, 10);
//         ft::Vector<int> ft_v2(5, 10);
 
//         std::string ft_res;
//         /*----------------------------------------------------*/
//         if (ft_v1 == ft_v2)
//             ft_res = "true";
//         else
//             ft_res = "false";

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //operator!= Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator!= with 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1(5, 10);
//         ft::Vector<int> ft_v2(5, 10);
//         std::string ft_res;
//         if (ft_v1 != ft_v2)
//             ft_res = "true";
//         else
//             ft_res = "false";

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //begin and end methode Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " begin and end methode with 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1(5, 10);

//         std::string ft_res;
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }
//     //rbegin Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rbegin and rend methode 10-...-40 "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1;
//         ft_v1.push_back(10);
//         ft_v1.push_back(20);
//         ft_v1.push_back(30);
//         ft_v1.push_back(40);

//         std::string ft_res;
//         for (ft::Vector<int>::reverse_iterator it = ft_v1.rbegin(); it != ft_v1.rend(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }
//     //size methode Vector test

//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " size methode with 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1(5, 10);

//         std::string ft_res;
//         ft_res = std::to_string(ft_v1.size());

//         std::cout << "\nft::vector_size == " << ft_res << std::endl;
//     }

//     //insert methode Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert 7 in the begin of 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {

//         ft::Vector<int> ft_v1(5, 10);
//         ft_v1.insert(ft_v1.begin(), 7);
//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //insert methode Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert 7 in the end of 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {

//         ft::Vector<int> ft_v1(5, 10);
//         ft_v1.insert(ft_v1.end(), 7);

//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //insert methode Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert 7 in the middle of 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         /*------------------ std::Vector ---------------------*/
//         ft::Vector<int> ft_v1(5, 10);
//         ft_v1.insert(ft_v1.begin() + 2, 7);

//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //insert range methode Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert range 7-8-9 in the begin of 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1(5, 10);
//         ft::Vector<int> ft_v2;
//         ft_v2.push_back(7);
//         ft_v2.push_back(8);
//         ft_v2.push_back(9);
//         ft_v1.insert(ft_v1.begin(), ft_v2.begin(), ft_v2.end());

//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //erase methode Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " erase the begin of 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1(5, 10);
//         ft_v1.erase(ft_v1.begin());

//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }


//     //erase range methode Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " erase range the begin to the end of 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1(5, 10);
//         ft_v1.erase(ft_v1.begin(), ft_v1.end());

//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //at methode Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " at methode with 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1;
//         ft_v1.push_back(10);
//         ft_v1.push_back(20);
//         ft_v1.push_back(30);
//         ft_v1.push_back(40);
//         ft_v1.push_back(50);

//         std::string ft_res;
//         ft_res = std::to_string(ft_v1.at(0));

//         std::cout << "\nft::vector_at == " << ft_res << std::endl;
//     }

//     //assign methode Vector test (NECESSARY TO EXPLAIIN WHY IT IS IMPORTANT THE ENABLE IF !!!!)
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " assign 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1;
//         ft_v1.assign(5, 10);

//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

//     //assign range methode Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " assign range 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1;
//         ft::Vector<int> ft_v2;
//         ft_v2.push_back(10);
//         ft_v2.push_back(20);
//         ft_v2.push_back(30);
//         ft_v2.push_back(40);
//         ft_v2.push_back(50);
//         ft_v1.assign(ft_v2.begin(), ft_v2.end());

//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }


//     //swap methode Vector test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " swap 5 elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Vector<int> ft_v1;
//         ft::Vector<int> ft_v2;
//         ft_v1.push_back(10);
//         ft_v1.push_back(20);
//         ft_v1.push_back(30);
//         ft_v1.push_back(40);
//         ft_v1.push_back(50);
//         ft_v2.push_back(60);
//         ft_v2.push_back(70);
//         ft_v2.push_back(80);
//         ft_v2.push_back(90);
//         ft_v2.push_back(100);
//         ft_v1.swap(ft_v2);

//         std::string ft_res;
//         /*----------------------------------------------------*/
//         for (ft::Vector<int>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(*it);

//         std::cout << "\nft::Vector == " << ft_res << std::endl;
//     }

// }



// STACK TESTS FOR CORRECTION
// #include "../Vectorr/stack.hpp"
// int main()
// {
//     //stack constructor test
//     std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " stack constructor test "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Stack<int> ft_s1;
//         std::cout << "\nft::stack == " << ft_s1.size() << std::endl;
//     }

//     // //stack push test
//     // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " stack push test "
//     //           << "] --------------------]\t\t\033[0m";
//     // {
//     //     ft::Stack<int> ft_s1;
//     //     ft_s1.push(10);
//     //     ft_s1.push(20);
//     //     ft_s1.push(30);
//     //     ft_s1.push(40);
//     //     ft_s1.push(50);

//     //     std::string ft_res;
//     //     /*----------------------------------------------------*/

//     //     std::cout << "\nft::stack == " << ft_res << std::endl;
//     // }
// }

//Map tests for correction




int main()
{
    //map constructor test
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " map constructor test "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     ft::Map<int, int> ft_m1;
    //     std::cout << "\nft::Map == " << ft_m1.size() << std::endl;
    // };

    //Map insert test
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " Map insert test "
              << "] --------------------]\t\t\033[0m";
    {
        ft::Map<int, int> ft_m1;
        ft_m1.insert(ft::make_pair(1, 10));
        ft_m1.insert(ft::make_pair(2, 20));
        ft_m1.insert(ft::make_pair(3, 30));
        ft_m1.insert(ft::make_pair(4, 40));
        ft_m1.insert(ft::make_pair(5, 50));

        std::string ft_res;
        /*----------------------------------------------------*/
        for (ft::Map<int, int>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += std::to_string(it->second) + " ";

        std::cout << "\nft::Map == " << ft_res << std::endl;
        std::cout << "\ndrawig Map for test == " << std::endl;
        ft_m1.printTree(ft_m1.get_root(),NULL, false);

    };

    //Map insert range test
    std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "Map insert range test "
              << "] --------------------]\t\t\033[0m";
    {
        ft::Map<int, int> ft_m1;
        ft::Map<int, int> ft_m2;
        ft_m2.insert(ft::make_pair(1, 10));
        ft_m2.insert(ft::make_pair(2, 20));
        ft_m2.insert(ft::make_pair(3, 30));
        ft_m2.insert(ft::make_pair(4, 40));
        ft_m2.insert(ft::make_pair(5, 50));
        ft_m1.insert(ft_m2.begin(), ft_m2.end());

        std::string ft_res;
        for(ft::Map<int, int> ::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += std::to_string(it->first) + " " + " ";
        std::cout << "\nft::Map == " << ft_res << std::endl;
        std::cout << "\ndrawig Map for test == " << std::endl;
        ft_m1.printTree(ft_m1.get_root(),NULL, false);
    };

    //Map erase test

    std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "Map erase test "
              << "] --------------------]\t\t\033[0m";
    {
        ft::Map<int, int> ft_m1;
        ft_m1.insert(ft::make_pair(1, 10));
        ft_m1.insert(ft::make_pair(2, 20));
        ft_m1.insert(ft::make_pair(3, 30));
        ft_m1.insert(ft::make_pair(4, 40));
        ft_m1.insert(ft::make_pair(5, 50));
        ft_m1.erase(3);

        std::string ft_res;
        for(ft::Map<int, int> ::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += std::to_string(it->first) + " ";
        std::cout << "\nft::Map == " << ft_res << std::endl;
        std::cout << "\ndrawig Map for test == " << std::endl;
        ft_m1.printTree(ft_m1.get_root(),NULL, false);
    };

//     //Map erase range test

    std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "Map erase range test "
              << "] --------------------]\t\t\033[0m";
    {
        ft::Map<int, int> ft_m1;
        ft_m1.insert(ft::make_pair(1, 10));
        ft_m1.insert(ft::make_pair(2, 20));
        ft_m1.insert(ft::make_pair(3, 30));
        ft_m1.insert(ft::make_pair(4, 40));
        ft_m1.insert(ft::make_pair(5, 50));
        ft_m1.erase(ft_m1.begin(), ft_m1.find(4));

        std::string ft_res;
        for(ft::Map<int, int> ::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += std::to_string(it->first) + " ";
        std::cout << "\nft::Map == " << ft_res << std::endl;
        std::cout << "\ndrawig Map for test == " << std::endl;
        ft_m1.printTree(ft_m1.get_root(),NULL, false);
    };

//     //Map swap test

//     std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "Map swap test "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Map<int, int> ft_m1;
//         ft::Map<int, int> ft_m2;
//         ft_m1.insert(ft::make_pair(1, 10));
//         ft_m1.insert(ft::make_pair(2, 20));
//         ft_m1.insert(ft::make_pair(3, 30));
//         ft_m1.insert(ft::make_pair(4, 40));
//         ft_m1.insert(ft::make_pair(5, 50));
//         ft_m2.insert(ft::make_pair(10, 100));
//         ft_m2.insert(ft::make_pair(20, 200));
//         ft_m2.insert(ft::make_pair(30, 300));
//         ft_m2.insert(ft::make_pair(40, 400));
//         ft_m2.insert(ft::make_pair(50, 500));
//         ft_m1.swap(ft_m2);

//         std::string ft_res;
//         for(ft::Map<int, int> ::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
//             ft_res += std::to_string(it->first) + " ";
//         std::cout << "\nft::Map == " << ft_res << std::endl;
//         std::cout << "\ndrawig Map for test == " << std::endl;
//         ft_m1.printTree(ft_m1.get_root(),NULL, false);
//     };

//     //Map upperbound test

//     std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "Map upperbound test "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Map<int, int> ft_m1;
//         ft_m1.insert(ft::make_pair(10, 10));
//         ft_m1.insert(ft::make_pair(20, 20));
//         ft_m1.insert(ft::make_pair(30, 30));
//         ft_m1.insert(ft::make_pair(45, 40));
//         ft_m1.insert(ft::make_pair(55, 50));
//         ft::Map<int, int>::iterator it = ft_m1.upper_bound(30);
//         std::cout << "\nft::Map == " << it->first << std::endl;
//         std::cout << "\ndrawig Map for test == " << std::endl;
//         ft_m1.printTree(ft_m1.get_root(),NULL, false);
//     };

//     //map lowerbound test

//     std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "Map lowerbound test "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Map<int, int> ft_m1;
//         ft_m1.insert(ft::make_pair(10, 10));
//         ft_m1.insert(ft::make_pair(20, 20));
//         ft_m1.insert(ft::make_pair(30, 30));
//         ft_m1.insert(ft::make_pair(31, 40));
//         ft_m1.insert(ft::make_pair(50, 50));
//         ft::Map<int, int>::iterator it = ft_m1.lower_bound(30);
//         std::cout << "\nft::Map == " << it->first << std::endl;
//         std::cout << "\ndrawig Map for test == " << std::endl;
//         ft_m1.printTree(ft_m1.get_root(),NULL, false);
//     };

//     //map equal_range test

//     std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "Map equal_range test "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Map<int, int> ft_m1;
//         ft_m1.insert(ft::make_pair(10, 10));
//         ft_m1.insert(ft::make_pair(20, 20));
//         ft_m1.insert(ft::make_pair(30, 30));
//         ft_m1.insert(ft::make_pair(40, 40));
//         ft_m1.insert(ft::make_pair(50, 50));
//         ft::Map<int, int>::iterator it = ft_m1.equal_range(20).first;
//         std::cout << "\nft::Map == " << it->first << std::endl;
//         std::cout << "\ndrawig Map for test == " << std::endl;
//         ft_m1.printTree(ft_m1.get_root(),NULL, false);
//     };
        
 }

// #include "../Map/map.hpp"
// #include "../Map/bidirectional_iterator.hpp"






// // BIDIRECTIONAL ITERATOR 

// int main()
// {
//     //++it operator
//     std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "++it operator "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Map<int, int> ft_m1;
//         ft_m1.insert(ft::make_pair(10, 10));
//         ft_m1.insert(ft::make_pair(20, 20));
//         ft_m1.insert(ft::make_pair(30, 30));
//         ft_m1.insert(ft::make_pair(40, 40));
//         ft_m1.insert(ft::make_pair(50, 50));
//         ft::Map<int, int>::iterator it = ft_m1.begin();
//         std::cout << "\nft::Map == " << it->first << std::endl;
//         ++it;
//         std::cout << "\nft::Map == " << it->first << std::endl;
//         ++it;
//         std::cout << "\nft::Map == " << it->first << std::endl;
//         std::cout << "\ndrawig Map for test == " << std::endl;
//         ft_m1.printTree(ft_m1.get_root(),NULL, false);
//     };


//     //--it operator

//     std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "--it operator "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Map<int, int> ft_m1;
//         ft_m1.insert(ft::make_pair(10, 10));
//         ft_m1.insert(ft::make_pair(20, 20));
//         ft_m1.insert(ft::make_pair(30, 30));
//         ft_m1.insert(ft::make_pair(40, 40));
//         ft_m1.insert(ft::make_pair(50, 50));
//         ft::Map<int, int>::iterator it = ft_m1.end();
//         --it;
//         std::cout << "\nft::Map == " << it->first << std::endl;
//         --it;
//         std::cout << "\nft::Map == " << it->first << std::endl;
//         --it;
//         std::cout << "\nft::Map == " << it->first << std::endl;
//         std::cout << "\ndrawig Map for test == " << std::endl;
//         ft_m1.printTree(ft_m1.get_root(),NULL, false);
//     };

// }

// #include "stack.hpp"

// int main()
// {
//     //stack push test

//     std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "stack push test "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Stack<int> ft_s1;
//         ft_s1.push(10);
//         ft_s1.push(20);
//         ft_s1.push(30);
//         ft_s1.push(40);
//         ft_s1.push(50);
//         std::cout << "\nft::Stack == " << ft_s1.top() << std::endl;
//         std::cout << "\ndrawig Stack for test == " << std::endl;
//         //ft_s1.printStack(ft_s1.get_root(),NULL, false);
//     };

//     //Stack pop test

//     std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "Stack pop test "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Stack<int> ft_s1;
//         ft_s1.push(10);
//         ft_s1.push(20);
//         ft_s1.push(30);
//         ft_s1.push(40);
//         ft_s1.push(50);
//         ft_s1.pop();
//         ft_s1.pop();
//         std::cout << "\nft::Stack == " << ft_s1.top() << std::endl;
//        // std::cout << "\ndrawig Stack for test == " << std::endl;
//         //ft_s1.printStack(ft_s1.get_root(),NULL, false);
//     };

//     //Stack top test

//     std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "Stack top test "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Stack<int> ft_s1;
//         ft_s1.push(10);
//         ft_s1.push(20);
//         ft_s1.push(30);
//         ft_s1.push(40);
//         ft_s1.push(50);
//         std::cout << "\nft::Stack == " << ft_s1.top() << std::endl;
//        // std::cout << "\ndrawig Stack for test == " << std::endl;
//         //ft_s1.printStack(ft
//     }


//     //print all stack elements

//     std::cout << "\n\n\n\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << "print all stack elements "
//               << "] --------------------]\t\t\033[0m";
//     {
//         ft::Stack<int> ft_s1;
//         std::string str;
//         ft_s1.push(10);
//         str = std::to_string(ft_s1.top());
//         ft_s1.push(20);
//         str = str + " " + std::to_string(ft_s1.top());
//         ft_s1.push(30);
//         str = str + " " + std::to_string(ft_s1.top());
//         ft_s1.push(40);
//         str = str + " " + std::to_string(ft_s1.top());
//         ft_s1.push(50);
//         str = str + " " + std::to_string(ft_s1.top());
//         std::cout << "\nft::Stack == " << str << std::endl;
//         //std::cout << "\ndrawig Stack for test == " << std::endl;
//         //ft_s1.printStack(ft_s1.get_root(),NULL, false);
//     };
// }