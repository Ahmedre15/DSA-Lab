
#include<iostream>
using namespace std;
int main(){
	int d[5]={0,1,2,3,4};
	int size0=sizeof(d)/sizeof(d[0]);
	 cout<<"1D array: "<<endl;
    for(int i=0;i<5;i++){
    cout<< d[i]<<" "; }
    cout<<endl;
    cout<<"Size : "<<size0<<endl;
    
	//2D Array
	
	int arr[2][5]={{2,3,1,6,0},{1,2,3,4,5}};

    
    cout<<"2D array: "<<endl;
    for(int i=0;i<2;i++){
    	for(int j=0;j<5;j++){
    cout<< arr[i][j]<<" ";}cout<<endl; }
    
    //Input
    //1D Array
    int n;
    cout<<"Enter size of 1D aray : ";
    cin>>n;
    int* arr1=new int[n];
	cout<<"Enter "<<n<<" elements : "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	} 
	cout<<"1D Array(input):"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr1[i]<<" ";
	} cout<<endl; delete arr1;
	//2D Array
	int n1,m;
	cout<<"Enter size of row : ";
    cin>>n1;
    cout<<"Enter size of column : ";
    cin>>m;
	int** arr2 =new int*[n1];
	for(int i=0;i<n1;i++){
		arr2[i]=new int[m];
	}
	
	
    for(int i=0;i<n1;i++){
    	for(int j=0;j<m;j++){
    cout<<"Enter the element at ["<<i<<"]["<<j<<"] : ";
	cin>>arr2[i][j];}}
	cout<<endl;
     for(int i=0;i<n1;i++){
    	for(int j=0;j<m;j++){
    cout<<"Element at ["<<i<<"]["<<j<<"] is: "<<arr2[i][j]<<endl;}}
    delete[] arr2;
    return 0;  
}

