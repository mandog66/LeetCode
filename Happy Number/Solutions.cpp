/*
    這題可以用兩個指標的方法解決。
    參考資料 :
        https://www.youtube.com/watch?v=PvrxZaH_eZ4
        https://medium.com/@zephyr.ventum/floyds-tortoise-and-hare-cycle-finding-algorithm-my-over-explanation-5631c5ce71d7

    方法 :
        可以將數字串在一起，類似鏈結(LinkList)。
        兩個指標分別是"慢指標{slowPointer，簡稱s}"和"快指標(fastPointer，簡稱f)"，s 每次移動一步，f 每次移動兩步。
        f 永遠會比 s 快到終點，如果 f 是 1，就回傳 true。
        如果兩個指標相遇了，表示是一個迴圈，所以回傳 false。
*/
class Solution
{
private:
    int nextNumber(int n)
    {
        int newNumber = 0;
        while (n != 0)
        {
            int num = n % 10;
            newNumber += num * num;
            n = n / 10;
        }
        return newNumber;
    }

public:
    bool isHappy(int n)
    {
        int slowPointer = n;
        int fastPointer = nextNumber(n);
        while (fastPointer != 1 && fastPointer != slowPointer)
        {
            slowPointer = nextNumber(slowPointer);
            fastPointer = nextNumber(nextNumber(fastPointer));
        }
        return fastPointer == 1;
    }
};