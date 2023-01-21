
#include <bits/stdc++.h>

using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    
    heap(){
        arr[0]=-1;
        size = 0;
    }
    
    void insert(int val){
        size+=1;
        int index=size;
        arr[index]=val;
        
        while(index>1){
            int parent=index/2;
            
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    
    void print(){
        for(int i=1;i<=size;i++)cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    void deleteFromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        else{
            arr[1]=arr[size];
            size--;
            
            //take root node to it's correct position
            
            int i=1;
            
            while(i<size){
                int leftIndex=2*i;
                int rightIndex=2*i+1;
                if(leftIndex<=size && arr[i] < arr[leftIndex]){
                    swap(arr[i],arr[leftIndex]);
                    i=leftIndex;
                }
                else if(rightIndex<=size && arr[i] < arr[rightIndex]){
                    swap(arr[i],arr[rightIndex]);
                    i=rightIndex;
                }
                else{
                    return;
                }
            }
            
        }
        
        
    }
    
    
};

void heapify(int arr[], int n, int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    
    if(left <= n && arr[largest] < arr[left]){
        largest=left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest=right;
    }
    
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    int t=n;
    
    while(t>1){
        if(arr[1]>arr[t]){
            swap(arr[1],arr[t]);
            heapify(arr,t-1,1);
        }
        t--;
    }
}

int main()
{
    
    heap h;
    
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(54);
    h.insert(1);
    h.print();
    h.deleteFromHeap();
    h.print();
    
    //heapify functuon
            int arr[6]={-1,54,1,53, 50,55};
            int n=5;
            for(int i=n/2;i>0;i--){
              heapify(arr,n,i);  
            }
            
            
            
            for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
            cout<<endl;
    //heapify functuon
    
    //heapSort
    
            heapSort(arr,n);
            
            for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
            cout<<endl;
            
    //heapSort
    
    //1 stl heap by priority_queue
    
            priority_queue<int> pq1;//max heap default
            
            pq1.push(4);
            pq1.push(2);
            pq1.push(5);
            pq1.push(3);
            cout<<"element at top of maxheap:"<<pq1.top();
            pq1.pop();
            cout<<endl;
            cout<<"element at top of maxheap:"<<pq1.top();
            cout<<endl;
            //pq1.empty()//pq1.push()//pq1.pop()//pq1.top()//pq1.size();
            
           
            
            // minHeap
            priority_queue<int, vector<int>, greater<int> >pq2;
            
            pq2.push(4);
            pq2.push(2);
            pq2.push(5);
            pq2.push(3);
            cout<<"element at top minHeap:"<<pq2.top();
            pq2.pop();
            cout<<endl;
            cout<<"element at top minHeap:"<<pq2.top();
            cout<<endl;
            
            //pq2.empty()//pq2.push()//pq2.pop()//pq2.top()//pq2.size();
            
    //\1 stl heap by priority_queue
    
    
    return 0;
}
