#include <iostream>
#include <stack>

using namespace std;

//Initializing two stacks forwardStack and backwardStack
stack<string> forwardStack;
stack<string> backwardStack;

string currentUrl = "";

void new_url(string url){
    if (currentUrl != ""){
        backwardStack.push(currentUrl);
    }
    currentUrl = url;
    cout << "\tCurrent URL is '" << currentUrl << "'\n";
}

void backward(){
    if (backwardStack.empty() || currentUrl == backwardStack.top()){
        cout << "\tLink not available. You can't backword. \n";
        return;
    }
    else{
        forwardStack.push(currentUrl);
        currentUrl = backwardStack.top();
        backwardStack.pop();
        cout << "\tCurrent URL after the backward is :" << currentUrl;
    }
}

void forward(){
    if (forwardStack.empty() || currentUrl == forwardStack.top()){
        cout << "\tLink not available. You can't forward. \n";
        return;
    }
    else{
        backwardStack.push(currentUrl);
        currentUrl = forwardStack.top();
        forwardStack.pop();
        cout << "\tCurrent URL after the forward is :" << currentUrl;

    }
}

int main(){
    
	char userInput;
	cout << "-- Backword and Forward Button --\n\n"
		<< "Option 'a': Add a New URL\n"
		<< "Option 'b': Forward Button\n"
		<< "Option 'c': Backward button\n"
		<< "Option 'q': Quit\n";
	do{
		system("cls");

		cout << "Please enter your choice: "; 
		cin >> userInput;	

		switch (userInput){
		case 'a':
			cout << endl << "Please enter the URL: ";
			cin >> currentUrl;
			new_url(currentUrl);
			break;
		case 'b':
			forward();
			break;
		case 'c':
			backward();
			break;
		case 'q':
			cout << endl << "You have chosen to quit...";
			break;
		default:
			cout << "\tThat option is not valid. Please enter a valid option." << endl;
			break;
		}
		cout << endl;
		system("pause");
	} while (userInput != 'q');
	
	cout << endl;
	system("pause");
}
