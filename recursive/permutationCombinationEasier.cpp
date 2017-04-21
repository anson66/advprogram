//This is an easy-to-read version.
//It is a very crude implementation using lots of memory and memory copying
#include <iostream>

using namespace std;

void permutate(string result, string input)
{
	if (input.empty())
	{
		cout << result << endl;
		return;
	}
	for(int i = 0; i < input.length(); i++)
	{
		//lay ra lua chon tiep theo
		string newResult = result + input[i];
		//bo ra khoi cac lua chon con lai
		string newInput = 
		input.substr(0, i) + input.substr(i+1, input.length());
		//de quy cho phan con lai
		permutate(newResult, newInput);
	}
}

void combination(string result, int k, const string& input)
{
	if (k == input.length()) {
		cout << "[" << result  << "]\n";
		return;
	}
	//khong lay input[k] va de qui tiep
	combination(result, k+1, input);
	//lay input[k] va de qui tiep	
	combination(result + input[k], k+1, input);
}

int main()
{
	string input;  //abc
	cin >> input;
	
	cout << "Permutations: \n";
	permutate("", input);
	
	cout << "Combinations: \n";
	combination("", 0, input);
}
