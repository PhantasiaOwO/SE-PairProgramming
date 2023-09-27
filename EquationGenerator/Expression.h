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
	inline friend bool operator==(const Expression& e1, const Expression& e2) {
		return SameTree(e1._root, e2._root);
	}

private:
	// 二叉树节点
	inline struct TreeNode {
		string val;
		Fraction result;
		TreeNode* left;
		TreeNode* right;

		TreeNode(string x) : val(x), result(0), left(nullptr), right(nullptr) {}

		TreeNode(Fraction x) : val(" "), result(0), left(nullptr), right(nullptr) {
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
		if (tree != nullptr) {
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
			::swap(left,right);
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
		ths->result = Calculate(ths->left->result, ths->right->result, elems[mid]);
		return ths;
	}

	inline void ExpressTree(TreeNode* tree, string& var, string ope) const {
		if (tree == nullptr) {
			return;
		}

		if (tree->left != nullptr &&
			((ope == MUL || ope == DIV) && (tree->val == ADD || tree->val == SUB)
				|| ope == DIV
				|| ope == SUB))
			var += "( ";
		ExpressTree(tree->left, var, tree->val);
		var += tree->val + " ";
		ExpressTree(tree->right, var, tree->val);
		if (tree->left != nullptr &&
			((ope == MUL || ope == DIV) && (tree->val == ADD || tree->val == SUB)
				|| ope == DIV
				|| ope == SUB))
			var += ") ";
	}

	inline static bool SameTree(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr && t2 == nullptr) return true;
		else if (t1 == nullptr || t2 == nullptr) return false;
		else {
			if (t1->val != t2->val) return false;
			else {
				return SameTree(t1->left, t2->left) && SameTree(t1->right, t2->right) || SameTree(t1->left, t2->right) && SameTree(t1->right, t2->left);
			}

		}
	}

public:
		// 生成表达式 传入随机数的最大值和...
	inline Expression(int maxNum, int depth) {
		_root = BuildTree(depth, maxNum);
	}

	// 将字符串表达式转换为数据结构
	inline explicit Expression(string& expression) {
		std::replace(expression.begin(), expression.end(), char("("), char(" "));
		std::replace(expression.begin(), expression.end(), char(")"), char(" "));
		std::vector<std::string> elems;
		stringstream ss(expression);
		string s;
		while (ss >> s) {
			elems.push_back(s);
		}
		_root = BuildTree(elems);
	}

	~Expression() {
		FreeTree(_root);
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
