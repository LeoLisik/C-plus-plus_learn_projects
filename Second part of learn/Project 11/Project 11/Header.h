using namespace std;

class KDS {
private:
	struct node
	{
		int el;
		node* next, *previous;
	} *phead;
public:
	KDS();
	~KDS();
	void SetValues();
	void Clearing();
	void DeleteNode(int key);
	void AddElementBefore(int key, int el);
	void AddElementAfter(int key, int el);
	void DisplayList();
};

void KDS::AddElementAfter(int key, int el) {
	node* t = phead->next;
	bool check = false;
	while (t->next != phead->next && check == false) {
		if (t->el == key) {
			t->previous->next = new node;
			t->previous->next->el = el;
			t->previous->next->previous = t->previous;
			t->previous->next->next = t;
			t->previous = t->previous->next;
			if (t == phead->next->next) {
				while (t->next != phead->next->next) {
					t = t->next;
				}
				t->next = phead->next;
			}
			check = true;
		}
		t = t->next;
	}
	if (t->el == key && check == false) {
		t->previous->next = new node;
		t->previous->next->el = el;
		t->previous->next->previous = t->previous;
		t->previous->next->next = t;
		t->previous = t->previous->next;
	}
}

void KDS::AddElementBefore(int key, int el) {
	node* t = phead->next;
	bool check = false;
	while (t->next != phead->next) {
		if (t->el == key) {
			t->next->previous = new node;
			t->next->previous->next = t->next;
			t->next = t->next->previous;
			t->next->el = el;
			t->next->previous = t;
			check = true;
		}
		t = t->next;
	}
	if (t->el == key && check == false) {
		t->next = new node;
		t->next->el = el;
		t->next->previous = t;
		t->next->next = phead->next;
		phead->next->previous = t->next;
	}
}

void KDS::Clearing() {
	node* t;
	t = phead->next;
	while (t->next != phead->next) {
		t = t->next;
		delete t->previous;
	}
	phead->next = NULL;
	delete t;
}

void KDS::DeleteNode(int key) {
	node* t = phead->next;
	bool check = false;
	while (t->next != phead->next && check == false) {
		if (t->el == key) {
			if (phead->next == t) {
				while (t->next != phead->next) {
					t = t->next;
				}
				t->next = phead->next->next;
				t = phead->next;
			}
			t->previous->next = t->next;
			t->next->previous = t->previous;
			check = true;
			delete t;
			t = phead;
		}
		t = t->next;
	}
	if (t->el == key && check == false) {
		t->previous->next = t->next;
		t->next->previous = t->previous;
		delete t;
	}
}

KDS::KDS() {
	phead = new node;
	phead->next = NULL;
	phead->previous = NULL;
	phead->el = 7777;
}

KDS::~KDS() {
	delete phead;
}

void KDS::SetValues() {
	node* t;
	int el;
	t = phead;
	cout << "Введите элементы: ";
	cin >> el;
	while (el != 0) {
		t->next = new node;
		t->next->previous = t;
		t = t->next;
		t->el = el;
		t->next = phead->next;
		cin >> el;
	}
}

void KDS::DisplayList() {
	node* t = phead->next;
	cout << "Состояние списка: " << phead->el << " ";
	if (t != NULL) {
		while (t->next != phead->next) {
			cout << t->el << " ";
			t = t->next;
		}
		cout << t->el << endl;
	}
}