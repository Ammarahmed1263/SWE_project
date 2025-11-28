#include "Member.h"
using namespace std;

Member::Member(string name,string email):name(name),email(email){

    memberID=++nextMemberID;
}

int Member::nextMemberID=0;

//Getters
int Member::getId(){return memberID;}
string Member::getName(){return name;}
string Member::getEmail(){return email;}

