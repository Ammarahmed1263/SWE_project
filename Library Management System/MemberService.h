#pragma once
#include <vector>
#include "Member.h"
using namespace std;

class MemberService {
private:
    vector<Member> members;

public:
    MemberService() = default;

    bool addMember(string name,string email);
    bool removeMember(int memberID);
    vector<Member>& getAllMembers();
    vector<Member> searchMembers(string query);
};
