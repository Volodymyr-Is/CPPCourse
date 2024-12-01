#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <sstream>
#include <set>

using namespace std;

class Student {
public:
    string name;
    string group;
    double averageGrade;

    Student(string n, string g, double avg) : name(move(n)), group(move(g)), averageGrade(avg) {}

    bool operator<(const Student& other) const {
        return group < other.group;
    }
};

void saveToFile(const vector<Student>& students, const string& filename) {
    ofstream outFile(filename);
    ostream_iterator<string> outIter(outFile, "\n");
    transform(students.begin(), students.end(), outIter, [](const Student& s) {
        ostringstream oss;
        oss << s.name << ";" << s.group << ";" << s.averageGrade;
        return oss.str();
        });
}

vector<Student> loadFromFile(const string& filename) {
    ifstream inFile(filename);
    istream_iterator<string> inIter(inFile), end;
    vector<Student> students;

    for_each(inIter, end, [&students](const string& line) {
        istringstream iss(line);
        string name, group;
        double averageGrade;
        getline(iss, name, ';');
        getline(iss, group, ';');
        iss >> averageGrade;
        students.emplace_back(name, group, averageGrade);
        });

    return students;
}

int main() {
    vector<Student> students = {
        {"Alice", "CS-101", 4.5},
        {"Bob", "CS-102", 3.8},
        {"Charlie", "CS-101", 4.2},
        {"Diana", "CS-101", 5.0},
        {"Eve", "CS-102", 4.7},
        {"Carlo", "CS-101", 3.8},
        {"Frank", "CS-101", 2.9}
    };

    saveToFile(students, "students.txt");
    vector<Student> loadedStudents = loadFromFile("students.txt");

    vector<Student> sortedByGrade = students;
    sort(sortedByGrade.begin(), sortedByGrade.end(), [](const Student& a, const Student& b) {
        return a.averageGrade > b.averageGrade;
        });

    vector<string> filteredGroups;
    set<string> uniqueGroups;
    for_each(students.begin(), students.end(), [&uniqueGroups](const Student& s) {
        uniqueGroups.insert(s.group);
        });

    copy_if(uniqueGroups.begin(), uniqueGroups.end(), back_inserter(filteredGroups), [&students](const string& group) {
        return count_if(students.begin(), students.end(), [&group](const Student& s) {
            return s.group == group;
            }) > 4;
        });

    vector<string> studentNames;
    for_each(filteredGroups.begin(), filteredGroups.end(), [&students, &studentNames](const string& group) {
        for_each(students.begin(), students.end(), [&studentNames, &group](const Student& s) {
            if (s.group == group) {
                studentNames.push_back(s.name);
            }
            });
        });

    int alphabetCount = count_if(studentNames.begin(), studentNames.end(), [](const string& name) {
        return is_sorted(name.begin(), name.end());
        });

    double averageGrade = accumulate(students.begin(), students.end(), 0.0, [](double sum, const Student& s) {
        return sum + s.averageGrade;
        }) / students.size();

    vector<string> allGroups;
    transform(students.begin(), students.end(), back_inserter(allGroups), [](const Student& s) {
        return s.group;
        });

    sort(allGroups.begin(), allGroups.end());
    sort(filteredGroups.begin(), filteredGroups.end());

    bool isSubset = includes(allGroups.begin(), allGroups.end(), filteredGroups.begin(), filteredGroups.end());

    cout << "Sorted students by avg grade:\n";
    for_each(sortedByGrade.begin(), sortedByGrade.end(), [](const Student& s) {
        cout << s.name << " (" << s.group << "): " << s.averageGrade << endl;
        });

    cout << "\nGroups, where students count > 4:\n";
    for_each(filteredGroups.begin(), filteredGroups.end(), [](const string& group) {
        cout << group << endl;
        });

    cout << "\nStudents names:\n";
    for_each(studentNames.begin(), studentNames.end(), [](const string& name) {
        cout << name << endl;
        });

    cout << "\nAlphabetical names count: " << alphabetCount << endl;
    cout << "All students avg grade: " << averageGrade << endl;
    cout << "Is the group a consequence of the original vector: " << (isSubset ? "Yes" : "No") << endl;

    return 0;
}


