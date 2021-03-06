#include <bits/stdc++.h>
using namespace std;

int minIndex(queue<int> &q, int sortedIndex)
{
	int min_index = -1;
	int min_val = INT_MAX;
	int n = q.size();
	for (int i=0; i<n; i++)
	{
		int curr = q.front();
		q.pop(); 
		if (curr <= min_val && i <= sortedIndex)
		{
			min_index = i;
			min_val = curr;
		}
		q.push(curr); 
	}
	return min_index;
}


void insertMinToRear(queue<int> &q, int min_index)
{
	int min_val;
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
		int curr = q.front();
		q.pop();
		if (i != min_index)
			q.push(curr);
		else
			min_val = curr;
	}
	q.push(min_val);
}

void sortQueue(queue<int> &q)
{
	for (int i = 1; i <= q.size(); i++)
	{
		int min_index = minIndex(q, q.size() - i);
		insertMinToRear(q, min_index);
	}
}

// driver code
int main()
{
queue<int> q;
int age , n;
cout<<"Enter the number of patients : "<<endl;
cin>>n;
for(int i = 1 ; i <= n ; i++){
    cout<<"Enter the patient's age : "<<endl;
    cin>>age;
    q.push(age);
}
// Sort queue
sortQueue(q);

// Print sorted queue
while (q.empty() == false)
{
	cout << q.front() << " ";
	q.pop();
}
cout << endl;
return 0;
}
