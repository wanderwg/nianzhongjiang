#include <iostream>
#include <vector>
using namespace std;
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		for (int i = 0; i < board.size(); ++i)
			//两个for循环遍历二维数组
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (i == 0 && j == 0) {}//起点，不作处理
				else if (i == 0)//第一行，只能往右走
					board[i][j] += board[i][j - 1];
				else if (j == 0)//第一列，只能往下走
					board[i][j] += board[i - 1][j];
				else//其余情况
				{
					int fromup = board[i - 1][j];//从该点上面下来的最大路径和
					int fromleft = board[i][j - 1];//从该点左边过来的最大路径和
					if (fromup > fromleft)
						board[i][j] += fromup;
					else if (fromup < fromleft)
						board[i][j] += fromleft;
				}
			}
		}
		return board[board.size() - 1][board[0].size() - 1];
	}
};