#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol139
{

  class Solution
  {
  private:
    bool _wb(const string &s, unordered_map<string, bool> mem);

  public:
    bool wordBreak(string s, vector<string> &wordDict);
  };
}
#endif