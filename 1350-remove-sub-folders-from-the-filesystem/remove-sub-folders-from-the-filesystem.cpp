
class Solution {
public:
    struct TrieNode{
  bool isEnd;
    unordered_map<string,TrieNode*> children;
        TrieNode(): isEnd(false){}
};
    TrieNode *root;
    void deleteTrie(TrieNode* node){
        if(node==nullptr) return;
        for(auto &pair:node->children){
            deleteTrie(pair.second);
        }
        delete node;
    }
    Solution(): root(new TrieNode()) {}
    ~Solution(){ deleteTrie(root); }
    vector<string> removeSubfolders(vector<string>& folder) {
        for(string &path: folder){
            TrieNode *cur=root;
            istringstream iss(path);
            string folderName;
            while(getline(iss,folderName, '/')){
                if(folderName.empty()) continue;
                if(cur->children.find(folderName)==cur->children.end()){
                    cur->children[folderName] = new TrieNode();
                }
                cur=cur->children[folderName];
            }
            cur->isEnd=true;
        }
        vector<string> res;
        for(string &path:folder){
            TrieNode *cur=root;
            istringstream iss(path);
            string folderName;
            bool isSubFolder = false;
            while(getline(iss,folderName,'/')){
                if(folderName.empty()) continue;
                TrieNode *nextNode = cur->children[folderName];
                if(nextNode->isEnd and iss.rdbuf()->in_avail()!=0){
                    isSubFolder=true;
                    break;
                }
                cur=nextNode;
            }
            if(!isSubFolder) res.push_back(path);
        }
        return res;
    }
};