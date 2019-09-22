#include <iostream>
#include <deque>

bool one_edit(std::string &word1, std::string word2);

bool one_edit(std::string &word1, std::string word2)
{
    int word1_size = word1.size();
    int word2_size = word2.size();
    // The if-statement appears redundant, as the else-statement solves the same issue as the if statement
    // However, the if statement helps to reduce the run time in cases where there is no need to create deques
    // thus, reducing the best case time-complexity to O(1) instead of O(n)
    if (std::abs(word1_size - word2_size) > 1)
    {
        return false;
    }
    else
    {
        bool check = true;
        std::deque<char> myDeque1, myDeque2;
        for (int i = 0; i < word1_size; ++i)
        {
            word1[i] = std::tolower(word1[i]);
            myDeque1.push_back(word1[i]);
        }
        for (int i = 0; i < word2_size; ++i)
        {
            word2[i] = std::tolower(word2[i]);
            myDeque2.push_back(word2[i]);
        }
        while(!myDeque1.empty() && !myDeque2.empty())
        {
            if (myDeque1.front() == myDeque2.front())
            {                                  
                myDeque1.pop_front();
                myDeque2.pop_front();
            }
            else if (myDeque1.back() == myDeque2.back())
            {
                myDeque1.pop_back();
                myDeque2.pop_back();
            }
            else
            {
                // exit the loop if both front and back of both words do not match
                break;
            }
        }
        // checks if there are still numbers not matched, after doing the matching checks in the while loop above.
        if (myDeque1.size() > 1 || myDeque2.size() > 1)
        {
            check = false;
        }
        return check;
    }
}

int main()
{
    std::string word1 = "j9ck&oi";
    std::string word2 = "J9ck&on";
    bool edit_one = one_edit(word1, word2);
    if (edit_one)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    
    return 0;
}