#include <iostream>
#include <fstream>


using namespace std;



class resturant
{
public:
    void menu();
    void login();
    void display();
    void Records();

};


void resturant::menu(){


      system("cls");
      cout<<"\t\t\t----------------------------"<<endl;
      cout<<"\t\t\t| BUN TALK AUTOMATION SYSTEM |"<<endl;
      cout<<"\t\t\t-----------------------------"<<endl;



      cout<<"\t\t\t\t 1.LOGIN"<<endl;
      cout<<"\t\t\t\t 2.VIEW RECORDS"<<endl;
      cout<<"\t\t\t\t 3.HELP"<<endl;
      cout<<"\t\t\t\t 4.EXIT"<<endl;


      int choise;
      cout<<"ENTER YOUR CHOISE=";
      cin>>choise;


      switch(choise){
          case 1:
              login();
              break;
          case 2:
              Records();
              break;
          case 3:
              cout<<"\t\t\t -----------------------------"<<endl;
              cout<<"\t\t\t WELCOME TO THE BUN TALK help"<<endl;
              cout<<"\t\t\t -----------------------------"<<endl;
              cout<<" "<<endl;
              cout<<"\t\t\t If you have any issues please contact us"<<endl;
              cout<<"HOT LINE= 011-xxxxxxx"<<endl;
              cout<<" "<<endl;
              cout<<"\t\t\t Our mail"<<endl;
              cout<<"buntalk@gmail.com"<<endl;
              break;
          case 4:
              cout<<"\t\t\t -----------------------------"<<endl;
              cout<<"\t\t\t HAVE A GOOD DAY WITH BUN TALK"<<endl;
              cout<<"\t\t\t -----------------------------"<<endl;
              break;
          default:
              cout<<"invalid choice."<<endl;

            }



}


void resturant::login() {
    system("cls");
    string username, password;
    string correctUsername = "sandaru";
    string correctPassword = "123";

    cout << "\t\t\t LOGIN TO BUN TALK AUTOMATION SYSTEM" << endl;
    cout << "\t\t\t ENTER YOUR USERNAME: ";
    cin >> username;
    cout << "\t\t\t ENTER YOUR PASSWORD: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        cout << "Login successful. :)" << endl;
        display();
    } else {
        cout << "Invalid username or password. :(" << endl;
    }
}








void resturant::display(){
    fstream file;
    file.open("buntalk_Record.txt", ios::app | ios::out);

    cout<<"\t\t\t-----------DISPLAY ITEMS-----------"<<endl;
    cout<<"\t\t\t-----------------------------------"<<endl;
    cout<<" " <<endl;

    cout<<" 1 . Assorted Pastries"<<"Rs.100/-"<<endl;
    cout<<" " <<endl;

    cout<<" 2.Freshly Baked Breads"<<"Rs.200/-"<<endl;
    cout<<" " <<endl;

    cout<<" 3. Muffins and Scones"<<"Rs.150/-"<<endl;
    cout<<" " <<endl;

    cout<<" 4. Sweet Treats"<<"Rs.200/-"<<endl;
    cout<<" " <<endl;

    cout<<" 5. Quiches and Savory Pastries"<<"Rs.250/-"<<endl;
    cout<<" " <<endl;


    int totalBill ;

    while (true) {
        int itemChoice, quantity;
        cout << "---------------------------------------" << endl;
        cout << "SELECT AN ITEM NUMBER (if you finished press 0 to get the total bill) = ";
        cin >> itemChoice;


        if (itemChoice == 0) {
            cout << "Exiting the code..." << endl;
            break;
        }

        cout << "ENTER THE QUANTITY = ";
        cin >> quantity;

        int itemCost;

        switch (itemChoice) {
            case 1:
                itemCost = 100 * quantity;
                break;
            case 2:
                itemCost = 200 * quantity;
                break;
            case 3:
                itemCost = 150 * quantity;
                break;
            case 4:
                itemCost = 200 * quantity;
                break;
            case 5:
                itemCost = 250 * quantity;
                break;


            default:
                cout << "Invalid item selection." << endl;
                continue;
        }

        totalBill += itemCost;
        cout << "Added to Bill: Rs. " << itemCost << endl;


        file << "item is=" << itemChoice <<" "<< " quantity is=" << quantity<<" "<<"total is="<<totalBill << "\n";
        file<<"---------------------------------------------"<<endl;
        file<<"1 . Assorted Pastries" << " Rs.100/-"<<endl;
        file<<" 2. Freshly Baked Breads" << " Rs.200/-"<<endl;
        file<<" 2. Freshly Baked Breads" << " Rs.150/-"<<endl;
        file<<" 2. Freshly Baked Breads" << " Rs.200/-"<<endl;
        file<<" 2. Freshly Baked Breads" << " Rs.250/-"<<endl;
        file<<"---------------------------------------"<<endl;
    }

    cout << "---------------------------------------" << endl;
    cout << "Your Total Bill: Rs. " << totalBill << endl;

    file.close();
}



void resturant::Records() {
    ifstream readfile("buntalk_Record.txt");
    string line;
    while (getline(readfile, line)) {
        cout << line << endl;
    }
    readfile.close();
}






int main()
{

 resturant project;
    project.menu();

    return 0;
}
