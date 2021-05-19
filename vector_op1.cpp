#include <iostream>
//using std::cin;
//using std::cout;
using namespace std;
#include <vector>
using std::vector;
#include <string>
using std::string;

bool search(vector<int> V,int x);
void oddvector(const vector<int> &V,vector<int> &New);
void unique(vector<int>& V);
/* exercise: read all lines given on stdin and print them
 * back out in reverse order. */
/* NOTE: to test this out you can just echo some lines into
 * it like this:
 * $ echo -e "aaa\nbbb\nccc" | ./vectors
 * Or even give it a whole file, e.g. our program source:
 * $ ./vectors < vectors.cpp
 * (This command gives vectors.cpp to our program on stdin.
 * TODO: try it out.)
 * */

int main()
{
/*
 vector<string> V;
//first read entire input into V:
    string line; //holds a single line
    while (getline(cin,line)) {
//NOTE: getline is sort of like doing "cin >> line" but it will read all the way until a newline (\n) instead of reading until spaces/tabs. 
        V.push_back(line);}
//at this point, we have read all of stdin.  Now just print it in reverse order:
//NOTE: V.size() tells you how many elements V has.
    for (size_t i = V.size()-1; i != (size_t)(-1); i--) {
        cout << V[i] << "\n";}
   */
 
  vector<int> V;
  int x;
  while(cin>>x){
   V.push_back(x);}

  int y=5;
  if (search(V,y)){
   cout<<"5 in the vector\n";}
  else{
   cout<<"5 not found\n";}

  vector<int> New;
  oddvector(V,New);
  for (size_t j=0;j<New.size();j++){
   cout<<New[j]<<" ";}
  cout<<"\n";


  unique(V);
  for(size_t i=0;i<V.size();i++){
   cout<<V[i]<<" ";}
  cout<<"\n";

return 0;
}

/* TODO: if you haven't already, read at least the first half or so of l3.pdf
 * (up until the section on arrays.)  Also read Prof. Li's notes, of course. */
/* TODO: write a function that takes a vector (say of integers) and searches
 * for a particular value x, returning true if and only if x is found. */
bool search(vector<int> V,int x){
 for (size_t i=0;i<V.size();i++)
  {
   if (V[i]==x)
    return true;}
 return false;}
/* TODO: write a function that takes a vector of integers, and returns a
 * new vector of integers which contains only the odd integers. */
void oddvector(const vector<int> &V,vector<int> &New){
 for (size_t i=0;i<V.size();i++)
 {
   if ((V[i]%2)!=0)
     New.push_back(V[i]);}
  }
/* TODO: write a function that takes a vector V of integers which
 * is *sorted*, and returns a vector of the unique integers from V.
 * E.g., if V = {1,2,2,3,3,3,4}, then the result should
 * be {1,2,3,4}. */
void unique(vector<int> &V){
 //only one element in the vector, already unique
 if(V.size()==1){
   return;}
 int c=V.size();
 int temp=V[c-1];//temp stores the last element on the vector
 V.pop_back();
 unique(V);
 bool b=search(V,temp);//last element in the vector;
 if(b==false){
  V.push_back(temp);}
 else{
  return;}
   }
