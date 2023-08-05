#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cout << "***************************** Welcome to Expense Distributor **************************************" << endl;
	cout << "Number of PERSON's involved: ";
	cin >> n;
	cout << endl;
	vector<string> personNames;

	for (int i = 0; i < n; i++)
	{
		string name;
		cout << "Name of Person " << i + 1 << " : ";
		cin >> name;
		personNames.push_back(name);
	}
	cout << endl;

	vector<vector<vector<double>>> allExpenseMatrix;

	for (int k = 0; k < n; k++)
	{
		cout << "************************************** " << personNames[k] << "'s Expenses ***************************************" << endl;
		cout << "Total number of Expenses: ";
		int expenseCtn;
		cin >> expenseCtn;
		vector<vector<double>> expenseMatrix;
		for (int i = 0; i < expenseCtn; i++)
		{
			vector<double> expenseItem;
			cout << "Expense " << i + 1 << " : ";
			int expense;
			cin >> expense;
			cout << "Equally distributed? (1 for Yes, 0 for No): ";
			int equalSplit;
			cin >> equalSplit;
			if (equalSplit)
			{
				double distribution = expense / n;
				for (int j = 0; j < n; j++)
				{
					expenseItem.push_back(distribution);
				}
			}
			else
			{
				for (int j = 0; j < n; j++)
				{
					cout << personNames[j] << "'s share : ";
					double share;
					cin >> share;
					expenseItem.push_back(share);
				}
			}
			expenseMatrix.push_back(expenseItem);
			cout << endl;
		}
		allExpenseMatrix.push_back(expenseMatrix);
	}

	// Total expenditure by each person from their pocket
	vector<double> expensePaid;
	// Total expense done of each person on self
	vector<double> expenseDone(n, 0.0);

	// Calculate the sum of each expense matrix and store in expensePaid, AND
	// Calculate the sum of each column in the allExpenseMatrix and store in expenseDone
	for (int i = 0; i < n; i++)
	{
		double matrixSum = 0.0;
		for (int j = 0; j < allExpenseMatrix[i].size(); j++)
		{
			for (int k = 0; k < allExpenseMatrix[i][j].size(); k++)
			{
				expenseDone[k] += allExpenseMatrix[i][j][k];
				matrixSum += allExpenseMatrix[i][j][k];
			}
		}
		expensePaid.push_back(matrixSum);
	}

	// Display the Expense Matrix for each person
	for (int i = 0; i < n; i++)
	{
		cout << "Expense Matrix for " << personNames[i] << ":" << endl;
		cout << "Expense\t";
		for (const string &person : personNames)
		{
			cout << person << "\t";
		}
		cout << endl;

		for (int j = 0; j < allExpenseMatrix[i].size(); j++)
		{
			cout << "Exp" << j + 1 << "\t";
			for (int k = 0; k < allExpenseMatrix[i][j].size(); k++)
			{
				cout << allExpenseMatrix[i][j][k] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	// for (int i = 0; i < expensePaid.size(); i++)
	// {
	// 	cout << personNames[i] << " Expense from his pocket : " << expensePaid[i] << endl;
	// 	cout << personNames[i] << " Expense from other's  pocket : " << expenseDone[i] << endl;
	// 	cout << endl;
	// }

	// Calculate and display the amount to be paid(-)/taken(+) to/from each person
	cout << "Amount to be paid(-)/taken(+) to/from each person:" << endl;
	for (int i = 0; i < n; i++)
	{
		double settlement = expensePaid[i] - expenseDone[i];
		cout << personNames[i] << ": " << settlement << endl;
	}	

	return 0;
}

/*
SAMPLE INPUT 1
3
P1
P2
P3
3
60
0
10
20
30
70
0
40
20
10
110
0
50
10
50
2
55
0
25
10
20
85
0
15
70
0
2
60
0
20
40
0
150
0
0
80
70
*/

/*
SAMPLE INPUT 2
3
P1
P2
P3
3
100
0
30
40
30
70
0
40
20
10
110
0
50
10
50
2
55
1
85
0
15
70
0
2
60
0
20
40
0
180
0
30
80
70
*/

/*
PRACTICAL INPUT 
3
SHOURYA
SACHIN
KHURANA
2
170
1
1083
0
0
1083
0
7
1000
1
123
0
61.5
61.5
0
1100
0
550
550
0
195
0
0
97.5
97.5
20
0
0
10
10
30
0
0
15
15
54
0
0
20
34
5
1000
1
272
1
33
0
0
16.5
16.5
80
0
0
30
50
1083
0
0
1083
0
*/