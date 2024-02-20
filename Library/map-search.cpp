// C++ code to demonstrate the working of find() 

#include<iostream> 
#include<map> // for map operations 
using namespace std; 

int main() 
{ 
	// declaring map 
	// of char and int 
	map< char, int > mp; 
	
	// declaring iterators 
	map<char, int>::iterator it ; 
	map<char, int>::iterator it1 ; 
	
	// inserting values 
	mp['a']=5; 
	mp['b']=10; 
	mp['c']=15; 
	mp['d']=20; 
	mp['e']=30; 
	
	// using find() to search for 'b' 
	// key found 
	// "it" has address of key value pair. 
	it = mp.find('b'); 
	
	if(it == mp.end()) 
		cout << "Key-value pair not present in map" ; 
	else
		cout << "Key-value pair present : "
		<< it->first << "->" << it->second ; 
	
	cout << endl ; 
	
	// using find() to search for 'm' 
	// key not found 
	// "it1" has address of end of map. 
	it1 = mp.find('m'); 
	
	if(it1 == mp.end()) 
		cout << "Key-value pair not present in map" ; 
	else
		cout << "Key-value pair present : "
			<< it1->first << "->" << it1->second ; 
	
} 
