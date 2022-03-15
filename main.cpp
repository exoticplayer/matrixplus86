#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
int*a;
long long sum;
int scale=10;
void recursion(int n)
 {
     if (n == 1)
        return;
     else
     {
         for (int i = 0; i < n / 2; i++)
            a[i]+=a[n-i-1];
         n = n / 2;
         recursion(n);
    }
 }
void init(int N)
{
    sum=0;
    a=new int[N];
    for(int i=0;i<N;i++)
    {
        a[i]=i+1;
    }
}
int main()
{
    ofstream file("C:\\Users\\26937\\Desktop\\bing1.2.txt");
    while(scale<100000)
    {
        init(scale);
        //common
        cout<<"���ݹ�ģΪ"<<scale<<":"<<endl;
        if(scale<1000)
        {
            long long head, tail,freq ;
            QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
            QueryPerformanceCounter((LARGE_INTEGER*)&head);
            int repeat=0;
            while(repeat<100)
            {
                for(int i=0;i<scale;i++)
                sum+=a[i];
                repeat++;
            }
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            double space=(tail-head)*1000.0/(freq*repeat);
            cout<<"ƽ���㷨 "<<space<<endl;

            //cache
            long long head2, tail2;
            QueryPerformanceCounter((LARGE_INTEGER*)&head2);
            repeat=0;
            long sum1 = 0;
            long sum2 = 0;
            while(repeat<100)
            {
                for (int i = 0;i < scale; i += 2)
                {
                    sum1 += a[i];
                    sum2 += a[i + 1];
                }
                sum = sum1 + sum2;
                repeat++;
            }
            QueryPerformanceCounter((LARGE_INTEGER *)&tail2);
            double space1=(tail2-head2)*1000.0/(freq*repeat);
            cout<<"��ʽ�㷨 "<<space1<<endl;
            //�ݹ�
            long long head3, tail3;
            QueryPerformanceCounter((LARGE_INTEGER*)&head3);
            repeat=0;
            while(repeat<100)
            {
                recursion(scale);
                repeat++;
            }
            QueryPerformanceCounter((LARGE_INTEGER *)&tail3);
            double space2=(tail3-head3)*1000.0/(freq*repeat);
            cout<<"��ʽ�㷨 "<<space2<<endl;
            file<<scale<<" "<<space<<" "<<space1<<" "<<space/space1<<endl;
            scale+=200;

        }
        //<1000
        else
        {
            long long head, tail,freq ;
            QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
            QueryPerformanceCounter((LARGE_INTEGER*)&head);
                for(int i=0;i<scale;i++)
                sum+=a[i];

            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            double space=(tail-head)*1000.0/(freq);
            cout<<"ƽ���㷨 "<<space<<endl;

            //cache
            long long head2, tail2;
            QueryPerformanceCounter((LARGE_INTEGER*)&head2);

                long sum1 = 0;
                long sum2 = 0;
                for (int i = 0;i < scale; i += 2)
                {
                    sum1 += a[i];
                    sum2 += a[i + 1];
                }
                sum = sum1 + sum2;

            QueryPerformanceCounter((LARGE_INTEGER *)&tail2);
            double space1=(tail2-head2)*1000.0/(freq);
            cout<<"��ʽ�㷨 "<<space1<<endl;
            //�ݹ�
            long long head3, tail3;
            QueryPerformanceCounter((LARGE_INTEGER*)&head3);
            recursion(scale);

            QueryPerformanceCounter((LARGE_INTEGER *)&tail3);
            double space2=(tail3-head3)*1000.0/(freq);
            cout<<"�ݹ��㷨 "<<space2<<endl;
            file<<scale<<" "<<space<<" "<<space1<<" "<<space/space1<<endl;
            scale+=10000;

        }


    }

    return 0;
}
