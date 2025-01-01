#include <iostream>
#include <cmath>
#include <vector>
#define Matrix vector<vector<double>>

using namespace std;




void print_vector(vector<vector<double>> W) {
    cout << endl;
    for (int i = 0; i < W.size(); i++) {
        for (int j = 0; j < W[0].size(); j++) {
            cout << W[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
double mean(vector<double> x){
    double n = 0;
    for(int i = 0; i < x.size(); i++){
        n = n + x[i];
    }
    return n / x.size();
}

vector<vector<double>> mat_mul_element(Matrix A, Matrix B) {
    Matrix C;
    vector<double> c;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            c.push_back(A[i][j] * B[i][j]);
        }
        C.push_back(c);
        c.clear();
    }
    return C;
}

vector<vector<double>> mat_mul(vector<vector<double>> A, vector<vector<double>> B) {
    vector<vector<double>> C;
    if (A[0].size() != B.size()) {
        int ra = A.size();
        int ca = A[0].size();
        int rb = B.size();
        int cb = B[0].size();
        if (ra == rb && ca == cb) {
            return mat_mul_element(A, B);
        }
        cout << "Error matrix mul col of A != row of B" << endl;
        return C;
    }
    vector<double> vv;
    double temp = 0;
    for (int i = 0; i < A.size(); i = i + 1) {
        for (int j = 0; j < B[0].size(); j++) {
            temp = 0;
            for (int k = 0; k < B.size(); k++) {
                temp = temp + A[i][k] * B[k][j];
            }
            vv.push_back(temp);
        }
        C.push_back(vv);
        vv.clear();
    }
    return C;
}

vector<vector<double>> remove(vector<vector<double>> D,int i, int j) {

    vector<vector<double>> A;
    int offset = 0;
    vector<double> B;

    for (int k = 0; k < D.size(); k++) {
        if (k == i) {
            continue;
        }
        for(int l = 0; l < D[0].size(); l++){
            if (l == j) {
                continue;
            }
            B.push_back(D[k][l]);
        }
        A.push_back(B);
        B.clear();
    }
    return A;
}

double det(vector<vector<double>> M) {
    if(M.size() == 2 && M[0].size() == 2){
        return M[0][0] * M[1][1] - M[0][1] * M[1][0];
    }
    double a = 0.0L;
    for(int i = 0; i < M[0].size(); i++){
        a = a + det(remove(M, 0, i)) * M[0][i] * pow((-1),(2 + i));
    }
    return a;
}



vector<vector<double>> mat_vec_sub(vector<vector<double>> A, vector<double> C) {
    Matrix V;
    vector<double> K;
    for (int i = 0; i < A[0].size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            K.push_back(A[j][i] - C[i]);
        }
        V.push_back(K);
    }
    return V;
}

vector<double> mat_vec_mul(vector<vector<double>> A, vector<double> C) {
    vector<double> V;
    double s = 0.0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            s = s + A[i][j] * C[j];
        }
        V.push_back(s);
    }
    return V;
}

vector<vector<double>> mat_add(vector<vector<double>> A, vector<vector<double>> B) {
    vector<vector<double>> C;
    vector<double> H;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            H.push_back(A[i][j] + B[i][j]);
        }
        C.push_back(H);
        H.clear();
    }
    return C;
}

Matrix mat_sub(Matrix A, Matrix B) {
    Matrix C;
    vector<double> D;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            D.push_back(A[i][j] - B[i][j]);
        }
        C.push_back(D);
    }
    return C;
}

vector<double> vec_scaler(vector<double> A, double C) {
    for (int i = 0; i < A.size(); i++) {
        A[i] = A[i] * C;
    }
    return A;
}

vector<double> vec_mul(vector<double> A, vector<double> B) {
    vector<double> C;
    for (int k = 0; k < A.size(); k++) {
        C.push_back(A[k] * B[k]);
    }
    return C;
}



double magnitude(vector<double> X) {
    double m = 0.0;
    for (int i = 0; i < X.size(); i++) {
        m = m + pow(X[i], 2);
    }
    return pow(m, 0.5);
}

vector<vector<double>> Transpose(vector<vector<double>> X) {
    vector<vector<double>> Y;
    vector<double> V;
    for (int i = 0; i < X[0].size(); i++) {
        for (int j = 0; j < X.size(); j++) {
            V.push_back(X[j][i]);
        }
        Y.push_back(V);
        V.clear();
    }
    return Y;
}

