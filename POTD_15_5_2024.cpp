// POTD geeksforgeeks 15/05/2024
// Account Merge

#include <bits/stdc++.h>

//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <sstream>
//#include <queue>
//#include <map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, string> email_to_name;
        unordered_map<string, vector<string>> graph;

        for (const auto &account : accounts)
        {
            string name = account[0];
            for (size_t i = 1; i < account.size(); ++i)
            {
                string email = account[i];
                graph[email].push_back(account[1]);
                graph[account[1]].push_back(email);
                email_to_name[email] = name;
            }
        }

        unordered_set<string> visited;
        vector<vector<string>> merged_accounts;

        for (const auto &kv : graph)
        {
            const string &email = kv.first;
            if (!visited.count(email))
            {
                vector<string> merged_emails;
                dfs(email, graph, email_to_name, visited, merged_emails);
                sort(merged_emails.begin(), merged_emails.end());
                merged_accounts.push_back({email_to_name[email]});
                merged_accounts.back().insert(merged_accounts.back().end(), merged_emails.begin(), merged_emails.end());
            }
        }

        return merged_accounts;
    }

    void dfs(const string &email, const unordered_map<string, vector<string>> &graph, const unordered_map<string, string> &email_to_name,
             unordered_set<string> &visited, vector<string> &merged_emails)
    {
        visited.insert(email);
        merged_emails.push_back(email);
        for (const auto &neighbor : graph.at(email))
        {
            if (!visited.count(neighbor))
            {
                dfs(neighbor, graph, email_to_name, visited, merged_emails);
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++)
        {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++)
            {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++)
            {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]"
             << endl;
    }
}
