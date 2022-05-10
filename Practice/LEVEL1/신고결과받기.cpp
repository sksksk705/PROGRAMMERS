//2022_05_10 프로그래머스 LEVEL1


#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    vector<int> reported(id_list.size(), 0);
    unordered_map<string,int> id_list_map;
    for (int i = 0; i < id_list.size(); ++i)
        id_list_map[id_list[i]] = i;

    vector<vector<bool>> history(id_list.size(), vector<bool>(id_list.size() , false));

    for (auto single : report)
    {
        stringstream ss(single);
        string accuser, accused;
        getline(ss, accuser, ' ');
        getline(ss, accused, ' ');
        int accuseridx = id_list_map[accuser];
        int accusedidx = id_list_map[accused];
        if (history[accusedidx][accuseridx])
            continue;
        reported[accusedidx]++;
        history[accusedidx][accuseridx] = true;
    }

    for (int i = 0; i < reported.size(); ++i)
    {
        if (reported[i] >= k)
        {
            for (int j = 0; j < history[i].size(); ++j)
                if (history[i][j])
                    answer[j]++;
        }
    }

    return answer;
}