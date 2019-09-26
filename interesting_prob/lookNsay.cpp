#include <iostream>
#include <vector>
#include <queue>

void lookNsay(int height);

void lookNsay(int height)  // use a queue intead of vectors
{
    if (height == 1)
    {
        std::cout << "1" << std::endl;
    }
    else if (height == 2)
    {
        std::cout << "1 1" << std::endl;
    }
    else
    {
        std::cout << "1" << std::endl;
        std::cout << "1 1" << std::endl;
        int old_size;
        std::queue<int> que;
        que.push(1);
        que.push(1);
        int temp;
        for (int i = 2; i < height; ++i)
        {
            int count = 1;
            old_size = que.size();
            for (int j = 1; j < old_size; ++j)
            {
                temp = que.front();
                que.pop();

                if (temp == que.front())
                {
                    count++;
                    // temp = que.front();
                    // que.pop();
                }
                else
                {
                    que.push(count);
                    que.push(temp);
                    //count = 1;
                }
            }
            // int back = que.back();
            temp = que.front();   
            que.push(count);
            que.push(temp);
            que.pop();
            
            for (int j = 0; j < que.size(); ++j)
            {
                temp = que.front();
                std::cout << que.front() << " ";
                que.pop();
                que.push(que.front());
            }
            std::cout << std::endl;
        }
    }

}

int main()
{
    lookNsay(5);
    return 0;
}

/*

1
11
21
1211
111221
312211
13112221
1113213211
31131211131221
13211311123113112211

*/