#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ROW 3
#define COL 4
void test1(){
	int array[ROW][COL];
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			array[i][j] = i + j;
		}
	}
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
void test2(){
	vector<vector<int>> vv(5,vector<int>(6,10));
	for (size_t i = 0; i < vv.size(); i++){
		for (size_t j = 0; j < vv[i].size(); j++){
			vv[i][j] = i + j;
		}
	}
	for (size_t i = 0; i < vv.size(); i++){
		for (size_t j = 0; j < vv[i].size(); j++){
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}

void test3(){
	// 整一个五行杨辉三角
	vector<vector<int>> vv(5);
	for (size_t i = 0; i < vv.size(); i++){
		vv[i].resize(i + 1,1);
		for (size_t j = 1; j < vv[i].size() - 1; ++j){
			vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
		}
	}
	for (size_t i = 0; i < vv.size(); i++){
		for (size_t j = 0; j <  vv[i].size(); j++){
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}

void test4(){
	vector<vector<int>> vv(5, vector<int>(6, 0));
	for (auto e : vv){
		for (auto v : e){
			cout << v << " ";
		}
		cout << endl;
	}
}

void test5(){
	vector<vector<int>> verc(5,vector<int>(6,0));
	int i = 0;
	for (i = 0; i < verc.size(); i++){
		int j = 0;
		for (; j < verc[i].size(); j++){
			cout << verc[i][j] << " ";
		}
		cout << endl;
	}
}

// 局部原理性，加载数据到内存进行访问，按照列优先会严重妨碍时间效率


// 遍历二叉树放到数组中，同一层放在同一个数组
struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
};
vector<vector<int>> levelOrder(TreeNode* root){
	vector<vector<int>> ret;
	if (nullptr == root){
		return ret;
	}
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()){
		// 为了提高效率，先插入一个空的vector
		ret.push_back(vector<int>());
		// 拿到数组的最后一行，借助引用直接在最后一行插入
		vector<int>& level = ret.back();
		// 本层中节点总的个数
		size_t size = q.size();
		for (int i = 0; i < size; ++i){
			TreeNode* cur = q.front();
			q.pop();

			level.push_back(cur->val);

			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->left);
		}
	}
	return ret;
}

vector<vector<int>> levelToArray(TreeNode* root){
	vector<vector<int>> vecLevel;
	queue<TreeNode*> q;
	if (nullptr == root){
		return vecLevel;
	}
	q.push(root);
	while (!q.empty()){
		vecLevel.push_back(vector<int>());

		vector<int>& level = vecLevel.back();

		size_t size = q.size();

		int i = 0;
		for (; i < size; i++){
			TreeNode* cur = q.front();
			q.pop();
			level.push_back(cur->val);

			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}
	}
	return vecLevel;
}

/*
	二维数组的误用
	用vector创建的二维数组，一般情况下是先给出有多少行，然后再对每一行进行操作
	最常见的误用就是还没有给每行分配空间，就直接对行进行操作而引起代码崩溃
*/
void Test2VectorOfError(){
	vector<vector<int>> vv;
	vv.resize(5);// 二维数组总共有5行，但是每行现在还没有空间
	//vv[0][0]; // 此时直接操作每行中元素时会崩溃
}


/*
	二维数组先行后列遍历效率高，还是先列后行效率高？
*/

/*
	1、先行后列
	先行后列是最常见的二维数组的遍历方式，而且效率非常高，因为二维数组的每
	一行都是一段连续的空间，根据局部性原理，操作系统再访问每个元素时，会将
	该元素附近多个元素一次性加载到缓存中来提高程序效率
*/
void Print2Vector(){
	// 采用C++11提供的列表初始化构造二维数组，每行元素使用{1,2,3,4,5}进行填充
	vector<vector<int>> vv(5, {1,2,3,4,5});

	// 常规方式
	for (size_t i = 0; i < vv.size(); i++){
		for (size_t j = 0; j < vv[i].size();j++){
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// 采用范围for打印
	for (auto& rowV : vv){
		for (auto e : rowV){
			cout << e << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/*
	先列后行
	该种方式比较少，因为效率低，一般情况下适合矩阵使用场景
*/
void Print2Vector2(){
	//采用C++11提供的列表初始化构造二维数组，每行元素使用{1,2,3,4,5}进行填充
	vector<vector<int>> vv(5, {1,2,3,4,5});

	// 先行后列
	for (size_t row = 0; row < vv.size(); row++){
		for (size_t col = 0; col < vv[row].size(); col++){
			cout << vv[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// 先列后行
	for (size_t col = 0; col < vv[0].size(); col++){
		for (size_t row = 0; row < vv.size(); row++){
			cout << vv[row][col] << " ";
		}
		cout << endl;
	}

	cout << endl;
}
void main(){
	Print2Vector2();
	//Print2Vector();
	//test5() ;
	//test4();
	//test3();
	//test2();
	//test1();
	while (1);
}







