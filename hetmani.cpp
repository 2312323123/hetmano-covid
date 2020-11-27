#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> const &input)
{
        for(int i=0; i < input.size(); i++) {
                cout << input.at(i) << '\t';
        }
}

vector<int> rekuker(int size, vector<int> answers, int y, vector<int> md, vector<int> sd) {
        if(y >= size) {
                cout << endl;
                return answers;
        }
        for(int i=0; i < size; i++) {
                if(find(answers.begin(), answers.end(), i) == answers.end() &&
                   find(md.begin(), md.end(), i+size-y) == md.end() &&
                   find(sd.begin(), sd.end(), i+y) == sd.end()) {
                        answers[y] = i;
                        md[y] = i+size-y;
                        sd[y] = i+y;
                        vector<int> ans = rekuker(size, answers, y+1, md, sd);
                        if(!ans.empty())
                                return ans;
                }
        }
        vector<int> empty;
        return empty;
}

int main() {
        size_t size;
        cout << "podaj wymiar: ";
        cin >> size;
        vector<int> answers(size, -1);
        int y = 0;
        vector<int> md(size); // main diagonal
        vector<int> sd(size); // secondary diagonal

        print(rekuker(size, answers, y, md, sd));
        cout << endl;

        return 0;
}
