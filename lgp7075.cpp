#include<bits/stdc++.h>
#define int long long
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=b&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=b&&c;i-=d)
using namespace std;
inline int read(){
    char c=0,f=1;int num=0;
    while(c<'0'||c>'9'&&c!='-')((c=getchar())=='-')&&(f=-f);
    while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
    return num*f;
}

const int BC_4713_01_01 = 0,BC_0001_12_31 = 1721423,AD_1582_10_04=2299160, 
    AD_1582_12_31=2299238,AD_1600_12_31=2305813;
const int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int beRun(int y){
    if(y<=1582){
        if(y<0)y=-y-1;
        return y%4==0;
    }
    else return (y%4==0&&y%100!=0||y%400==0);
}
int mday(int y,int m){
    return month[m]+(m==2)*beRun(y);
}
signed main(){
    int q=read();
    while(q--){
        int day=read();
        if(day<=BC_0001_12_31){
            if(day<=365){
                int mn=1,days=0;
                day++;
                for(;day>days+mday(-4713,mn)&&mn<12;)
					days+=mday(-4713,mn++);
                printf("%lld %lld %lld BC\n",day-days,mn,4713);
            }
            else{
                day-=365;
                int fys=(day-1)/1461;
                int lys=(day-1)%1461+1;
                int year=4713-fys*4;
                if(lys<=365)year--;
                else if(lys<=365*2)year-=2,lys-=365;
                else if(lys<=365*3)year-=3,lys-=365*2;
                else year-=4,lys-=365*3;
                int mn=1,days=0;
                day=lys;
                for(;day>days+mday(-year,mn)&&mn<12;)
					days+=mday(-year,mn++);
				printf("%lld %lld %lld BC\n",day-days,mn,year);
            }
        }
        else if(day<=AD_1582_10_04){
            day-=BC_0001_12_31;
            int year=0;
            int fys=(day-1)/1461;
            int lys=(day-1)%1461+1;
            year=year+4*fys;
            if(lys<=365)year++;
            else if(lys<=365*2)year+=2,lys-=365;
            else if(lys<=365*3)year+=3,lys-=365*2;
            else year+=4,lys-=365*3;
            int mn=1,days=0;
            day=lys;
            for(;day>days+mday(year,mn)&&mn<12;)
				days+=mday(year,mn++);
            printf("%lld %lld %lld\n",day-days,mn,year);
        }
        else if(day<=AD_1582_12_31){
            day-=AD_1582_10_04;
            if(day<=17){
                printf("%lld %lld %lld\n",14+day,10,1582);
            }
            else if(day<=17+30){
                printf("%lld %lld %lld\n",day-17,11,1582);
            }
            else printf("%lld %lld %lld\n",day-17-30,12,1582);
        }
        else if(day<=AD_1600_12_31){
            day-=AD_1582_12_31;
            if(day<=365){
                int mn=1,days=0;
                for(;day>days+mday(1583,mn)&&mn<12;)
                    days+=mday(1583,mn++);
                printf("%lld %lld %lld\n",day-days,mn,1583);
            }else if(day<=365+366){
                day-=365;
                int mn=1,days=0;
                for(;day>days+mday(1584,mn)&&mn<12;)
                    days+=mday(1584,mn++);
                printf("%lld %lld %lld\n",day-days,mn,1584);
            }else{
                day-=365+366;
                int fys=(day-1)/1461;
                int lys=(day-1)%1461+1;
                int year=1584+fys*4;
                if(lys<=365)year++;
                else if(lys<=365*2)year+=2,lys-=365;
                else if(lys<=365*3)year+=3,lys-=365*2;
                else year+=4,lys-=365*3;
                int mn=1,days=0;
                day=lys;
                for(;day>days+mday(year,mn)&&mn<12;)
					days+=mday(year,mn++);
				printf("%lld %lld %lld\n",day-days,mn,year);
            }
        }
        else{
            day-=AD_1600_12_31;
            int fhy=(day-1)/146097;
            int lys=(day-1)%146097+1;
            int year=1600+fhy*400;
            if(lys<=36524);
            else if(lys<=2*36524)year+=100,lys-=36524;
            else if(lys<=3*36524)year+=200,lys-=2*36524;
            else year+=300,lys-=3*36524;
            int fys=(lys-1)/1461;
            int lys2=(lys-1)%1461+1;
            year+=fys*4;
            if(lys2<=365)year++;
            else if(lys2<=2*365)year+=2,lys2-=365;
            else if(lys2<=3*365)year+=3,lys2-=2*365;
            else year+=4,lys2-=3*365;
            day=lys2;
            int mn=1,days=0;
            for(;day>days+mday(year,mn)&&mn<12;)
				days+=mday(year,mn++);
            printf("%lld %lld %lld\n",day-days,mn,year);
        }
    }
}