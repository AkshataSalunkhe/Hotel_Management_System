#include<iostream>
#include<string>
using namespace std;


class node                        // Node Class
{
    node *next;
    string na,adr,eid;
    long int mn;
    int cash;

    public:
    friend class order;            // Friend class order
    node(string name,string add,string email,long int mob,int bill)
    {
        na=name;
        adr=add;
        mn=mob;
        eid=email;
        cash=bill;
        next=NULL;

    }
};

class order 
{
    public:                           //Variables
    node* head;
    node *ptr;
    int bill=0;
    long int mob;
    string name,email,add;
    order()
    {
       head=NULL;
    }

    void enqueue()                    // Enqueue the personal details
    {
        int ch;
        node *temp;
        cout<<"Enter your details"<<endl;
        cout<<"Name :";
        cin>>name;
        cout<<"Email :";
        cin>>email;
        cout<<"Address :";
        cin>>add;
        cout<<"Mobile NO:";
        cin>>mob;
        bill=menu();
        temp=new node(name,add,email,mob,bill);
        {
            if(head==NULL)
            head=temp;
            else
            {
                ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=temp;
            }        
        }
    }
    int dequeue()                   // Order get completed then dequeue the deatils
    {
        
        if (head!=NULL)
        {
            ptr=head;
            cout<<"\n Order Delivered"<<endl;
            cout<<"Customer name : "<<ptr->na<<endl;
            cout<<"Bill : "<<ptr->cash<<endl;
            head=ptr->next;
            delete ptr;  
            return 1;
        }
        else
        {
            cout<<"\n No order to deliver"<<endl;
            return 0;
        }
        
    }
    int menu()                        // Take orders from customers
    {
        int ch,i,j,sw,q;
        do
        {
        cout<<"\n What do you want ? \n Menu :-\n\t1.sweet\n\t2.veg\n\t3.non veg\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            do
            {
                cout<<"\n\t11. Gulabjamun----1000 Rs\n\t12. rasmala----200 Rs \n\t12. rasgulla----10 Rs\n Enter your sweet :-\n"<<endl;
                cin>>sw;
                switch(sw)
                {
                    case 11:
                        cout<<"Your choice is Gulabjamun \n Enter quantity:"<<endl;
                        cin>>q;
                        bill=bill+q*1000;
                        break;
                    case 12:
                        cout<<"Your choice is Rasmala \n Enter quantity:"<<endl;
                        cin>>q;
                        bill=bill+q*200;
                        break;
                    case 13:
                        cout<<"Your choice is Rasgulla \n Enter quantity:"<<endl;
                        cin>>q;
                        bill=bill+q*10;
                        break;
                }
              cout<<"Do you want more sweets - press 1\n If you want other Menu press 2";
              cin>>i;
            }while(i==1);
            break;
            case 2:
            do
            {
                cout<<"\n\t21. Panner pizza ---200\n\t22. Methi paratha --60 \n\t23. Bhendi--20\n enter you sweet"<<endl;
                cin>>sw;
                switch (sw)
                {
                    case 21:
                        cout<<"Your choice is PP \n Enter quantity:"<<endl;
                        cin>>q;
                        bill=bill+q*200;
                        break;
                    case 22:
                        cout<<"Your choice is MP \n Enter quantity:"<<endl;
                        cin>>q;
                        bill=bill+q*60;
                        break;
                    case 23:
                        cout<<"Your choice is BB \n Enter quantity:"<<endl;
                        cin>>q;
                        bill=bill+q*20;
                        break;
                }
              cout<<"Do you want more veg - press 1 \n If you don't want more press 2";
              cin>>i;
            }while(i==1);
            break;
        }
        cout<<"\nFor Main Menu:press 1 \nOtherwise press 2";
		cin>>j;
		}while(j==1);
		cout<<"Bill:"<<bill;
		return bill;
    }
    void feedback()
		    {
		        string ch;
		        cout<<"\n\nHope you enjoyed your meal.\nPlease give rating:\n\t1.***** :Excellent\n\t2.****  :Awesome\n\t3.***   :Good\n\t4.**    :Quite Good\n\t5.*     :Bad";
		        cout<<"\nEnter your Feedback: ";
		        cin>>ch;
		        cout<<"---THANK YOU---";
		    }

};



int main()
{
    order o1;
    int m=0,ch;
    do
    {
    cout<<"\n1. Order\n2. Confirm\n ";
    cin>>ch;
    
    
    switch (ch)
    {
    case 1: 
        o1.enqueue();
        break;
    case 2:
        m=0;
        m=o1.dequeue();
        if(m==1)
        {
            o1.feedback();
        }
        break;
    }
    }while(ch<2);
    return 0;
}
