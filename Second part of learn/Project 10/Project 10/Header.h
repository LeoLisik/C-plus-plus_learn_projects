using namespace std;

class LDS {
private:
	struct node
	{
		int el;
		node* next, * previous;
	} *phead;
public:
	LDS();
	~LDS();
	void SetValues();
	void Clearing();
	void DeleteNode(int key);
	void AddElementBefore(int key, int el);
	void AddElementAfter(int key, int el);
	void DisplayList();
};

void LDS::AddElementAfter(int key, int el) {
	node* t = phead->next;
	bool check = false;
	while (t->next != NULL) {
		if (t->el == key) {
			t->next->previous = new node;
			t->next->previous->next = t->next;
			t->next = t->next->previous;
			t->next->previous = t;
			t->next->el = el;
			check = true;
			break;
		}
		t = t->next;
	}
	if (t->el == key && check == false) {
		t->next = new node;
		t->next->previous = t;
		t = t->next;
		t->el = el;
		t->next = NULL;
	}
}

void LDS::AddElementBefore(int key, int el) {
	node* t = phead->next;
	bool check = false;
	while (t->next != NULL) {
		if (t->el == key) {
			t->previous->next = new node;
			t->previous = t->previous->next;
			t->previous->el = el;
			t->previous->next = t;
			check = true;
			break;
		}
		t = t->next;
	}
	if (t->el == key && check == false) {
		t->previous->next = new node;
		t->previous = t->previous->next;
		t->previous->el = el;
		t->previous->next = t;
	}
}

void LDS::DeleteNode(int key) {
	node* t = phead->next;
	while (t->next != NULL) {
		if (t->el == key) {
			t->previous->next = t->next;
			delete t;
			break;
		}
		t = t->next;
	}
	if (t->el == key) {
		t->previous->next = NULL;
		delete t;
	}
}

void LDS::Clearing() {
	node* t;
	t = phead->next;
	phead->next = NULL;
	while (t->next != NULL) {
		t = t->next;
		delete t->previous;
	}
	delete t;
}

void LDS::SetValues() {
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
		t->next = NULL;
		cin >> el;
	}
}

LDS::LDS() {
	phead = new node;
	phead->previous = NULL;
	phead->next = NULL;
	phead->el = 7777;
}

LDS::~LDS() {
	delete phead;
}

void LDS::DisplayList() {
	node* t = phead;
	cout << "Состояние списка: ";
	while (t->next != NULL) {
		cout << t->el << " ";
		t = t->next;
	}
	cout << t->el << endl;
}
