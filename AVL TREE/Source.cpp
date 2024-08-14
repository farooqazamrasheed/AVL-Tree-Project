#include"Header.h"


int main()
{
	AVL<int> obj;
	char ch;
	cout << "==========================================" << endl;
	cout << "=            ******************          =" << endl;
	cout << "=            **     MENU     **          =" << endl;
	cout << "=            ******************          =" << endl;
	cout << "=      Press 1 for New Order             =" << endl;
	cout << "=      Press 2 for Display Inorder       =" << endl;
	cout << "=      Press 3 for Display Preorder      =" << endl;
	cout << "=      Press 4 for Display Postorder     =" << endl;
	cout << "=      Press 5 for Height                =" << endl;
	cout << "=      Press 6 for Search                =" << endl;
	cout << "=      Press 7 for Quite                 =" << endl;
	cout << "==========================================" << endl;

	while (true)
	{
		cout << "  Choose Option from above MENU: ";
		cin >> ch;
		if (ch == '1')
		{
			int num;
			cout << "  Enter Order ID: ";
			cin >> num;
			obj.InsertData(num);
			cout << endl;
		}
		else if (ch == '2')
		{
			cout << "  INORDER: ";
			obj.Inorder(); 
			cout << endl << endl;
		}
		else if (ch == '3')
		{
			cout << "  PREORDER: ";
			obj.preorder();
			cout << endl << endl;
		}
		else if (ch == '4')
		{
			cout << "  POSTORDER: ";
			obj.postorder();
			cout << endl << endl;
		}
		else if (ch == '5')
		{
			cout << "  Height is: " << obj.getheight() << endl;
			cout << endl;
		}
		else if (ch == '6')
		{
			int num;
			cout << "  Enter a Number you want to Search: ";
			cin >> num;
			node<int>* find = obj.Search(num);
			{
				if (find == NULL)
				{
					cout << "  --DATA NOT FOUND!!--" << endl;
				}
				else
				{
					cout << "  " << find->data << " is FOUND" << endl;
				}
			}
			cout << endl;
		}
		else if (ch == '7')
		{
			cout << "==========================================" << endl;
			break;
		}
		else
		{
			cout << "  Invalid Input " << endl;
			cout << endl;
		}
	}
	system("pause");
	return 0;
}