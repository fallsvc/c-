#include "mine.h"

void loadI(IMAGE* image)
{
	char str[50] = { 0 };
	for (int i = 0; i < 12; i++)
	{
		sprintf(str, "./images/%d.jpg", i);
		loadimage(&image[i], str, imageWidth, imageWidth);
	}
}
void setMine(int arr[ROW + 2][COL + 2])
{
	static unsigned s = time(0);
	srand(s);
	s = rand();

	for (int k = 0; k < _MINE; k++)
	{
		int r = rand() % ROW+1;
		int c = rand() % COL+1;
		if (arr[r][c] == 0)
		{
			arr[r][c] = 9;//��
		}
		else
		{
			k--;
		}
	}

}

void setNumber(int arr[ROW + 2][COL + 2])
{
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			int n=arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] +
				arr[i][j - 1] + arr[i][j + 1] +
				arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1];
			if (n != 0&&arr[i][j]==0) {
				arr[i][j] = n / 9;//������
			}
		}
	}
}

void initDraw(IMAGE* image)
{
	for (int i=0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			putimage(j* imageWidth, i* imageWidth, &image[10]);
		}
	}
}
void gameDraw(int arr[ROW + 2][COL + 2],IMAGE* image)
{

	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
		 putimage((j-1) * imageWidth, (i-1) * imageWidth, &image[arr[i][j]]);
		}
	}
}
//�����
int arrS[ROW + 2][COL + 2] = { 0 };//����Ϊ1�������Ϊ2��δ��Ϊ0
void reveal(int arr[ROW + 2][COL + 2],IMAGE*image,int x, int y) {
	if (x < 1 || x >ROW  || y < 1 || y > COL || arrS[x][y]==1||arrS[x][y]==2) return;
	if (arr[x][y]==9) {
		return;
	}
	//չ��
	putimage((y - 1) * imageWidth, (x - 1) * imageWidth, &image[arr[x][y]]);
	arrS[x][y] = 1;
	if (arr[x][y]== 0) {
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				if (dx == 0 && dy == 0) continue;
				reveal(arr,image,x + dx, y + dy);
			}
		}
	}
}

int mouseEvent(int arr[ROW + 2][COL + 2],IMAGE* image)
{
	MOUSEMSG msg = GetMouseMsg();//��ȡ�����Ϣ
	//�������ת��
	int r = (msg.y / imageWidth)+1;
	int c = (msg.x / imageWidth)+1;
	//������
	if (msg.uMsg == WM_LBUTTONDOWN)
	{
		if (arr[r][c] < 9)
		{
			/*putimage((c - 1) * imageWidth, (r-1)*imageWidth, &image[arr[r][c]]);
			arrS[r][c] = 1;*/
			reveal(arr, image, r, c);
		}
		else if (arr[r][c] == 9)
		{
			return -1;
		}
	}
	//����Ҽ�
	else if (msg.uMsg == WM_RBUTTONDOWN)
	{
		if (arrS[r][c]==0) 
		{
			putimage((c-1) * imageWidth, (r-1) * imageWidth, &image[11]);
			arrS[r][c] = 2;
		}
		else if(arrS[r][c]==2) 
		{
			putimage((c-1) * imageWidth, (r-1) * imageWidth, &image[10]);
			arrS[r][c] = 0;
		}
	}
}

int winGame() {
	int sum = 0;
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 0; j <= COL; j++)
		{
			if (arrS[i][j] == 1)
			{
				sum++;
			}
		}
	}
	if (sum == ROW * COL - _MINE)
	{
		return 1;
	}
	return 0;
}

void game()
{
	IMAGE image[12];
	int arr[ROW + 2][COL + 2] = { 0 };
	//��ʼ������
	initgraph(imageWidth * ROW, imageWidth * COL);
	loadI(image);//����ͼƬ
	setMine(arr);//������
	setNumber(arr);//��������
	//ͼ�δ�ӡ
	initDraw(image);

	//gameDraw(arr,image);
	
	while (1)
	{
		//�㵽��
		if (mouseEvent(arr, image) == -1)
		{
			break;
		};

		if (GetAsyncKeyState(27))//��esc����
		{
			break;
		}
		if (winGame()) {
			break;
		}
	}
	gameDraw(arr, image);
	getchar();
	closegraph();
}
