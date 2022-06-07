#include<iostream>
#include<vector>
using namespace std;


class prio_q{
vector<int> pq;
public:
prio_q(){  // constructor

}
bool isEmpty(){
    return pq.size()==0;
    
    }
   // return the size of priority queue -no oof elemenets
   int getSize(){
       return pq.size();
   } 
   int getMin(){
       if(isEmpty())
       {
           return 0;  // queue is empty
       }
   return pq[0];
   }
void insert(int elemenet){
    pq.push_back(elemenet);
    int childIndex=pq.size()-1;
   while(childIndex>0){
       int parentIndex=(childIndex-1)/2;
       if(pq[childIndex]<pq[parentIndex]){
           int temp=pq[parentIndex];
           pq[childIndex]=pq[parentIndex];
           pq[parentIndex]=temp;
       }
       else{
           break;
       }
       childIndex=parentIndex;
   }
    }

    int removeMin(){
        if(isEmpty()){
            return 0;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

      //down-Heapify
    
      int parentIndex=0;
      int leftChildIndex=2*parentIndex+1;
      int rightChildIndex=2*parentIndex+2;
        // now we have to compare the root element by its children and the smaller one will get swapped by yht root element 
      // yeh comparaing and swapping hmein tab tak karni hai jb tak element leaf ni bn jata
      // aur leaf hmein 2i+1 and 2i+2 wale formulae se pta chlega ki wo out of  length of the array to ni ja rha 2i+1 and 2i+2 karne pr

while(leftChildIndex<pq.size()){
int minIndex=parentIndex; // this is a temp variable storing the minimum element index while comparaing
if(pq[minIndex]>pq[leftChildIndex]){
    minIndex=leftChildIndex;
}
if(rightChildIndex<pq.size()&&pq[rightChildIndex]<pq[minIndex] ){
    minIndex=rightChildIndex;
}

if(minIndex==parentIndex)  // element is at correct position
{
    break;
}
int temp=pq[minIndex];
pq[minIndex]=pq[parentIndex];
pq[parentIndex]=temp;

parentIndex=minIndex;
leftChildIndex=2*parentIndex+1;
rightChildIndex=2*parentIndex+2;
}

         return ans;
    }



}

// if we want to find the child index of a parent then 2i+1 for left and 2i+2 for right where i is the index of the parent
// visulize it as a tree and implement it in the vector


int main(){
    prio_q p;
    p.insert(100);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67); 
    cout<<p.getSize()<<endl;
    // cout<p.getMin()<<endl; 
    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";
    }
    cout<<endl; 

 
}