class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if ( root == no )return {} ;

        queue< N* > q ;
        vector<int> t ;
        vector< vector<int> > res;

        q.push(root);
        q.push(no);

        while ( q.size() )
        {
            auto x = q.front() ; q.pop();

            if ( x == no )
            {
                res.push_back(t);
                if (!q.size()) return res;
                x = q.front();
                q.pop();
                t.clear();
                q.push(no);
            }

            t.push_back(x->v);

            if (x->l)q.push(x->l);
            if (x->r)q.push(x->r);

        }

        return res;
    }
};