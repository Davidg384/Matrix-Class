#include<iostream>
#include<vector>
using namespace std;

class matrix{
    public:
        vector<vector<float>> cells;
        int rows = 0;
        int cols = 0;
        matrix(){}
        void fill_matrix(){
          cout << "Num Rows" << endl;
          cin >> rows;
          cout << "Num Cows" << endl;
          cin >> cols;
          for(int i = 0; i < rows; i++){
            vector<float> temprow;
            for(int k = 0; k < cols; k++){
              float num;
              cout << "Enter cell " << i+1 << "," << k+1 << endl;
              cin >> num;
              temprow.push_back(num);
            }
            cells.push_back(temprow);
          }
        }
        
        void print(){
          for(int i = 0; i < rows; i++){
            cout << "[";
            for(int k = 0; k < cols; k++){
              cout << cells[i][k];
              if(k < cols-1){
                cout<<", ";
              }
            }
            cout << "]" << endl;
          }
        }
        
        void change(int i, int j, float val){cells[i][j] = val;}


        friend matrix operator +(matrix A, matrix B){return A;}
        friend matrix operator -(matrix A, matrix B){return A;}
        friend matrix operator *(matrix A, matrix B){return A;}
        friend void operator ++(matrix A){
          for(int i = 0; i < A.rows; i++){
            for(int k = 0; k < A.cols; k++){
              A.cells[i][k]++;
            }
          }
        }
        friend void operator --(matrix A){
          for(int i = 0; i < A.rows; i++){
            for(int k = 0; k < A.cols; k++){
              A.cells[i][k]--;
            }
          }
        }
};

int main(){
  matrix A;
  A.fill_matrix();
  system("clear");
  A.print();
  A.print();
  return 0;
}
