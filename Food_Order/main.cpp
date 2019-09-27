// FOOD ORDERING SYSTEM

#include "iostream"
#include "conio.h"
#include "string.h"
#include "fstream"
#include "E:\pfxx\Food_Order\paisa1.cpp"
#include "E:\pfxx\Food_Order\paisa2.cpp"
#include "stdlib.h"

using namespace std;

int id_1=1;
int id_2=1;
extern int p1[100],p2[100];
int tt;
extern int total;

class Display_Vg{
	public:
	void display_vg(){
		system("cls");
		cout<<"\nVegetarian Items : "<<endl;
		cout<<"-------------------"<<endl;
		std::string line;
		ifstream file("E:\pfxx\Food_Order\listveg.txt");
		string name1[10];
		int price1[10];
		id_1 = 1;
		if(file.is_open()){
			while(file>>name1[id_1]>>price1[id_1]){
				std::cout<<"["<<id_1<<"] "<<name1[id_1]<<" "<<price1[id_1]<<"\n";
				id_1++;
			}
			file.close();
		}
		else{
			cout<<"Error";
		}
	}
};

class Display_NVg{
	public:
	void display_nvg(){
		system("cls");
		cout<<"\nNon Vegetarian Items : "<<endl;
		cout<<"-----------------------"<<endl;
		std::string line;
		ifstream file("E:\pfxx\Food_Order\listnonveg.txt");
		string name2[10];
		int price2[10];
		int price;
		id_2 = 1;
		if(file.is_open()){
		while(file>>name2[id_2]>>price2[id_2]){
				std::cout<<"["<<id_2<<"] "<<name2[id_2]<<" "<<price2[id_2]<<"\n";
				id_2++;
		}
		file.close();
		}
		else{
			cout<<"Error";
		}
	}
};

class Ordering:public Display_NVg, public Display_Vg{
	private:
		int co;
		char ans;
		int coa,cob;

	public:
		void Order(){
			cout<<"Order"<<endl;
			cout<<"-----"<<endl;

			cout<<"[1] Vegetarian";
			cout<<"\n[2] Non Vegetarian"<<endl;

			cout<<"\nEnter Your Choice : ";
			cin>>co;

			if(co==1){
				Ordering O1;
				O1.Display_Vg::display_vg();
				cout<<"\n\nEnter Your Choice : "<<endl<<"= > ";
				cin>>coa;
				tt=tt+get_v(coa);
				cout<<"\n= > Total : "<<tt;
			}

			else if(co==2){
				Ordering O2;
				O2.Display_NVg::display_nvg();
				cout<<"\n\nEnter Your Choice : "<<endl<<"= > ";
				cin>>cob;
				tt=tt+get_nv(cob);
				cout<<"\n= > Total : "<<tt;
			}
		}
};


class Item:public Display_NVg, public Display_Vg{
	private:
		int ci;
	public:
		void Order(){
			cout<<"[1] Vegetarian";
			cout<<"\n[2] Non Vegetarian"<<endl;

			cout<<"\nEnter Your Choice : ";
			cin>>ci;

			if(ci==1){
				Item X1;
				X1.Display_Vg::display_vg();
			}

			else if(ci==2){
				Item X2;
				X2.Display_NVg::display_nvg();
			}

		}

};

int main(){

	int c1;
	char ans;
	float f_tt;
	char check;

	do{
	system("cls");
	cout<<"FOODIE NEPAL"<<endl;
	cout<<"------------"<<endl;

	cout<<"[1] Item"<<endl;
	cout<<"[2] Order"<<endl;


	cout<<"\nEnter Your Choice : ";
	cin>>c1;

	system("cls");

	if(c1==1){
		cout<<"Items"<<endl;
		cout<<"-----"<<endl;
		Item objItem;
		objItem.Order();
	}

	else if(c1==2){
		Ordering objOrder;

		do{
			objOrder.Order();
			cout<<"\n\nDo you want to order again (y/n) ? "<<endl<<"= > ";
			cin>>ans;
			system("cls");
		}while(ans=='y'||ans=='Y');

		f_tt = tt + (0.13)*tt;

		cout<<"\t\t\t\tBill"<<endl;
		cout<<"\t\t\t\t----"<<endl;
		cout<<"Total : "<<tt<<endl;
		cout<<"VAT : 13%"<<endl;
		cout<<"Total Payment : "<<f_tt<<endl;
		cout<<"\nPress Any Key To Exit ..."<<endl;
		cout<<"\n\n";
		return 0;
	}

	cout<<"\n\nDo you want to continue odrering (y/n) ? "<<endl<<"= > ";
	cin>>check;

	}while(check='y'||'Y');

	return 0;
}
