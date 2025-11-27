#pragma once
#include <vector>
#include "Member.h"
using namespace std;

class MemberService {
private:
    vector<Member> members;

public:
    MemberService() = default;

    bool addMember(Member m);
    bool removeMember(int memberID);
    vector<Member> getAllMembers();
    vector<Member> searchMembers(string query);
};
