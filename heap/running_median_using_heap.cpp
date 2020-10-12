#include <bits/stdc++.h>
using namespace std;

//https://www.hackerrank.com/challenges/find-the-running-median

int main()
{
    int n; cin>>n; float median = 0;

    priority_queue<float> maxHeap;
    priority_queue<float,vector<float>,greater<float>> minHeap;

    while(n--)
    {
        int x; cin>>x;

        if(x>median)    minHeap.push(x);
        else            maxHeap.push(x);

        int minHeap_size = minHeap.size();
        int maxHeap_size = maxHeap.size();

        if(minHeap_size > maxHeap_size+1)
        {
            maxHeap.push(minHeap.top()); minHeap.pop(); minHeap_size--; maxHeap_size++;
        }
        if(maxHeap_size > minHeap_size+1)
        {
            minHeap.push(maxHeap.top()); maxHeap.pop(); maxHeap_size--; minHeap_size++;
        }

        if(minHeap_size == maxHeap_size)
        {
            median = ( minHeap.top() + maxHeap.top() ) / 2.0;
        }
        else if(minHeap_size > maxHeap_size)    median = minHeap.top();
        else                                    median = maxHeap.top();

        printf("%0.1f\n",median);
    }
    
    return 0;
}
