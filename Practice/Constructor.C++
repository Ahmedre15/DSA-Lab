#include<iostream>
using namespace std;
class Arraycopy{
    int* arr;
    int size;
    public:
    Arraycopy(int s){
        size=s;
        arr=new int[size];
        for(int i=0;i<size;i++){
            arr[i]=i+1;
        }
    }
    Arraycopy(const Arraycopy &obj){
        size=obj.size;
        arr=new int[size];
        for(int i=0;i<size;i++){
         arr[i]=obj.arr[i];  
        }
    }
    Arraycopy& operator=(const Arraycopy& obj){
if(this!= &obj){
delete[] arr;
size=obj.size;

for(int i=0;i<size;i++){
    arr[i]=obj.arr[i];
}}

return *this;
    }

    ~Arraycopy() {
    delete[] arr;
}
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};
int main(){
    Arraycopy a1(5);
    cout<<"Original Array: ";
    a1.display();
    Arraycopy a2=a1;
        cout<<"Copy Array: ";
        a2.display();
    Arraycopy a3(3);
    a3=a1;
        cout<<"Copy Assignment Array: ";
        a3.display();

return 0;

}