#define _CRT_SECURE_NO_WARNINGS 1
#define HEAP_MALLOC(size)    pvPortMalloc(size);
#define HEAP_REALLOC(p,size) realloc(p,size);
#define HEAP_CALLOC(n,size)  calloc(n,size);
#define HEAP_FREE(p)         vPortFree(p);

#define HEAP_MAX_SIZE        100

struct heap_node;
struct heap;

/*
 * ��key�Ƚ�, key_cmp:�����Ҫ�Ƚϵ�key, key_becmp:���Ƚϵ�key
 * ����һ���ڵ㣬��������������һ���ڵ��ֵ����ҪС������ڵ��ֵ
 * ����һ�����㣬��������������һ���ڵ��ֵ����Ҫ��������ڵ��ֵ
 * ����ֵ > 0 : key_cmp > key_becmp
 * ����ֵ = 0 : key_cmp = key_becmp
 * ����ֵ < 0 : key_cmp < key_becmp
*/
typedef int(*heap_keycmp)(struct heap *heap, const void *key_cmp, const void *key_becmp);
/* ���еĽڵ�����ɾ������,�������ڵ�Ϊ��̬����,����Ҫ�ڸú������ͷŽڵ�ռ� */
typedef int(*heap_value_free)(struct heap_node *node);

struct heap_node
{
	void *key;
	void *value;
};

struct heap
{
	int num; /*�����Ѿ��洢��Ԫ�ظ���*/
	struct heap_node  array[HEAP_MAX_SIZE];  /*��*/
	heap_keycmp       keycmp;                /*��key�Ƚ�*/
	heap_value_free   valuefree;             /*�ѽڵ�����ɾ��*/
};

#define OFFSETOF(TYPE,MEMBER) ((unsigned int)&((TYPE *)0)->MEMBER)
#define container(ptr,type,member) ((type *) ((char *)ptr - OFFSETOF(type,member)))