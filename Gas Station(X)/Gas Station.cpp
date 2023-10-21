/*
    I didn't get it.(See Solutions.cpp)

    It's fine!

    Keep going!
*/

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    /*
        要能檢查出能否繞一圈，不行就回傳 -1
        如果可以，判斷這個加油站能不能當起點，可以的話就回傳該加油站
        具有唯一解
    */

    const int n = gas.size();
    int total_gas = 0, total_cost = 0; // 如果可以繞行一圈，(total_gas) - (total_cost) >= 0
    int starting_point = 0;            // 能當起點的位置
    int curr_gas = 0;                  // 現在可以使用的汽油量

    for (int i = 0; i < n; i++)
    {
        // 最後要計算能不能繞行一圈
        total_gas += gas[i];
        total_cost += cost[i];

        // 現在可以使用的汽油量
        curr_gas += gas[i] - cost[i];
        // 如果可以使用的汽油量變成負的
        // 表示這個加油站不適合當起點(沒有汽油到下一個加油站)
        if (curr_gas < 0)
        {
            starting_point = i + 1;
            curr_gas = 0;
        }
    }
    // 能不能繞行一圈由(total_gas < total_cost)判斷
    // curr_gas 是找起點，不用管經過的加油站
    // 如果可以繞行一圈，自然會有唯一解出現(starting_point)
    return (total_gas < total_cost) ? -1 : starting_point;
}

int main()
{
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};

    vector<int> gas2 = {5, 1, 2, 3, 4};
    vector<int> cost2 = {4, 4, 1, 5, 1};

    vector<int> gas3 = {4, 5, 2, 6, 5, 3};
    vector<int> cost3 = {3, 2, 7, 3, 2, 9};

    vector<int> gas4 = {3, 3, 4};
    vector<int> cost4 = {3, 4, 4};

    vector<int> gas5 = {3, 1, 1};
    vector<int> cost5 = {1, 2, 2};

    vector<int> gas6 = {1, 2, 3, 4, 5, 5, 70};
    vector<int> cost6 = {2, 3, 4, 3, 9, 6, 2};

    cout << canCompleteCircuit(gas1, cost1) << endl; // return 3
    cout << canCompleteCircuit(gas2, cost2) << endl; // return 4
    cout << canCompleteCircuit(gas3, cost3) << endl; // return -1
    cout << canCompleteCircuit(gas4, cost4) << endl; // return -1
    cout << canCompleteCircuit(gas5, cost5) << endl; // return 0
    cout << canCompleteCircuit(gas6, cost6) << endl; // return 6
}