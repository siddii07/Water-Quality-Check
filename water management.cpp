#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>
#include<fstream>
fstream f;
class base{
	protected:
	    char name[50];
	    float pH,dis_oxygen,temp;

};
class hardness:protected base{
    public:
    void input_details();
    void show_details();
    void save_details();
    void display_all_details();
	void delete_details();
	void water_suitable();
   	void menu1();
	void menu2();
	};
hardness h;
void hardness::input_details(){
		cout<<"\n\nPlease Enter The Name of The city : ";
		cin>>name;
		cout<<"\nPlease Enter The pH value of the water present in the city : ";
		cin>>pH;
		cout<<"\nPlease Enter The Temperature of the water in celsius : ";
		cin>>temp;
		cout<<"\nPlease Enter The percentage of desolved oxygen present in the water "<<endl;
		cin>>dis_oxygen;
}
void hardness::show_details(){
		cout<<"\n\nName of The city : ";
		cout<<name;
		cout<<"\nThe pH value of the water present in the city : ";
		cout<<pH;
		cout<<"\nThe Temperature of the water : ";
		cout<<temp;
		cout<<" celsius";
		cout<<"\nThe percentage of desolved oxygen present in the water "<<endl;
		cout<<dis_oxygen;
		cout<<"%";}
void hardness::save_details(){
	f.open("water.txt",ios::out|ios::app);
	input_details();
	f.write((char*)&h,sizeof(h));
	f.close();
	cout<<"\n\nThe Details Has Been Saved ";
	//TO ADD ANOTHER CITY
	cout<<endl<<"Do you want to add details of another CITY ?"<<endl;
	cout<<endl<<"[1] Yes\n[2] No\nEnter your choice : ";
	int choice = 0;
	cin>>choice;
	system("cls");
    switch(choice){
    	case 1: save_details();
    	break;
    	case 2: menu1();
		break;
		default: {
			cout<<"You entered an invalid choice!!";
			cout<<endl<<"Enter to go back to menu...";
			menu2();
			break;
		}
	}
}
void hardness::display_all_details(){
	cout<<"\n\n\n\t\tDISPLAYING ALL RECORD !!!\n\n";
	f.open("water.txt",ios::in);
	while(f.read((char*)&h,sizeof(h)))
{
show_details();
	cout<<"\n\n====================================\n";
}
f.close();

	cout<<endl<<"[1] Main Menu\n[0] Exit\nEnter your choice : ";
	int choice= 0;
	cin>>choice;
	system("cls");
    switch(choice){
    	case 1: menu1();
    	break;
    	case 0: exit(0);
		break;
		default:{
			cout<<"You entered an invalid choice!!";
			cout<<"\nEnter to go to the main menu...";
			system("cls");
			menu1();
			break;
		}
	}
}
void hardness::delete_details(){
	string n;
cout<<"\n\nEnter The city name you want to delete details : ";
cin>>n;
f.open("water.txt",ios::in|ios::out);
fstream f2;
f2.open("alter.txt",ios::out);
f.seekg(0,ios::beg);
while(f.read((char*)&h,sizeof(h)))
{
if(name!=n)
{
f2.write((char*)&h,sizeof(h));
}
}
f2.close();
f.close();
remove("water.txt");
rename("alter.txt","water.txt");
cout<<"\n\n\tRecord Deleted ..";

cout<<"\n[1] Main Menu\n[0] Exit\nEnter your choice : ";
	int choice= 0;
	cin>>choice;
    switch(choice){
    	case 1: menu1();
    	break;
    	case 0: exit(0);
		break;
		default: {
			cout<<"You entered an invalid choice!!";
			cout<<endl<<"Enter to go to the main menu...";
			system("cls");
			menu1();
			break;
		}
	}
}
void hardness::water_suitable(){
	system("cls");
	int g=0;
	f.open("water.txt",ios::in);
	while(f.read((char*)&h,sizeof(h)))
	{
		if(pH>=6.4&&pH<=7.5)
		{show_details();
		g=1;
		}
	}
	f.close();
	if(g==1)
	{
		cout<<endl<<endl<<endl<<"\t\t\tTHE WATER OF THESE CITIES ARE SUITABLE FOR DRINKING"<<endl<<endl;
	}
	else if(g==0)
	{
		cout<<endl<<endl<<endl<<"Data of the city does not exist in file whose ph range from 6.5 to 7.5 "<<endl;
	}
	cout<<"\n[1] Main Menu\n[0] Exit\nEnter your choice : ";
	int choice= 0;
	cin>>choice;
    switch(choice){
    	case 1: menu1();
    	break;
    	case 0: exit(0);
		break;
		default: {
			cout<<"You entered an invalid choice!!";
			cout<<"\nEnter to go to the main menu...";
			system("cls");
			menu1();
			break;
		}
	}
}
void hardness::menu1(){
	system("cls");
	int choice;
	cout<<"\t\t\t\t\t\t_______________________"<<endl;
	cout<<"\t\t\t\t\t\tNAGARPALIKA WATER CHECK "<<endl;
	cout<<"\t\t\t\t\t\t-----------------------"<<endl<<endl<<endl;
	cout<<"\t\t\t\t1.CITY DETAILS"<<endl<<"\t\t\t\t2.ADD/REMOVE"<<endl;
	cout<<"\t\t\t\t3.LIST OF CITIES WITH SUITABLE WATER FOR DRINKING"<<endl;
	cout<<"\t\t\t\t4.EXIT"<<endl<<endl;
	cout<<"\t\t\t\tPLEASE ENTER REQUIRED OPTION : ";
	cin>>choice;
	system("cls");
	switch(choice)
	{
			case 1:{
		    display_all_details();
			break;
		}
		case 2:{
			menu2();
			break;
		}
		case 3:{
			water_suitable();
			break;
		}
		case 4:{
			exit(0);
			break;
		}
		default:{
			cout<<endl<<"\t\t\t\tINVALID ENTRY..."<<endl<<endl;
			cout<<"\t\t\t\tREDIRECTING TO MAIN MENU........."<<endl<<endl;
			menu1();
			break;
		}
	}
}
void hardness::menu2(){
	int ch;
	cout<<"\t\t\t\tDETAILS EDITOR"<<endl;
	cout<<"\t\t\t\t==========="<<endl<<endl<<endl;
	cout<<"\t\t1.ADD CITY DETAILS"<<endl;//<<"\t\t2.EDIT ITEM DETAILS"<<endl;
	cout<<"\t\t2.DELETE CITY DETAILS"<<endl<<"\t\t3.BACK TO MAIN MENU"<<endl;
	cout<<"\t\tPLEASE ENTER REQUIRED OPTION : ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case 1:{
		    save_details();
			break;
		}
		case 2:{
			delete_details();
			break;
		}
		case 3:{
			menu1();
			break;
		}
	}
}
main(){
h.menu1();
}

