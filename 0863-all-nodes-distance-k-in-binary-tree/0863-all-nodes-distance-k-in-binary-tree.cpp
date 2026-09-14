class Solution {
public:
    void makeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (root == NULL) return;

        if (root->left) {
            parent[root->left] = root;
            makeParent(root->left, parent);
        }

        if (root->right) {
            parent[root->right] = root;
            makeParent(root->right, parent);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;
        makeParent(root, parent);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int distance = 0;

        while (!q.empty()) {

            int size = q.size();

            if (distance == k)
                break;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if (parent.count(node) && !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }

            distance++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};