
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class Itr>
void m_sort(Itr start, unsigned low, unsigned int high)
// internal merge source routine
{
	if (low + 1 < high) 
	{
		unsigned int center = (high + low) / 2;
		m_sort (start, low, center);
		m_sort (start, center, high);
		inplace_merge (start + low, start + center, start + high);
	}
}

template <class T> 
void mergeSort(vector<T> & s)
// sort vector in accendig order using merge sort algirithm
{
	m_sort(s.begin(), 0, s.size());
}

int main () 
{
  vector<int> v;     // Whatever values you want
  v.push_back(5);
  v.push_back(8);
  v.push_back(12);
  v.push_back(2);
  v.push_back(6);
 
  for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it) //  display the vector before it's sorted
  
  cout << ' ' << *it<< endl;// displays an element  of vectors

  mergeSort(v); //Call the mergeSort function, passing though vector v.

  for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it) // display the sorted vector

  cout << ' ' << *it<< endl; // displays an element  of vectors

return 0;
}
