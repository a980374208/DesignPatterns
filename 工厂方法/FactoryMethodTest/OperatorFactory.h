#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H

enum Except{
    EXCEP_ZERO,  //除数为0
    EXCEP_ONE   //待定
};

class Operator{
public:
    virtual double Calculate() = 0;


    void SetNumA(double a){
        NumA = a;
    }
    void SetNumB(double b){
        NumB = b;
    }
    double NumA;
    double NumB;
};

class AddOperator:public Operator{
public:
    virtual double Calculate(){
        return this->NumA+this->NumB;
    }
};

class SubOperator:public Operator{
public:    
    virtual double Calculate(){
        return this->NumA-this->NumB;
    }
};

class MulOperator:public Operator{
public:
    virtual double Calculate(){
            return this->NumA*this->NumB;
    }
};

class DivOperator:public Operator{
public:
    virtual double Calculate(){
        if(NumB == 0){
            throw EXCEP_ZERO;
        }else
        {
             return this->NumA/this->NumB;
        }
    }
};





class IOperator{
  public:
  virtual Operator* CreateFactory() = 0;
};

class AddFactory:public IOperator{
public:
    Operator* CreateFactory(){
        return new AddOperator;
    }
};

class MulFactory:public IOperator{
    public:
    Operator* CreateFactory(){
        return new  MulOperator;
    }
};

class SubFactory:public IOperator{
    public:
    Operator* CreateFactory(){
        return new SubOperator;
    }
};

class DivFactory:public IOperator{
    public:
    Operator* CreateFactory(){
        return new DivOperator;
    }
};





#endif // OPERATORFACTORY_H
