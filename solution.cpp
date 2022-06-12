#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm> //lower_bound
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol139;
using namespace std;

/*takeaways
  - DP
    - recursion and memorize what has been evaluated
  - time complexity : O(n^2)
*/

bool Solution::wordBreak(string s, vector<string> &wordDict)
{
  /* remember what has been calculated */
  auto mem = unordered_map<string, bool>();
  /* base */
  for (auto w : wordDict)
    mem[w] = true;

  return _wb(s, mem);
}

bool Solution::_wb(const string &s, unordered_map<string, bool> mem)
{
  /* s has been evaluated before; just return the result
     - you don't need to further break down s
  */
  if (mem.count(s))
    return mem[s];

  /* break the string into left and right
     from all possible locations
     - we already dealt with the case where
       the left is an empty string in the above
  */
  for (auto i = 1; i < s.size(); i++)
  {
    auto rit = mem.find(s.substr(i));
    /* check if the right is legit first
       - then recursively checking the left
    */
    if (rit != end(mem) && rit->second && _wb(s.substr(0, i), mem))
      /* we only need to find one legit combination to declare
         that s is legit too
      */
      return mem[s] = true;
  }

  /* no ligit combination */
  return mem[s] = false;
}