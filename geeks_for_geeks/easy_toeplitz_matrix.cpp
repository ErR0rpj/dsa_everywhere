//[2 3 4 5]
//[6 2 3 4]
//[5 5 2 3]
//[7 5 6 2]
//GIven matrix is called toeplitz when each diagonal element is same. In above, its not a toeplitz

#include<bits/stdc++.h>
using namespace std;
bool isToeplitz(vector<vector<int>>& mat);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }

        bool b = isToeplitz(a);

        if(b = true){
            cout<<"true";

        }else{
            cout<<"false";
        }
        cout<<endl;
    }
    return 0;
}


bool isToeplitz(vector<vector<int>>& mat) {
    bool isToeplitz = true;
    for(int i=0;i<mat.size();i++){
    for(int j=0;j<mat[i].size();j++){
        int current = mat[i][j];
        int x = i+1;
        int y = j+1;
        while(x<mat.size() && y<mat[0].size()){
            if(mat[x][y] != current){
                isToeplitz = false;
                break;
            }
            x++;
            y++;
        }
        if(!isToeplitz){
            break;
        }
    }
    if(!isToeplitz){
            break;
        }
    }

    return isToeplitz;
}
