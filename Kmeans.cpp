// k means and k medoids
#include <bits/stdc++.h>
using namespace std;

int max_iterations = 6; // It will not run for more than 6 iterations

pair<double,double> mean(vector<pair<double, double>>& vect){
        double x = 0, y = 0;
        
        for(int i = 0; i < vect.size(); i++){
            x += vect[i].first;
            y += vect[i].second;
        }
        
        x /= vect.size();
        y /= vect.size();
        
        return make_pair(x,y);
}

#define print(vect) for(int ele: vect) cout << ele << " "; cout << "\n"; 

int main()
{
   cout << setprecision (2) << fixed;
   cout << "Enter total number of points: \n";
   int n; cin >> n; // n is the number of points
    
   double x[n + 1],y[n + 1];
   
   cout << "Enter the points in this format: \n";
   cout << "x1 y1 \n";
   cout << "x2 y2 \n";
   cout << "x3 y3 \n";
   
   for(int i=1;i<=n;i++){
       cin >> x[i] >> y[i];
   }
   
   cout << "Enter number of initial cluster points: \n";
   int m, u, v; cin >> m;
   
   vector<vector<pair<double,double>>> old_points_in_cluster(m + 1);
   vector<pair<double,double>> old_cluster_centre(m + 1, make_pair(-1,-1));
   
   vector<vector<pair<double,double>>> points_in_cluster(m + 1);
   vector<pair<double,double>> cluster_centre(m + 1);
   
   cout << "Enter the points in this format: \n";
   cout << "x1 y1 \n";
   cout << "x2 y2 \n";
   
   for(int i = 1; i <= m; i++){
       cin >> u >> v;
       cluster_centre[i] = make_pair(u,v);
   }
   
   for(int itr = 1; itr <= max_iterations; itr++){
       cout << "ITERATION " << itr << "\n";
       // check if cluster centres same
       bool flag = true;
       for(int i = 1; i <= m ; i++){
           if(old_cluster_centre[i]!=cluster_centre[i]){
               flag = false;
           }
           old_cluster_centre[i] = cluster_centre[i]; // this cluster centre will become old
       }
       
       if(flag){
           cout << "Cluster centres are same, so we stop our k means here \n";
           break;
       }
       
       cout << "Points \t" << "Distance from Cluster center 1... \n";
       for(int i = 1; i <= n; i++){
           double min_distance = INT_MAX, dis;
           int min_cluster_num;
           
           cout << "( " << (int)x[i] << ", " << (int)y[i] << ") \t"; // coordinate
           for(int j = 1; j <= m; j++){
               dis = sqrt(pow((x[i] - cluster_centre[j].first),2) + pow((y[i] - cluster_centre[j].second),2));
               cout << dis << "\t \t \t";
               if(dis < min_distance){
                   min_distance = dis;
                   min_cluster_num = j;
               }
           }
           cout << "\n";
           points_in_cluster[min_cluster_num].push_back(make_pair(x[i], y[i]));
       }
       cout << "\n \n"; 
       flag = true;
       for(int i = 1; i <= m; i++){
           if(old_points_in_cluster[i]!=points_in_cluster[i]){
               flag = false;
           }
           old_points_in_cluster[i] = points_in_cluster[i];
           points_in_cluster[i].clear(); // make all clusters empty
       }
       
       if(flag){
           cout << "All points are in the same cluster, so we stop here \n \n";
           break;
       }
       
       // calculate new cluster points
       cout << "new cluster centers \n";
       cout << "First cluster 1 then cluster 2 ... \n";
       for(int i = 1; i <= m; i++){
           cluster_centre[i] = mean(old_points_in_cluster[i]);
           cout << cluster_centre[i].first << " ";
           cout << cluster_centre[i].second << "\n";
       }
       cout << "\n \n";
       
   }

    return 0;
}
