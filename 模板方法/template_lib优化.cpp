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
		void Step(){   //�ȶ� 
			
		}
		void Step3(){   //�ȶ� 
			
		}
		void Step5(){    //�ȶ� 
			
		}
		virtual bool Step2() = 0;   //�仯 
		virtual void Step4() = 0;   //�仯 
}; 
