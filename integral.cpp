#include <iostream>
#include <cmath>

using namespace std;

double fungsi(double x){
    double fx = x*x;
    return fx;
}

void leftRiemannSum(int n, double deltaX, double xo){
    double erLRS;
    double xi[100000], luas, luasTotal = 0;
    cout<<"LRS"<<endl;
    cout<<"Iterasi"<<"\t\t"<<"Luas"<<endl;

    for(int j=0; j<=n; j++){
        xi[j] = xo + deltaX * j;
    }

    for(int i=0; i<n; i++){
        luas = fungsi(xi[i])*deltaX;
        luasTotal += luas;
        cout<<i<<"\t\t"<<luas<<endl;
    }
    //erLRS=((8.0/3.0)-luasTotal)/(8.0/3.0);
    cout<<"Total : "<<luasTotal<<endl;
    //cout<<"Error : "<<erLRS<<endl;
    cout<<endl;
}

void rightRiemannSum(int n, double deltaX, double xo){
    double erRRS;
    double xi[100000], luas, luasTotal = 0;
    cout<<"RRS"<<endl;
    cout<<"Iterasi"<<"\t\t"<<"Luas"<<endl;

    for(int j=0; j<=n; j++){
        xi[j] = xo + deltaX * j;
    }

    for(int i=0; i<n; i++){
        luas = fungsi(xi[i+1])*deltaX;
        luasTotal += luas;
        cout<<i<<"\t\t"<<luas<<endl;
    }
    //erRRS=((8.0/3.0)-luasTotal)/(8.0/3.0);
    cout<<"Total : "<<luasTotal<<endl;
    //cout<<"Error : "<<erRRS<<endl;
    cout<<endl;
}

void trapesium(int n, double deltaX, double xo){
    double erTrap;
    double xi[100000], luas, luasTotal = 0;
    cout<<"Trapesium"<<endl;
    cout<<"Iterasi"<<"\t\t"<<"Luas"<<endl;

    for(int j=0; j<=n; j++){
        xi[j] = xo + deltaX * j;
    }

    for(int i=0; i<n; i++){
        luas = 0.5*(fungsi(xi[i+1])+fungsi(xi[i]))*deltaX;
        luasTotal += luas;
        cout<<i<<"\t\t"<<luas<<endl;
    }
    //erTrap=((8.0/3.0)-luasTotal)/(8.0/3.0);
    cout<<"Total : "<<luasTotal<<endl;
    //cout<<"Error Relatif : "<<erTrap<<endl;
    cout<<endl;
}

main(){

    int n;
    double a, b;
    double deltaX;
    cout<<"Banyak Partisi (n) : ";
    cin>>n;
    cout<<"Batas Awal (a) : ";
    cin>>a;
    cout<<"Batas Akhir (b) : ";
    cin>>b;
    cout<<endl;

    deltaX = (b-a)/n;

    leftRiemannSum(n, deltaX, a);
    rightRiemannSum(n, deltaX, a);
    trapesium(n, deltaX, a);

}
