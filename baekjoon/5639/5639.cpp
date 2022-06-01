#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

void setBinaryTree(map<int, pair<int, int>>& binaryTree, const vector<int>& preorder,
				   const int& start, const int& end) {
	if (start >= end) {
		return;
	}

	if (start + 1 == end) {
		return;
	}

	if (start + 2 == end) {
		if (preorder.at(start) > preorder.at(start + 1)) {
			binaryTree[preorder.at(start)].first = preorder.at(start + 1);
		} else {
			binaryTree[preorder.at(start)].second = preorder.at(start + 1);
		}

		return;
	}

	binaryTree[preorder.at(start)].first = preorder.at(start + 1);

	int index = start + 1;
	for (int i = start + 1; i < end; ++i) {
		if (preorder[start] < preorder[i]) {
			index = i;
			break;
		}
	}

	if (index > start + 1) {
		binaryTree[preorder.at(start)].second = preorder.at(index);
	}
	setBinaryTree(binaryTree, preorder, start + 1, index);
	setBinaryTree(binaryTree, preorder, index, end);
}

void postorderTraversal(const map<int, pair<int, int>>& binaryTree, const int& rootNode) {
	if (rootNode == 0) {
		return;
	}

	if (binaryTree.find(rootNode) == binaryTree.end()) {
		cout << rootNode << "\n";
		return;
	}

	postorderTraversal(binaryTree, binaryTree.at(rootNode).first);
	postorderTraversal(binaryTree, binaryTree.at(rootNode).second);
	cout << rootNode << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int node = 0;
	vector<int> preorder;
	preorder.clear();
	while (cin >> node) {
		preorder.push_back(node);
	}

	vector<int> graph[10000];

	map<int, pair<int, int>> binaryTree;
	binaryTree.clear();

	setBinaryTree(binaryTree, preorder, 0, preorder.size());

	postorderTraversal(binaryTree, preorder.at(0));

	return 0;
}
