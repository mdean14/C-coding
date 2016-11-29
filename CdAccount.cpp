


//DISPLAY 10.1 A Structure Definition 
//Program to demonstrate the CDAccount structure type.
#include <iostream>
using namespace std;

class CdAccount
{
public:
	CdAccount ();
	CdAccount (double new_balance, double new_interest_rate, int new_term);
	double get_initial_balance();
	double get_balance_at_majority();
	double get_interest_rate();
	int get_term();
	void input( istream &istr);
	void output( ostream &ostr);
private:
	double balance;
    double interest_rate;
    int term;//months until maturity
};

int main( )
{
	CdAccount account(100, 10.0, 6);
	account.output(cout);

	cout << "Enter account balance, interest rate, and term: " <<endl;
	account.input(cin);
	account.output(cout);
	
    return 0;
}

CdAccount::CdAccount()
{
	balance = 0;
    interest_rate = 0;
    term = 0;//months until maturity
}
CdAccount::CdAccount (double new_balance, double new_interest_rate, int new_term)
{
	balance = new_balance;
    interest_rate = new_interest_rate;
    term = new_term;
}
double CdAccount::get_initial_balance()
{
	return balance;
}

double CdAccount::get_balance_at_majority()
{
	double interest = balance * (interest_rate/ 100) * (term / 12.0);
	return balance + interest;
}
double CdAccount::get_interest_rate()
{
	return interest_rate;
}
int CdAccount::get_term()
{
	return term;
}
void CdAccount::input(istream &istr)
{
	istr >> balance;
	istr >> interest_rate;
	istr >> term;
}
void CdAccount::output(ostream &ostr)
{
	ostr.setf(ios::fixed);
    ostr.setf(ios::showpoint);
    ostr.precision(2);
	ostr << "The CD Account's interest rate is: " << get_interest_rate() << endl;
	ostr << "The CD Account's initial balance is: " << get_initial_balance() <<endl;
	ostr << "Your CD matures in " << get_term() << " months" << endl;
	ostr << "the balance will be: " << get_balance_at_majority() << endl;
	ostr << endl;
}