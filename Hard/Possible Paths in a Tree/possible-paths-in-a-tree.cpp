//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class disjoint_set_union
{
private:
    vector<int> size, parent;
 
public:
    disjoint_set_union(int n)
    {
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i]=1;
        }
    }
    int find_ultimate_parent(int num)
    {
        if (parent[num] == num)
            return num;
        return parent[num] = find_ultimate_parent(parent[num]);
    }
    int union_by_size(int x, int y, int &number_of_way_containing_weight)
    {
        int parent_of_x = find_ultimate_parent(x);
        int parent_of_y = find_ultimate_parent(y);
 
        if (parent_of_x == parent_of_y)
        {
            return size[parent_of_x] * size[parent_of_y];
        }
        if (size[parent_of_x] > size[parent_of_y])
        {
            number_of_way_containing_weight += size[parent_of_x] * size[parent_of_y];
            parent[parent_of_y] = parent_of_x;
            size[parent_of_x] += size[parent_of_y];
        }
        else
        {
            number_of_way_containing_weight += size[parent_of_x] * size[parent_of_y];
            parent[parent_of_x] = parent_of_y;
            size[parent_of_y] += size[parent_of_x];
        }
        return number_of_way_containing_weight;
    }
};
 
 
class Solution{
public:
 
 
 
vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
{
    // code here
    disjoint_set_union d(n);
    vector<pair<int, pair<int, int>>> weight_node1_node2;
    for (int i = 0; i < n-1; i++)
    {
        weight_node1_node2.push_back(make_pair(edges[i][2], make_pair(edges[i][0], edges[i][1])));
    }
    sort(weight_node1_node2.begin(), weight_node1_node2.end());
 
    int number_of_way_containing_weight = 0;
    map<int, int> map_of_all_path_containing_weight;
    for (int i = 0; i < n-1; i++)
    {
        int weight = weight_node1_node2[i].first;
        int node1 = weight_node1_node2[i].second.first;
        int node2 = weight_node1_node2[i].second.second;
 
        map_of_all_path_containing_weight[weight] = d.union_by_size(node1, node2, number_of_way_containing_weight);
    }
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        auto it = map_of_all_path_containing_weight.upper_bound(queries[i]);
        if (it == map_of_all_path_containing_weight.begin())
        {
          
            ans.push_back(0);
        }
        else
        {
            it--;
   
            ans.push_back(it->second);
        }
    }
    return ans;
}
};



//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends