#define _CRT_SECURE_NO_WARNINGS 1
void quickSort(int a[], int left, int right) {
	if (left > right)
		return;
	//��Ŧ��Ԫ��ѡȡΪ����ߡ����м䡢���ұ�����������λ��,ʹ�����ҷֲ���������
	int key;
	int index = 0;
	if (a[left] > a[right] && a[left] < a[(left + right) / 2] || a[left]<a[right] && a[left] > a[(left + right) / 2]) {
		key = a[left];
		index = left;
	}
	else if (a[right] > a[left] && a[right] < a[(left + right) / 2] || a[right]<a[left] && a[right] > a[(left + right) / 2]) {
		key = a[right];
		index = right;
	}
	else {
		key = a[(left + right) / 2];
		index = (left + right) / 2;
	}
	//��key��ֵ���ڵ�һλ
	int temp = a[left];
	a[left] = a[index];
	a[index] = temp;

	//ʵ�ִ����ұ�С�����
	int i = left, j = right;
	while (i < j) {
		while (i<j&&a[j]>key) { j--; }
		if (i < j) {
			a[i++] = a[j];
		}
		while (i < j&&a[i] < key) { i++; }
		if (i < j) {
			a[j--] = a[i];
		}
	}
	//����˳�һ����i==j����Ϊĳ����i����j���ڵȴ�ʱ����һ��++��--����++��--������һ�����ʱ
	//���˳�����ʱ��ȵ��±�λ�þ��ǵȴ��Ų���Ԫ�ص�λ�ã�Ҳ�������Ҫ��keyֵ��λ�á�
	a[i] = key;
	//�ݹ�ش�����ߣ��ݹ�ش����ұ�
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);

}
