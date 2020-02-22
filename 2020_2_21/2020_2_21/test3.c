#include<math.h>
#include<time.h>
#include <windows.h>
#include<stdio.h>
#include<stdlib.h>
#define SNAKE_SIZE 10
#define MOVABLE 1
#define UNMOVABLE 0 
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
static struct tagRECT* sr=(struct tagRECT*)malloc(sizeof(struct tagRECT));
HDC 		hdc;
PAINTSTRUCT ps;
PRECT 		foodpr;
int         direction=2;
int         start=0;
int         score=0;
int         food=0;
int         speed=150;
int         dscore=7;
int         foodsum=1;
int         foodtype=1;
int         score_t=0;
int         score_f1=5;
int         score_f2=10;
char*       score_c;
char*       best=(char*)"0";
PRECT       foodpos=NULL;
typedef struct Link
{
	int 	posx;
	int 	posy;
	struct  Link* next;
}*link; 
typedef struct LoopLink
{
	int 	size;
	struct  Link* head;
	struct  Link* tail;
}*p_link;
typedef struct InRect
{
	int x;
	int y;
}*INRECT,IRECT;
void Init(struct LoopLink* plink)  //init the snake's body
{
	plink->size=4;
	plink->tail=(link)malloc(sizeof(struct Link));
	plink->head=(link)malloc(sizeof(struct Link));
	plink->tail->next=(link)malloc(sizeof(struct Link));
	plink->tail->next->next=(link)malloc(sizeof(struct Link));
	plink->tail->next->next->next=plink->head; 
	plink->head->next=plink->tail;
	plink->head->posx=30;
	plink->head->posy=200;
	plink->head->next->posx=0;
    plink->head->next->posy=200;
	plink->head->next->next->posx=10;
	plink->head->next->next->posy=200;	
	plink->head->next->next->next->posx=20;
	plink->head->next->next->next->posy=200;
}
int ClearLink(struct LoopLink* plink)
{
	if(plink==NULL) return 0;
	int i=1;
	struct Link* p=plink->head;
	struct Link* q=p;
	while(i<=plink->size)
	{
		q=p;
		p=p->next;
		free(q);
		i++;
	}
}
static struct LoopLink* plink=(struct LoopLink*)malloc(sizeof(struct LoopLink));
int AddElement(struct LoopLink* plink)   /*increase the length of the body*/
{
	link p=(link)malloc(sizeof(struct Link));
	plink->head->next=p;
	p->next=plink->tail;
	plink->tail=p;
	plink->size++;
	return 1;
}
PRECT Move_Right(struct LoopLink* plink)      //move toward the right side 
{
	PRECT inrect=(PRECT)malloc(sizeof(RECT));
	inrect->left=plink->tail->posx;
	inrect->top=plink->tail->posy;
	inrect->right=inrect->left+10;
	inrect->bottom=inrect->top+10;
	if(plink->head->posx+10<=270) 
	plink->tail->posx=plink->head->posx+10;
	else plink->tail->posx=0;
	plink->tail->posy=plink->head->posy;
	plink->head=plink->tail;
	plink->tail=plink->head->next;
	return inrect;
}
PRECT Move_Left(struct LoopLink* plink)    /*move toward the left side*/
{
	PRECT inrect=(PRECT)malloc(sizeof(RECT));
	inrect->left=plink->tail->posx;
	inrect->top=plink->tail->posy;
	inrect->right=inrect->left+10;
	inrect->bottom=inrect->top+10;
	if(plink->head->posx-10>=0)
	plink->tail->posx=plink->head->posx-10;
	else 	plink->tail->posx=270;
	plink->tail->posy=plink->head->posy;
	plink->head=plink->tail;
	plink->tail=plink->head->next;
	return inrect;
}
PRECT Move_Up(struct LoopLink* plink)   /*move toward the up side*/
{
	PRECT inrect=(PRECT)malloc(sizeof(RECT));
	inrect->left=plink->tail->posx;
	inrect->top=plink->tail->posy;
	inrect->right=inrect->left+10;
	inrect->bottom=inrect->top+10;
	plink->tail->posx=plink->head->posx;
	if(plink->head->posy-10>=30)
	plink->tail->posy=plink->head->posy-10;
	else plink->tail->posy=340;
	plink->head=plink->tail;
	plink->tail=plink->head->next;
	return inrect;
}
PRECT Move_Down(struct LoopLink* plink)   /*move down*/
{
	PRECT inrect=(PRECT)malloc(sizeof(RECT));
	inrect->left=plink->tail->posx;
	inrect->top=plink->tail->posy;
	inrect->right=inrect->left+10;
	inrect->bottom=inrect->top+10;
	plink->tail->posx=plink->head->posx;
	if(plink->head->posy+10<=340)
	plink->tail->posy=plink->head->posy+10;
	else plink->tail->posy=30;
	plink->head=plink->tail;
	plink->tail=plink->head->next;
	return inrect;
}
int Check_Crash(struct LoopLink* plink) /*to check if the head crash it's body*/
{
	int index=1;
	struct Link* p=plink->head;
	struct Link* q=p->next;
	while(q!=p)
	{
		if((q->posx==p->posx)&&(p->posy==q->posy)&&(index<=plink->size))
		{
			return 1;
		}
		q=q->next; 
		index++;
	}
	return 0;
}
typedef struct Snake_Link
{
	struct Snake_Pos* p[80];
}*Snake_L;
void InitRect(struct tagRECT* rect)
{
	rect->left=0;
	rect->top=0;
	rect->right=10;
	rect->bottom=10;
}
void ShowSnake(HDC hdc)
{
	struct Link* p=plink->head;
	int i=1;
	while(i<=plink->size)
        {
        	PRECT rect=(PRECT)malloc(sizeof(RECT));
        	rect->left=p->posx;
        	rect->top=p->posy;
        	rect->right=p->posx+SNAKE_SIZE;
        	rect->bottom=p->posy+SNAKE_SIZE;
        	FillRect(hdc,rect,(HBRUSH)GetStockObject(GRAY_BRUSH));
        	p=p->next;
        	++i;
		}
}
PRECT ProduceFood()
{
	int x;
	int y;
	if(food!=0) return NULL;
	if(food==0)
	{
	srand((unsigned)time(NULL));
	int t=1,i=1,j=0;
    for(j=0;j<300;j++)
    {
    x=rand()%27;
    y=rand()%31+3;
    struct Link* p=plink->head;
    for(i=1;i<=plink->size;i++)
    {
    	if(p->posx==x*10&&p->posy==y*10) t=0;
    	p=p->next;
	}
	if(t==1) break;
	}
		PRECT r=(PRECT)malloc(sizeof(RECT));
		r->left=x*10;
		r->top=y*10;
		r->right=x*10+10;
		r->bottom=y*10+10;
		food=1;
		if((x+y)%5==0) foodtype=2;
		return r;
	}
}
int ShowFood(HDC hdc)
{
		if((foodpr=ProduceFood())!=NULL) 
					{
						if(foodtype==1)
						{
						FillRect(hdc,foodpr,(HBRUSH)GetStockObject(GRAY_BRUSH));	
						}
						if(foodtype==2)
						{
						FillRect(hdc,foodpr,(HBRUSH)GetStockObject(BLACK_BRUSH));	
						}
						foodpos=foodpr;	
					}
					return 1;
}
int EatFood(PRECT rect)
{
	if(rect==NULL) return 0;
	int i=1;
	struct Link* p=plink->head;
    if((p->posx==rect->left)&&(p->posy==rect->top))
		{
			food=0;
			AddElement(plink);
            if(foodtype==1)
			score+=(score_f1+dscore*5);
			if(foodtype==2)
			{
			score+=(score_f2+dscore*7);
			foodtype=1;
			}
			dscore=7;
			return 1;
		}
	return 0;
}
int SaveBest(char* best)
{
	FILE *f;
	if((f=fopen("c://tcs_best.txt","w"))==NULL) 
	{
	if((f=fopen("e://tcs_best.txt","w"))==NULL)
	return FALSE;
	}
	fputs(best,f);
	fclose(f);
	return TRUE;
}
char* ReadBest()
{
	FILE *f;
	char* best=(char*)malloc(sizeof(char)*4);
	if((f=fopen("c://tcs_best.txt","r"))==NULL) 
	{
		if((f=fopen("e://tcs_best.txt","r"))==NULL)
		return (char*)"0";
	}
	fgets(best,5,f);
	fclose(f);
	return best;
}
int GameOver(HWND hwnd,HDC hdc,struct LoopLink* plink)
{
		PRECT prect=(PRECT)malloc(sizeof(RECT));
		PRECT prect2=(PRECT)malloc(sizeof(RECT));
		PRECT prect3=(PRECT)malloc(sizeof(RECT));
	    char* best=(char*)malloc(sizeof(char)*4);
	    prect->left=0;
		prect->top=30;
		prect->bottom=400;
		prect->right=300;
		prect2->left=46;
		prect2->top=0;
		prect2->bottom=22;
		prect2->right=80;
		prect3->top=0;
		prect3->left=117;
		prect3->right=157;
		prect3->bottom=22;
	    itoa(score,best,10);
	    int t=atoi(ReadBest());
	    food=0;
	    foodpr=NULL;
	    foodpos=NULL;
	    if(t<score)
	    {		
		    SaveBest(best);
	    	InvalidateRect(hwnd,prect3,TRUE);
	    	TextOut(hdc,117,6,ReadBest(),strlen(ReadBest()));
		}
		KillTimer(hwnd,1);
		KillTimer(hwnd,2);
		KillTimer(hwnd,3);
		Sleep(1000);
		InvalidateRect(hwnd,prect,TRUE);
		InvalidateRect(hwnd,prect2,TRUE);
		ClearLink(plink);
		score=0;
		int x=MessageBox(hwnd,TEXT("Mr.Snake,你刚刚不小心自杀了，要重来吗?"),TEXT("游戏结束"),1);
		if(x==1)
		{
			Init(plink);
			food=0;
			foodtype=1;
			direction=2;
			speed=150;
			Sleep(500);
			SetTimer(hwnd,1,speed,NULL);
    		SetTimer(hwnd,2,3000,NULL);
   		    SetTimer(hwnd,3,1000,NULL);
   		    free(prect);
   		    free(prect2);
   		    free(prect3);
		}
		else
		{
		PostQuitMessage(0);	
		}
}
/*WinMain function and WndProc function*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) 
	{
        case WM_TIMER:
			{
				switch(wParam)
				{
				case 1:
				{	
					hdc=GetDC(hwnd);
					itoa(score,score_c,10);
					TextOut(hdc,46,6,score_c,strlen(score_c));
					ReleaseDC(hwnd,hdc);	
				switch(direction)
				{
					case LEFT:        /*the reaction after pressing the vk_left key on the keyboard*/
					hdc=GetDC(hwnd);
        			ShowSnake(hdc);
					if(Check_Crash(plink)==1)
			        GameOver(hwnd,hdc,plink);
					InvalidateRect(hwnd,Move_Left(plink),TRUE);
					EatFood(foodpos);
					ShowSnake(hdc);
        			ReleaseDC(hwnd,hdc);
					break;
					case RIGHT:       /*the reaction after pressing the vk_right key on the keyboard*/
					hdc=GetDC(hwnd);
        			ShowSnake(hdc);
					if(Check_Crash(plink)==1)
					GameOver(hwnd,hdc,plink);
					InvalidateRect(hwnd,Move_Right(plink),TRUE);
					EatFood(foodpos);
					ShowFood(hdc);
        			ReleaseDC(hwnd,hdc);
					break;
					case UP:          /*the reaction after pressing the vk_up key on the keyboard*/
					hdc=GetDC(hwnd);
        			ShowSnake(hdc);
					if(Check_Crash(plink)==1)
					GameOver(hwnd,hdc,plink);
					InvalidateRect(hwnd,Move_Up(plink),TRUE);
					EatFood(foodpos);
					ShowFood(hdc);
        			ReleaseDC(hwnd,hdc);
					break;
				    case DOWN:        /*the reaction after pressing the vk_down key on the keyboard*/
				    hdc=GetDC(hwnd);
        			ShowSnake(hdc);
					if(Check_Crash(plink)==1)
					GameOver(hwnd,hdc,plink);
					InvalidateRect(hwnd,Move_Down(plink),TRUE);
					EatFood(foodpos);
					ShowFood(hdc);
        			ReleaseDC(hwnd,hdc);
				    break;
				}
				break;		
				}	
				case 2:
				speed-=1;
				if(speed<=30) speed=30;
				SetTimer(hwnd,1,speed,NULL);
				break;
				case 3:
				dscore--;
				if(dscore<=1) dscore=1;
				break;
				}
				break; 
			}
		case WM_KEYDOWN:
		{
			switch(wParam)
		{
			case VK_RIGHT:
			if(direction!=1&&direction!=2) direction=2;
			break;
			case VK_LEFT:
			if(direction!=1&&direction!=2) direction=1;
			break;
			case VK_UP:
			if(direction!=3&&direction!=4) direction=3;
			break;
			case VK_DOWN:
			if(direction!=3&&direction!=4) direction=4;
			break;
		}
		break;
		}
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			KillTimer(hwnd,1);
			break;
		}
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}
 
