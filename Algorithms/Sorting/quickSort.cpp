#include<bits/stdc++.h>

void quickSort(int[],int,int);
int partition(int[],int,int);
void swap(int&,int&);


int main()
{
    int arr[]={6,8,9,3,2,5,3,6,7,8,10};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,arrSize-1);

    for(int i = 0; i < arrSize; i++)
    {
        std::cout<<arr[i]<<std::endl;
    }

    return 0;
}

void quickSort(int data[], int left,int right)
{
    if(left < right)
    {
        int pivot = partition(data,left,right);

        quickSort(data,left,pivot-1);
        quickSort(data,pivot+1,right);
    }
}

int partition(int data[],int left,int right)
{
    int pivot = data[right],
        i = left,
        j = right-1;

    while (i < j)
    {
        if(data[i] > pivot)
            swap(data[i],data[j--]);
        else
            i++;
    }

    if(data[i] > pivot)
    {
        swap(data[i],data[right]);
        return i;
    }
     
    else
    {
        swap(data[i+1],data[right]);
        return i+1;
    }
        
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

