#include <iostream>
#include <algorithm>
#include <vector>

/*
    This program caclulates the longest commonn sequence in a pair of strings 
*/

int lcs(std::string &first_seq, std::string &second_seq);

int lcs(std::string &first_seq, std::string &second_seq)
{
   std::vector<std::vector<int> > table(first_seq.size() + 1, std::vector<int>(second_seq.size() + 1, 0));
   for (int i = 1; i < first_seq.size() + 1; i++)
   {
       for (int j = 0; j < second_seq.size() + 1; j++)
       {
           if (first_seq[i - 1] == second_seq[j - 1])
           {
               table[i][j] = 1 + table[i - 1][j - 1];
           }
           else
           {
               table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);
           }
       }
   }
//    for (int i = 0; i < first_seq.size(); i++)
//    {
//        for(int j = 0; j < second_seq.size(); j++)
//        {
//            std::cout << table[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
   return table[first_seq.size()][second_seq.size()];
}

int main()
{
    std::string first_seq = "AGGTAB";
    std::string second_seq = "GXTXAYB";
    int lcs_num;
    lcs_num = lcs(first_seq, second_seq);
    std::cout << "lcs = " << lcs_num << std::endl;
    // for(int i = 0; i < first_seq.size(); i++)
    // {
    //     std::cout << first_seq[i];
    // }
    // std::cout << "\n";
}