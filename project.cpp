#include <bits/stdc++.h>
#define MAX_SIZE 5
using namespace std;

int space = 0;
struct order
{
    int order_id;
    string order_name;
    string order_size;
};

class Queue {
public:
    
    int front, rear;
    order arr[MAX_SIZE];
    Queue() { front = rear = -1; }

    bool isEmpty()
    {
        if (front == rear && front == -1) return 1;
        return 0;
    }

    /*bool isFull()
    {
        if ((rear + 1) % MAX_SIZE == front) return 1;
        return 0;
    }
*/
    bool isFull()
    {
        if(front==0 && rear ==MAX_SIZE-1)
            return true;
        if(front == rear+1)
            return true;
        return false;
    }

    void enqueue(order val)
    {
        if (this->isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        else if(front == -1)
        {
            front++;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
    }

   /* void dequeue()
    {
        if (this->isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        front = (front + 1) % MAX_SIZE;
    }
 */
 void dequeue()
    {
        if(front==-1)
            cout << "Queue is empty" << endl;
        else
        {
            if(front == rear)
                front = rear = -1;
            else
                front = (front + 1)%MAX_SIZE;
        }
    }
    void finish_orders()
    {
    if(this->isEmpty())
    {
        cout << "There is No orders now\n";
        return;
    }
    cout<<"Order finished !\n";
    cout <<"ID : "  << arr[front].order_id << " | Name :" << arr[front].order_name << " | Size : " << arr[front].order_size << "\n";
    dequeue();
    }

    void print_orders()
    {
        if(this->isEmpty())
        {
        cout << "There is No order now\n";
        return;            
        }
        cout << "Current orders are : " << "\n";
        int i = front;
        while(true)
        {
            cout << "Id: " << arr[i].order_id << " | Name: " << arr[i].order_name << " | Size: " << arr[i].order_size << endl;
            if(i == rear) break;
            i =  (i + 1) % MAX_SIZE;
        }
    }

    int remaining_space(){
       return MAX_SIZE-space;
    }
    
};


order place_order(order x){
    //x.order_id++;
    bool check = false;
    string orderName[] = {"","Pizza","Chicken Burger","Beef Burger","Soda"};
    cout<<"Menu\n";
    cout<<"------------\n";
    cout<<"1.Pizza\n";
    cout<<"2.Chicken Burger\n";
    cout<<"3.Beef Burger\n";
    cout<<"4.Soda\n";
    while(check == false)
    {
    int i;
    cin>>i;
    if(i < 1 || i > 4)
    {
        cout<<"Invalid input, try again\n";
    }else
    {
        x.order_name = orderName[i];
        check = true;
    }
    }
    string size[] = {"S","M","L","XL"};
    cout<<"Size\n";
    cout<<"------------\n";
    cout<<"1.S\n";
    cout<<"2.M\n";
    cout<<"3.L\n";
    cout<<"4.XL\n";
    check = false;
    while(check == false)
    {
    int i;
    cin>>i;
    if(i < 1 || i > 4)
    {
        cout<<"Invalid input, try again\n";
    }else
    {
        x.order_size = size[i];
        check = true;
    }
    }

    return x;
};

int main()
{
    Queue q;
    int orderid = 1;
    cout<<"Welcome to Ptizza Restaurant \n";
    bool loop = true;
    while(loop)
    {
        cout<<"1. Place order\n";
        cout<<"2. Finish order\n";
        cout<<"3. Print orders\n";
        cout<<"4. Free order spaces\n";
        cout<<"5. Exist\n";
        int i = 0;
        cin >> i;
        switch(i)
        {
            case 1:
            {
                order X;
                // place_order(X);
                if(q.remaining_space() == 0)
                {
                    cout << "There is no Free space Now !\n";
                    break;
                }
                X.order_id = orderid++;
                q.enqueue(place_order(X));
                //X.order_id = orderid++;
                cout << "Added to queue. \n";
                space++;
                break;
            }
            case 2:
            {
                if(q.remaining_space() == 5)
                {
                    cout<<"There are no orders!\n";
                    break;
                }
                q.finish_orders();
                space--;
                break;
            }
            case 3:
            {
                if(q.remaining_space() == 5)
                {
                    cout<<"There are no orders!\n";
                    break;
                }
                q.print_orders();
                cout << "\n";
                break;
            }
            case 4:
            {
                cout<<"Remaining space : "<<q.remaining_space() << endl;
                break;
            }
            case 5:
            {
                loop = false;
                break;
            }
    }

}
}
