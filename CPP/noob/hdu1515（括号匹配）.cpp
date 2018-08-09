/*
ID: jinyu121
PROG:
LANG: C++
EDIT: 1.0
*/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

#define MAXMAX 150

using namespace std;

string strOri;
string strAim;
int n, n2;

bool iLog[MAXMAX];

void doit( int oriNow, int aimNow, int step, stack<char> iStack ) {
	if ( aimNow >= n ) {
		if ( !iStack.empty() ) {
			return;
		}

		for ( int i = 1; i <= n2; i++ ) {
			cout << ( iLog[i] ? "i" : "o" ) << " ";
		}

		cout << endl;
		return;
	}

	stack<char> stackNew( iStack );
	int oriNew = oriNow;
	int aimNew = aimNow;
	int stepNew = step;

	// Make the Stack's top equals with the concerning char in the aim string
	while ( ( stackNew.empty() ) || ( stackNew.top() != strAim[aimNew] ) ) {
		if ( oriNew >= n ) {
			return;
		}

		stackNew.push( strOri[oriNew] );
		oriNew++;
		stepNew++;
		iLog[stepNew] = true;
	}

	// Push one
	{
		stack<char> stackNew1( stackNew );

		if ( oriNew < n ) {
			stackNew1.push( strOri[oriNew] );
			iLog[stepNew + 1] = true;
			doit( oriNew + 1, aimNew, stepNew + 1, stackNew1 );
		}
	}
	// Pop one
	{
		stack<char> stackNew2( stackNew );

		if ( ( !stackNew2.empty() ) && ( stackNew2.top() == strAim[aimNew] ) ) {
			stackNew2.pop();
			iLog[stepNew + 1] = false;
			doit( oriNew , aimNew + 1, stepNew + 1, stackNew2 );
		}
	}
}

int main() {
	//freopen( "data.in", "r", stdin );
	//freopen("data.out", "w", stdout);
	for ( ; cin >> strOri >> strAim ; ) {
		cout << "[" << endl;
		stack<char> iStack;

		if ( strOri.length() == strAim.length() ) {
			n = strOri.length();
			n2 = n << 1;
			doit( 0, 0, 0, iStack );
		}

		cout << "]" << endl;
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