vector<double> vec_div_scaler(vector<double> A, double v) {
    double n = 0.0;
    for (int i = 0; i < A.size(); i++) {
        n = A[i];
        A[i] = n / v;
    }
    return A;
}

vector<double> dot_scaler(vector<double> A, double C) {
    for (int i = 0; i < A.size(); i++) {
        A[i] = A[i] * C;
    }
    return A;
}

double dot(vector<double> A, vector<double> B) {
    float C = 0.0;
    for (int i = 0; i < A.size(); i++) {
        C = C + A[i] * B[i];
    }
    return C;
}

vector<double> vec_add(vector<double> A, vector<double> B) {
    vector<double> C;
    for (int i = 0; i < A.size(); i++) {
        C.push_back(A[i] + B[i]);
    }
    return C;
}

vector<double> vec_sub(vector<double> A, vector<double> B) {
    vector<double> C;
    for (int i = 0; i < A.size(); i++) {
        C.push_back(A[i] - B[i]);
    }
    return C;
}

vector<vector<vector<double>>> QR(vector<vector<double>> M) {
    vector<vector<double>> Q;
    vector<vector<vector<double>>> V;
    vector<vector<double>> R;
    vector<double> q;
    vector<double> r;
    vector<double> mag;
    vector<vector<double>> MT = Transpose(M);
    vector<double> dot_sum;
    double temp = 0.0;
    int is_fill = 0;

    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++) {
            if (!(is_fill)) {
                r.push_back(0);
                q.push_back(0);
                continue;
            }
            break;
        }
        Q.push_back(q);
        is_fill = 1;
    }
    for (int i = 0; i < M.size(); i++) {
        dot_sum.push_back(0);
    }

    for (int i = 0; i < MT.size(); i++) {
        mag.push_back(magnitude(MT[i]));
        R.push_back(r);
    }
    r.clear();
    q.clear();
    R[0][0] = mag[0];

    q = vec_div_scaler(MT[0], mag[0]);

    for (int l = 0; l < M.size(); l++) {
        Q[l][0] = q[l];
    }
    vector<vector<double>> QT = Transpose(Q);
   
    for (int i = 1; i < M[0].size(); i++) {
        for (int j = 0; j < i; j++) {
            R[j][i] = dot(MT[i], QT[j]);
            dot_sum = vec_add(dot_sum, dot_scaler(QT[j], R[j][i]));
        }

        q = vec_sub(MT[i], dot_sum);
        R[i][i] = magnitude(q);
        q = vec_div_scaler(q, R[i][i]);
        for (int l = 0; l < M.size(); l++) {
            Q[l][i] = q[l];
            dot_sum[l] = 0;
        }
        QT = Transpose(Q);
        q.clear();
    }
    V.push_back(Q);
    V.push_back(R);
    return V;
}

bool check(vector<vector<double>> A,double e) {
    int s = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i][i] <= e) {
            s = s + 1;
        }
    }
    if (s == A[0].size()) {
        return 1;
    }
    return 0;
}

vector<double> diag(vector<vector<double>> A) {
    vector<double> B;
    for (int i = 0; i < A.size(); i++) {
        B.push_back(A[i][i]);
    }
    return B;
}

vector<vector<double>> sort(vector<double> A) {
    bool has_sort = 0;
    int ind;
    Matrix Sets;
    vector<double> index;
    for (int i = 0; i < A.size(); i++) {
        index.push_back(i);
    }
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size() - 1; j++) {
            if (A[j] < A[j + 1]) {
                ind = index[j];
                index[j] = index[j + 1];
                index[j + 1] = ind;
                A[j] = A[j] + A[j + 1];
                A[j + 1] = A[j] - A[j + 1];
                A[j] = A[j] - A[j + 1];
                has_sort = 1;
            }
        }
        if (!has_sort) {
            break;
        }
        has_sort = 0;
    }

    Sets.push_back(A);
    Sets.push_back(index);
    return Sets;
}

Matrix mat_vec_div(Matrix A,vector<double> x) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            A[i][j] = A[i][j] / x[i];
        }
    }
    return A;
}

