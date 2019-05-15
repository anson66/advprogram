#include <iostream>

using namespace std;
struct Fraction {
	int num, denom;	
	Fraction() {}
	
	Fraction(int n, int d) { num = n; denom = d; }
	
	int operator>(Fraction other) {
		return num * other.denom > denom * other.num;
	}
};

ostream& operator<<(ostream& os, const Fraction& fraction) {
		os << fraction.num << "/" << fraction.denom;
		return os;
	}
	
template <class T>
class MyPair { 
  T a, b; 
public: 
  MyPair (T first, T second) {a=first; b=second;} 
  T getmax (); 
}; 

template <class T>
T MyPair<T>::getmax () { 
  T retval = a > b ? a : b; 
  return retval; 
}

int main () { 
  MyPair<int> myIntPair (100, 75); 
  cout << 
  myIntPair.getmax(); 
  
  MyPair<string> myStringPair ("aaa", "abc"); 
  cout << 
  myStringPair.getmax(); 
  
  MyPair<Fraction> myFractionPair(Fraction(1,2), Fraction(2,3)); 
  cout << 
  myFractionPair.getmax(); 
  return 0; 
}

