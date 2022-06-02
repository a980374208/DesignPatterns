class TaxStrategy{
public:
	virtual double Calculate(const Context& context) = 0;
	virtual ~ TaxStrategy(){}
};

class CNTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
    	//...
	}
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
    	//...
	}	
};

class DETax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
    	//...
	}	
};


class SalesOrder{
private:
	TaxStrategy* strategy;
	
public:
	SalesOrder(StrategyFactory* strategyFactory){
		/*工厂模式可动态创建对象不是本节重点*/
		this->strategy = strategyFactory->NewStrategy();
	}
	~SalesOrder(){
		delete this->strategy;
	}
	
	public double CalculateTax(){
		
		Context context();
		
		double val = strategy->Calculate(context);
	}
};
