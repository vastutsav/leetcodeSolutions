class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector <vector<int>> answer;
        vector <int> path;
        
        path.push_back(0);
        backTrack(graph, path, graph.size()-1, 0, answer);
        
        return answer;
    }
    
    void backTrack(vector<vector<int>> &graph, vector <int> &path, int finalNum, int currNode, vector <vector<int>> &answer)
    {

        if (currNode == finalNum)
        {
            //end condition - return answer
            printPath(path);
            answer.push_back(path);
            return;
        }
        
        for (auto i = 0; i < graph[currNode].size(); ++i)
        {
            
            cout << currNode << "->" << graph[currNode][i] << endl;
            //set
            //path.push_back(graph[currNode][i]);
            
            int j = (int)graph[currNode][i];
            path.push_back(j);
            
            //cout<<"path ---->" << path.back() << endl;
            //printPath(path);
        
            //recur
            backTrack(graph, path, finalNum, path.back(), answer);
            
            //unset
            path.pop_back();
        }
        
    }
    
    void printPath(vector <int> &path)
    {
        cout <<"======PATH Starts=======\n";
        
        for (int i = 0; i< path.size(); ++i)
            cout << path[i] << " ";
        
        cout <<"\n======PATH Ends=======\n";
    }
    
};