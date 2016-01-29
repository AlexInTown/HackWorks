#include <iostream>
using namespace std;

int total_cnt = 0;
void put(int& max_edge, int & area, int edge, int &cnt){
    if(area == 0 || cnt == 0) return;
    if(max_edge < edge) return;
    int temp;
    switch(edge){
    case 1:{
        temp = min(area, cnt);
        area -=  temp;
        cnt -= temp;
        total_cnt -= temp;
        break;
    }
    case 2:{
        switch(max_edge){
            case 2: {
                temp = min(cnt, 5);
                area -=  temp * 4;
                cnt -= temp;
                total_cnt -= temp;
                max_edge = 1;
                break;
            }
            case 3: {
                temp = min(cnt, area/4-1);
                area -=  temp * 4;
                cnt -= temp;
                total_cnt -= temp;
                max_edge = 1;
                break;
            }
            case 6: {
                temp = min(cnt, area/(edge*edge));
                area -= temp * (edge*edge);
                max_edge -= edge;
                cnt -= temp;
                total_cnt -= temp;
                break;
            }
            default:
                cout<<"error edge "<<edge<<" max_edge "<<max_edge<<endl;
                break;
        }
        break;
    }
    case 3:{
        if(max_edge == 6){
            temp = min(cnt, area/(edge*edge));
            area -= temp * (edge*edge);
            max_edge -= edge;
            cnt -= temp;
            total_cnt -= temp;
            //cout<<"total "<<total_cnt<<"  temp "<<temp<<"  count "<<cnt<<endl;
        }
        else
            cout<<"error edge "<<edge<<endl;
        break;
    }
    case 4:
    case 5:{
        if(max_edge == 6){
            temp = min(cnt, 1);
            area -= temp * (edge*edge);
            max_edge -= edge;
            cnt -= temp;
            total_cnt -= temp;
        }
        else
            cout<<"error edge "<<edge<<endl;
        break;
    }
    }
}

int main(){
    int res, i;
    int arr[6];
    total_cnt = 0;
    for(i = 0; i < 6; ++i){
        cin>>arr[i];
        total_cnt += arr[i];
    }
    
    while(total_cnt > 0){
        res = arr[5];
        total_cnt -= arr[5];
        arr[5] = 0;
        while(total_cnt > 0){
            int area = 36;
            int max_edge = 6;
            for(i = 4; i >= 0; --i){
                put(max_edge, area, i+1, arr[i]);
            }
            res += 1;
            /*for(i = 0; i < 6; ++i){
                cout<<arr[i]<<" ";
            }
            cout<<total_cnt<<endl;
            cout<<"res "<<res<<endl;*/
        }

        cout<<res<<endl;
        for(i = 0; i < 6; ++i){
            cin>>arr[i];
            total_cnt += arr[i];
        }
    }
    
    return 0;
}
