#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cout << endl;
	cout << "*****************************Welcome to Expense Distributor**************************************"
		 << "\n";
	cout << endl;
	cout << "Number of PERSON's involved: "
		 << "\n";
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
		cout << "\n";
		cout << "Total number of Expenses : ";
		int expenseCtn;
		cin >> expenseCtn;
		cout << "\n";
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
		cout << endl;
		allExpenseMatrix.push_back(expenseMatrix);
	}

	return 0;
}
