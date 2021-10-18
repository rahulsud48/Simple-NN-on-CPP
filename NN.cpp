#include<algorithm>
#include<vector>
#include<iostream>
#include<random>
#include<numeric>
#include<cmath>
#include<time.h>

using namespace std;

class Perceptron {
    public:
        vector<double> weights;
        double bias;
        Perceptron(int inputs, double bias = 1.0);
        double run(vector<double> x);
        void set_weights(vector<double> w_init);
        double sigmoid(double x);

};

double frand(){
    return (2.0*(double)rand()/RAND_MAX) - 1.0;
}

Perceptron::Perceptron(int inputs, double bias){
    this->bias = bias;
    weights.resize(inputs + 1);
    generate(weights.begin(), weights.end(), frand);
}

double Perceptron::run(vector<double> x){
    x.push_back(bias);
    double sum = inner_product(x.begin(), x.end(), weights.begin(), (double)0.0);
}

void Perceptron::set_weights(vector<double> w_init){
    weights = w_init;
}

double Perceptron::sigmoid(double x){
    return 1.0/(1.0 + exp(-x));
}


int main(){
    srand(time(NULL));
    rand();

    cout << "\n\n ---------------- Logic Gate Example ---------------- \n\n";
    Perceptron *p = new Perceptron(2);

    p->set_weights({10,10,-15});

    cout << "Gate: "<<endl;
    cout << p->run({0,0})<<endl;
    cout << p->run({0,1})<<endl;
    cout << p->run({1,0})<<endl;
    cout << p->run({1,1})<<endl;
}