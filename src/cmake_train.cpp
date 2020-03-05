#include <iostream>
#include <math.h>
#include <vector>
#include <iterator>
#include <utility>

using namespace std;


int main() {
	int count, answer=0;
	bool flag=true;
	cin>>count;
	vector<pair<int,int> > plates;

	for(int i=0;i<count;i++){
		int one, two;
		cin>>one>>two;
		plates.push_back(make_pair(one,two));
	}

	for(auto start=0;start<plates.size();start++){
		for(auto sec_start=0;sec_start<plates.size();sec_start++){
			if( (plates[start].first < plates[sec_start].first && plates[start].second < plates[sec_start].second) ||(plates[start].first < plates[sec_start].second && plates[start].second < plates[sec_start].first)){
				answer++;
				break;
			}
		}
	}

	cout<<answer;
}
