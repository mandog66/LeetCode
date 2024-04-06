/*
    I didn't get it.(See Solutions.cpp)

    Hang in there!

    I have faith in you!
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::unordered_map;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ostream &operator<<(ostream &os, const vector<TreeNode *> &v)
{
    os << "[";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i]->val;
        os << (i != v.size() - 1 ? ", " : "");
    }
    os << "]";

    return os;
}

// string dfs(TreeNode *node, unordered_map<string, vector<TreeNode *>> &v, vector<TreeNode *> &res)
// {
//     string s;

//     if (!node)
//         return "null";
//     s = std::to_string(node->val) + "," + dfs(node->left, v, res) + "," + dfs(node->right, v, res);

//     if (v[s].size() == 1)
//         res.push_back(node);

//     v[s].push_back(node);
//     return s;
// }

// vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
// {
//     unordered_map<string, vector<TreeNode *>> hashmap;
//     vector<TreeNode *> res;

//     dfs(root, hashmap, res);

//     return res;
// }

/*********** another solution ***********/
string DFS(TreeNode *node, unordered_map<string, int> &m, vector<TreeNode *> &res)
{
    /*
        利用DFS遍歷樹找到子樹，並將遍歷順序當成Key。
        Key有一個重點，就是如果沒有子節點回傳空字串。目的是區分不同樹的結構但有一樣遍歷順序的樹。
            1               1
        2       3               2
                                    3

        上面兩個樹遍歷後都是[1,2,3]的順序，加上空字串加以區分。(左 : [1,2,"","",3,"",""]、右 : [1,"",2,"",3,""])

        字串加上逗號是區分數字[1,2]和[12]如果每有加上逗號看起來是一樣的。
    */
    if (!node)
        return "";

    string s = std::to_string(node->val) + "," + DFS(node->left, m, res) + "," + DFS(node->right, m, res);

    if (m[s]++ == 1)
        res.push_back(node);

    return s;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    unordered_map<string, int> map;
    vector<TreeNode *> res;

    DFS(root, map, res);

    return res;
}
/*********** another solution ***********/

int main()
{
    TreeNode *node9 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(2, node9, nullptr);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(3, node5, node6);
    TreeNode *node1 = new TreeNode(2, node3, nullptr);
    TreeNode *root = new TreeNode(1, node1, node2);

    cout << findDuplicateSubtrees(root) << endl;
}