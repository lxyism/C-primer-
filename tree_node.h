//定义二叉树数据结构的头文件
#ifndef TREE_NODE
#define TREE_NODE
#include<vector>
#include<string>

using namespace std;

class TreeNode{
public:
    friend void CopyTree(void);
    friend int ReleaseTree(void);
    TreeNode() : value(""), count(1), left(nullptr), right(nullptr) { }
    TreeNode(const string &s = string(), TreeNode *lchild = nullptr, TreeNode *rchild = nullptr) : value(s), count(1), left(lchild), right(rchild) {}
    ~TreeNode();
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree{
friend class TreeNode;
public:
    BinStrTree() : root(nullptr) { }
    BinStrTree(TreeNode *t = nullptr):root(t) { }
    ~BinStrTree();
private:
    TreeNode *root;
};

BinStrTree::BinStrTree(const BinStrTree &bst): root(bst.root)
{
    root->CopyTree();
}

void TreeNode::CopyTree(void)   //拷贝以此节点为根的子树————增加引用计数
{
    if(left)
        left->CopyTree();
    if(right)
        right->CopyTree();
    count++;
}

//从某个节点开始烤焙子树
TreeNode::TreeNode(const TreeNode &tn):value(tn->value), count(1), left(tn->left), right(tn->right)
{
    if(left)
        left->CopyTree();
    if(right)
        right->CopyTree();
}
BinStrTree::~BinStrTree()    //释放整棵树
{
    if(!root->ReleaseTree()){  //释放整棵树
        delete root;            //引用技术为0，释放节点空间
    }
}

int TreeNode::ReleaseTree(void)
{
    if(left){
        if(!left->CopyTree())
        delete left;
    }
    if(right){
        if(!right->CopyTree())
        delete right;
    }
    count--;
    return count;
}

TreeNode::~TreeNode()
{
    //count为0表示资源已被释放，是delete触发的析构函数
    if(count)
        ReleaseTree();
}