# include <iostream>

using namespace std;

void selection_sort(int arr[],int n){
    int i,j,min;
    
    for(i=0;i<n;i++){
        min =i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        if (min!=i)
        swap(arr[i],arr[min]);
    }
for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
}
//main
int main(){
int a[]={2,5,1,7,9,3,7};
    int n=7;
    selection_sort(a,n);
    
 return 0;
}