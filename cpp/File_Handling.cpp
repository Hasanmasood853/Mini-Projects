#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Task 5
//void writeArrFile(const string& name, string arr[], int size) {
//	ofstream outFile(name, ios::out);
//	if (outFile.is_open()) {
//		for (int i = 0; i < size; i++) {
//			outFile << arr[i] << endl;
//		}
//		outFile << endl;
//		outFile.close();
//		cout << "Array written to file" << endl;
//	}
//	else {
//		cout << "Unable to access file" << endl;
//	}
//}
//
//void readArrFile(const string& nameFile) {
//	ifstream inFile(nameFile, ios::in);
//	if (inFile.is_open()) {
//		string line;
//		while (inFile >> line) {
//			cout << line << endl;
//		}
//		inFile.close();
//	}
//	else {
//		cout << "Unable to access file" << endl;
//	}
//}
//
//void bubbleSort(string arr[], int size) {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size - i - 1; j++) {
//			if (arr[j] > arr[j + 1]) {
//				swap(arr[j], arr[j + 1]);
//			}
//		}
//	}
//}
//void appendFile(const string& fileName, string arr[], int size) {
//	ofstream file(fileName, ios::app);
//	if (file.is_open()) {
//		file << "Sorted List: " << endl;
//		for (int i = 0; i < 10; i++) {
//			file << arr[i] << endl;
//		}
//		file.close();
//	}
//	else {
//		cout << "Unable to access file" << endl;
//	}
//}
int main() {

	//Task 1
	/*string names[10]; int wordCount = 0;
	ofstream namesFile("Names.txt", ios::out);
	for (int i = 0; i < 10; i++) {
		cout << "Enter names of employee no "<<i+1<< " : ";
		cin >> names[i];
	}
	if (namesFile.is_open()) {
		for (int i = 0; i < 10; i++) {
			namesFile << names[i] << endl;
			wordCount++;
		}
	}
	else {
		cout << "Unable to access file" << endl;
	}
	namesFile.close();
	cout << "Total number of words in file: " << wordCount << endl;*/

	//Task 2
	/*int total = 0, digit;
	ofstream outputFile("numbers.txt", ios::out);
	if (outputFile.is_open()) {
		for (int i = 1; i <= 10; i++) {
			outputFile << i << endl;
		}
	}
	else {
		cout << "Unable to access file" << endl;
	}
	outputFile.close();
	ifstream inputFile("numbers.txt", ios::in);
	if (inputFile.is_open()) {
		while (inputFile >> digit) {
			total += digit;
		}
	}
	else {
		cout << "Unable to access file" << endl;
	}
	inputFile.close();
	cout << "Sum of digits is: " << total << endl;*/

	//Task 3
	/*ifstream inputFile("data.txt", ios::in);
	ofstream outputFile("updated.txt", ios::out);
	string line;
	if (inputFile.is_open()) {
		while (getline(inputFile, line)) {
			string newLine = "";
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == 'o' && line[i + 1] == 'l' && line[i + 2] == 'd')
				{
					newLine += "new";
					i = i + 2;
				}
				else
				{
					newLine += line[i];
				}
			}
			outputFile << newLine << endl;
		}
	}
	else {
		cout << "File cannot be accessed" << endl;
	}
	inputFile.close();
	outputFile.close();
	cout << "File updated successfully!" << endl;*/

	//Task 4
	/*int rate, startingBal, months, totalDeposit = 0, totalWithdraw = 0;
	float interest = 0;

	cout << "Enter annual interest rate (e.g., 5 for 5%): ";
	cin >> rate;
	float annualRate = float(rate) / 100;

	cout << "Enter starting balance: ";
	cin >> startingBal;

	cout << "Enter number of months: ";
	cin >> months;

	float monthlyRate = annualRate / 12;

	ofstream accountFile("Accounts.txt", ios::out);

	if (accountFile.is_open()) {
		for (int i = 1; i <= months; i++) {
			int deposit, withdraw;

			cout << "\nEnter amount deposited during month " << i << " : ";
			cin >> deposit;
			while (deposit < 0) {
				cout << "Invalid! Enter a non-negative deposit value: ";
				cin >> deposit;
			}

			accountFile << "Month " << i << " deposit: " << deposit << endl;
			startingBal += deposit;
			totalDeposit += deposit;

			cout << "Enter amount withdrawn during month " << i << " : ";
			cin >> withdraw;
			while (withdraw < 0) {
				cout << "Invalid! Enter a non-negative withdrawal value: ";
				cin >> withdraw;
			}

			accountFile << "Month " << i << " withdraw: " << withdraw << endl;
			startingBal -= withdraw;
			totalWithdraw += withdraw;

			if (startingBal < 0) {
				cout << "\nAccount closed due to negative balance!" << endl;
				interest = 0;
				accountFile << "Account closed due to negative balance." << endl;
				break;
			}

			interest += (monthlyRate * startingBal);
		}

		accountFile << "Ending balance: " << startingBal << endl;
		accountFile << "Total Deposits: " << totalDeposit << endl;
		accountFile << "Total withdrawals: " << totalWithdraw << endl;
		accountFile << "Total interest earned: " << interest << endl;

		accountFile.close();
	}
	else {
		cout << "Unable to access file" << endl;
	}

	string line;
	ifstream account("Accounts.txt", ios::in);

	if (account.is_open()) {
		while (getline(account, line)) {
			cout << line << endl;
		}
		account.close();
	}
	else {
		cout << "Unable to access file" << endl;
	}

	cout << "\nWriting of the account file was successful." << endl;*/


	//Task 5
	/*string array[10];
	cout << "Enter 10 names: ";
	for (int i = 0; i < 10; i++) {
		cin >> array[i];
	}
	string fileName = "array_data.txt";
	writeArrFile(fileName, array, 10);
	readArrFile(fileName);
	bubbleSort(array, 10);
	appendFile(fileName, array, 10);
	readArrFile(fileName);*/


	return 0;
}