/*
* Problem Link: https://www.hackerrank.com/challenges/median
*/


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

void median(char temp, int tempint) {
    static multiset<int> mset;
    static multiset<int>::iterator miter = mset.begin();
    bool flag = true;
    if(temp == 'a'){
        mset.insert(tempint);
        if(mset.size() == 1){
            miter = mset.begin();
        }else if(mset.size() & 1){
            if(tempint >= *miter) miter++;
        }
        else{
            if(tempint < *miter) miter--;
        }
    }
    else if(temp == 'r'){
        multiset<int>::iterator remiter = mset.find(tempint);
        if(remiter != mset.end()){
            int data = *miter;
            unsigned int size = mset.size();
            if(size & 1){
                if(tempint > data || remiter == miter) miter--;
            }
            else{
                if(tempint <= data) miter++;
            }
            mset.erase(remiter);
        }
        else{
            cout << "Wrong!\n";
            flag = false;
        }
    }
    if(flag){
    	if(mset.size() == 0)
    		cout << "Wrong!\n";
    	else if(mset.size() & 1){
            cout << *miter << "\n";
        }
        else{
        	long int sum = 0;
            multiset<int>::iterator next = miter;
            ++next;
            sum += (*miter); sum += (*next);
            if(sum & 1)
//                cout << (float)sum/2.0f << "\n";
            	printf("%.1f\n", (double)sum/2.0);
            else
                cout << sum/2 << "\n";
        }
    }
}
int main(void){

//Helpers for input and output

   unsigned int N;
   cin >> N;

   char temp;
   int tempint;
   for(int i = 0; i < N; i++){
      cin >> temp >> tempint;
      median(temp,tempint);
   }
   return 0;
}

