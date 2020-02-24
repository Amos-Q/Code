#define _CRT_SECURE_NO_WARNINGS 1
void CheckCapacity(Stack* ps)
{
	if (ps->_capacity == ps->_size)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType *)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
	}
}


void StackInit(Stack* ps)
{
	ps->_a = (STDataType*)calloc(DEFSTACKSIZE, sizeof(STDataType));
	ps->_capacity = DEFSTACKSIZE;
	ps->_size = 0;
}


void StackPush(Stack* ps, STDataType data)
{
	CheckCapacity(ps);


	ps->_a[ps->_size] = data;
	ps->_size++;
}


void StackPop(Stack* ps)
{
	if (ps->_size == 0)
	{
		return;
	}
	ps->_size--;
}


STDataType StackTop(Stack* ps)
{
	if (ps->_size == 0)
	{
		return (STDataType)0;
	}
	return ps->_a[ps->_size - 1];
}


int StackSize(Stack* ps)
{
	return ps->_size;
}


int StackEmpty(Stack* ps)
{
	return ps->_size == 0;
}


void StackDestroy(Stack* ps)
{
	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_size = 0;
		ps->_capacity = 0;
	}
}
void StackPrintf(Stack* ps)
{
	if (ps->_size == 0)
	{
		return;
	}
	for (int i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}

