#include<iostream>
#include<string>
#include <windows.h>
using namespace std;
void DisplayMall() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "-----------------------------------------------------------------------\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "\t\t\tTHE SHOPPING MALL\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "-----------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void StoreList() {
	cout << "\n\tList of stores:\n\t1. BOOKSTORE\n\t2. SHOESTORE\n\t3. JEWELLERYSTORE\n";
}
int ValidateInput(int s, int e) {
	int ch;
	do {
		cout << "\n\nEnter your choice : ";
		cin >> ch;
		cin.clear();
		cin.ignore();
		if (ch < s || ch > e)
			cout << " Invalid Option.";
	} while ((ch < s || ch > e));
	system("cls");
	return ch;
}
class Item {
	string name;
	int ID;
	int sID;
	float price;
public:
	Item() {
		name = " ";
		ID = 0;
		sID = 0;
		price = 0.0f;
	}
	Item(string name,int ID,int sID,float price) {
		this->name = name;
		this->ID = ID;
		this->sID = sID;
		this->price = price;
	}
	void setname(string n){
		name = n;
	}
	void setID(int id){
		ID = id;
	}
	void setsID(int id){
		sID = id;
	}
	void setPrice(float p){
		price = p;
	}
	string getname(){
		return name;
	}
	int getID(){
		return ID;
	}
	int getsID(){
		return sID;
	}
	float getPrice(){
		return price;
	}
	void ShowAnItem() {
		cout << getID() << ") " << getname() << '\t' << getPrice() << endl;
	}
};
class ShoppingCart {
	int item_no;
	Item list[20];
	int index;
public:
	ShoppingCart() {
		item_no = index = 0;
	}
	void setCart(ShoppingCart cart) {
		item_no = index = 0;
		for (int i = 0; i < item_no; i++) {
			list[i].setname(" ");
			list[i].setID(0);
			list[i].setsID(0);
			list[i].setPrice(0.0f);
		}
	}
	int getItem_no() {
		return item_no;
	}
	int getIndex() {
		return index;
	}
	Item getItem(int i) {
		return list[i];
	}
	void AddItem(Item &new_item) {
		if (index < 20) {
			list[index].setname(new_item.getname());
			list[index].setID(new_item.getID());
			list[index].setsID(new_item.getsID());
			list[index].setPrice(new_item.getPrice());
			index++;
			item_no++;
			cout << "\n\n\t\tAdded to cart.\n\n";
		}
		else
			cout << "\ncart full" << endl;
	}
	void RemoveItem(Item &del_item) {
		int d = found(del_item);
		if (d == -1)
			cout<< "\n\n\t\titem doesn't exist in the cart.\n";
		else {
			list[d] = list[index-1];
			index--;
			item_no--;
			cout << "\n\n\t\tRemoved from cart.\n";
		}
	}
	int found(Item &key) {
		for (int i = 0; i < item_no ; i++) {
			if (list[i].getname() == key.getname() && list[i].getID() == key.getID() && list[i].getsID() == key.getsID() && list[i].getPrice() == key.getPrice())
				return i;
		}
		return -1;
	}
	void ShowCart() {
		if (index == 0)
			cout << "\tcart is empty.\n";
		else {
			cout << "\n\tITEMS IN THE CART:\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			cout << "ID    Name\t\tPrice\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			for (int i = 0; i < item_no; i++)
					cout << list[i].getID() << ")   " /*<< list[i].getID()*/ << list[i].getname()  << '\t' << list[i].getPrice() << endl;
		}
	}
};
class Customer {
	string name;
	string store;
	ShoppingCart cart;
public:
	Customer() {
		this->store = "no store";
	}
	void setname(string name) {
		this->name = name;
	}
	void setstore(string store) {
		this->store = store;
	}
	ShoppingCart * getCart() {
		return &cart;
	}
	string getname() {
		return name;
	}
	string getstore() {
		return store;
	}
	void showCustomer() {
		cout << "\n   Name: " << name << endl;
		cout << "   in " << store << endl;
		cout << "   Items in cart:" << endl;
		cart.ShowCart();
	}
};
class Store {
private:
	string sName;
	int sID;
	Item items[5];
protected:
	Customer *c;
public:
	Store(string name, int sID) {
		this->sName = name;
		this->sID = sID;
		if (sID == 1) {
			this->setStoreItem(Item("The Alchemist  ", 1, 1, 60.4f), 0);
			this->setStoreItem(Item("The Kite Runner", 2, 1, 40.50f), 1);
			this->setStoreItem(Item("The Outsiders  ", 3, 1, 70.00f), 2);
			this->setStoreItem(Item("Divergent      ", 4, 1, 80.25f), 3);
			this->setStoreItem(Item("Fangirl        ", 5, 1, 45.00f), 4);
		}
		else if (sID == 2) {
			this->setStoreItem(Item("Black Wedges   ", 1, 2, 120.00f), 0);
			this->setStoreItem(Item("White Canvas   ", 2, 2, 100.50f), 1);
			this->setStoreItem(Item("Red FlipFlops  ", 3, 2, 80.20f), 2);
			this->setStoreItem(Item("Grey Boots     ", 4, 2, 140.00f), 3);
			this->setStoreItem(Item("Pink Heels     ", 5, 2, 150.30f), 4);
		}
		else if (sID == 3) {
			this->setStoreItem(Item("Bangles        ", 1, 3, 50.30f), 0);
			this->setStoreItem(Item("Earings        ", 2, 3, 80.00f), 1);
			this->setStoreItem(Item("Necklace       ", 3, 3, 60.75f), 2);
			this->setStoreItem(Item("Rings          ", 4, 3, 20.45f), 3);
			this->setStoreItem(Item("Anklet         ", 5, 3, 40.05f), 4);
		}
	}
	int getS_ID() {
		return sID;
	}
	Item getAnItem(int id) {
		for (int i = 0; i < 5; i++) 
			if (id == items[i].getID()) 
				return items[i];
		return Item();
	}
	void setStoreItem(Item item, int i) {
		this->items[i].setname(item.getname());
		this->items[i].setID(item.getID());
		this->items[i].setsID(item.getsID());
		this->items[i].setPrice(item.getPrice());
	}
	void EnumerationItems() {
		cout << "\nItems available in the " << sName << " are: \n";
		for (int i = 0; i < 5; i++)
			cout << items[i].getID() << ") " << items[i].getname() << '\t' << items[i].getPrice() << endl;
	}
	void EnumerationCustomers() {
		cout << "There are 1 customer(s) present in the mall.\n";
	}
	void checkout(Customer &c) {
		system("cls");
		DisplayMall();
		c.getCart()->ShowCart();
		float sum = 0;
		for (int i = 0; i < (*c.getCart()).getItem_no(); i++)
			sum = sum + ((*c.getCart()).getItem(i)).getPrice();
		if (sum != 0) {
			cout << "-------------------------------------";
			cout << "\n\tTotal  :  " << sum << endl << endl;
		}
		(*c.getCart()).setCart(ShoppingCart());
		cout << "\n\t";
		system("pause");
		system("cls");
		DisplayMall();
		cout << "\n\n    THANKYOU FOR SHOPPING AT THE STORE!!\n\n";
	}
	virtual void Enter(Customer &c) = 0;
	virtual void Exit(Customer &c) = 0;
	virtual void addToCart(ShoppingCart cart, Item obj) = 0;
	virtual void removeFromCart(ShoppingCart cart, Item obj) = 0;
};
class BookStore : public Store {
public:
	BookStore() : Store("BOOKSTORE", 1) {
	}
	virtual void addToCart(ShoppingCart cart, Item obj) {
		cart.AddItem(obj);
	}
	virtual void removeFromCart(ShoppingCart cart, Item obj) {
		cart.RemoveItem(obj);
	}
	virtual void Enter(Customer &c) {
		c.setstore("BOOKSTORE");
		this->c = &c;
		cout << "\tWelcome to the BOOKSTORE, " << c.getname() << endl;
	}
	virtual void Exit(Customer &c) {
		c.setstore("no store");
		this->c = NULL;
		checkout(c);
	}
};
class ShoeStore : public Store {
public:
	ShoeStore() : Store("SHOESTORE", 2) {
	}
	virtual void addToCart(ShoppingCart cart, Item obj) {
		cart.AddItem(obj);
	}
	virtual void removeFromCart(ShoppingCart cart, Item obj) {
		cart.RemoveItem(obj);
	}
	virtual void Enter(Customer &c) {
		c.setstore("SHOESTORE");
		this->c = &c;
		cout << "\tWelcome to the SHOESTORE, " << c.getname() << endl;
	}
	virtual void Exit(Customer &c) {
		c.setstore("no store");
		this->c = NULL;
		checkout(c);
	}
};
class JewelleryStore : public Store {
public:
	JewelleryStore() : Store("JEWELLERYSTORE", 3) {
	}
	virtual void addToCart(ShoppingCart cart, Item obj) {
		cart.AddItem(obj);
	}
	virtual void removeFromCart(ShoppingCart cart, Item obj) {
		cart.RemoveItem(obj);
	}
	virtual void Enter(Customer &c) {
		c.setstore("JEWELLERY STORE");
		this->c = &c;
		cout << "\tWelcome to the JEWELLERYSTORE, " << c.getname() << endl;
	}
	virtual void Exit(Customer &c) {
		c.setstore("no store");
		this->c = NULL;
		checkout(c);
	}
};
class Mall {
	string name;
	Customer cus;
	Store *s;
public:
	Mall() {
		name = "THE SHOPPING MALL\n";
	}
	~Mall() {
		delete s;
	}
	ShoppingCart getShoppingCart() {
		return ShoppingCart();
	}
	void EnumerationCustomers() {
		cout << "There are 1 customer(s) present in the mall.\n";
	}
	void ExitMall() {
		cout << "\n\n    THANKYOU FOR VISITING THE MALL...!!\n\n";
	}
	void EnterStore(int s) {
		int chs, ch, id;
		if (s == 1)
			this->s = new BookStore();
		else if (s == 2)
			this->s = new ShoeStore();
		else if (s == 3)
			this->s = new JewelleryStore();
		this->s->Enter(cus);
		while (true) {
			cout << "\n\t1. Get list of items available for sale at the store.\n\t2. View Store ID.\n\t3. View the total Customers in the store.\n\t4. View your details. \n\t5. Get an Empty Shopping cart. \n\t6. Exit the store.";
			ch = ValidateInput(1, 6);
			DisplayMall();
			if (ch == 1) {
				this->s->EnumerationItems();
				cout << "\n\n\t1. Add item in the cart.\n\t2. Remove item from cart.\n\t3. View the total Customers in the store.\n\t4. View your details. \n\t5. Get an Empty Shopping cart. \n\t6. Exit the store.";
				chs = ValidateInput(1, 6);
				DisplayMall();
				this->s->EnumerationItems();
				if (chs == 1 || chs == 2) {
					id = ValidateInput(1, 5);
					DisplayMall();
					if (chs == 1) 
						(*cus.getCart()).AddItem(this->s->getAnItem(id));
					if (chs == 2) 
						(*cus.getCart()).RemoveItem(this->s->getAnItem(id));
					cout << "\n\t";
					system("pause");
				}
				else if (chs == 3)
					ch = 3;
				else if (chs == 4)
					ch = 4;
				else if (chs == 5)
					ch = 5;
				else if (chs == 6)
					ch = 6;
				system("cls");
				DisplayMall();
			}
			if (ch == 2) {
				cout << "\t\tStore Id is: "<<this->s->getS_ID()<<"\n";
				cout << "\n";
				system("pause");
			}
			if (ch == 3) {
				cout << "\t\t";
				this->s->EnumerationCustomers();
				cout << "\n\t";
				system("pause");
			}
			if (ch == 4) {
				cus.showCustomer();
				cout << "\n\n";
				system("pause");
			}
			if (ch == 5) {
				cout << '\n';
				cout << "YOUR CART IS EMPTY NOW.\n";
				(*cus.getCart()).setCart(this->getShoppingCart());
				cout << "\n\t";
				system("pause");
			}
			if (ch == 6) {
				system("cls");
				DisplayMall();
				this->s->Exit(cus);
				cout << "\n\t";
				system("pause");
				break;
			}
			system("cls");
			DisplayMall();
		}
	}
	void EnterMall() {
		DisplayMall();
		string name;
		cout << "\n\tPlease enter your name: ";
		getline(cin, name);
		cus.setname(name);
		system("cls");
		StartMall();
	}
	void StartMall() {
		int ch, choice, s;
		while (true) {
			system("cls");
			DisplayMall();
			cout << "\n\t1. View Available Stores. \n\t2. Get an Empty Shopping Cart. \n\t3. View Total customers in the mall. \n\t4. View your details. \n\t5. Exit the mall.\n";
			ch = ValidateInput(1, 5);
			DisplayMall();
			if (ch == 1) {
				StoreList();
				cout << "\n   1. Enter a store.\n   2. Get an Empty Shopping cart.\n   3. View Total customers in the mall. \n   4. View your details. \n   5. Exit the mall.\n";
				choice = ValidateInput(1, 5);
				DisplayMall();
				if (choice == 1) {
					StoreList();
					s = ValidateInput(1, 3);
					DisplayMall();
					EnterStore(s);
				}
				else if (choice == 2)
					ch = 2;
				else if (choice == 3)
					ch = 3;
				else if (choice == 4)
					ch = 4;
				else if (choice == 5)
					ch = 5;
			}
			if (ch == 2) {
				cout << '\n';
				cout << "YOUR CART IS EMPTY NOW.\n";
				(*cus.getCart()).setCart(getShoppingCart());
				cout << "\n\t";
				system("pause");
			}
			if (ch == 3) {
				cout << "\t\t";
				EnumerationCustomers();
				cout << "\n\t";
				system("pause");
			}
			if (ch == 4) {
				cus.showCustomer();
				cout << "\n\n";
				system("pause");
			}
			if (ch == 5) {
				system("cls");
				ExitMall();
				break;
			}
		}
	}
};
int main() {

	Mall mall;
	int ch;

	cout << "\n\n\t1. Enter the mall. \n\t2. Exit the mall\n";
	ch = ValidateInput(1, 2);

	if (ch == 1)
		mall.EnterMall();
	else if (ch == 2)
		mall.ExitMall();

	return 0;
}
