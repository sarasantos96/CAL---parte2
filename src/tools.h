#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int editDistance(string pattern, string text);

void pre_kmp(string pattern, vector<int> & prefix);

int kmp(string text, string pattern);
