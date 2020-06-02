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
	// ��һ�������������
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

// �ֲ�ԭ���ԣ��������ݵ��ڴ���з��ʣ����������Ȼ����ط���ʱ��Ч��


// �����������ŵ������У�ͬһ�����ͬһ������
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
		// Ϊ�����Ч�ʣ��Ȳ���һ���յ�vector
		ret.push_back(vector<int>());
		// �õ���������һ�У���������ֱ�������һ�в���
		vector<int>& level = ret.back();
		// �����нڵ��ܵĸ���
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
	��ά���������
	��vector�����Ķ�ά���飬һ����������ȸ����ж����У�Ȼ���ٶ�ÿһ�н��в���
	��������þ��ǻ�û�и�ÿ�з���ռ䣬��ֱ�Ӷ��н��в���������������
*/
void Test2VectorOfError(){
	vector<vector<int>> vv;
	vv.resize(5);// ��ά�����ܹ���5�У�����ÿ�����ڻ�û�пռ�
	//vv[0][0]; // ��ʱֱ�Ӳ���ÿ����Ԫ��ʱ�����
}


/*
	��ά�������к��б���Ч�ʸߣ��������к���Ч�ʸߣ�
*/

/*
	1�����к���
	���к���������Ķ�ά����ı�����ʽ������Ч�ʷǳ��ߣ���Ϊ��ά�����ÿ
	һ�ж���һ�������Ŀռ䣬���ݾֲ���ԭ������ϵͳ�ٷ���ÿ��Ԫ��ʱ���Ὣ
	��Ԫ�ظ������Ԫ��һ���Լ��ص�����������߳���Ч��
*/
void Print2Vector(){
	// ����C++11�ṩ���б��ʼ�������ά���飬ÿ��Ԫ��ʹ��{1,2,3,4,5}�������
	vector<vector<int>> vv(5, {1,2,3,4,5});

	// ���淽ʽ
	for (size_t i = 0; i < vv.size(); i++){
		for (size_t j = 0; j < vv[i].size();j++){
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// ���÷�Χfor��ӡ
	for (auto& rowV : vv){
		for (auto e : rowV){
			cout << e << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/*
	���к���
	���ַ�ʽ�Ƚ��٣���ΪЧ�ʵͣ�һ��������ʺϾ���ʹ�ó���
*/
void Print2Vector2(){
	//����C++11�ṩ���б��ʼ�������ά���飬ÿ��Ԫ��ʹ��{1,2,3,4,5}�������
	vector<vector<int>> vv(5, {1,2,3,4,5});

	// ���к���
	for (size_t row = 0; row < vv.size(); row++){
		for (size_t col = 0; col < vv[row].size(); col++){
			cout << vv[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// ���к���
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







