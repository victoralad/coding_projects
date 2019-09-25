#include <iostream>
#include <vector>

void lookNsay(int height);

void lookNsay(int height)  // use a queue intead of vectors
{
    std::vector<int> vec(1, 1);
    for (int i = 1; i < height; ++i)
    {
        int count = 0;
        for (int j = 1; j < vec.size(); ++j)
        {
            if(vec[j - 1] == vec[j])
            {
                count++;
            }
            else
            {
                vec.push
                count = 0;
            }
            
        }
    }
}

int main()
{
    lookNsay(10);
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