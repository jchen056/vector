#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

/* NOTE: you can write a swap function without using a temporary
 * variable.  It just requires a bit of arithemtic cleverness.
 * If you're bored, try to figure out how. */
void pushfront(vector<int>& V,int x);
void swap(int& a, int& b)
{
int temp = a;
a = b;
b = temp;
}
//------------------------
/* NOTE: the const by reference pattern: we can use it to
 * get the best of both worlds: efficiency of by reference
 * (since we don't have to copy) and a guarantee that V
 * will not be changed by the funcion. */
bool subsetsum(const vector<int>& V, int t)
{
size_t n = V.size();
for (size_t i = 0; i < n-1; i++) {
for (size_t j = i+1; j < n; j++) {
if (V[i] + V[j] == t){
cout<<i<<j<<"\n";
return true;}
}
}
/* if we ever make it down here, we know that the
* target was never found. */
return false;
}

/* TODO: write a "pop_front" function that removes the first element.
 * It should preserve the order of the other elements.
 * NOTE: if you don't care about preserving the order of elements, there
 * is a much more efficient way to remove the first element (or any other
 * element).  Can you see how?
 * */
void removal (vector<int>& Vec){
for (size_t i=0;i<Vec.size();i++)
{
Vec[i]=Vec[i+1];
}
Vec.pop_back();}
/* NOTE: the above takes approximately n^2/2 steps (corresponding
 * to the number of pairs we examine in the loops).  Can you see
 * a more efficient way to solve this problem if the input vector
 * was in sorted order? */
/* TODO: modify the above function so that in the case where
 * a solution is found, it also "returns" the pair of indexes
 * found to work.  (Use by reference params...)  Update the test
 * code in main accordingly. */

/* function to reverse vector contents: */
void reverse(vector<int>& V)
{
size_t n = V.size();
for (size_t i = 0; i < n/2; i++) {
swap(V[i],V[n-1-i]);
}
}

int main()
{
//step1: takes std inputs and stores them in a vector
int x;
vector<int> T;
while (cin >> x) {
T.push_back(x);
}

//step2: reverse the vector
reverse(T);

//step3: add an element to the beginning of the vector
int numb=11;
pushfront(T,numb);
/* now T's elements are in reverse order.  Let's check: */
for (size_t i = 0; i < T.size(); i++) {
cout << T[i] << " ";
}
cout << "\n";

//ste4: are there two elements whose sum is 3?
if (subsetsum(T,3)){
cout << "found 3 as a sum of 2 elements.\n";}
else{
cout<<"no two elements in the vector add up to 3\n";}


//remove the first element in the vector
removal(T);
for (size_t i = 0; i < T.size(); i++) {
cout << T[i] << " ";
}
cout << "\n";

return 0;
}

/* TODO: write a function called "push_front(V,x)" for a vector, which
 * adds parameter x to index 0 of vector V by moving all the other values
 * to higher indexes.  (This should show you why inserting elements is only
 * efficient at the *end* of a vector.) */
void pushfront(vector<int>& V,int x){
/* IDEA: increase size of V, say by pushing a "dummy"
* element to the back.  Then shift all elements to
* a higher index, leaving index 0 free to be overwritten. */
V.push_back(12);
/* now shift all elements "to the right" (higher indexes) */
for (size_t i=(V.size()-1);i>0;i--){
V[i]=V[i-1];}
V[0]=x;
}

