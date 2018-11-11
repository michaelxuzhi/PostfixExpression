#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

char s[100];
int i=0;
typedef struct node
{
    char data;
    struct node *next;
} Node,*LinkList;
LinkList Createzhan1()//��������ջ
{
    LinkList top;
    top=NULL;
    return top;
}
LinkList push(LinkList s,char x)//ջ�в���Ԫ��
{
    LinkList q,top=s;
    q=(LinkList)malloc(sizeof(Node));
    if(!q) return 0;
    q->data=x;
    q->next=top;
    top=q;
    return top;
}
LinkList pop(LinkList s,char &e)//ɾ��ջ��Ԫ��
{
    e=s->data;
    LinkList p=s;
    s=s->next;
    free(p);
    return s;
}
char GetTop(LinkList s)//ȡ��ջ��Ԫ��
{
    return s->data;
}
int precede(char op1, char op2)
{
    if(op1 == ')'&& op2 == '(')
        return 2;
    else if (op1 == '('||op2 == '(' || op2 == '#')
        return 0;
    else if(op1 == ')')
        return 1;
    else if (op1 == '+' || op1 == '-')
    {
        return 1;
    }
    else if (op1 == '*' || op1 == '/')
    {
        if (op2 == '+' || op2 == '-')
            return 0;
        else
            return 1;
    }
}
int isInt(char a)//�ж��ǲ�������
{
    if(a>='0'&&a<='9')
        return 1;
    else  return 0;
}
char to(LinkList optr)//��׺���ʽ���׺
{
    optr=push(optr,'#');//��#������ջ�ף��������
    char c=getchar();//������ʽ���ԡ�#������
    while(c!='#'||GetTop(optr)!='#')
    {
        if(isInt(c))//�������ַ�c�������ַ�����������
        {
            s[i++]=c;
            c=getchar();
        }
        else
        {
            if(c==')')//ȥ����
            {
                while(GetTop(optr)!='(')
                {
                    optr=pop(optr,s[i++]);
                }
                char x;
                optr=pop(optr,x);
                c=getchar();
            }
            else if(!precede(c,GetTop(optr)))//c����ߣ���ջ
            {
                optr=push(optr,c);
                c=getchar();
            }
            else if(precede(c,GetTop(optr)))
            {
                optr=pop(optr,s[i++]);
            }
        }
    }
}
char sum(char a,char t,char b)
{
    int c=a-'0';
    int d=b-'0';
    if(t=='+')
    {
        a=c+d+'0';
        return a;
    }
    else if(t=='-')
    {
        a=c-d+'0';
        return a;
    }
    else if(t=='*')
    {
        a=c*d+'0';
        return a;
    }
    else if(t=='/')
    {
        a=c/d+'0';
        return a;
    }
}
char tosum(LinkList optr)//��׺���ʽ�ļ���
{
    i=0;
    char c=s[i++];
    while(c!='#')
    {
        if(isInt(c))
        {
            optr=push(optr,c);
            c=s[i++];
        }
        else
        {
            char a,b;
            optr=pop(optr,b);
            optr=pop(optr,a);
            optr=push(optr,sum(a,c,b));//������Ӧ���㣬�����ջ
            c=s[i++];
        }
    }
    return GetTop(optr);
}
int main()
{
    LinkList top1;
    top1=Createzhan1();
    to(top1);
    s[i]='#';
    cout<<tosum(top1)-'0'<<endl;
    return 0;
}