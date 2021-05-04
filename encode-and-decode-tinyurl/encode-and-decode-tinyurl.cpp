class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map <string, string> umap;
    
    string getToken()
    {
        srand(time(NULL));
        string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int l = dict.length();
        string s = "";
        for (int i = 0; i <  6; i++){
            s = s+dict[rand()%l];
        }
        return s;
    }
    
    string encode(string longUrl) {
        
        string en = "";
        string shortUrl = "http://tinyurl.com/"; 
        do
        {
            en = getToken();
        }while(umap.find(en) != umap.end());
        
        umap[en] = longUrl;
        return shortUrl + en;
        
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string r = shortUrl.substr(shortUrl.length() -6, 6); 
        return umap[r];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
