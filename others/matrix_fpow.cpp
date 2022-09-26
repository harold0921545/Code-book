#define matrix vector<vector<int>>
matrix operator*(const matrix &a, const matrix &b){
    matrix c = vector<vector<int>>(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < b.size(); k++)
                (c[i][j] += a[i][k] * b[k][j]);
    return c;
}
matrix fpow(matrix &a, int p){
    matrix I;
    for(int i = 0;i < a.size(); i++){
        vector<int> tmp;
        for(int j = 0; j < a.size(); j++)
            if(j == i)
                tmp.pb(1);
            else 
                tmp.pb(0);
        I.pb(tmp);
    }
    for (; p; p >>= 1){
        if (p & 1)
            I = I * a;
        a = a * a;
    }
    return c;
}