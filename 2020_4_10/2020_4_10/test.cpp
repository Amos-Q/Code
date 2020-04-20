#include "home.h"

void SetCursor(int x, int y)             //���ù��λ��
{
	COORD cd = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void SetCursor(const Point& p)          //�������е�λ��ӳ�䵽��Ļ��
{
	SetCursor(2 * p.y, p.x);
}

void HideCursor()                       //���ع��
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}

template<typename T>
void PrintAt(const Point& p, T data, int wid = 0)                   //�ڵ�p�����data
{
	SetCursor(p);
	if (wid)
		cout.width(wid);
	cout << data;
}

void MagicShow(const Point& p, bool flag = false, bool info = false)  //�ڵ�p�����/��������
{
	if (info || g[p.x][p.y] == space)
		PrintAt(p, flag ? square : space);
}
void Block::State_Init()
{
	//I
	all_state[0][0] = all_state[0][2] = "0100 0100 0100 0100";
	all_state[0][1] = all_state[0][3] = "0000 1111 0000 0000";
	//O
	all_state[1][0] = all_state[1][1] = "0000 0110 0110 0000";
	all_state[1][2] = all_state[1][3] = "0000 0110 0110 0000";
	//S
	all_state[2][0] = all_state[2][2] = "0000 0110 1100 0000";
	all_state[2][1] = all_state[2][3] = "0100 0110 0010 0000";
	//Z
	all_state[3][0] = all_state[3][2] = "0000 1100 0110 0000";
	all_state[3][1] = all_state[3][3] = "0100 1100 1000 0000";
	//T
	all_state[4][0] = "0000 1110 0100 0000";
	all_state[4][1] = "0100 1100 0100 0000";
	all_state[4][2] = "0100 1110 0000 0000";
	all_state[4][3] = "0100 0110 0100 0000";
	//J
	all_state[5][0] = "0100 0100 1100 0000";
	all_state[5][1] = "1000 1110 0000 0000";
	all_state[5][2] = "1100 1000 1000 0000";
	all_state[5][3] = "0000 1110 0010 0000";
	//L
	all_state[6][0] = "0100 0100 0110 0000";
	all_state[6][1] = "0000 1110 1000 0000";
	all_state[6][2] = "1100 0100 0100 0000";
	all_state[6][3] = "0010 1110 0000 0000";
}
Block::Block()
{
	id = rand() % 7;                      //������ɿ������
	dir = rand() % 4;                     //������ɿ�ķ���
	p = Point(4, 13);                    //��ʼ����p��λ��
	StateCpy();
}
void Block::StateCpy()
{
	for (int i = 0, add = 0; i < 4; i++, add++)
		for (int j = 0; j < 4; j++)
			state[i][j] = all_state[id][dir][i * 4 + j + add] == '1';   //��ÿ�������״̬��ֵ
}

void Block::Rotate()
{
	dir = (dir + 1) % 4;
	StateCpy();
}

void Block::Show(bool info = false)           //info��ʾ�Ƿ�����Ϣ��,��ͬ
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			MagicShow(Point(p.x + i, p.y + j), state[i][j], info);
}
Game::Game() :level(1), score(0)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			g[i][j] = "  ";
		for (int j = 0; j < MM; j++)
			gg[i][j] = "  ";
	}
	for (int i = 1; i < M; i++)
		g[0][i] = g[N - 1][i] = line[0];
	for (int i = 1; i < MM; i++)
		gg[0][i] = gg[N - 1][i] = line[0];
	for (int i = 1; i < N; i++)
		g[i][0] = g[i][M - 1] = gg[i][0] = gg[i][MM - 1] = line[1];
	g[0][0] = gg[0][0] = corner[0];
	g[0][M - 1] = gg[0][MM - 1] = corner[1];
	g[N - 1][0] = gg[N - 1][0] = corner[2];
	g[N - 1][M - 1] = gg[N - 1][MM - 1] = corner[3];
}

int Game::GetTickCnt()
{
	return tick_cnt[level];
}

void Game::ShowFrame()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << g[i][j];
		for (int j = 0; j < MM; j++)
			cout << gg[i][j];
		cout << endl;
	}
	PrintAt(Point(2, 13), " Next");
	PrintAt(Point(9, 13), " Level");
	PrintAt(Point(10, 14), level, 2);
	PrintAt(Point(12, 13), " Score");
	PrintAt(Point(13, 14), score, 2);
	PrintAt(Point(20, 13), " @Xiaod");
}

bool Game::AllSquare(int xx)
{
	for (int j = 1; j < M - 1; j++)
		if (g[xx][j] != square)
			return false;
	return true;
}

void Game::DropDown(int xx)
{
	for (int i = xx; i > 1; i--)
		for (int j = 1; j < M - 1; j++)
			g[i][j] = g[i - 1][j];
	for (int j = 1; j < M - 1; j++)
		g[1][j] = space;
}

void Game::Update(int flash_line_cnt)
{
	score += score_up[flash_line_cnt];
	PrintAt(Point(13, 14), score);
	if (level < 6 && score >= level_up[level])
		PrintAt(Point(10, 14), ++level, 2);
}

