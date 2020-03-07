#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

/*bài toán cái túi Trong siêu thị có n đồ vật (n≤1000), đồ vật thứ i có trọng lượng là W[i]≤10­00 và
giá trị V[i] ≤1000. Một tên trộm đột nhập vào siêu thị, tên trộm mang theo một cái túi có thể mang
được tối đa trọng lượng M (M≤1000). Hỏi tên trộm sẽ lấy đi những đồ vật nào để được tổng giá trị lớn nhất.*/
int DP(vector<int> weight_packages, vector<int> value, int n, int max_weight){
    vector<vector<int>> DP(n + 1,vector<int>(max_weight + 1,0));
    for(int M = 1;M <= max_weight;++M){
        for(int i = 1;i <= n;++i){
            DP[i][M] = DP[i - 1][M];
            if(weight_packages[i] <= M && DP[i][M] < (DP[i - 1][M - weight_packages[i]] + value[i])){
                DP[i][M] = DP[i - 1][M - weight_packages[i]] + value[i];
            }
        }
    }
    return DP[n][max_weight];
    
}


int main(){
    //dữ liệu đặt trong file input.txt rồi đọc file ra
    ifstream fi;
    fi.open("input.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    }   

    int n, max_weight;
    fi >> n >> max_weight;
    vector<int> weight_packages(n + 1,0);
    vector<int> value(n + 1,0);
    for(int i = 1;i <= n;i++){
        fi >> weight_packages[i] >> value[i];
    }
    cout << DP(weight_packages,value,n,max_weight);
}