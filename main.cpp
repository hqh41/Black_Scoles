#include "call.h"
#include "put.h"
#include "matrix.h"
#include<fstream>
#include<string>
#include <iostream>
using namespace std;

int main() {
    call c(1, 0.1, 0.1, 100, 300);
    matrix c1(1000+1, 1);
    c1 = c.option_Crank_Nicolson(1000, 1000);
    //affichage(c1);
    ofstream firstfile;
    firstfile.open ("call_Crank.txt");
    for(int i=0; i<=1000; i++)
    {
        if(i<1000)
            firstfile << c1(i, 0) << "\n";
        else
            firstfile << c1(i, 0);
    }
    firstfile.close();




    call cc(1, 0.1, 0.1, 100, 300);
    matrix cc1(1000+1, 1);
    cc1 = cc.option_DFI(1000, 1000);
    //affichage(cc1);
    ofstream secondfile;
    secondfile.open ("call_DFI.txt");
    for(int i=0; i<=1000; i++)
    {
        if(i<1000)
            secondfile << cc1(i, 0) << "\n";
        else
            secondfile << cc1(i, 0);
    }
    secondfile.close();


    put p(1, 0.1, 0.1, 100, 300);
    matrix p1(1000+1, 1);
    p1 = p.option_Crank_Nicolson(1000, 1000);
    //affichage(c1);
    ofstream thirdfile;
    thirdfile.open ("put_Crank.txt");
    for(int i=0; i<=1000; i++)
    {
        if(i<1000)
            thirdfile << p1(i, 0) << "\n";
        else
            thirdfile << p1(i, 0);
    }
    thirdfile.close();
    

    put pp(1, 0.1, 0.1, 100, 300);
    matrix pp1(1000+1, 1);
    pp1 = pp.option_DFI(1000, 1000);
    //affichage(c1);
    ofstream forthfile;
    forthfile.open ("put_DFI.txt");
    for(int i=0; i<=1000; i++)
    {
        if(i<1000)
            forthfile << pp1(i, 0) << "\n";
        else
            forthfile << pp1(i, 0);
    }
    forthfile.close();


    ofstream fifthfile;
    fifthfile.open ("diff_call.txt");
    /*ifstream firstfile1;
    firstfile1.open ("call_Crank.txt");
    ifstream secondfile2;
    secondfile2.open ("call_DFI.txt");
    string temp1, temp2;
    while(getline(firstfile1, temp1)&&getline(secondfile2, temp2)){
        fifthfile<<stod(temp2)-stod(temp1)<<"\n";
    }
    */
    for(int i=0; i<=1000; i++)
    {
        if(i<1000)
            fifthfile << c1(i,0)-cc1(i,0) << "\n";
        else
            fifthfile << c1(i,0)-cc1(i,0);
    }
    fifthfile.close();

    ofstream sixthfile;
    sixthfile.open ("diff_put.txt");
    /*ifstream firstfile11;
    firstfile11.open ("put_Crank.txt");
    ifstream secondfile22;
    secondfile22.open ("put_DFI.txt");
    string temp11, temp22;
    while(getline(firstfile11, temp11)&&getline(secondfile22, temp22)){
        sixthfile<<stod(temp22)-stod(temp11)<<"\n";
    }
     */
    for(int i=0; i<=1000; i++)
    {
        if(i<1000)
            sixthfile << p1(i,0)-pp1(i,0) << "\n";
        else
            sixthfile << p1(i,0)-pp1(i,0);
    }
    sixthfile.close();



    return 0;
}
