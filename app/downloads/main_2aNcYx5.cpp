#include <string>
#include <map>
#include <iostream>
using namespace std;

class IceCream{
    private:
    string flavour;
    int balls = 0;
    int price = 0;
    public:
    IceCream(){};
    void setFlavour(string flourTemp){
        this->flavour = flourTemp;
    }
    string getFlavour(){
        return this->flavour;
    }
    void setBalls(int balls){
        this->balls = balls;
    }
    int getBalls(){
        return this->balls;
    }
    void setPrice(int price){
        this->price = price;
    }
    int getPrice(){
        return this->price;
    }
};

class Order{
    private:
    int balls = 0;
    int type;
    int money = 0;
    public:
    Order(int type, int money,int balls){
        this->type = type;
        this->money = money;
        this->balls = balls;
    }
    int getType(){
        return this->type;
    }
    int getMoney(){
        return this->money;
    }
    int getBalls(){
        return this->balls;
    }
};

class IceCreamCreator{
    protected:
    IceCream * iceCream;
    int amount = 500;
    public:
    IceCreamCreator(){
        this->iceCream = new IceCream[amount];
    }
    virtual IceCream* createIceCream(string flavour,int balls, int price){
        if (amount != 0){
            iceCream->setFlavour(flavour);
            iceCream->setBalls(balls);
            iceCream->setPrice(price * balls);
            this->amount--;
            return iceCream;
        }
    };
};

class DeluxeIceCreamCreator: public IceCreamCreator {
    protected:
    IceCream * iceCream;
    int amount = 600;
    private:
    int multiplicator = 10;
    public:
    DeluxeIceCreamCreator(){
        this->iceCream = new IceCream[amount];
    }
    IceCream* createIceCream(string flavour,int balls, int price){
        if (amount != 0){
            iceCream[amount-1].setFlavour(flavour + "with syrup");
            iceCream[amount-1].setBalls(balls);
            iceCream[amount-1].setPrice((price + this->multiplicator) * balls);
            this->amount--;
            return &iceCream[amount];
        }
    }
};
class Printer{
    public:
    static void printRecipe(int money, int price, string flavour){
        cout << "Flavour        :" << flavour << endl;
        cout << "Given money    :" << money << endl;
        cout << "Price          :" << price << endl;
        cout << "Change         :" << money - price<< endl;
        cout << "============================"<< endl;
    }
};
class IceCreamShop{
    
    private:
    DeluxeIceCreamCreator* machine;
    int types= 0;
    int * prices;
    string * flavour;

    public:
    IceCreamShop(int types){
        this->types = types;
        this->flavour = new string[this->types];
        this->prices = new int[this->types];
        flavour[0] = "chocolate";
        prices[0] = 100;
        flavour[1] = "watermalon";
        prices[1] = 120;
        flavour[2] = "blueberry";
        prices[2] = 150;
        flavour[3] = "strawberry";
        prices[3] = 110;
    }
    void rentDeluxeMachine(DeluxeIceCreamCreator * machine){
        this->machine  = machine;
    }
    IceCream * buyIceCream(Order * order){
        string flavour = this->flavour[order->getType()];
        int balls = order->getBalls();
        int money = order->getMoney();
        int price = this->prices[order->getType()];
        IceCream * selledIceCream = this->machine->createIceCream(flavour,balls,price);
        int priceOfPrepared = selledIceCream->getPrice();
        if(money < price){
            IceCream * nullIceCream = new IceCream;
            return nullIceCream;
        }
        Printer::printRecipe(money,priceOfPrepared,selledIceCream->getFlavour());
        return selledIceCream;
    }
    
};
int main(){
    Order * a = new Order(0,2,400);
    IceCreamShop b(4);
    DeluxeIceCreamCreator * machine = new DeluxeIceCreamCreator;
    b.rentDeluxeMachine(machine);
    b.buyIceCream(a);
    return 0;
}