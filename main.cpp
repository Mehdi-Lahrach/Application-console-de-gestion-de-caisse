#pragma once





//Dans cette application, le client peut commander la nourriture de son choix.Ce dernier est inscrit dans les données du gérant qui peut également suivre et connaître la quantité vendue, le nombre de fois et la quantité vendue de l'aliment.
//Le gérant peut aussi changer le mot de passe de son compte de surveillance et les prix.

#include <iostream>
#include "food.h"
#include "manager.h"
#include "global.h"
#include <string>

// L'utilisateur choisi "Manager" ou "Client".
void ShowHomeApp()
{
    using namespace std;
    cout << "\n\t********** Home **********\n\n";
    cout << "\t\t1. Manager \n\n";
    cout << "\t\t2. Client  \n\n";
    cout << "\t*************************\n\n";
}

//Cette fonction affiche le menu .
void ShowMenu() {
    using namespace std;
    cout << "\n\t**************************** MUNE *****************************\n\n";
    cout << "\n\t*                                                             *\n\n";

    cout << "\n\t*            " << TacosPoulet.getID() << ". " << TacosPoulet.getname() << "               -> " << TacosPoulet.getprice() << " dh           *\n\n";
    cout << "\n\t*            " << TacosViandeHachee.getID() << ". " << TacosViandeHachee.getname() << "        -> " << TacosViandeHachee.getprice() << " dh           *\n\n";
    cout << "\n\t*            " << TacosBeldi.getID() << ". " << TacosBeldi.getname() << "                -> " << TacosBeldi.getprice() << " dh          *\n\n";
    cout << "\n\t*            " << TacosNuggets.getID() << ". " << TacosNuggets.getname() << "              -> " << TacosNuggets.getprice() << " dh           *\n\n";

    cout << "\n\t*                                                             *\n\n";
    cout << "\n\t*            " << PizzaThon.getID() << ". " << PizzaThon.getname() << "                 -> " << PizzaThon.getprice() << " dh           *\n\n";
    cout << "\n\t*            " << PizzaViandeHachee.getID() << ". " << PizzaViandeHachee.getname() << "        -> " << PizzaViandeHachee.getprice() << " dh           *\n\n";
    cout << "\n\t*            " << PizzaFruitDeMer.getID() << ". " << PizzaFruitDeMer.getname() << "         -> " << PizzaFruitDeMer.getprice() << " dh           *\n\n";
    cout << "\n\t*            " << PizzaFromages.getID() << ". " << PizzaFromages.getname() << "             -> " << PizzaFromages.getprice() << " dh           *\n\n";
    cout << "\n\t***************************************************************\n\n";
    cout << "\n\n\n";

}


//Cette fontion prend la commande et calcule le prix total, incremente le compteur de l'aliment et y ajoute le total.
void takeorder(food* f)
{
    int  quantity;
    double total, money, change;
    std::cout << "\n";

    std::cout << "\tHow Much (quantity) : ";
    std::cin >> quantity;
    f->setcounter(quantity);
    total = f->getprice(quantity);;
    Manager1.setamountmoney(total);
    std::cout << "\n\tTotal = " << total << " DH";
    do {
        std::cout << "\n\tPLEASE PAY : ";
        std::cin >> money;
    } while (money < total);

    change = money - total;
    std::cout << "\n\tYour Change is : " << change<<" DH\n";
}

// On a ici le passage de la commande
void clientOrder()
{
    int order;

    std::cout << "\tPlease Enter Your Order  ";
    std::cin >> order;


    if (order == TacosPoulet.getID())
        takeorder(&TacosPoulet);
    else if (order == TacosViandeHachee.getID())
        takeorder(&TacosViandeHachee);
    else if (order == TacosBeldi.getID())
        takeorder(&TacosBeldi);
    else if (order == TacosNuggets.getID())
        takeorder(&TacosNuggets);
    else if (order == PizzaThon.getID())
        takeorder(&PizzaThon);
    else if (order == PizzaViandeHachee.getID())
        takeorder(&PizzaViandeHachee);
    else if (order == PizzaFruitDeMer.getID())
        takeorder(&PizzaFruitDeMer);
    else if (order == PizzaFromages.getID())
        takeorder(&PizzaFromages);
    else
        std::cout << "\tPlease Enter Avalid Order  ";
}

