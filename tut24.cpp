// Word Ladder II

#include <bits/stdc++.h>
using namespace std;
void solve(string beginWord, string endWord, vector<string> &wordList, vector<vector<string>> &ans)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();
        if (vec.size() > level)
        {
            level++;
            for (auto it : usedOnLevel)
            {
                st.erase(it);
            }
            usedOnLevel.clear();
        }
        string word = vec.back();
        if (word == endWord)
        {
            ans.push_back(vec);
        }
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.count(word) > 0)
                {
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
}
int main()
{
   string beginWord = "hit";
   string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> ans;
    solve(beginWord, endWord, wordList, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
return 0;
}