#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol139;

/* Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode"
can be segmented as "leet code".

*/
tuple<string, vector<string>, bool>
testFixture1()
{
  auto dict = vector<string>{"leet", "code"};
  return make_tuple("leetcode", dict, true);
}

/* Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

*/
tuple<string, vector<string>, bool>
testFixture2()
{
  auto dict = vector<string>{"apple", "pen"};
  return make_tuple("applepenapple", dict, true);
}

/* Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/
tuple<string, vector<string>, bool>
testFixture3()
{
  auto dict = vector<string>{"cats", "dog", "sand", "and", "cat"};
  return make_tuple("catsandog", dict, false);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << get<2>(f) << endl;
  Solution sol;
  cout << sol.wordBreak(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << get<2>(f) << endl;
  Solution sol;
  cout << sol.wordBreak(get<0>(f), get<1>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - exepct to see " << get<2>(f) << endl;
  Solution sol;
  cout << sol.wordBreak(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}