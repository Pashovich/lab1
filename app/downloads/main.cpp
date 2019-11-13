#include <string>
#include <map>
#include <iostream>
using namespace std;

class IceCream{
    private:
    string flour;
    int balls = 0;
    int price = 0;
    public:
    IceCream(){};
    void setFlour(string flour){
        this->flour = flour;
    }
    string getFlour(){
        return this->flour;
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
    public:
    int balls = 0;
    int type;
    int money = 0;
    IceCream * iceCream = new iceCream;
};

class IceCreamCreator{
    protected:
    IceCream * iceCream;
    public:
    virtual IceCream* createIceCream(string type,int balls, int price){
        this->iceCream = new IceCream;
        cout << "origine\n";
        iceCream->setFlour(type + "with syrope");
        iceCream->setBalls(balls);
        iceCream->setPrice(price * balls);
        return iceCream;
    };
};

class DeluxeIceCreamCreator: public IceCreamCreator {
    private:
    int multiplicator = 10;
    public:
    IceCream* createIceCream(string type,int balls, int price){
        cout << "deluxe\n";
        this->iceCream = new IceCream;
        iceCream->setFlour(type + "with syrope");
        iceCream->setBalls(balls);
        iceCream->setPrice((price + this->multiplicator) * balls);
        return iceCream;
    }
};

class IceCreamShop{
    
    private:
    IceCreamCreator* machine = new IceCreamCreator;
    int types = 4;
    int * prices;
    string * flavour;
    IceCream * makeIceCream(IceCreamCreator * iceMachine,string type,int balls,int price){
        return iceMachine->createIceCream(type,balls,price);
    }

    public:
    IceCreamShop(){
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
    void buyIceCream(Order * order){
        order->iceCream = this->machine->createIceCream(this->flavour[order->type],order->balls,this->prices[order->type]);
        int price = order->iceCream->getPrice();
        if(order->money < price){
            order->iceCream = new IceCream;
            return ;
        }
        cout << price << endl;
        order->money = order->money - price;
    }
};
int main(){
    Order * a = new Order;
    a->type = 0;
    a->balls = 2;
    a->money = 400;
    IceCreamShop b;
    DeluxeIceCreamCreator * machine = new DeluxeIceCreamCreator;
    b.rentDeluxeMachine(machine);
    b.buyIceCream(a);
    cout << a->money;
    return 0;
}