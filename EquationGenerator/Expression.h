#ifndef __EXPRESSION__
#define __EXPRESSION__

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

#include "Fraction.h"

#define MUL "×"
#define DIV "÷"
#define SUB "-"
#define ADD "+"

class Expression {
    friend bool Equal(Expression& e1, Expression& e2);

    friend bool operator==(Expression& e1, Expression& e2);

private:
    // 二叉树节点
    inline struct TreeNode {
        string val;
        Fraction result;
        TreeNode* left;
        TreeNode* right;

        TreeNode(string x) : val(x), result(0), left(NULL), right(NULL) {}

        TreeNode(Fraction x) : val(0), result(0), left(NULL), right(NULL) {
            stringstream ss;
            ss << x;
            val = ss.str();
        }
    };

    TreeNode* _root;

    // 随机生成数字
    inline string GenerateNumber(int max) {
        return to_string(rand() % max);
    }

    // 随机生成运算符
    inline string GenerateOperator() {
        string operators[] = {ADD, SUB,MUL, DIV};
        int index = rand() % 4;
        return operators[index];
    }

    // 计算结果
    inline Fraction Calculate(Fraction a, Fraction b, const string& op) {
        if (op == ADD) return a + b;
        else if (op == SUB) return a - b;
        else if (op == MUL) return a * b;
        else if (op == DIV) return a / b;
    }

    inline void FreeTree(TreeNode* tree) {
        if (tree != NULL) {
            FreeTree(tree->left);
            FreeTree(tree->right);
            delete tree;
        }
    }

    // 构建二叉树
    inline TreeNode* BuildTree(int depth, int max) {
        if (depth == 0) {
            string number = GenerateNumber(max);
            TreeNode* tmp = new TreeNode(number);
            tmp->result = stoi(number);
            return tmp;
        }

        string operator_ = GenerateOperator();

        TreeNode* left = BuildTree(depth - 1, max);
        TreeNode* right = BuildTree(depth - 1, max);

        while (operator_ == DIV && right->result == 0) {
            FreeTree(right);
            right = BuildTree(depth - 1, max);
        }

        Fraction result = Calculate(left->result, right->result, operator_);

        if (result < 0) {
            (left, right) = (right, left);
            result = -result;
        }

        //return new TreeNode(operator_);
        TreeNode* tmp = new TreeNode(result);
        tmp->left = left;
        tmp->right = right;
        tmp->result = result;
        tmp->val = operator_;
        return tmp;
    }

    inline TreeNode* BuildTree(const std::vector<std::string>& elems) {
        if ((elems.size() & 1) == 0) return nullptr;
        if (elems.size() == 1) {
            // 单个元素就是数值
            auto* ths = new TreeNode(elems[0]);
            stringstream ss;
            Fraction f;
            ss >> f;
            ths->result = f;
            return ths;
        }
        // 不是单个元素就递归创建
        int mid = elems.size() / 2;
        TreeNode* ths = new TreeNode(elems[mid]);
        ths->left = BuildTree(std::vector<std::string>(elems.begin(), elems.begin() + mid - 1));
        ths->right = BuildTree(std::vector<std::string>(elems.begin() + mid + 1, elems.end()));
        ths->result = Calculate(ths->left->result , ths->right->result, elems[mid]);
        return ths;
    }

    inline void ExpressTree(TreeNode* tree, string& var, string ope) const {
        if (tree == NULL) {
            return;
        }

        if ((ope == MUL || ope == DIV) && (tree->val == ADD || tree->val == SUB)) var += "( ";
        ExpressTree(tree->left, var, tree->val);
        var += tree->val + " ";
        ExpressTree(tree->right, var, tree->val);
        if ((ope == MUL || ope == DIV) && (tree->val == ADD || tree->val == SUB)) var += ") ";
    }

public:
    // 默认构造函数
    inline Expression(): _root(nullptr) { }

    // 生成表达式 传入随机数的最大值和...
    inline Expression(int maxNum, int depth) {
        _root = BuildTree(depth, maxNum);
    }

    // 将字符串表达式转换为数据结构
    inline explicit Expression(string& expression) {
        std::replace(expression.begin(), expression.end(), string("("), string(""));
        std::replace(expression.begin(), expression.end(), string(")"), string(""));
        std::vector<std::string> elems;
        stringstream ss(expression);
        string s;
        while (ss >> s) {
            elems.push_back(s);
        }
        _root = BuildTree(elems);
    }

    // 获得字符串
    inline std::string GetString() const {
        std::string ret;
        ExpressTree(_root, ret, " ");
        return ret;
    }

    // 获得表达式结果
    inline std::Fraction GetResult() const {
        return _root->result;
    }
};
#endif // __EXPRESSION__
