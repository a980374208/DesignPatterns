class Library{
	public:
		void Run(){
			Step1();
			
			if(Step2()){
				Step3();
			}
			
			for(int i = 0;i<4; i++){
				Step4();
			}
			
			Step5();
		} 
		
	virtual ~Library(){ }
	
	protected:
		void Step(){   //稳定 
			
		}
		void Step3(){   //稳定 
			
		}
		void Step5(){    //稳定 
			
		}
		virtual bool Step2() = 0;   //变化 
		virtual void Step4() = 0;   //变化 
}; 
