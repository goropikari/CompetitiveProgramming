#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<typename T>
struct Matrix {
    Matrix(int h, int w): isSwap(false), H(h), W(w), grid(h, vector<T>(w,0)), xid(h), yid(w) {
        rep(i,h) xid[i] = i;
        rep(i,w) yid[i] = i;
    }


    T find(int x, int y) {
        P p = index(x,y);
        return grid[p.first][p.second];
    }

    void set(int x, int y, T val) {
        P p = index(x,y);
        grid[p.first][p.second] = val;
    }

    void rotr90() {
        isSwap = !isSwap;
        vector<int> new_yid(H);
        rep(i,H) new_yid[i] = H - 1 - xid[i];
        swap(H, W);
        xid = yid;
        yid = new_yid;
    }

    void rotl90() {
        isSwap = !isSwap;
        vector<int> new_xid(W);
        rep(i,W) new_xid[i] = W - 1 - yid[i];
        swap(H, W);
        yid = xid;
        xid = new_xid;
    }

    void topbottom() {
        rep(i,H/2) swap(xid[i], xid[H-1-i]);
    }

    void leftright() {
        rep(i,W/2) swap(yid[i], yid[W-1-i]);
    }

    void transpose() {
        isSwap = !isSwap;
        swap(xid, yid);
        swap(H, W);
    }

    void print() {
        rep(i,H) {
            rep(j,W) {
                cout << find(i,j) << " ";
            }
            cout << endl;
        }
    }

    private:
        bool isSwap;
        int H, W;
        vector<vector<T>> grid;

        // 新しい行列の index と original の行列の index との対応表
        // 新しい行列の i, j 成分は
        // swap is false のとき
        //   grid[xid[i]][yid[j]]
        // swap is true のとき
        //   grid[yid[j]][xid[i]]
        vector<int> xid, yid;

        pair<int,int> index(int x, int y) {
            int i = xid[x];
            int j = yid[y];
            if (isSwap) swap(i,j);
            return {i,j};
        }
};

void solve() {
    int h = 2, w = 3;
    Matrix<char> mat(2, 3);
    rep(i,h) rep(j,w) mat.set(i, j, 'a' + i*w + j);
    printf("original\n");
    mat.print();
    cout << endl;

    printf("rotr90\n");
    mat.rotr90();
    mat.print();
    cout << endl;

    printf("set 'z' at (0, 1)\n");
    mat.set(0, 1, 'z');
    mat.print();
    cout << endl;

    printf("rotr90\n");
    mat.rotr90();
    mat.print();
    cout << endl;

    printf("rotl90\n");
    mat.rotl90();
    mat.print();
    cout << endl;

    printf("transpose\n");
    mat.transpose();
    mat.print();
    cout << endl;
}

int main() {
    solve();
    return 0;
}
