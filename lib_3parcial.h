
int gotoxy(int x,int y)
{
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X=x;
	dwPos.Y=y;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

int marco()
{
	int i;
	for (i=1;i<=80;i++)
	{
		gotoxy(i,1);
		printf("-");
	}
	for (i=1;i<=80;i++)
	{
		gotoxy(i,24);
		printf("-");
	}
	for (i=1;i<=24;i++)
	{
		gotoxy(1,i);
		printf("-");
	}
	for (i=1;i<=24;i++)
	{
		gotoxy(80,i);
		printf("-");
	}
}


