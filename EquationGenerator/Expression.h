#ifndef __EXPRESSION__
#define __EXPRESSION__

#include <string>
#include <sstream>

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
        string operators[] = { ADD, SUB,MUL, DIV };
        int index = rand() % 4;
        return operators[index];
    }

    // 计算结果
    inline Fraction Calculate(Fraction a, Fraction b, const string& op) {
        if (op == ADD)
            return a + b;
        else if (op == SUB)
            return a - b;
        else if (op == MUL)
            return a * b;
        else if (op == DIV)
            return a / b;
    }

    inline void FreeTree(TreeNode* tree) {
        if (tree != NULL)
        {
            FreeTree(tree->left);
            FreeTree(tree->right);
            delete tree;
        }
    }

    // 构建二叉树
    inline TreeNode* BuildTree(int depth,int max) {
        if (depth == 0) {
            string number = GenerateNumber(max);
            TreeNode* tmp = new TreeNode(number);
            tmp->result = stoi(number);
            return tmp;
        }

        string operator_ = GenerateOperator();

        TreeNode* left = BuildTree(depth - 1, max);
        TreeNode* right = BuildTree(depth - 1,max);

        while (operator_ == DIV && right->result == 0)
        {
            FreeTree(right);
            right = BuildTree(depth - 1);
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



    inline void ExpressTree(TreeNode* tree, string& var, string ope) {
        if (tree == NULL)
        {
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
    inline Expression() {

   }

    // 生成表达式 传入随机数的最大值和...
    inline Expression(int maxNum, int depth) {
        _root = BuildTree(depth, maxNum);
   }
    
    // 将字符串表达式转换为数据结构
   inline explicit Expression(string& expression);

    // 获得字符串
   inline std::string GetString() const {
       
   }

    // 获得表达式结果
   inline  std::Fraction GetResult() const {
       
  }
};
#endif // __EXPRESSION__
