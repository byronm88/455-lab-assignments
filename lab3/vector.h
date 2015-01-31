
#ifndef _VECTOR_H
#define _VECTOR_H




#include <iostream>
using namespace std;

template <class T> class vector {
public:
    typedef T * iterator;
	 typedef T  value_type;
     
		// constructors
	vector	() { buffer = 0; resize(0); }
	vector	(unsigned int size) { buffer = 0; resize(size) ;}
	vector(unsigned int size, T initial);
    vector (vector & v);
    ~vector () {delete [] buffer; }
    
    vector( const vector & v );     // copy constructor
    vector( );                       // destructor
		// member functions
	T			back	()	{ return buffer[mySize-1]; }
	iterator	begin	()	{ return buffer; }
	int			capacity	() { return myCapacity; }
	iterator	end		()	{ return buffer + mySize; }
	bool		empty	()	{ return mySize == 0; }
	T			front	()	{ return buffer[0]; }
	void		pop_back () { mySize--; }
	void		push_back	(T value);
	void		reserve	(unsigned int newSize);
	void		resize	(unsigned int newSize)	{ reserve(newSize); mySize = newSize; }
	int			size	()	{ return mySize; }
		// operators
	T &		operator [ ] (unsigned int index) { return buffer[index]; }
private:
	unsigned int mySize;
	unsigned int myCapacity;
	T * buffer;
};

template <class T> vector<T>::vector (unsigned int size, T initial)

  //create vector with given size
  // intiialize each element with value
{
    buffer = 0;
    resize(size);
    // use fill algorightm to iniitialize each location
    fill (begin(), end(), initial);
}

template <class T> vector<T>::vector (vector & v)
// create vector with iven size
// intilalize element by copying from agument
{
    buffer = 0;
    resize(v.size());
    // use copy algorithhm to intinitialize location
    copy (v.begin(), v.end(), begin());
}
template <class T> void vector<T>::reserve (unsigned int newCapacity)
// rrevese capcity at least as large as argument value
{
	if (buffer == 0) { // no buffer, zero size
		mySize = 0; 
		myCapacity = 0;
		}
        // don't do anythimg if large enough
	if (newCapacity <= myCapacity)
		return;
        // alocate new buffer make sure successful
	T * newBuffer = new T [newCapacity];
	copy (buffer, buffer + mySize, newBuffer);
    // reset data field
	myCapacity = newCapacity;
    // change buffer pointer
	delete [] buffer;
	buffer = newBuffer;
}

template <class T> void vector<T>::push_back (T value)
// push value on to end of vector
{
    // show buffer if neccessary
	if (mySize >= myCapacity)
		reserve(myCapacity + 5);
	buffer[mySize++] = value;
}


#endif

