#include <iostream>
#include <map>
#include <vector>

class Tree {
public:
  Tree(int _val, Tree *_left, Tree *_right)
      : val(_val), left(_left), right(_right) {}
  Tree(int _val) : val(_val) {}
  int val;
  Tree *left = nullptr;
  Tree *right = nullptr;
};

void inorder(Tree *root, std::map<int, int> &verticalSum,
             int currentVertical = 0) {
  if (nullptr == root) {
    return;
  }
  inorder(root->left, verticalSum, currentVertical - 1);

  verticalSum[currentVertical] =
      verticalSum.find(currentVertical) == verticalSum.end()
          ? root->val
          : root->val + verticalSum[currentVertical];
  inorder(root->right, verticalSum, currentVertical + 1);
}

std::map<int, int> verticalSumOfBinaryTree(Tree *root) {

  std::map<int, int> verticalSum;
  inorder(root, verticalSum);

  return verticalSum;
}

int main() {
  Tree *root = new Tree(1, new Tree(2, new Tree(4), new Tree(5)),
                        new Tree(3, new Tree(7), new Tree(6)));

  auto sum = verticalSumOfBinaryTree(root);

  for (const auto s : sum) {
    std::cout << s.first << " " << s.second << "\n";
  }
  return 0;
}