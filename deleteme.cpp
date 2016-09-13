#include <iostream>

using namespace std;

int main(){

int paul;
int *melissa;
int dave;

paul = 21;
melissa = &paul;
dave = *melissa;

cout << "Paul = " << paul << endl;

cout << "Melissa = " << *melissa << endl;

cout << dave;

}
