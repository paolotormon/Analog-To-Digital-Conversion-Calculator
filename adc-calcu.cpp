#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <bits/stdc++.h> 
using namespace std;

double getCloser(double val1, double val2, double target) 
{ 
    if (target - val1 >= val2 - target) 
        return val2; 
    else
        return val1; 
} 

double findDigitalCode(double arr[], int n, double target) 
{ 
    if (target <= arr[0]) 
        return arr[0]; 
    if (target >= arr[n - 1]) 
        return arr[n - 1]; 

    int i = 0, j = n, mid = 0; 
    while (i < j) { 
        mid = (i + j) / 2; 
  
        if (arr[mid] == target) 
            return arr[mid]; 

        if (target < arr[mid]) { 
  
            if (mid > 0 && target > arr[mid - 1]) 
                return getCloser(arr[mid - 1], 
                                  arr[mid], target); 
  
            j = mid; 
        } 
  
        else { 
            if (mid < n - 1 && target < arr[mid + 1]) 
                return getCloser(arr[mid], 
                                  arr[mid + 1], target); 
            i = mid + 1;  
        } 
    } 
  
    //last element
    return arr[mid]; 
}

main(){
	system("Color fc");
	float lowerbound, higherbound, range;
	float pcm_bits;
	int qnt_levels;
	float step_size;
	
	cout<<"PAO'S ANALOG TO DIGITAL CONVERSION CALCULATOR\n"<<endl;
	cout<<"Enter the signal range (ex: -5v to +5v) in volts. "<<endl;
	cout<<"First, the lower value (ex: -5): ";
	cin>>lowerbound;
	cout<<"Next, the higher value (ex: +5): ";
	cin>>higherbound;
	cout<<"Enter the number of bits used in the PCM System: ";
	cin>>pcm_bits;
	
	range=higherbound-lowerbound;
	qnt_levels=pow(2,pcm_bits);
	step_size=range/qnt_levels;
	cout<<"\n\n---Analog to Digital Conversion SPECS--"<<endl;
	cout<<"There are: "<<qnt_levels<<" quantization levels "<<endl;
	cout<<"The step size is: "<<step_size<<" volts per level"<<endl;
	cout<<"The maximum quantization error is: "<<step_size/2<<" volts\n"<<endl;
	

	double arr[qnt_levels];
	double it_volt;
	double s_amplitude;
	int x = sizeof(arr)/sizeof(arr[0]);
	it_volt=lowerbound;
	arr[0]=it_volt;
	for(int i=1;i<qnt_levels;i++){
		it_volt=it_volt+step_size;
		arr[i]=it_volt;
	}
	
	cout<<"Below are the Amplitude of Pulses in volts"<<endl;
	for(int i=0;i<qnt_levels;i++){
		cout<<arr[i]<<"\n";
	}
	
	cout<<"\nBelow is a digital code calculator given a sample amplitude."<<endl;
	
	do{
	
		cout<<"\nEnter amplitude of a sample: ";
		cin>>s_amplitude;
		cout<<(findDigitalCode(arr,x,s_amplitude))<<
		" is the equivalent digital code. Press enter to try again.\n";
		cin.ignore();
	}while(true);
}

//BY PAOLO TORMON. IF YOU FOUND THIS USEFUL STAR MY GITHUB REPO 