double standard_deviation(vector<double> x) {
    double mu = mean(x);
    double s = 0.0;
    for (int i = 0; i < x.size(); i++) {
        s = s + (x[i] - mu) * (x[i] - mu);
    }
    return pow(s / x.size(), .5);
}


void print_dim(int r, int c) {
    cout << "row = " << r << "  col = " << c << endl << endl;
    return;
}

vector<vector<vector<double>>> PCA(vector<vector<double>> A, int T,int k,int d=0) {
    double epsilon = 1 / pow(10, 7);
    if (A.size() > 20 && d == 0) {
        Matrix X = A;
        double mu = 0.0;
        double st = 0.0;
        X = Transpose(X);
        for (int i = 0; i < A[0].size(); i++) {
            mu = mean(X[i]);
            st = standard_deviation(X[i]);
            for (int j = 0; j < A.size(); j++) {
                X[i][j] = (X[i][j] - mu)/st;
            }
        }
        A = Transpose(X);
        X.clear();
    }
    if (A.size() != A[0].size()) {
       //rectangular matrix case
       
        vector<vector<double>> AT = Transpose(A);
        vector<vector<double>> AAT = mat_mul(AT, A);
        vector<vector<vector<double>>> SS = PCA(AAT,T,k,d=1);
        vector<vector<double>> Lambda = SS[0];
        vector<vector<double>> Eigen_Vectors = SS[1];
        vector<double> dd;
        vector <vector<double>> X;
        SS.clear();

        int size = Lambda[0].size();
        vector<vector<double>> Sigma;
        
        for (int i = 0; i < A[0].size(); i++) {
            dd.push_back(0);
        }
        for (int i = 0; i < A.size(); i++) {
            Sigma.push_back(dd);
        }
        int r = min(A.size(), A[0].size());
        vector<double> eigen_values = diag(Lambda);
        Matrix Sets = sort(eigen_values);
        eigen_values = Sets[0];
        vector<double> index = Sets[1];
    
        for (int i = 0; i < r; i++) {
            eigen_values[i] = pow(eigen_values[i], .5);
            Sigma[i][i] = eigen_values[i];
        }
        
        //computing left singular vectors
        Eigen_Vectors = Transpose(Eigen_Vectors);
        
        vector<vector<double>> U;

        for (int i = 0; i < eigen_values.size(); i++) {
            if (eigen_values[i] <= epsilon) {
                continue;
            }
            U.push_back(vec_div_scaler(mat_vec_mul(A, Eigen_Vectors[i]),eigen_values[i]));
        }
        U = Transpose(U);
        Matrix extract;

        // Dimensionality reduction
        for (int i = 0; i < k; i++) {
            extract.push_back(Eigen_Vectors[index[i]]);
        }
        extract = Transpose(extract);

        Matrix Z = mat_mul(A, extract);
        cout << "PCA " << endl;
        print_vector(Z);
        SS.clear();
        SS.push_back(Z);

        return SS;
    }
    Matrix AA = A;
    vector<vector<vector<double>>> V;
    int i = 0;
    vector<vector<double>> Q;
    vector<vector<double>> Q_prev;
    vector<vector<double>> R;
    vector<vector<double>> Eigen_vectors;
    while (i <= T) {
        V = QR(A);
        Q = V[0];
        R = V[1];
        A = mat_mul(R, Q);
        if (i == 0) {
            Eigen_vectors = Q;
            i = 1;
            continue;
        }
        i = i + 1;
        Eigen_vectors = mat_mul(Eigen_vectors, Q);   
    }
    vector<double> eigen_values = diag(A);
    Matrix Sets = sort(eigen_values);
    eigen_values = Sets[0];
    vector<double> index = Sets[1];
    Matrix extract;
    Eigen_vectors = Transpose(Eigen_vectors);
    for (int i = 0; i < k; i++) {
        extract.push_back(Eigen_vectors[index[i]]);
    }
    extract = Transpose(extract);
    Matrix Z = mat_mul(AA, extract);
    if (d == 0) {
        cout << "PCA";
        print_vector(Z);
    }
    Eigen_vectors = Transpose(Eigen_vectors);
   vector<Matrix> SS;
   SS.push_back(A);
   SS.push_back(Eigen_vectors);
   SS.push_back(Z);
   return SS;
   
}