//Cette fonctoin change le prix de la l'aliment
void changePrices(food* f)
{
    double newprice;
    std::cout << "\n\tEnter newprice : ";
    std::cin >> newprice;

    f->setFoodPrice(newprice);
}



void changeFoodProperty(food* f)
{
    std::string newname;
    double newprice;
    std::cout << "\n\tENTER THE NAME : ";
    std::cin >> newname;
    f->setname(newname);
    std::cout << "\n\tENTER THE PRICE : ";
    std::cin >> newprice;
    f->setFoodPrice(newprice);
}

//Cette fonction verifie le mot de passe
bool  CheckPasswordManager()
{

    using namespace std;
    int  Etat, conditionEnter = 0, i = 1;
    std::string birthDay = "21";
    std::string corectpass = Manager1.getpasswd();
    std::string testpass;



    do {

        cout << "\n\tENTER PASSWORD : ";
        cin >> testpass;
        i++;
        Etat = corectpass.compare(testpass);
        if (Etat == 0)
        {
            conditionEnter = 1;
            break;
        }
    } while (i < 4);

    std::cout << "\n";

    if (conditionEnter == 1)
    {
        cout << "\tPASSWORD CORRECT  \n";
        return true;
    }

    else
    {
        cout << "\n\tWhat is the day you were born in : ";
        cin >> birthDay;
        if (birthDay == "21") return true;
        else
        {
            cout << "\n\tWrong answer ";
            return false;
        }
    }
}


// display the amount money the manager has and how many itemes he sold
void displayinfo()
{
    std::cout << "\n\tYour Current Money is " << Manager1.getamountmoney() << " DH \n\n";
    std::cout << "\t" << TacosPoulet.getname() << " SOLD : " << TacosPoulet.getcounter() << "\n\n";
    std::cout << "\t" << TacosViandeHachee.getname() << " SOLD :" << TacosViandeHachee.getcounter() << "\n\n";
    std::cout << "\t" << TacosBeldi.getname() << " SOLD : " << TacosBeldi.getcounter() << "\n\n";
    std::cout << "\t" << TacosNuggets.getname() << " SOLD : " << TacosNuggets.getcounter() << "\n\n";
    std::cout << "\t" << PizzaThon.getname() << " SOLD : " << PizzaThon.getcounter() << "\n\n";
    std::cout << "\t" << PizzaViandeHachee.getname() << " SOLD : " << PizzaViandeHachee.getcounter() << "\n\n";
    std::cout << "\t" << PizzaFruitDeMer.getname() << " SOLD : " << PizzaFruitDeMer.getcounter() << "\n\n";
    std::cout << "\t" << PizzaFromages.getname() << " SOLD : " << PizzaFromages.getcounter() << "\n\n";
}

void displayChoice()
{
    std::cout << "\n\n\t" << TacosPoulet.getname() << "  " << TacosPoulet.getID() << " \n\t" << TacosViandeHachee.getname() << " " << TacosViandeHachee.getID() << "\n\t" << TacosBeldi.getname() << " " << TacosBeldi.getID() << "\n\t" << TacosNuggets.getname() << "  " << TacosNuggets.getID();
    std::cout << "\n\n\t" << PizzaThon.getname() << " " << PizzaThon.getID() << " \n\t" << PizzaViandeHachee.getname() << " " << PizzaViandeHachee.getID() << "  \n\t" << PizzaFruitDeMer.getname() << " " << PizzaFruitDeMer.getID() << " \n\t" << PizzaFromages.getname() << " " << PizzaFromages.getID() << " : ";
}

