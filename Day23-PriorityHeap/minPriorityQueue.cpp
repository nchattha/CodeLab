#include<iostream>
#include<vector>

using namespace std;

class MinPriorityQueue{
    vector<int>pq;
    bool isEmpty(){ return pq.size()==0;}
    int getSize(){ return pq.size();}
    public:
        MinPriorityQueue(){}
        int getMinimum(){ 
            if(!isEmpty())
                return pq.at(0);
            return -1;    
        }
        void insert(int value)
        {
            if(!isEmpty()){
                pq.push_back(value);
                int currentIndex = pq.size()-1;
                int parentIndex = (currentIndex-1)/2;
                while(pq[parentIndex]>value)
                {
                    swap(pq[parentIndex],pq[currentIndex]);
                    currentIndex = parentIndex;
                    parentIndex = (currentIndex-1)/2;
                }
            }
            else
            {
                pq.push_back(value);
            }
            
        }

        void removeMin()
        {
            if( !isEmpty() )
            {
                int lastIndex = pq.size()-1;
                int currentIndex = 0;
                swap(pq[currentIndex],pq[lastIndex]);
                pq.pop_back(); //remove last Element

                //Update the index
                lastIndex = pq.size()-1;
                int leftChildIndex  = (2 * currentIndex)+1;
                int rightChildIndex = (2 * currentIndex)+2;
                while( (leftChildIndex <= lastIndex &&  pq[leftChildIndex]<pq[lastIndex]) || 
                (rightChildIndex <= lastIndex &&pq[rightChildIndex]<pq[lastIndex]) )
                {
                    int lowerIndex = pq[leftChildIndex]<pq[rightChildIndex]?leftChildIndex:rightChildIndex;
                    swap(pq[currentIndex],pq[lowerIndex]);
                    currentIndex = lowerIndex;
                    leftChildIndex  = (2 * currentIndex)+1;
                    rightChildIndex = (2 * currentIndex)+2;
                }
            }
            else
            {
                cout<<"Nothoing to Remove"<<endl;
            }
            
        }

        void printPQ()
        {
            cout<<"\n Print in level Order "<<endl;
            for( auto val:pq)
            {
                cout<<val<<" , ";
            }
            cout<<"NULL"<<endl;
        }
};


int main(void)
{
    MinPriorityQueue minPq;
    minPq.insert(10);
    minPq.insert(50);
    minPq.insert(20);
    minPq.insert(60);
    minPq.insert(100);
    minPq.insert(25);
    minPq.insert(12);
    minPq.printPQ();

    minPq.removeMin();
    minPq.printPQ();
}