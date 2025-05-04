// polynomial addition using array ...

#include <iostream>
#include <vector>
using namespace std;

struct poly{
    int cof;
    int expo;
};

vector<poly> helper (vector<poly> & eq1, vector<poly> & eq2){
   
    vector<poly> res;

    int i = 0, j = 0;
     
    while(i < eq1.size() && j < eq2.size()){
       if(eq1[i].expo < eq2[j].expo) res.push_back(eq2[j++]);
       else if(eq2[j].expo < eq1[i].expo) res.push_back(eq1[i++]);
       else {
        poly temp;
        temp.cof =  eq1[i].cof + eq2[j].cof;
        temp.expo = eq1[i].expo;
        res.push_back(temp);
        i++;
        j++;
       }
    }

    while(i < eq1.size())
        res.push_back(eq1[i++]);

    while (j < eq2.size())
        res.push_back(eq2[j++]);

        return res;
}

int main()
{

    vector<poly> eq1 = {{2,3}, {4, 2}, {3,0}};
    vector<poly> eq2 = {{5,4}, {2,2}, {7,1}, {2,0}};

    vector<poly> res = helper(eq1, eq2);

    for(int i = 0; i < res.size(); i++){
        cout << res[i].cof;
         if (res[i].expo > 1)
             cout<< "x^" << res[i].expo << " + ";
        else if(res[i].expo == 1) cout<<"x"<<" + ";
        else cout<<"";
    }


    return 0;
}

// output - 5x^4 + 2x^3 + 6x^2 + 7x + 5%