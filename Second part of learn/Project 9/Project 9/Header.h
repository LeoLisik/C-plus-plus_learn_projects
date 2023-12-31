using namespace std;

class LOS
{
private:
	struct node
	{
		int el;
		node* next;
	} *phead;
public:
	LOS();
	~LOS();
	void SetValues();
	void Clearing();
	void DeleteNode(int key);
	void AddElementBefore(int key, int el);
	void AddElementAfter(int key, int el);
	void DisplayList();
};

void LOS::DisplayList() {
	node* t = phead;
	cout << "Состояние списка: ";
	while (t->next != NULL) {
		cout << t->el << " ";
		t = t->next;
	}
	cout << t->el << endl;
}

void LOS::AddElementAfter(int key, int el) {
	node* t = phead->next, * p = t->next;
	while (t->next != NULL) {
		if (t->el == key) {
			t->next = new node;
			t = t->next;
			t->el = el;
			t->next = p;
			break;
		}
		t = t->next;
		p = p->next;
	}
	if (t->el == key) {
		t->next = new node;
		t = t->next;
		t->el = el;
		t->next = p;
	}
}

void LOS::AddElementBefore(int key, int el) {
	node* t = phead->next, * p = phead;
	bool check = false;
	while (t->next != NULL) {
		if (t->el == key) {
			p->next = new node;
			p = p->next;
			p->el = el;
			p->next = t;
			check = true;
			break;
		}
		t = t->next;
		p = p->next;
	}
	if (t->el == key && check == false) {
		p->next = new node;
		p = p->next;
		p->el = el;
		p->next = t;
	}
}

void LOS::DeleteNode(int key) {
	node* t = phead->next, * p = phead;
	while (t->next != NULL) {
		if (t->el == key) {
			p->next = t->next;
			delete t;
			break;
		}
		t = t->next;
		p = p->next;
	}
	if (t->el == key) {
		p->next = NULL;
		delete t;
	}
}

void LOS::Clearing() {
	node* t, * p;
	t = phead->next;
	phead->next = NULL;
	p = t->next;
	while (p->next != NULL) {
		delete t;
		t = p;
		p = t->next;
	}
	delete t;
	delete p;
}

LOS::LOS() {
	phead = new node;
	phead->el = 7777;
	phead->next = NULL;
}

LOS::~LOS() {
	delete phead;
}

void LOS::SetValues() {
	node* t;
	int el;
	t = phead;
	cout << "Введите элементы: ";
	cin >> el;
	while (el != 0) {
		t->next = new node;
		t = t->next;
		t->el = el;
		t->next = NULL;
		cin >> el;
	}
}