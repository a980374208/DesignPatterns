class Application{
	public:
		bool Step2(){  //变化 
			
		}
		void Step4(){  //变化 
			
		}
};

int main(){
	Library lib();
	Application app();
	
	lib.Step1();
	
	if(app.Step2()){
		lib.Step3();
	}
	
	for(int i = 0;i<4;i++){
		app.Step4();
	}
	
	lib.Step5()
}
