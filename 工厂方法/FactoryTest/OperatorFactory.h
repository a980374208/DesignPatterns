#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H

class Operator{
public:
    virtual double Calculate() = 0;


    Operator(double a,double b):NumA(a),NumB(b){

    }
    //virtual ~ Operator(){}

    double NumA;
    double NumB;
};

class AddOperator:public Operator{
public:
    AddOperator(double a,double b):Operator(a,b){}
    virtual double Calculate(){
        return this->NumA+this->NumB;
    }
};

class SubOperator:public Operator{
public:
    SubOperator(double a,double b):Operator(a,b){}
    virtual double Calculate(){
        return this->NumA-this->NumB;
    }
};

class MulOperator:public Operator{
public:
    MulOperator(double a,double b):Operator(a,b){}
    virtual double Calculate(){
        return this->NumA*this->NumB;
    }
};

class DivOperator:public Operator{
public:
    DivOperator(double a,double b):Operator(a,b){}
    virtual double Calculate(){
        return this->NumA/this->NumB;
    }
};

enum Except{
    EXCEP_ZERO,  //除数为0
    EXCEP_ONE   //待定
};


class OperatorFactory{
    public:
    OperatorFactory(double a,double b):NumA(a),NumB(b){

    }

    Operator *CreateOperator(QString str){
        Operator * operatorTmp = nullptr;
       if(str == "+"){
           operatorTmp = new AddOperator(NumA,NumB);
           return operatorTmp;
        }else if(str == "-"){
           operatorTmp = new SubOperator(NumA,NumB);
           return operatorTmp;
        }else if(str == "*"){
           operatorTmp = new MulOperator(NumA,NumB);
           return operatorTmp;
        }else if(str == "/"){
           if(NumB == 0){
               throw EXCEP_ZERO;
           }else{
               operatorTmp = new DivOperator(NumA,NumB);
           }

        }
       return operatorTmp;

    }
    double NumA;
    double NumB;
};





#endif // OPERATORFACTORY_H
