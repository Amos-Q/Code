#define _CRT_SECURE_NO_WARNINGS 1
#define HEAP_MALLOC(size)    pvPortMalloc(size);
#define HEAP_REALLOC(p,size) realloc(p,size);
#define HEAP_CALLOC(n,size)  calloc(n,size);
#define HEAP_FREE(p)         vPortFree(p);

#define HEAP_MAX_SIZE        100

struct heap_node;
struct heap;

/*
 * 堆key比较, key_cmp:传入的要比较的key, key_becmp:被比较的key
 * 任意一个节点，其左子树中任意一个节点的值，都要小于这个节点的值
 * 任意一个几点，其右子数中任意一个节点的值，都要大于这个节点的值
 * 返回值 > 0 : key_cmp > key_becmp
 * 返回值 = 0 : key_cmp = key_becmp
 * 返回值 < 0 : key_cmp < key_becmp
*/
typedef int(*heap_keycmp)(struct heap *heap, const void *key_cmp, const void *key_becmp);
/* 堆中的节点数据删除函数,如果插入节点为动态分配,则需要在该函数中释放节点空间 */
typedef int(*heap_value_free)(struct heap_node *node);

struct heap_node
{
	void *key;
	void *value;
};

struct heap
{
	int num; /*堆中已经存储的元素个数*/
	struct heap_node  array[HEAP_MAX_SIZE];  /*堆*/
	heap_keycmp       keycmp;                /*堆key比较*/
	heap_value_free   valuefree;             /*堆节点数据删除*/
};

#define OFFSETOF(TYPE,MEMBER) ((unsigned int)&((TYPE *)0)->MEMBER)
#define container(ptr,type,member) ((type *) ((char *)ptr - OFFSETOF(type,member)))