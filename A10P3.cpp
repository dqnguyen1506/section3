#include <bits/stdc++.h>

using namespace std;

bool prob_true(double p)
{
return rand()/(RAND_MAX + 1.0) < p;
}
int main()
{
int time_to_wash;
double prob;
int total_time;
cout << "Seconds to wash one car: " <<endl;
cin>>time_to_wash;
cout << "Probability of customer arrival during a second: "<<endl;
cin>>prob;
cout<< "Total simulation seconds: "<<endl;
cin>>total_time;
  
//For calculating the time where the vehicle might have arrived;
vector<int>v;
for(int i=0;i<=total_time;i++)
{
if(prob_true(prob))
{
v.push_back(i);
}
}
  
//starting from first car
int no_of_cars_serviced = 0;
  
//Last served time
int last_served_time = 0;
if(v.size() > 0)
{
no_of_cars_serviced = 1;
last_served_time = v[0] + time_to_wash;
}
int waiting_time = 0;
for(int i=1;i<v.size(); i++)
{
if(last_served_time > total_time)
break;
if(last_served_time > v[i])
{
waiting_time = waiting_time + (last_served_time - v[i]);
last_served_time = last_served_time + time_to_wash;
no_of_cars_serviced = no_of_cars_serviced + 1;
}
else
{
last_served_time = v[i] + time_to_wash;
no_of_cars_serviced = no_of_cars_serviced + 1;
}
}
cout<<"Customers Serviced is "<<no_of_cars_serviced<<endl;
cout<<"Average waiting time is "<<(waiting_time*1.0)/(no_of_cars_serviced)<<endl;
  
}
