#include <iostream>
#include <vector>
using namespace std;
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		for (int i = 0; i < board.size(); ++i)
			//����forѭ��������ά����
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (i == 0 && j == 0) {}//��㣬��������
				else if (i == 0)//��һ�У�ֻ��������
					board[i][j] += board[i][j - 1];
				else if (j == 0)//��һ�У�ֻ��������
					board[i][j] += board[i - 1][j];
				else//�������
				{
					int fromup = board[i - 1][j];//�Ӹõ��������������·����
					int fromleft = board[i][j - 1];//�Ӹõ���߹��������·����
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