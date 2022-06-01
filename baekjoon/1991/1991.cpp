#include <iostream>
#include <map>
#include <utility>

using namespace std;

void preorderTraversal(const map<char, pair<char, char>>& binaryTree,
					   const char& rootNode) {
	if (rootNode == '.') {
		return;
	}

	cout << rootNode;
	preorderTraversal(binaryTree, binaryTree.at(rootNode).first);
	preorderTraversal(binaryTree, binaryTree.at(rootNode).second);
}

void inorderTraversal(const map<char, pair<char, char>>& binaryTree,
					  const char& rootNode) {
	if (rootNode == '.') {
		return;
	}

	inorderTraversal(binaryTree, binaryTree.at(rootNode).first);
	cout << rootNode;
	inorderTraversal(binaryTree, binaryTree.at(rootNode).second);
}

void postorderTraversal(const map<char, pair<char, char>>& binaryTree,
						const char& rootNode) {
	if (rootNode == '.') {
		return;
	}

	postorderTraversal(binaryTree, binaryTree.at(rootNode).first);
	postorderTraversal(binaryTree, binaryTree.at(rootNode).second);
	cout << rootNode;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<char, pair<char, char>> binaryTree;
	binaryTree.clear();

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		char rootNode = '\0', leftNode = '\0', rightNode = '\0';
		cin >> rootNode >> leftNode >> rightNode;

		binaryTree[rootNode] = {leftNode, rightNode};
	}

	preorderTraversal(binaryTree, 'A');
	cout << "\n";

	inorderTraversal(binaryTree, 'A');
	cout << "\n";

	postorderTraversal(binaryTree, 'A');
	cout << "\n";

	return 0;
}
