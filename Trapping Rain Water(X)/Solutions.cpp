/*

input               0   1   0   2   1   0   1   3   2   1   2   1

left max            0   0   1   1   2   2   2   2   3   3   3   3

right max           3   3   3   3   3   3   3   2   2   2   1   0

min(lMax, rMax)     0   0   1   1   2   2   2   2   2   2   1   0

min - input         0   0   1   0   1   2   1   0   0   1   0   0

要知道input可以儲存多少水，能從input這個位置往左右兩邊查看最高input是多少。像是height[2] = 0，而左邊最大是1，右邊最大是3，
但水最多只能儲存高度小的那方，多的會流掉。Min(1, 3) - height[2] = 1，所以這裡能裝1單位的水。要是相減是負的，那就設定為0，畢
竟不可能裝負單位的水。要注意的是第一個和最後一個的最大值設定為0(左右兩邊沒有東西)。最後將相減後的結果全部相加就是答案。

比較好的方式是使用兩個指標，上面的方法會需要比較多的空間，這個可以不用。

首先，設定兩個指標，分別指向頭和尾(lpos和rpos)，然後左邊最大值(lmax)預設height[lpos]，而右邊最大值(rmax)預設height[rpos]。
比較lmax和rmax，從小的開始。以上面的例子(lmax < rmax)，從lmax開始，lpos + 1(最左和最右邊無法裝水)，現在想要知道lpos這裡能裝
多少水，依照上面的想法，要找到左右兩邊的最大值，那左邊最大值已經有了(lamx)，右邊的最大值要怎麼判斷?這裡有個想法，因為我們要比較
兩個最大值中比較小的那個，那現在是lmax < rmax，可以知道現在的lmax就是比rmax小，不管中間高度是多少都可以忽略。所以照上面的想法，
lmax - height[lpos] = -1，不可能有負單位的水，故得0單位的水。接著更新lmax = 1。現在lmax和rmax相同，所以從左位移還是從右位移都
可以，這裡我是從左繼續，一直做到lpos和rpos相遇就結束迴圈並回傳答案。

參考影片 : https://www.youtube.com/watch?v=ZI2z5pq0TqA

*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int lpos = 0;            // left index
        int rpos = n - 1;        // right index
        int lmax = height[lpos]; // left max value
        int rmax = height[rpos]; // right max value
        int res = 0;             // result

        while (lpos < rpos)
        {
            if (lmax < rmax)
            {
                lpos += 1;
                lmax = max(lmax, height[lpos]);
                // Note : this code doesn't check negative, because above code have max function. the result will get 0.
                // Ex.
                //  lmax = 0
                //  lpos = 1
                //  height[lpos] = 1
                //  lmax = max(0, 1) = 1
                //  lmax - height[lpos] = 1 - 1 = 0
                res += (lmax - height[lpos]);
            }
            else
            {
                rpos -= 1;
                rmax = max(rmax, height[rpos]);
                res += (rmax - height[rpos]);
            }
        }

        return res;
    }
};