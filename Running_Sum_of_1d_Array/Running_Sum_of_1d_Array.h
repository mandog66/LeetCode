#ifndef RUNNING_SUM_OF_1D_ARRAY_H
#define RUNNING_SUM_OF_1D_ARRAY_H
#include <vector>

using std::vector;

class Solution
{
public:
    // error : vector is not a template
    // vector is from the std namespace,so must use std::
    vector<int> runningSum(vector<int> &);
};
#endif