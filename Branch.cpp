#include "Branch.h"

Branch::Branch(): Branch(nullptr,0,0) {}

Branch::Branch(Branch& obj)
{
	numberOfAcc = obj.numberOfAcc;
	totalBalance = obj.totalBalance;
	arraylist = new Accounts[numberOfAcc];

	for (int i = 0; i < numberOfAcc; i++)
	{
		arraylist[i] = obj.arraylist[i];			 
	}
	
}

Branch::Branch(Accounts* obj, int numberOfAcc, double totalBalance)
{ 
	this->numberOfAcc = numberOfAcc;
	this->totalBalance = totalBalance;
	arraylist = new Accounts[numberOfAcc];

	for (int i = 0; i < numberOfAcc; i++)
	{
		arraylist[i] = obj[i];			//overload the = operator in Accounts
	}
}

Accounts* Branch::getarraylist()
{ 
	Accounts* newlist = new Accounts[this->numberOfAcc];

	for (int i = 0; i < numberOfAcc; i++)
	{
		newlist[i] = arraylist[i];			//overload the = operator in Accounts
	}
	return newlist;
}

int Branch::getnumberOfAcc()
{
	return numberOfAcc;
}

double Branch::gettotalBalance()
{
	return totalBalance;
}

void Branch::setnumberOfAcc(int x)
{
	numberOfAcc = x;
}

void Branch::settotalBalance(double x)
{
	totalBalance = x;
}

void Branch::addAccount(Accounts account)
{
	Accounts* newlist = new Accounts[numberOfAcc+1];

	for (int i = 0; i < numberOfAcc; i++)
	{
		newlist[i] = arraylist[i];	
		this->totalBalance += newlist[i].getAccBalance();		//overload the = operator in Accounts
	}
	newlist[numberOfAcc].operator=(account);
	this->totalBalance += newlist[numberOfAcc].getAccBalance();
	numberOfAcc++; 
	delete[] arraylist;
	arraylist = newlist;
}

void Branch::deleteAccount(string name)
{
	Accounts* newlist = new Accounts[numberOfAcc];

	for (int i = 0; i < numberOfAcc - 1; i++)
	{
		if (arraylist[i].getTitle()== name)
		{
			numberOfAcc--;
		}
		else
		newlist[i] = this->arraylist[i];			//overload the = operator in Accounts
	} 
	
	delete [] arraylist;
	arraylist = newlist;
}

void Branch::updateAccount(Accounts account)
{ 
	for (int i = 0; i < numberOfAcc - 1; i++)
	{
		if (arraylist[i].getAccNumber()== account.getAccNumber())
		{
			arraylist[i].setTitle(account.getTitle());
			arraylist[i].setAccBalance(account.getAccBalance());
		} 
	}
}

void Branch::findAccount(long num)
{
	for (int i = 0; i < numberOfAcc - 1; i++)
	{
		if (arraylist[i].getAccNumber() == num)
		{
			cout << "\nAccount found\n";
		}	 
	}
}

void Branch::findAccount(string name)
{
	for (int i = 0; i < numberOfAcc - 1; i++)
	{
		if (arraylist[i].getTitle() == name)
		{
			cout << "\nAccount found\n";
		}
	}
}

Branch::~Branch() {
	delete[] arraylist;
}

void Branch::menu()
{
	cout << "What operation would you like to perform\n";
	cout << "press 1 to add an account\n"
		<< "press 2 to delete an account\n"
		<< "press 3 to update an account\n"
		<< "press 4 to find an account using account number\n"
		<< "press 5 to find an account using account title\n";
	int choice;
	cin >> choice;
	if (choice==1)
	{
		Accounts obj;
		cout << "enter account details\nEnter account title; then account number; then Account Balance; ";
		obj.operator>>(cin);
		this->addAccount(obj);
	}
	else if (choice == 2)
	{
		string name;
		cout << "enter account title to delete it ";
		cin >>name;
		this->deleteAccount(name);
	}
	else if (choice == 3)
	{
		Accounts obj;
		cout << "enter account details to update it\nEnter account title; then account number; then Account Balance; ";
		obj.operator>>(cin);
		this->updateAccount(obj);
	}
	else if (choice == 4)
	{
		long name;
		cout << "enter account number to find it ";
		cin >> name;
		this->findAccount(name);
	}
	else if (choice == 5)
	{
		string name;
		cout << "enter account title to find it ";
		cin >> name;
		this->findAccount(name);
	}
}

Branch& Branch::operator=(Branch& obj)
{
	this->totalBalance = obj.gettotalBalance();
	this->numberOfAcc = obj.getnumberOfAcc();
	arraylist = new Accounts[numberOfAcc];
	for (int i = 0; i < numberOfAcc; i++)
	{
		arraylist[i] = obj.arraylist[i];
	}
	return *this;
}

bool Branch::operator==(Branch& obj)
{
	if(this->totalBalance == obj.gettotalBalance())
		if (this->numberOfAcc == obj.getnumberOfAcc()){
			for (int i = 0; i < numberOfAcc; i++)
				{
				if (arraylist[i] != obj.arraylist[i])
				{
					return false;
				}
			}
			return true;
				}
	return false;
}

 ostream&  Branch::operator << (ostream& fout) {
	 fout << "\nnumber of accounts= "
		 << numberOfAcc
		 << "\ntotal balance= "
		 << totalBalance;
	 for (int i = 0; i < numberOfAcc; i++)
	 {
		 arraylist[i].operator<<(fout);
	 }
	 return fout;
}

 istream& Branch::operator>>(istream& fin)
 {
	 fin >> numberOfAcc >> totalBalance;
	 for (int i = 0; i < numberOfAcc; i++)
	 {
		 arraylist[i].operator>>(fin);
	 }
	 return fin;
 }

