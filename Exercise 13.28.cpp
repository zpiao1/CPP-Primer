#include <string>
using std::string;
class TreeNode {
    // pointerlike class
private:
    std::string value;
    int         *count;
    TreeNode    *left;
    TreeNode    *right;
public:
    TreeNode():
        value(string()), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &tn):
        value(tn.value), count(tn.count), left(tn.left), right(tn.right) { ++*count; }
    TreeNode &operator=(const TreeNode &tn);
    ~TreeNode();
};
TreeNode::~TreeNode()
{
    if (--*count == 0) {
        delete left;
        delete right;
        delete count;
        left = nullptr;
        right = nullptr;
        count = nullptr;
    }
}
TreeNode &TreeNode::operator=(const TreeNode &rhs)
{
    ++*rhs.count;
    if (--*count == 0) {
        delete left;
        delete right;
        delete count;
        left = nullptr;
        right = nullptr;
        count = nullptr;
    }
    left = rhs.left;
    right = rhs.right;
    value = rhs.value;
    count = rhs.count;
    return *this;
}
class BinStrTree {
    // valuelike class
private:
    TreeNode *root;
public:
    BinStrTree():
        root(new TreeNode()) {}
    BinStrTree(const BinStrTree &bst):
        root(new TreeNode(*bst.root)) {}
    BinStrTree &operator=(const BinStrTree &rhs);
    ~BinStrTree()
    { delete root; }
};
BinStrTree &BinStrTree::operator=(const BinStrTree &rhs)
{
    auto tempRoot = new TreeNode(*rhs.root);
    delete root;
    root = tempRoot;
    return *this;
}