int main()
{
    vector<vector<double>> A = { {1,2,4},{0,1,0},{0,0,3} };
   PCA(A, 500,2);
    vector<vector<double>> N = { {2,3},{4,5},{7,7} };
    PCA(N, 6,1);
    vector<vector<double>> L = { {3, 4, 6}, { 0, 1, 0 }, { .6, .7, 3 } };
   PCA(L, 5000,2);
    Matrix B = { {4,11,14},{8,7,-2} };
    PCA(B,5000,2);
    vector<vector<double>> iris_data = {
       {5.1, 3.5, 1.4, 0.2}, {4.9, 3.0, 1.4, 0.2}, {4.7, 3.2, 1.3, 0.2}, {4.6, 3.1, 1.5, 0.2},
        {5.0, 3.6, 1.4, 0.2}, {5.4, 3.9, 1.7, 0.4}, {4.6, 3.4, 1.4, 0.3}, {5.0, 3.4, 1.5, 0.2},
        {4.4, 2.9, 1.4, 0.2}, {4.9, 3.1, 1.5, 0.1}, {5.4, 3.7, 1.5, 0.2}, {4.8, 3.4, 1.6, 0.2},
        {4.8, 3.0, 1.4, 0.1}, {4.3, 3.0, 1.1, 0.1}, {5.8, 4.0, 1.2, 0.2}, {5.7, 4.4, 1.5, 0.4},
        {5.4, 3.9, 1.3, 0.4}, {5.1, 3.5, 1.4, 0.3}, {5.7, 3.8, 1.7, 0.3}, {5.1, 3.8, 1.5, 0.3},
        {5.4, 3.4, 1.7, 0.2}, {5.1, 3.7, 1.5, 0.4}, {4.6, 3.6, 1.0, 0.2}, {5.1, 3.3, 1.7, 0.5},
        {4.8, 3.4, 1.9, 0.2}, {5.0, 3.0, 1.6, 0.2}, {5.0, 3.4, 1.6, 0.4}, {5.2, 3.5, 1.5, 0.2},
        {5.2, 3.4, 1.4, 0.2}, {4.7, 3.2, 1.6, 0.2}, {4.8, 3.1, 1.6, 0.2}, {5.4, 3.4, 1.5, 0.4},
        {5.2, 4.1, 1.5, 0.1}, {5.5, 4.2, 1.4, 0.2}, {4.9, 3.1, 1.5, 0.1}, {5.0, 3.2, 1.2, 0.2},
        {5.5, 3.5, 1.3, 0.2}, {4.9, 3.6, 1.4, 0.1}, {4.4, 3.0, 1.3, 0.2}, {5.1, 3.4, 1.5, 0.2},
        {5.0, 3.5, 1.3, 0.3}, {4.5, 2.3, 1.3, 0.3}, {4.4, 3.2, 1.3, 0.2}, {5.0, 3.5, 1.6, 0.6},
        {5.1, 3.8, 1.9, 0.4}, {4.8, 3.0, 1.4, 0.3}, {5.1, 3.8, 1.6, 0.2}, {4.6, 3.2, 1.4, 0.2},
        {5.3, 3.7, 1.5, 0.2}, {5.0, 3.3, 1.4, 0.2}, {7.0, 3.2, 4.7, 1.4}, {6.4, 3.2, 4.5, 1.5},
        {6.9, 3.1, 4.9, 1.5}, {5.5, 2.3, 4.0, 1.3}, {6.5, 2.8, 4.6, 1.5}, {5.7, 2.8, 4.5, 1.3},
        {6.3, 3.3, 4.7, 1.6}, {4.9, 2.4, 3.3, 1.0}, {6.6, 2.9, 4.6, 1.3}, {5.2, 2.7, 3.9, 1.4},
        {5.0, 2.0, 3.5, 1.0}, {5.9, 3.0, 4.2, 1.5}, {6.0, 2.2, 4.0, 1.0}, {6.1, 2.9, 4.7, 1.4},
        {5.6, 2.9, 3.6, 1.3}, {6.7, 3.1, 4.4, 1.4}, {5.6, 3.0, 4.5, 1.5}, {5.8, 2.7, 4.1, 1.0},
        {6.2, 2.2, 4.5, 1.5}, {5.6, 2.5, 3.9, 1.1}, {5.9, 3.2, 4.8, 1.8}, {6.1, 2.8, 4.0, 1.3},
        {6.3, 2.5, 4.9, 1.5}, {6.1, 2.8, 4.7, 1.2}, {6.4, 2.9, 4.3, 1.3}, {6.6, 3.0, 4.4, 1.4},
        {6.8, 2.8, 4.8, 1.4}, {6.7, 3.0, 5.0, 1.7}, {6.0, 2.9, 4.5, 1.5}, {5.7, 2.6, 3.5, 1.0},
        {5.5, 2.4, 3.8, 1.1}, {5.5, 2.4, 3.7, 1.0}, {5.8, 2.7, 3.9, 1.2}, {6.0, 2.7, 5.1, 1.6},
        {5.4, 3.0, 4.5, 1.5}, {6.0, 3.4, 4.5, 1.6}, {6.7, 3.1, 4.7, 1.5}, {6.3, 2.3, 4.4, 1.3},
        {5.6, 3.0, 4.1, 1.3}, {5.5, 2.5, 4.0, 1.3}, {5.5, 2.6, 4.4, 1.2}, {6.1, 3.0, 4.6, 1.4},
        {5.8, 2.6, 4.0, 1.2}, {5.0, 2.3, 3.3, 1.0}, {5.6, 2.7, 4.2, 1.3}, {5.7, 3.0, 4.2, 1.2},
        {5.7, 2.9, 4.2, 1.3}, {6.2, 2.9, 4.3, 1.3}, {5.1, 2.5, 3.0, 1.1}, {5.7, 2.8, 4.1, 1.3},
        {6.3, 3.3, 6.0, 2.5}, {5.8, 2.7, 5.1, 1.9}, {7.1, 3.0, 5.9, 2.1}, {6.3, 2.9, 5.6, 1.8},
        {6.5, 3.0, 5.8, 2.2}, {7.6, 3.0, 6.6, 2.1}, {4.9, 2.5, 4.5, 1.7}, {7.3, 2.9, 6.3, 1.8},
        {6.7, 2.5, 5.8, 1.8}, {7.2, 3.6, 6.1, 2.5}, {6.5, 3.2, 5.1, 2.0}, {6.4, 2.7, 5.3, 1.9},
        {6.8, 3.0, 5.5, 2.1}, {5.7, 2.5, 5.0, 2.0}, {5.8, 2.8, 5.1, 2.4}, {6.4, 3.2, 5.3, 2.3},
        {6.5, 3.0, 5.5, 1.8}, {7.7, 3.8, 6.7, 2.2}, {7.7, 2.6, 6.9, 2.3}, {6.0, 2.2, 5.0, 1.5},
        {6.9, 3.2, 5.7, 2.3}, {5.6, 2.8, 4.9, 2.0}, {7.7, 2.8, 6.7, 2.0}, {6.3, 2.7, 4.9, 1.8},
        {6.7, 3.3, 5.7, 2.1}, {7.2, 3.2, 6.0, 1.8}, {6.2, 2.8, 4.8, 1.8}, {6.1, 3.0, 4.9, 1.8},
        {6.4, 2.8, 5.6, 2.1}, {7.2, 3.0, 5.8, 1.6}, {7.4, 2.8, 6.1, 1.9}, {7.9, 3.8, 6.4, 2.0},
        {6.4, 2.8, 5.6, 2.2}, {6.3, 2.8, 5.1, 1.5}, {6.1, 2.6, 5.6, 1.4}, {7.7, 3.0, 6.1, 2.3},
        {6.3, 3.4, 5.6, 2.4}, {6.4, 3.1, 5.5, 1.8}, {6.0, 3.0, 4.8, 1.8}, {6.9, 3.1, 5.4, 2.1},
        {6.7, 3.1, 5.6, 2.4}, {6.9, 3.1, 5.1, 2.3}, {5.8, 2.7, 5.1, 1.9}, {6.8, 3.2, 5.9, 2.3},
        {6.7, 3.3, 5.7, 2.5}, {6.7, 3.0, 5.2, 2.3}, {6.3, 2.5, 5.0, 1.9}, {6.5, 3.0, 5.2, 2.0},
        {6.2, 3.4, 5.4, 2.3}, {5.9, 3.0, 5.1, 1.8}
    };
    PCA(iris_data, 20, 2);
    return 0;
}