/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX 	wc; /* A properties struct of our window */
	HWND 		hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG 		msg; /* A temporary location for all messages */
	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */
 
	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
 
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Hello,Snake!",WS_VISIBLE|WS_OVERLAPPEDWINDOW&~WS_MAXIMIZEBOX&~WS_MINIMIZEBOX,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		300, /* width */
		400, /* height */
		NULL,NULL,hInstance,NULL);
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
    SetTimer(hwnd,1,speed,NULL);
    SetTimer(hwnd,2,3000,NULL);
    SetTimer(hwnd,3,1000,NULL);
    InitRect(sr);
   	Init(plink);
   	score_c=(char*)malloc(sizeof(char)*4);
   	hdc=GetDC(hwnd);
   	MoveToEx(hdc,0,25,NULL);
   	LineTo(hdc,300,25);
   	Rectangle(hdc,250,7,270,18);
   	PRECT rect=(PRECT)malloc(sizeof(RECT));
   	rect->left=260;
   	rect->top=7;
   	rect->right=270;
   	rect->bottom=17;
   	FillRect(hdc,rect,(HBRUSH)GetStockObject(BLACK_BRUSH));
   	TextOut(hdc,184,6,TEXT("8:00 AM"),7);
   	MoveToEx(hdc,151,18,NULL);
   	LineTo(hdc,151,16);
   	MoveToEx(hdc,154,18,NULL);
   	LineTo(hdc,154,14);
   	MoveToEx(hdc,157,18,NULL);
   	LineTo(hdc,157,10);
   	MoveToEx(hdc,160,18,NULL);
   	LineTo(hdc,160,8);
   	TextOut(hdc,162,6,TEXT("4G"),2);
   	TextOut(hdc,3,6,TEXT("score:"),6);
   	TextOut(hdc,80,6,TEXT("best:"),5);
   	best=ReadBest();
   	TextOut(hdc,117,6,best,strlen(best));
   	ReleaseDC(hwnd,hdc);
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}