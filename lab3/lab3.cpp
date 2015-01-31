#include <iostream>
#include  "svector.h"

using namespace std;
int main()
{
    vector <int> example;         
    example.push_back(3);         //add 3 onto the vector
    example.push_back(10);        //add 10 to the end
    example.push_back(33);        //add 33 to the end
    for(int x=0; x<example.size(); x++) 
    {
        cout<<example[x]<<" ";    //output: 3 10 33
    }
    if(!example.empty())          
        example.clear();          
    vector <int> another_vector;  
    another_vector.push_back(10); //adds to end of vector
    example.push_back(10);        
    if(example==another_vector) 
    {
        example.push_back(20); 
    }
    for(int y=0; y<example.size(); y++)
    {
        cout<<example[y]<<" ";    //should output 10 20
    }
    return 0;
}
