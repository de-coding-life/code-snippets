#include<bits/stdc++.h>
using namespace std;
class student
{
   int priv=0;
   // before public: , variables cannot be accessed outside class i.e. they are private
   public:
   string name;
   int age;
   int id;
   // This is a parameterised constructor so that we can give value directly to data members like ---> student a(3,"manoj",10,195);
   student (int p,string n,int a,int i)
   {   
      cout<<"\nParameterised Constructor"; 
      priv=p;
      name=n;
      age=a;
      id=i;
   }
   // This is a default constructor so that we dont get error if no value is passed eg ---> student a;
   student ()
   {   
      cout<<"\nDefault Constructor";
   }
   // This is a copy constructor , however it is automatically made but automatic one does a shallow copy and ours does a deep copy , it is used when ----> student b=c; or student b(c);
   student (student &a)
   {   
      cout<<"\nCopy Constructor";
      priv=a.priv;
      name=a.name;
      age=a.age;
      id=a.id;
   }
   // This is a destructor , it calls after the object is destroyed (usually end of the function where object is created), no arguments can be passed in this
   ~student ()
   {   
      cout<<"\nDestructor";
   }
   // operator overloading --> defining the use of operator 
   void operator == (student &a)
   {
      if (name==a.name and age == a.age and priv==get_priv() and id==a.id)
      cout<<"\nData in both classes are identical";
      else
      cout<<"\nData in both classes isn't same";
   }
   void set_priv(int a)
   {
      priv=a;
   }
   int get_priv()
   {
      return priv;
   }
   void get_info()
   {
      cout<<endl;
      cout<<priv<<endl;
      cout<<name<<endl;
      cout<<age<<endl;
      cout<<id<<endl;
   }
};
int main()
{
   // we can also create a array of objects like below
   student a[2];
   for (int i=0;i<2;i++)
   {
      cout<<"\nName "<<i<<" = ";
      cin>>a[i].name;
      cout<<"\nAge "<<i<<" = ";
      cin>>a[i].age;
      cout<<"\nId "<<i<<" = ";
      cin>>a[i].id;
   }
   cout<<a[0].name;
   // a[1].priv=6 will give error as priv is private
   a[1].set_priv(6);
   a[1].get_info();

   student b(3,"manoj",10,195); // Use of Parameterised Constructor
   b.get_info();
   student c; // Use of Default Constructor
   c.name="kartik";
   c.age=13;
   c.id=432;
   c.get_info();
   student d=b; // Use of Copy Constructor
   d.get_info();
   d==b; // Use of operator overload
   c==b; // Use of operator overload
   return 0; // Destructer will be called after main() is destroyed
}