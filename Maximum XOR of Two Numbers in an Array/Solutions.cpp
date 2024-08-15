#include <iostream>
#include <vector>
#include <bitset>

using std::bitset;
using std::vector;

class TrieNode
{
public:
    TrieNode *child[2];

    TrieNode()
    {
        this->child[0] = NULL;
        this->child[1] = NULL;
    }
};

class Trie
{
public:
    Trie() {}

    int findMaximumXOR(vector<int> &nums)
    {
        int res = 0;
        root = new TrieNode();

        // 建立好 Trie，子節點固定為兩個
        // 數字轉換成二進制的方式加入，每次一個位元，二進制最大長度是32(題目限制)
        for (auto &n : nums)
            insert(n);

        // 尋找XOR最大值，由MSB開始在LSB結束，這樣做的理由是從最大位元開始如果XOR計算發現是有效位元，那在更新解(res)時，能確保解一定是最大值
        // 在移動節點時的判斷是直接計算出XOR，如果 Trie 中部存在該位元(XOR解存在)，就更新結果(1 << i)
        // 如果不存在該位元，表示以目前的位元來說"前綴"相同
        //
        // 假設有兩個數字 :
        //      十進制 : 3和2
        //      二進制 : 011和010
        //      XOR = 1
        // 可以知道兩個數字的前綴相同(都是01)，所以在判斷時(計算XOR)不會存在該位元，所以節點往存在的節點前進
        // 在最後一個位元是不同的，所以判斷時會有該位元存在，所以解(res)會更新(1 << 1 = 1)，最後回傳解
        for (auto n : nums)
            res = std::max(res, maxXOR(n));

        return res;
    }

    int maxXOR(int num)
    {
        int res = 0;
        TrieNode *curr = root;
        bitset<32> bs(num);

        for (int i = 31; i >= 0; i--)
        {
            if (curr->child[!bs[i]])
            {
                res += (1 << i); // 1 move left i bis
                curr = curr->child[!bs[i]];
            }
            else
                curr = curr->child[bs[i]];
        }

        return res;
    }

private:
    TrieNode *root;

    void insert(int num)
    {
        /*
            將所有數字轉成 32 bits，然後加入到 Trie 中。
            從最高有效位(Most Significant Bit，MSB)到最低有效位(Least Significant Bit，LSB)依次加入到 Trie。
        */
        TrieNode *curr = root;
        bitset<32> bs(num); // num convert to 32 bits

        for (int i = 31; i >= 0; i--)
        {
            if (!curr->child[bs[i]])
                curr->child[bs[i]] = new TrieNode();

            curr = curr->child[bs[i]];
        }
    }
};

int findMaximumXOR(vector<int> &nums)
{
    Trie *trie = new Trie();

    return trie->findMaximumXOR(nums);
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    std::cout << findMaximumXOR(nums) << std::endl; // 28
}