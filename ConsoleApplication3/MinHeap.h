
template <typename Type>
class MinHeap {
public:
	MinHeap(Type heap[], int n);
	MinHeap(int size):m_nMaxSize(size > defaultsize?size:defaultsize),m_pheap(new Type[m_nMaxSize]),m_ncurrentsize(0){}
	~MinHeap() {
		delete[] m_pheap;
	}

	bool Insert(const Type item);
	bool Delete(const Type item);
	bool IsEmpty() const {
		return m_ncurrentsize == 0;
	}
	bool IsFull()const {
		return m_ncurrentsize == m_nMaxSize;
	}
	void Print(const int start = 0, int n = 0);

private:
	void Adjust(const int start, const int end);
	static const int defaultsize = 100;
	const int m_nMaxSize;
	Type *m_pheap;
	int m_ncurrentsize;
};

template <typename Type>
void MinHeap<Type>::Adjust(const int start, const int end) {
	int i = start, j = i * 2 + 1;
	Type temp = m_pheap[i];
	while (j <= end) {
		if(j < end && m_pheap[j] > m_pheap[j + 1]){
			j++;
		}
		if (temp <= m_pheap[j]) {
			break;
		}
		else {
			m_pheap[i] = m_pheap[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	m_pheap[i] = temp;
}

template <typename Type>
MinHeap<Type>::MinHeap(Type heap[], int n) :m_nMaxSize(n > defaultsize ? n : defaultsize) {
	m_pheap = new Type[m_nMaxSize];
	for (int i = 0; i < n; i++) {
		m_pheap[i] = heap[i];
	}
	m_ncurrentsize = n;
	int pos = (n - 2) / 2;
	while (pos >= 0) {
		Adjust(pos, n - 1);
		pos--;
	}
}

template <typename Type>
bool MinHeap<Type>::Insert(const Type item) {
	if (m_ncurrentsize == m_nMaxSize) {
		cout << "Heap Full!" << endl;
		return false;
	}
	m_pheap[m_ncurrentsize] = item;
	int j = m_ncurrentsize, i = (j - 1) / 2;
	Type temp = m_pheap[j];
	while(j > 0) {
		if (m_pheap[i] <= temp) {
			break;
		}
		else {
			m_pheap[j] = m_pheap[i];
			j = i;
			i = (j - 1) / 2;
		}
	}
	m_pheap[j] = temp;
	m_ncurrentsize++;
	return true;
}

template <typename Type>
bool MinHeap<Type>::Delete(const Type item) {
	if (0 == m_ncurrentsize) {
		cerr << "Heap Empty!" << endl;
		return 0;
	}
	for (int i = 0; i < m_ncurrentsize; i++) {
		if (m_pheap[i] == item) {
			m_pheap[i] = m_pheap[m_ncurrentsize - 1];
			Adjust(i, m_ncurrentsize - 2);
			m_ncurrentsize--;
			i = 0;
		}
	}
	return 1;
}

template <typename Type>
void MinHeap<Type>::Print(const int start, int n) {
	if (start >= m_ncurrentsize) {
		return;
	}
	Print(start * 2 + 2, n + 1);
	
	cout << m_pheap[start] << endl;
	Print(start * 2 + 1, n + 1);
}
