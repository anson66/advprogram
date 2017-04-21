//This version minimizes memory usage and copying, thus faster

#include <iostream>
#include <cstring>

using namespace std;

void permutate(char* result, int resultIndex, int length)
{
	if (resultIndex >= length) cout << result << endl;
	else {
		for (int i = resultIndex; i < length; i++)	{
			swap(result[resultIndex], result[i]);
			permutate(result, resultIndex + 1, length);
			swap(result[resultIndex], result[i]);
		}
	}
}

void makeCombination(char* result, int resultIndex, const string& input, int inputIndex)
{
	if (inputIndex >= input.length()) {
		result[resultIndex] = 0;
		cout << "[" << result << "]"<< endl;	
	}
	else {
		makeCombination(result, resultIndex, input, inputIndex+1);
		result[resultIndex] = input[inputIndex];
		makeCombination(result, resultIndex+1, input, inputIndex+1);
	}
}

void listAllPermutations(const string& s)
{
	char* result = new char[s.length() + 1];
	strcpy(result, s.c_str());
	cout << "Permutations: \n";
	permutate(result, 0, s.length());
	delete [] result;
}

void listAllCombinations(const string& s)
{
	char* result = new char[s.length() + 1];
	cout << "Combinations: \n";
	makeCombination(result, 0, s, 0);
	delete [] result;
}

int main() {
	string input;
	cin >> input;
	
	listAllPermutations(input);
	listAllCombinations(input);
}

