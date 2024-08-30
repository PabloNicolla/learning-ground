#include <vector>
using namespace std;

vector<int> gradingStudents(vector<int> grades)
{
    std::vector<int> ans{};

    for (int grade : grades)
    {
        if (grade < 38)
            ans.push_back(grade);
        else if (grade % 5 >= 3)
            ans.push_back(grade + (5 - grade % 5));
        else
            ans.push_back(grade);
    }

    return ans;
}