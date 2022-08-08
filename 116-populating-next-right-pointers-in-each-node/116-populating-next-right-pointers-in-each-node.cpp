/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> tq;
        queue<Node*> sq;
        
        tq.push(root);
        tq.push(NULL);
        
        while(!tq.empty()){
            Node* frontNode = tq.front();
            tq.pop();
            
            sq.push(frontNode);
            if(frontNode==NULL){
                if(!tq.empty())
                    tq.push(NULL);
            }
            
            else{
                if(frontNode->left)
                    tq.push(frontNode->left);
            
                if(frontNode->right)
                    tq.push(frontNode->right);
            }
        }
        sq.pop();
        // sq.push(NULL);
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            temp->next = sq.front();
            if(sq.front()==NULL){
                sq.pop();
                sq.pop();
            }
            else
                sq.pop();
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return root;
    }
};