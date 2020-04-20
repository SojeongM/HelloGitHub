#ifndef __ARRAY__
#define __ARRAY__

#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T> class Array{

	protected:
		T *data;
		int len;
	public:
		Array(){};
		Array(int size);
		~Array();

	int length() const;

	virtual T &operator[](int i);
	virtual T operator[](int i) const;

	void print();
};

template <class T> Array<T>::Array(int size){
	if(size<0){
		cout<<"Array bound error"<<endl;
		exit(0);
	}	
	data = new T[size];
//	cout<<"complete"<<endl;
	len=size;
}

template <class T> Array<T>::~Array(){
	delete[] data;
}

template <class T> int Array<T> :: length() const{
	return len;
} 

template <class T> T &Array<T>::operator[](int i){
	static T v;
	//cout<<data[i]<<endl;
	if(i >= 0 && i<len){
		return data[i];
	}
	else{
		cout<<"Array bound error"<<endl;
		return v;
	}
}

template <class T> T Array<T>::operator[](int i) const{
//	static int var;
	if(i >= 0 && i<len){
		//cout<<data[i]<<endl;
		return data[i];
	}
	else{
		cout<<"Array bound error"<<endl;
		return 0;
	}
}

template <class T> void Array<T> :: print(){
	cout<<"[";
	int i;
	for(i=0;i<len;i++){
		cout<<' '<<data[i];
	}
	cout<<"]"<<endl;
}

#endif

