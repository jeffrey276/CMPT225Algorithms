/*
**  a4.cpp
**  Assignment 4, CMPT-225, Fall 2015
**    
**  301233627 jzcheng Jeffrey Cheng
**  
**  Reads a sequence of integers (in the range of int's) from standard in;
**  It is interpreted as two lists, separated by a single 0
**/

#include "LL2.h"
#include <string>
#include <iostream>

using namespace std;

int listDiff(LL2 ls1,LL2 ls2){
    if(ls1.GetLargest() > ls2.GetLargest()){
        return ls1.GetLargest();
    }
    else if(ls1.GetLargest() < ls2.GetLargest() ){
        ls2.remove(ls2.GetLargest());
        return listDiff(ls1, ls2);
    }
    else if(ls1.GetLargest() == ls2.GetLargest()){
        ls1.remove(ls1.GetLargest());
        if(ls1.isEmpty()==1){
            return 0;
        }
        else{
            return listDiff(ls1, ls2);
            
        }
    }
    else{
        return 0;
    }
   return 0;
}

int main(){
	 LL2 ls1;
	 LL2 ls2;
     int x ;
     cin >> x ;
    while(!cin.eof()){
        if(x != 0){
            ls1.add(x);
        }
        else{
                while(!cin.eof()){
                    cin >> x;
                ls2.add(x);
                }
        }
        cin >> x;
    }

    cout <<"301233627    jzcheng    Jeffrey Cheng"<<endl;

    ls1.removeDuplicates();
    ls2.removeDuplicates();
    
   if(ls1.isEmpty()==1){
       cout <<"None"<<endl;
   }
   else if(ls2.isEmpty()==1){
       cout <<ls1.GetLargest()<<endl;
   }
   else{
       if(listDiff(ls1, ls2)==0){
        cout<<"None"<<endl;
       }
       else{
           cout<<listDiff(ls1, ls2)<<endl;
       }
   }
}
