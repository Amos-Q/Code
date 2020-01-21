#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

/**
 * ��key�Ƚ�, key_cmp:�����Ҫ�Ƚϵ�key, key_becmp:���Ƚϵ�key
 *
 * @return > 0 : key_cmp > key_becmp
 * @return = 0 : key_cmp = key_becmp
 * @return < 0 : key_cmp < key_becmp
 *
 */
static int heap_keycmp_default(struct heap *heap, const void *key_cmp, const void *key_becmp)
{
	return strcmp(key_cmp, key_becmp);
}

/**
 * �����������ڵ�����.
 *
 * @param array: ��
 * @param child: �ڵ��±�
 * @param father: �ڵ㸸�ڵ��±�
 */
static void heap_swap(struct heap_node *array, int child, int father)
{
	struct heap_node temp;

	temp = array[child];
	array[child] = array[father];
	array[father] = temp;
}

/**
 * �󶥶Ѵ������½��жѻ�
 *
 * @param array: ��
 */
static void heapify(struct heap *heap, int start_pos)
{
	int max_pos = start_pos;//���ڵ��2���ӽڵ�3���ڵ��������Ǹ��ڵ��±�,�ӶѶ���ʼ

	while (1)
	{
		/*�ӽڵ�û�г����ѷ�Χ & �ӽڵ�ȸ��ڵ������Ҫ�������ڵ���ӽڵ�λ�ò��������¶ѻ�*/
		if ((start_pos * 2 + 1 < heap->num) && (heap->keycmp(heap, heap->array[start_pos].key, heap->array[start_pos * 2 + 1].key) < 0))
		{
			max_pos = start_pos * 2 + 1;
		}
		if ((start_pos * 2 + 2 < heap->num) && (heap->keycmp(heap, heap->array[max_pos].key, heap->array[start_pos * 2 + 2].key) < 0))
		{
			max_pos = start_pos * 2 + 2;
		}

		if (max_pos == start_pos) break;//���ڵ��±�û�ı䣬˵�����ڵ�������Ľڵ��ˣ�ֹͣ���¶ѻ�
		heap_swap(heap->array, max_pos, start_pos);
		start_pos = max_pos;//�������¶ѻ�
	}
}

/**
 * ��̬����һ����.
 *
 * @return NULL:����ʧ��
 *        !NULL:�����ɹ�
 */
struct heap *heap_creat(heap_keycmp keycmp, heap_value_free valuefree)
{
	struct heap *heap = NULL;
	int i = 0;

	if (keycmp == NULL)
		return NULL;

	/*����ѽṹ�ռ䣬�����±��0 - n-1*/
	heap = HEAP_MALLOC(sizeof(*heap));
	if (heap == NULL)
		return NULL;

	heap->keycmp = keycmp;
	heap->valuefree = valuefree;
	heap->num = 0;
	for (i = 0; i < HEAP_MAX_SIZE; i++)
	{
		heap->array[i].key = NULL;
		heap->array[i].value = NULL;
	}

	return heap;
}

/**
 * ʹ��Ĭ�� key�ȽϺ��� ��̬����һ����.
 *
 * @return NULL:����ʧ��
 *        !NULL:�����ɹ�
 */
struct heap *heap_creat_default(heap_value_free valuefree)
{
	return heap_creat(heap_keycmp_default, valuefree);
}

/**
 * ����в���һ���ڵ�.�������϶ѻ�
 *
 * @param heap: ��
 * @param key: �ؼ�ֵ
 * @param value: �ڵ�����
 *
 * @return 0:����ɹ�
 *        -1:�Ѳ����� �� keyΪ�� �� valueΪ��
 *        -3:����ʧ��
 */
int heap_insert(struct heap *heap, void *key, void *value)
{
	int n = 0;

	if (heap == NULL || key == NULL || value == NULL)
		return -1;

	/*������*/
	if (heap->num >= HEAP_MAX_SIZE)
		return -3;

	heap->array[heap->num].key = key;//���±��0��ʼ
	heap->array[heap->num].value = value;
	heap->num += 1;

	/*1���������Ͻ��жѻ���(n/2 + 1) - nΪҶ�ӽڵ㲻��Ҫ�ѻ�
	 *2��n/2�ڵ�Ϊn�ڵ�ĸ��ڵ㣬n�ڵ�Ϊn/2�ڵ��2���ӽڵ�
	 *3���ӽڵ����0���ӽڵ�ȸ��ڵ�ֵ����������϶ѻ�
	*/
	n = heap->num - 1;
	while ((n > 0) && (heap->keycmp(heap, heap->array[n].key, heap->array[(n - 1) / 2].key) > 0))
	{
		heap_swap(heap->array, n, (n - 1) / 2);//�����ڵ�����ڵ�����
		n = n / 2;//���±�ָ����ڵ㣬�������϶ѻ�
	}
	return 0;
}

/**
 * �󶥶�ɾ�����ڵ�,�������¶ѻ�
 *
 * @param heap: ��
 *
 * @return 0:ɾ���ɹ�
 *        -1:�Ѳ�����
 *        -3:ɾ��ʧ��
 */
int heap_delete_max(struct heap *heap)
{
	if (heap == NULL)
		return -1;

	/*����û������*/
	if (heap->num < 1)
		return -3;

	heap->valuefree(&heap->array[0]);
	heap->array[0] = heap->array[heap->num - 1];
	heap->array[heap->num - 1].key = NULL;
	heap->array[heap->num - 1].value = NULL;
	heap->num--;
	heapify(heap, 0);

	return 0;
}

