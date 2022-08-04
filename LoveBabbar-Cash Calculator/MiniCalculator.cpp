//Mini Calculator
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the Amount"<<endl;
    cin>>n;
    int num = 1;
    int hundredNote,fiftyNote,twentyNote,oneNote,remainingCash;
 
    switch(num){
        case 1:
            hundredNote=n/100;
            remainingCash= n-(hundredNote*100);
            cout<<"Hundred Note = "<<hundredNote<<endl;
            num++;

        case 2: 
            fiftyNote=remainingCash/50;
            remainingCash=remainingCash-(fiftyNote*50);
            cout<<"Fifity Note = "<<fiftyNote<<endl;
            num++;

        case 3: 
            twentyNote=remainingCash/20;
            remainingCash=remainingCash-(twentyNote*20);
            cout<<"Twenty Note = "<<twentyNote<<endl;
            num++;
            
        case 4: 
            oneNote=remainingCash/1;
            cout<<"One Note = "<<oneNote<<endl;
            num++;
    }

    return 0;
}