int main()
{
start:
    int option;
    std::string gotosomewhere;
    std::string newpasswd;

    ShowHomeApp();
    do
    {
        std::cout << "\tManager or Client ?  ";
        std::cin >> option;

    } while (option != 1 && option != 2);

    switch (option)
    {
    case 1:
        if (CheckPasswordManager())
        {
        Back:
            do
            {
                std::cout << "\n\tPress 1 to check info \n";
                std::cout << "\n\tPress 2 to change prices \n";
                std::cout << "\n\tPress 3 to change password \n ";
                std::cout << "\n\tPress 4 to change food properties : ";
                std::cin >> option;
            } while (option < 1 || option > 5);
            switch (option)
            {
            case 1:
                displayinfo();
                std::cout << "\tExit (Y/y) or (N/n) ? : ";
                std::cin >> gotosomewhere;

                if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                else  goto start;

                break;
            case 2:
                std::cout << "\n\tWhich price do want to change  : ";
                displayChoice();
                std::cin >> option;
                switch (option)
                {
                case  1:

                    changePrices(&TacosPoulet);
                    std::cout << "\n\tExit (Y/y) or (N/n) ? : ";
                    std::cin >> gotosomewhere;
                    if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                    else  goto start;
                    break;
                case 2:

                    changePrices(&TacosViandeHachee);
                    std::cout << "n\tExit (Y/y) or (N/n) ? : ";
                    std::cin >> gotosomewhere;
                    if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                    else  goto start;
                    break;
                case 3:

                    changePrices(&TacosBeldi);
                    std::cout << "\n\tExit (Y/y) or (N/n) ? : ";
                    std::cin >> gotosomewhere;
                    if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                    else  goto start;
                    break;
                case 4:
                    changePrices(&TacosNuggets);

                    std::cout << "\n\tExit (Y/y) or (N/n) ? : ";
                    std::cin >> gotosomewhere;
                    if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                    else  goto start;

                    break;
                case 5:
                    changePrices(&PizzaThon);

                    std::cout << "\n\tExit (Y/y) or (N/n) ? : ";
                    std::cin >> gotosomewhere;
                    if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                    else  goto start;

                    break;

                case 6:
                    changePrices(&PizzaViandeHachee);
                    std::cout << "\n\tExit (Y/y) or (N/n) ? : ";
                    std::cin >> gotosomewhere;
                    if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                    else  goto start;

                    break;
                case 7:
                    changePrices(&PizzaFruitDeMer);
                    std::cout << "\n\tExit (Y/y) or (N/n) ? : ";
                    std::cin >> gotosomewhere;
                    if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                    else  goto start;

                    break;
                case 8:
                    changePrices(&PizzaFromages);
                    std::cout << "\n\tExit (Y/y) or (N/n) ? : ";
                    std::cin >> gotosomewhere;
                    if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                    else  goto start;
                default:
                    break;


                }
                break;
            case 3:

                std::cout << "\n\tEnter new password : ";
                std::cin >> newpasswd;
                Manager1.setpasswd(newpasswd);
                std::cout << "\n\tExit (Y/y) or (N/n) ? : ";
                std::cin >> gotosomewhere;
                if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                else  goto start;
            case 4:
                std::cout << "\n\tWhich price do want to change  : ";
                displayChoice();
                std::cin >> option;

                if (option == TacosPoulet.getID())
                    changeFoodProperty(&TacosPoulet);
                else if (option == TacosViandeHachee.getID())
                    changeFoodProperty(&TacosViandeHachee);
                else if (option == TacosBeldi.getID())
                    changeFoodProperty(&TacosBeldi);
                else if (option == TacosNuggets.getID())
                    changeFoodProperty(&TacosNuggets);
                else if (option == PizzaThon.getID())
                    changeFoodProperty(&PizzaThon);
                else if (option == PizzaViandeHachee.getID())
                    changeFoodProperty(&PizzaViandeHachee);
                else if (option == PizzaFruitDeMer.getID())
                    changeFoodProperty(&PizzaFruitDeMer);
                else if (option == PizzaFromages.getID())
                    changeFoodProperty(&PizzaFromages);

                std::cout << "\n\tExit (Y/y) or (N/n) ? : ";
                std::cin >> gotosomewhere;
                if (gotosomewhere == "N" || gotosomewhere == "n") goto Back;
                else  goto start;
                break;
            default:
                break;
            }
        }
        else goto start;
        break;
    case 2:
    Menu:
        ShowMenu();
        clientOrder();

        std::cout << "\n\n\tDo you Want to order anything else ? (Y/y) or (N/n) : ";

        std::cin >> gotosomewhere;

        if (gotosomewhere == "Y" || gotosomewhere == "y") goto Menu;
        else goto start;
        break;


    default:
        break;
    }

    std::cin.get();

    //by : 
     //EL MEHDI LAHRACH
     //BILAL ZOUHAIDI
     //TAHA MOUKHALID
     //ABDELGHAFOUR RAY
}