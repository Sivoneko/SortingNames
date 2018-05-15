#pragma once
//#include <string>
#include <random>
using namespace std;
//����� � ������� ����� ��������� ���� ����
template<typename T, typename T2>
class Sort
{
protected:
	int count;
	struct NameOnly
	{
		T2 Name;
		NameOnly* NEXT;
	};
	NameOnly* NEXT;
public:
	Sort() { NEXT = NULL; }

	//����������� ���������� �����
	void Push(T2 vvod)
	{
		NameOnly* pv = new NameOnly;
		pv->Name = vvod;
		pv->NEXT = NEXT;
		NEXT = pv;
	}
	T2 Pop()
	{
		T2 temp = NEXT->Name;
		NameOnly* pv = NEXT;
		NEXT = NEXT->NEXT;
		delete pv;
		return temp;
	}
	
	//������� ���������� �����
	void QuickSort(T* arr, int l, int r)
	{
		if (l < 0 || r < 0) throw "Wrong index!";
		int i, j;
		i = l;
		j = r;
		T middle = (arr[(l + r) / 2]);
		//T2 middle = arr[l];
		do
		{
			while (middle > arr[i]) i++;
			while (middle < arr[j]) j--;

			if (i <= j)
			{
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		} while (i < j);

		if (i < r) QuickSort(arr, i, r);
		if (j > l) QuickSort(arr, l, j);
	}

	virtual ~Sort()
	{
		delete[] NEXT;
	}

};

//�����, � ������� ��������� ����������� ������ ��������� ������������  
template<typename T, typename T2>
class New : public Sort<T, T2>
{
protected:
	struct Stek
	{
		T2 name;
		int number;
		Stek* next;
		Stek* prev;
	};
	Stek* next;
	Stek* prev;
	T* mass;
public:
	New() :Sort() { next = NULL; prev = NULL; mass = NULL; }

	//���������� ������������ ������ ��������� ���� � ��������� ������
	void add(int Number)
	{
		if (Number == 0)
			throw "You can't add something";
		for (int i(0); i < Number; i++)
		{
			T2 vvod;
			int number;
			cout << "Enter name: ";
			cin.get();
			getline(cin, vvod);

			Sort<T, T2>::Push(vvod);

			bool good = true;
			do
			{
				cout << "Enter number: ";
				cin >> number;
				if (!(good = cin.good()))
					cout << "Wrong input!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (!good);

			

			Stek *pv = new Stek;
			pv->number = number;
			pv->name = vvod;
			Sort<T, T2>::Pop();
			if (i == 0)
			{
				pv->next = 0;
				pv->prev = 0;
				next = pv;
				prev = next;
			}
			else
			{
				pv->next = 0;
				pv->prev = prev;
				prev->next = pv;
				prev = pv;
			}
		}
	}

	Stek** getNext()
	{
		return *next;
	}
	Stek** getPrev()
	{
		return *prev;
	}

	//������ ��� ������������ ������, � �� �������� ����������� ��������
	void Delete()
	{
		while (next != NULL)
		{
			Stek* temp = next;
			next = next->next;
			delete temp;
		}
	}

	//���������� (������ �� �����������) - �� ����� �������
	void Sortir()
	{
		if (!next || !next->next)
			throw "Nothing to sort :(";

		Stek * list = next; // ��������� ������
		Stek * node, *node2;
		for (node = list; node; node = node->next)
			for (node2 = list; node2; node2 = node2->next)
				if (node->name > node2->name) { // ���� ����� �� node ������ ����� �� node2 �� ������������ ��
					T2 i = node->name;
					int j = node->number;
					node->name = node2->name;
					node->number = node2->number;
					node2->name = i;
					node2->number = j;
				}
	}

	void sort() {
		//��������� ������ �� �������� (�������, ���� f) � ����������
		//��������� �� ������ ����������� ������
		Stek* ph = next;
		Stek *q, *out = NULL, *p, *pr; //out - ����� - ������� ����
		while (ph != NULL) { //���� �� ����� �������� ������
			q = ph; ph = ph->next; //��������� ��������� �������
			for (p = out, pr = NULL; p != NULL && (q->name > p->name); pr = p, p = p->next)
			{
			
			}
		
			//����, ���� �������� ��������� ������� - ��� strcmp
			//������ �������� ��������� ���������, � ����� ������ �.�. ������
			if (pr == NULL) { q->next = out; out = q; } //��������� � ������
			else { q->next = p; pr->next = q;  } //��� ����� �����������
		}
		next = out;
	}


	//����������� �����
	friend ostream& operator<<(ostream& os, Stek& kek)
	{
		while (kek.next)
		{
			cout << kek.name << " " << kek.number << endl;
			kek.next = kek.next->next;
		}
		return os;
	}

	friend ostream& operator<<(ostream& os, New& kek)
	{
		while (kek.next != NULL)
		{
			cout << kek.next->name << " " << kek.next->number << endl;
			kek.next = kek.next->next;
		}
		return os;
	}

	virtual ~New()
	{
		New <T, T2>::Delete();
	}
};
