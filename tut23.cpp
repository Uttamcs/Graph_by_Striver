// Word Ladder I
#include <bits/stdc++.h>
using namespace std;
void solve(string beginWord, string endWord, vector<string> &wordList, int &cnt)
{
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> s(wordList.begin(), wordList.end());
    s.erase(beginWord);
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (word == endWord)
        {
            cnt = steps;
            break;
        }
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (s.find(word) != s.end())
                {
                    s.erase(word);
                    q.push({word, steps + 1});
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
    int cnt = 0;
    solve(beginWord, endWord, wordList, cnt);
    cout << cnt << endl;
    return 0;
}