/**
 * ���������ݵĶѽ��жѻ�
 *
 * @param heap: ��
 *
 * @return 0:���ѳɹ�
 *        -1:�Ѳ�����
 *        -3:����û������
 */
int heap_build(struct heap *heap)
{
	int i = 0;

	if (heap == NULL)
		return -1;

	/*����û������*/
	if (heap->num < 1)
		return -3;

	for (i = heap->num / 2 - 1; i >= 0; i--)
	{
		heapify(heap, i);
	}

	return 0;
}

/**
 * ���������ݵĶѣ��Զѵ����ݽ��д�С��������
 *
 * @param heap: ��
 *
 * @return 0:����ɹ�
 *        -1:�Ѳ�����
 *        -3:����û������
 */
int heap_sort(struct heap *heap)
{
	int num = heap->num;

	if (heap == NULL)
		return -1;

	/*����û������*/
	if (heap->num < 1)
		return -3;

	/*���Ѷ����ݷ����������Ȼ��ӶѶ���ʼ�ѻ�*/
	while (heap->num > 1)
	{
		heap_swap(heap->array, heap->num - 1, 0);//���Ѷ�Ԫ�ط����������
		heap->num--;//Ԫ�ظ�����1,���һ��Ԫ���Ѿ��������˲���Ҫ�ٲ���ѻ�
		heapify(heap, 0);
	}

	heap->num = num;

	return 0;
}

/**
 * ��ն������нڵ�����
 *
 * @param heap: ��
 *
 * @return NULL
 */
void heap_empty(struct heap *heap)
{
	if (heap == NULL || heap->num < 1)
		return;

	/*���Ѷ����ݷ����������Ȼ��ӶѶ���ʼ�ѻ�*/
	for (; heap->num > 0; heap->num--)
	{
		heap->valuefree(&heap->array[heap->num - 1]);
		heap->array[heap->num - 1].key = NULL;
		heap->array[heap->num - 1].value = NULL;
	}
}

/**
 * ���ٶ�
 *
 * @param heap: ��
 *
 * @return NULL
 */
void heap_destroy(struct heap **heap)
{
	heap_empty(*heap);
	HEAP_FREE(*heap);
	*heap = NULL;
}


/*******************************************************************************************
 *                                          ʹ��ʾ��
 *******************************************************************************************/
struct test_node
{
	char key[10];
	char value[10];
};

static int node_value_free_sample(struct heap_node *node)
{
	struct test_node *node_temp = NULL;

	/*����key��test_node�ṹ���е�ƫ�Ƶ�ַ,�ҵ�����������ڵ�ʵ��ָ��Ľṹ���׵�ַ*/
	node_temp = container(node->key, struct test_node, key);
	/*����ڵ���ָ�����ݿռ�Ϊ��̬���������Ҫ�ͷ�*/
	HEAP_FREE(node_temp);
	/*����������ָ������ڴ�Ľڵ�key �� value ��Ϊ��*/
	node->key = NULL;
	node->value = NULL;

	return 0;
}


struct heap *heap_test = NULL;
char heap_node_read[10][10];

void heap_sample(void)
{
	int i = 0, key[10] = { 0 };
	struct test_node *node_temp = NULL;

	heap_test = heap_creat_default(node_value_free_sample);

	for (i = 0; i < 10; i++)
	{
		key[i] = rand() % 10;
	}



	/*���� -- ��ѯ*/
	for (i = 0; i < 10; i++)
	{
		node_temp = HEAP_MALLOC(sizeof(*node_temp));
		memset(node_temp, 0, sizeof(*node_temp));
		sprintf(node_temp->key, "AAA%d", key[i]);
		sprintf(node_temp->value, "%d", key[i]);
		heap_insert(heap_test, node_temp->key, node_temp->value);
	}
	for (i = 0; i < 10; i++)
	{
		memset(heap_node_read[i], 0, 10);
		memcpy(heap_node_read[i], heap_test->array[i].value, 10);
	}




	/*���� -- ��ѯ*/
	heap_sort(heap_test);
	for (i = 0; i < 10; i++)
	{
		memset(heap_node_read[i], 0, 10);
		memcpy(heap_node_read[i], heap_test->array[i].value, 10);
	}




	/*���� -- ��ѯ*/
	heap_build(heap_test);
	for (i = 0; i < 10; i++)
	{
		memset(heap_node_read[i], 0, 10);
		memcpy(heap_node_read[i], heap_test->array[i].value, 10);
	}
	/*���� -- ��ѯ*/
	heap_sort(heap_test);
	for (i = 0; i < 10; i++)
	{
		memset(heap_node_read[i], 0, 10);
		memcpy(heap_node_read[i], heap_test->array[i].value, 10);
	}



	/*��� -- ���� -- ��ѯ*/
	heap_empty(heap_test);
	for (i = 0; i < 10; i++)
	{
		node_temp = HEAP_MALLOC(sizeof(*node_temp));
		memset(node_temp, 0, sizeof(*node_temp));
		sprintf(node_temp->key, "AAA%d", key[i]);
		sprintf(node_temp->value, "%d", key[i] + 10);
		heap_insert(heap_test, node_temp->key, node_temp->value);
	}
	for (i = 0; i < 10; i++)
	{
		memset(heap_node_read[i], 0, 10);
		memcpy(heap_node_read[i], heap_test->array[i].value, 10);
	}



	/*ɾ����� -- ��ѯ*/
	heap_delete_max(heap_test);
	for (i = 0; i < 10; i++)
	{
		memset(heap_node_read[i], 0, 10);
		memcpy(heap_node_read[i], heap_test->array[i].value, 10);
	}

	heap_destroy(&heap_test);
}