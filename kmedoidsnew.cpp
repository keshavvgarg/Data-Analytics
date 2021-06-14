#include <bits/stdc++.h>
using namespace std;

double  calculate_cost(vector<vector<pair<double,double>>>& points_in_cluster,
              vector<pair<double,double>>& cluster_centre,
              vector<double>& x,
              vector<double>& y){
    int n = x.size() - 1, m = cluster_centre.size() - 1, cost = 0;
    cout << "Points \t" << "Distance from medoid 1..2... \n";
       for(int i = 1; i <= n; i++){
           double min_distance = INT_MAX, dis;
           int min_cluster_num;
           
           cout << "( " << (int)x[i] << ", " << (int)y[i] << ") \t"; // coordinate
           for(int j = 1; j <= m; j++){
               dis = abs(x[i] - cluster_centre[j].first) + abs(y[i] - cluster_centre[j].second);
               cout << dis << "\t \t \t";
               if(dis < min_distance){
                   min_distance = dis;
                   min_cluster_num = j;
               }
           }
           cout << "\n";
           cost += min_distance;
           points_in_cluster[min_cluster_num].push_back(make_pair(x[i], y[i]));
       }
       cout << "\n \n";   
        
       cout << "Cost for this arrangement is: " << cost << "\n \n";   
       return cost;
}

int main()
{
   cout << setprecision (2) << fixed;
   cout << "Enter total number of points: \n";
   int n; cin >> n; // n is the number of points
    
   vector<double> x(n + 1, 0);
   vector<double> y(n + 1, 0);
   
   cout << "Enter the points in this format: \n";
   cout << "x1 y1 \n";
   cout << "x2 y2 \n";
   
   for(int i=1;i<=n;i++){
       cin >> x[i] >> y[i];
   }
   
   cout << "Enter number of initial medoids: \n";
   int m, u, v; cin >> m;
   
   vector<vector<pair<double,double>>> points_in_cluster(m + 1);
   vector<pair<double,double>> cluster_centre(m + 1);
   
   cout << "Enter the medoids in this format: \n";
   cout << "x1 y1 \n";
   cout << "x2 y2 \n";
   
   for(int i = 1; i <= m; i++){
       cin >> u >> v;
       cluster_centre[i] = make_pair(u,v);
   }
   
   int total = calculate_cost(points_in_cluster, cluster_centre, x , y); // this function 
   // will give us cost, will save which clusters will have which points
   

    int status = 0;
    cout << "Do you want to replace medoid, -1 if not, 1 if yes: \n";
    cin >> status;
       
    while(status!= -1){
        vector<vector<pair<double,double>>> temp_points_in_cluster(m + 1);
        vector<pair<double,double>> temp_cluster_centre;
        
        temp_cluster_centre = cluster_centre;
         
         cout << "Enter the medoid you want to replace in this format: \n";
         cout << "x1 y1 \n";
         cout << "x2 y2 \n";
         pair<int,int> medoid;
         cin >> medoid.first >> medoid.second;
         
         int temp;
         cout << "Which medoid do you want to replace and try 1, 2, 3.. ? \n";
         cin >> temp;
         temp_cluster_centre[temp] = medoid;
         
         int temp_cost = calculate_cost(temp_points_in_cluster, temp_cluster_centre, x, y);
         if(temp_cost < total){
             cout << "Yes, we can replace medoid " << temp << " with (" << medoid.first << ", " << medoid.second << ")\n";
             cout << "Old_Cost: " << total << "\n";
             cout << "New_Cost: " << temp_cost << "\n";
             total = temp_cost;
             points_in_cluster = temp_points_in_cluster;
             cluster_centre = temp_cluster_centre;
         }
        
        cout << "Do you want to replace medoid, -1 if not, 1 if yes: \n";
        cin >> status;
    }

    return 0;
}
