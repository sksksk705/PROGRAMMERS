#include <string>
#include <vector>

#define STAR 9
#define ZENG 11
#define L "L";
#define R "R"

using namespace std;

vector<int> example{ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = STAR, right = ZENG;
    for (auto num : numbers)
    {
        if (num == 0)
            num = 11;
        if (num == 1 || num == 4 || num == 7) {
            answer += L;
            left = num - 1;
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += R;
            right = num - 1;
        }
        else {
            num--;
            int leftdist = abs(num - left) / 3 + abs(num - left) % 3;
            int rightdist = abs(num - right) / 3 + abs(num - right) % 3;
            if (leftdist < rightdist) {
                answer += L;
                left = num;
            }
            else if (rightdist < leftdist) {
                answer += R;
                right = num;
            }
            else {
                if (hand == "right") {
                    answer += R;
                    right = num;
                }
                else {
                    answer += L;
                    left = num;
                }
            }
        }
    }
    return answer;
}

int main() {
    solution(example, "left");
    return 0;
}