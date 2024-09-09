#include <iostream>
#include <string>
using namespace std;

class TreeNode {
private:
    int marks;
    string gender;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int m, const std::string& g) : marks(m), gender(g), left(nullptr), right(nullptr) {}

    int getMarks() const { return marks; }
    const string& getGender() const { return gender; }
    void setLeft(TreeNode* l) { left = l; }
    void setRight(TreeNode* r) { right = r; }

    bool isLeaf() const { return (left == nullptr && right == nullptr); }

    void inOrder() const {
        if (left != nullptr)
            left->inOrder();
		  cout << "Marks: " << marks << ", Gender: " << gender << endl;
        if (right != nullptr)
            right->inOrder();
    }
};

int main() {
    TreeNode* maleRoot = new TreeNode(80, "Male");
    maleRoot->setLeft(new TreeNode(70, "Male"));
    maleRoot->setRight(new TreeNode(90, "Male"));

    TreeNode* femaleRoot = new TreeNode(85, "Female");
    femaleRoot->setLeft(new TreeNode(75, "Female"));
    femaleRoot->setRight(new TreeNode(95, "Female"));
    cout << "Male Students:" << std::endl;
    maleRoot->inOrder();
    cout << "\nFemale Students:" << std::endl;
    femaleRoot->inOrder();

    return 0;
}

