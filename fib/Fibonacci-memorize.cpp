#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool checkMember(int num, const std::map<int,int>& memb) {
    for(const auto& pair : memb){
    	if(num == pair.first){
    		return 1;
		}
	}
	return 0;
}

int fibWithMem(int num,std::map<int,int>& memb){
    if(num <= 2){
      //cout << "pass node : " << num << endl;
       return 1;
    }
    if(checkMember(num,memb)){
    	return memb[num];
	}
	else{
		//cout << "pass node : " << num << endl;
		memb[num] = fibWithMem(num-1,memb) + fibWithMem(num-2,memb);
		return memb[num];
	}
}

int fib(int num){
	if(num <= 2){
		//cout << "pass node : " << num << endl;
		return 1;
	}
	//cout << "pass node : " << num << endl;
	return fib(num-1) + fib(num-2);
}

int main(){
    std::map<int,int> fib_map = {};
    cout << "result: " << fibWithMem(7, fib_map);
   	//cout << "result: " << fib(40);
    return 0;
}
