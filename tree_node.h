//������������ݽṹ��ͷ�ļ�
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

void TreeNode::CopyTree(void)   //�����Դ˽ڵ�Ϊ�����������������������ü���
{
    if(left)
        left->CopyTree();
    if(right)
        right->CopyTree();
    count++;
}

//��ĳ���ڵ㿪ʼ��������
TreeNode::TreeNode(const TreeNode &tn):value(tn->value), count(1), left(tn->left), right(tn->right)
{
    if(left)
        left->CopyTree();
    if(right)
        right->CopyTree();
}
BinStrTree::~BinStrTree()    //�ͷ�������
{
    if(!root->ReleaseTree()){  //�ͷ�������
        delete root;            //���ü���Ϊ0���ͷŽڵ�ռ�
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
    //countΪ0��ʾ��Դ�ѱ��ͷţ���delete��������������
    if(count)
        ReleaseTree();
}