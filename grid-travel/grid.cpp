#include <iostream>
#include <map>
#include <vector>
using namespace std;

int GridPossible(int col,int row){
//	cout << col <<":" << row << endl;
	if(col == 0 || row == 0){
		return 0;
	}
	if(col == 1 && row == 1){
		return 1;
	}
	return GridPossible(col-1,row) + GridPossible(col,row-1);
	
}

void AddNodeToVector(int col,int row,int value,std::vector<map<string,int>>& mem){
	map<string,int> zero_node;
	zero_node["col"] = col;
	zero_node["row"] = row;
	zero_node["value"] = value;
	mem.push_back(zero_node);
}

int GetMember(int col,int row,std::vector<map<string,int>>& mem){
	for(auto& m : mem){
		if(m["col"] == col && m["row"] == row){
			return m["value"];
			break;
		}
	}
	
}

bool CheckMember(int col,int row,std::vector<map<string,int>>& mem){
	for(auto m : mem){
		
		if(m["col"] == col && m["row"] == row){
			//cout << "col : " << m["col"] << " | row : " << m["row"] << " | value : " <<  m["value"] << endl;
			return true;
			break;
		}
	}
}

int GridPossibleWithMem(int col,int row,std::vector<map<string,int>>& mem){

	if(CheckMember(col,row,mem) == 1){
		int member = GetMember(col,row,mem);
		//cout << member << " : get member" << endl;
		return member;
	}	
	if(col == 0 || row == 0){
//		cout << "add 0" << endl;
		AddNodeToVector(col,row,0,mem);
		return 0;
	}
	if(col == 1 && row == 1){
//		cout << "add 1" << endl;
		AddNodeToVector(col,row,1,mem);
		return 1;
	}
	 int node_value = GridPossibleWithMem(col-1,row,mem) + GridPossibleWithMem(col,row-1,mem);
	 AddNodeToVector(col,row,node_value,mem);
	 return node_value;
}
int main(){
	std::map<string,int> grid_map = {};
	std::vector<std::map<string,int>> grid_mem = {};
	//cout << GridPossible(2,3) << " : Possible"; // for test Grid travel without memorize
	cout << GridPossibleWithMem(11,11,grid_mem) << " : Possible"; // for test Grid travel with memorize
	//cout << CheckMember(1,1,grid_mem); // for test check member function
	return 0;
}
