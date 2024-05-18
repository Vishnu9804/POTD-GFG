#include <bits/stdc++.h>
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
