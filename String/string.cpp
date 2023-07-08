// insert() , find() , clear() , append() , compare() , empty() , erase() , substr() , stoi() , to_string() , sort() , begin() , end() , transform()
// size() equivalent to length()

#include <bits/stdc++.h>
using namespace std;
int main()
{
   //' for char
   //" for string

   string str = "YASH IS A BOY";
   cout << str << endl;

   string str1(10, 'n');
   cout << str1 << endl;

   string str2;
   cin >> str2;  // only stores first word
   cin.ignore(); // always use cin.ignore() while using getline
   cout << str2 << endl;

   getline(cin, str1); // stores whole line ( for char cin.getline(chr,n))
   cout << str1 << endl;
   cout << "str1 " << str1 << endl;

   str2.append(str1);
   cout << str2 << endl;
   cout << str1 << endl;

   str += str2;
   cout << str << endl;
   cout << str[1] << endl;
   str.clear();
   cout << str << endl;

   str = "taj";
   cout << str.compare("tag") << endl; //+
   str = "king";
   cout << str.compare("kingston") << endl; //-
   str = "apple";
   cout << str.compare("apricot") << endl; //-
   str = "apple";
   cout << str.compare("apple") << endl; // 0

   cout << str.empty() << endl; // 0
   str = "";
   cout << str.empty() << endl; // 0

   str = "yashvats";
   cout << str.erase(4, 1) << endl;

   cout << str.find("as") << endl;
   cout << str.find("k") << endl;

   str.insert(1, "*()*");
   cout << str << endl;

   cout << str.length() << endl;
   cout << str.size() << endl;

   cout << str.substr(5, 3) << endl;

   str = "123";
   cout << stoi(str) + 2 << endl;
   int t = stoi(str) + 2;
   cout << to_string(t) + "21" << endl;

   str = "fnmjtzxcvoqwpeeshgduilkyaerb";
   sort(str.begin(), str.end());
   cout << str << endl;
   sort(str.begin(), str.end(), greater<char>());
   cout << str << endl;

   str = "UEIDFEFNEFE";
   transform(str.begin(), str.end(), str.begin(), ::tolower);
   cout << str << endl;
   transform(str.begin(), str.end(), str.begin(), ::toupper);
   cout << str << endl;

   return 0;
}