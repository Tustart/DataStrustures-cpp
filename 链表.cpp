#include <iostream>
#include <cstdlib>
#include <ctime>
//节点类型
struct Node
{
    int data;
    Node *next;
    Node(int data = 0) : data(data),next(nullptr){}
};


//单链表代码实现
class Clink
{
    private: 
        Node *head; //指向链表的头节点

    public:
        Clink()
        {   
            //给head初始化指向头节点
            head = new Node();
        }
        ~Clink()
        {   
            //节点的释放
            Node *p = head;
            while(p != nullptr)
            {
                Node *temp = p->next;
                delete p;
                p = temp;
            }
        }

    public:
        //链表尾插法
        void InsertTail(int val)
        {
            Node *p = head;
            while(p->next != nullptr)
            {
                p = p->next;
            }

            Node* node = new Node(val);
            p->next = node;
        }
        //链表的头插法
        void InserHead(int val)
        {
            Node *node = new Node(val);
            node->next = head->next;
            head->next = node;         
        }
        //链表打印
        void show()
        {
            Node *p = head->next;
            while(p != nullptr)
            {
                std::cout<< p->data<<"->";
                p = p->next;
            }
        }
        //链表节点的删除
        void Remove(int val)
        {
            Node *p = head->next;
            Node *q = head;
            while(p != nullptr)
            {
                if(p->data == val)
                {
                    q->next = p->next;
                    delete p;
                    return;
                }
                q = p;
                p = p->next;
            }
        }
        //删除所有值为val的节点
        void Allremove(int val)
        {
            Node *p = head->next;
            Node *q = head;
            while(p != nullptr)
            {
                if(p->data == val)
                {
                    q->next = p->next;
                    delete p;
                    //对指针p进行重置
                    p = q->next;
                }
                q = p;
                p = p->next;
            }
        } 
        


};

int main()
{
    Clink link;
    //srand(time(0));
    for(int i = 0;i < 10;i++)
    {
        int val = rand()%100;
        link.InsertTail(val);
        std::cout<< val <<" ";
    }
    std:: cout<< std::endl;
    link.show();
    std::cout<< std::endl;
    Clink relink;
    for(int i = 0;i < 10;i++)
    {
        int val = rand()%100;
        relink.InserHead(val);
        std::cout<< val <<" ";
    }
    std:: cout<< std::endl;
    relink.show();
    std::cout<< std::endl;
    relink.Allremove(26);
    relink.show();
    return 0;

} 