void Game::CheckLine()
{
	vector<int> flash_line;                                 //��������Ҫ��ȥ���к�
	vector<int>::iterator it;
	for (int i = 0; i < 4; i++)
		if (AllSquare(i + runB.p.x))
			flash_line.push_back(i + runB.p.x);
	if (flash_line.empty())
		return;
	int flash_times = 5;
	while (flash_times--)                                    //��
	{
		for (it = flash_line.begin(); it != flash_line.end(); it++)
			for (int j = 1; j < M - 1; j++)
				MagicShow(Point(*it, j), flash_times & 1, true);
		Sleep(60);
	}
	for (it = flash_line.begin(); it != flash_line.end(); it++)    //��ȥĳ�к󣬽��������Ϣ�����ƶ�
		DropDown(*it);
	it = flash_line.end() - 1;
	for (int i = 1; i <= *it; i++)
		for (int j = 1; j < M - 1; j++)
			MagicShow(Point(i, j), g[i][j] == square, true);     //����Ҫ��ȥ�����һ���Ϸ�����Ϣ
	Update(flash_line.size());
	flash_line.clear();
}
void Game::PlaceOn()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (runB.state[i][j])
				g[runB.p.x + i][runB.p.y + j] = square;
}

void Game::GetNext()
{
	runB = nextB;
	runB.p = Point(1, 5);
	nextB = Block();
	nextB.Show(true);
	runB.Show();
}

inline bool Game::OutBoard(int x, int y)
{
	return x <= 0 || x >= N - 1 || y <= 0 || y >= M - 1;
}

void Game::CheckBoard()
{
	char ch[2];
	for (int i = 0; i < 2; i++)
		if (kbhit())                                     //�������Ƿ���
		{
			ch[i] = getch();                            //ֻ����getch��������
			if (ch[0] != -32)
			{
				i--;
				if (ch[0] == ' ')                        //���ո���ͣ��Ϸ
					getch();
				continue;
			}
			if (i == 1)
			{
				switch (ch[1])
				{
				case 72:Rotate(); break;             //��
				case 80:ChangePos(1, 0); break;       //��
				case 75:ChangePos(0, -1); break;      //��
				case 77:ChangePos(0, 1); break;       //��
				}
			}
		}
}

void Game::CheckBoard()
{
	char ch[2];
	for (int i = 0; i < 2; i++)
		if (kbhit())                                     //�������Ƿ���
		{
			ch[i] = getch();                            //ֻ����getch��������
			if (ch[0] != -32)
			{
				i--;
				if (ch[0] == ' ')                        //���ո���ͣ��Ϸ
					getch();
				continue;
			}
			if (i == 1)
			{
				switch (ch[1])
				{
				case 72:Rotate(); break;             //��
				case 80:ChangePos(1, 0); break;       //��
				case 75:ChangePos(0, -1); break;      //��
				case 77:ChangePos(0, 1); break;       //��
				}
			}
		}
}

bool Game::CanChange(int dx = 0, int dy = 0)
{
	const int x = runB.p.x, y = runB.p.y;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (runB.state[i][j] && (OutBoard(i + x + dx, j + y + dy) || g[i + x + dx][j + y + dy] == square))
				return false;
	return true;
}
void Game::Rotate()
{
	runB.Rotate();
	if (!CanChange())
		for (int i = 0; i < 3; i++)
			runB.Rotate();
	runB.Show();
}

bool Game::ChangePos(int dx, int dy)
{
	if (!CanChange(dx, dy))
		return false;
	const int x = runB.p.x, y = runB.p.y;
	if (dx == 1)                                     //����������е���ʾ
	{
		for (int j = 0; j < 4; j++)
			MagicShow(Point(x, y + j));
		++runB.p;
	}
	else if (dy == 1)                                //+1
	{
		for (int i = 0; i < 4; i++)
			MagicShow(Point(x + i, y));
		runB.p++;
	}
	else if (dy == -1)                               //+2
	{
		for (int i = 0; i < 4; i++)
			MagicShow(Point(x + i, y + 3));
		runB.p--;
	}
	runB.Show();
	return true;
}

void Game::Begin()
{
	ShowFrame();
	nextB = Block();
	GetNext();
	int flash_times = 1000;
	while (!kbhit() && flash_times--)
	{
		PrintAt(Point(9, 1), flash_times & 1 ? "                   " : " * * * * * * * * * ");
		PrintAt(Point(10, 1), flash_times & 1 ? "  Anykey to start  " : "* Anykey to start *");
		PrintAt(Point(11, 1), flash_times & 1 ? "                   " : " * * * * * * * * * ");
		Sleep(100);
	}
	getch();                                        //anykey to start!
	PrintAt(Point(9, 1), "                   ");
	PrintAt(Point(10, 1), "                   ");
	PrintAt(Point(11, 1), "                   ");
}

void Game::Over()
{
	int flash_times = 12;
	while (flash_times--)
	{
		PrintAt(Point(9, 3), flash_times & 1 ? "             " : " * * * * * * ");
		PrintAt(Point(10, 3), flash_times & 1 ? "  Game over  " : "* Game over *");
		PrintAt(Point(11, 3), flash_times & 1 ? "             " : " * * * * * * ");
		Sleep(200);
	}
	PrintAt(Point(21, 0), "");                        //�ѹ���Ƶ����
}