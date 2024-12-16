#include "bst.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

int rangeSum(Node *root, int L, int R) {
	
	//Base case - called on a null node -> return 0!	
	if (root == NULL) return 0;
	//Otherwise get the value of the left and right trees under you (recursive call)
	int l_sum = rangeSum(root->left, L, R);
	int r_sum = rangeSum(root->right, L, R);
	//Sum em
	int sum = l_sum + r_sum;
	//Should add node->key to the sum?
	if (root->key >= L && root->key <= R) sum += root->key;
	//Return the sum!
	return sum;
}

int height(Node *n) {
	if (n == NULL) {
		return 0;
	} else {
		int l_height = height(n->left);
		int r_height = height(n->right);
		if (l_height > r_height) {
			return l_height + 1;
		} else {
			return r_height + 1;
		}
	}
}
    
bool isBalanced(Node *root) {
	//Get the heights of the left and right subtrees - helper func?
	int l_height = height(root->left);
	int r_height = height(root->right);
	//Determine if this node is balanced! If not ret false!
	if (abs(l_height - r_height) > 1) return false;
	//Check if there are subtrees under us
	//Are they balanced?
	bool b = true;
	if (root->left != NULL) {
		if (!isBalanced(root->left)) b = false;
	}
	if (root->right != NULL) {
		if (!isBalanced(root->right)) b = false;
	}
	//If all nodes are balanced return true!
	return b;
}
/*

Given a binary tree, return the level order traversal of its nodes' values. (i.e. from left to right, level by level).


If you're given this binary tree as input:

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/
vector<vector<int>> levelOrder(Node* root) {
	vector<vector<int>> results;
	queue<pair<Node *, int>> q;
	if (root != NULL) q.push({root, 1});
	int h = 1;
	vector<int> r;
	while (!q.empty()) {
		Node *n = q.front().first;
		int he = q.front().second;
		q.pop();
		r.push_back(n->key);
		if (n->left != NULL) q.push({n->left, he + 1});
		if (n->right != NULL) q.push({n->right, he + 1});
		if (q.empty() || q.front().second == h + 1) {
			results.push_back(r);
			r.clear();
			h = he + 1;
		}
	}
    return results;
}
