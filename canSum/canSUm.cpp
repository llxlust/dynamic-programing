#include <iostream>
#include <vector>
using namespace std;

vector<int> FilterOutSelf(int number,vector<int>& member){
	cout << number << endl;
	vector<int> payload;
	vector<int> targetFound;
	for(auto m:member){
		if(number == m){
			targetFound.push_back(m);
		}else{
			payload.push_back(m);
		}
	}
	if(targetFound.size() > 1){
		for(int i =0;i < targetFound.size()-1;i++){
			payload.push_back(targetFound[i]);
		}
	}
	for(auto& memb:payload){
		cout << memb << " | ";
	}
	cout << endl;
	return payload;
}

bool canSum(int num,vector<int>& member){
	if(num == 0){
		return true;
	}
	if(num < 0){
		return false;
	}
	vector<int> filterMember = FilterOutSelf(num,member);
	for(auto m : filterMember){
		int reminder = num - m;
			if(canSum(reminder,filterMember) == true){
				return true;
			}
	}
	return false;
}


int main(){
	
	vector<int> member = {8,10,6};
	int number = 16;
	int isCanSum = canSum(number,member);
	if(isCanSum == 0){
		cout << "member can't sum to : " << number;
	}else{
		cout << "member can sum to : " << number;
	}
}
