#include <iostream>
using namespace std;

class Queue
    {
    private:
        int f ,r;
        int size;
        int *arr;
    public:
         Queue(int array_size)
            {
                f = r = -1;
            size = array_size;
            arr = new int[size];
            for(int i=0; i < size; i++){
                 arr[i] = 0;
                }
            }
         ~Queue()
            {
            delete[] arr;
            }
    bool isEmpty()
    {
        if (f == -1 && r == -1){
            return true;
        }
        else {
            return false;
        }
    }
    bool isFull()
    {
        if (r-f == size-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int item)
    {
        if(isFull())
        {
            cout<<"\n Queue Overflow";
            
        }
        else if(isEmpty())
        {
          f = r = 0;
          arr[r] = item;             
        }
        else
        {
            r++;
            arr[r] = item;
        }
        // arr[r] = item;
    }
    int denqueue()
    {
        int denq_value;
       if(isEmpty())
        {
            cout<<"\n No items in the Queue";
            return 0;
        }
        else if(f == r)
        {
            denq_value = arr[f];
            arr[f] = 0;
            f = r = -1;
           return denq_value;
        }
        else
        {
            denq_value = arr[f];
            arr[f] = 0;
            f++;
            return denq_value;
            
        }
    }
    int peek(int pos)
    {
        if(isEmpty())
        {
            cout << "\n Queue Underflow";
            return 0;
        }
        else
        {
            return arr[pos];
        }
        
    }
    void display()
    {
        cout<<"\n ----------Items in Queue-----------\n";
        for(int i=0; i < size; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    int count()
       {
           if (r == -1 && f == -1)
           {
               return 0;
           }
           else
           {
               return (r - f) + 1;
           }
       }    

};

int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin >> size;
    Queue q1(size);
    int option, item, pos,denq;
    do
    {
        cout<<"\n Which option you would like to choose?. Choose 0 to exit. \n";
        cout << "1. isEmpty()" << endl;
        cout << "2. isFull()" << endl;
        cout << "3. Enqueue()" << endl;
        cout << "4. Denqueue()" << endl;
        cout << "5. Display" << endl;
        cout << "6. Count()" << endl;
        cout << "7. ClearScreen" << endl;
  
        cin >> option;
    switch(option)
    {
        case 0:
            break;
        case 1:
            cout<<"\n -------------isEmpty function called--------------------";
            if(q1.isEmpty())
            {
                cout << "\n Queue is Empty.";
            }
            else
            {
                cout << "\n Queue is not Empty.";
            }
            break;
        case 2:
            cout << "\n -------------------isFull function called-----------------";
            if (q1.isFull())
            {
                cout << "\n Queue is Full";
            }
            else
            {
                cout << "\n Queue is not Full.";
            }
            break;
        case 3:
            cout << "\n ----------------------Enqueue function called--------------------";
            cout <<" \n Enter the item to put in the queue: ";
            cin >> item;
            q1.enqueue(item);
            break;
        case 4:
            cout << "\n ------------------------Denqueue function called----------------------";
            denq = q1.denqueue();
            if(denq != 0)
            {
                cout << "\n  Item denqued from the que:  " << denq;
            }     
            break;
        case 5:
            cout << "\n -------------------------Display function called-----------------------";
            q1.display();
            break;
        case 6:
            cout << "\n ---------------------------Count function called------------------------";
            cout << " \n Number of items present in the Queue: " << q1.count();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "\n Enter valid option: "<< endl;
      }
    } while (option != 0);
    
    return 0;
}

