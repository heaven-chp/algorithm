#include <iostream>

using namespace std;

const int MAX_LEN = 100000;

int inorderIndex[MAX_LEN] = {
	0,
};

int inorder[MAX_LEN] = {
	0,
};
int postorder[MAX_LEN] = {
	0,
};

void preorderTraversal(int inorderStart, int inorderEnd, int postorderStart,
					   int postorderEnd) {
	if (inorderStart > inorderEnd || postorderStart > postorderEnd) {
		return;
	}

	cout << postorder[postorderEnd] << " ";

	int inorderStartNew1 = inorderStart;
	int inorderEndNew1 = inorderIndex[postorder[postorderEnd]] - 1;
	int postorderStartNew1 = postorderStart;
	int postorderEndNew1 = postorderStart + (inorderEndNew1 - inorderStartNew1);
	preorderTraversal(inorderStartNew1, inorderEndNew1, postorderStartNew1,
					  postorderEndNew1);

	int inorderStartNew2 = inorderIndex[postorder[postorderEnd]] + 1;
	int inorderEndNew2 = inorderEnd;
	int postorderStartNew2 = postorderEndNew1 + 1;
	int postorderEndNew2 = postorderEnd - 1;
	preorderTraversal(inorderStartNew2, inorderEndNew2, postorderStartNew2,
					  postorderEndNew2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> inorder[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> postorder[i];
	}

	for (int i = 0; i < n; ++i) {
		inorderIndex[inorder[i]] = i;
	}

	preorderTraversal(0, n - 1, 0, n - 1);

	return 0;
}
