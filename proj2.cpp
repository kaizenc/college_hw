#include <iostream>
#include <string>
#include <vector>
using namespace std;

string foo(string target, string curr_string, vector<string> elements, int size, string element_string){
	if(target == ""){
		return element_string;
	}
	for(int i = 0; i < size; i++){
		if(target.substr(0, elements[i].length()) == elements[i]){
			string new_element_string = element_string + to_string(i);
			string new_target = target.substr(elements[i].length(), target.length() - elements[i].length());

			string recurr = foo(new_target, curr_string+elements[i], elements, size, new_element_string);
			if(recurr != "") return recurr;
		}
	}
	return "";
}

int main(){
  cout << "Please enter a target string: ";
	string target_string;
	cin >> target_string;
	
	cout << endl << "Please enter the number of elements: ";
	int size;
	cin >> size;
	
	
	cout << endl << "Please enter your elements one by one.";
	vector<string> elements;
	for(int i=0;i<size;i++){
	  string temp;
	  cin >> temp;
	  cout << endl;
	  elements.push_back(temp);
	  
	}

	string result = foo(target_string, "", elements, size, "");

	cout << "Your result is: " << result << endl;

	return 0;
}
