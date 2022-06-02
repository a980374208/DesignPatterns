class Application : public Library{
	protected:
		virtual bool Step2(){
			
		}
		virtual void Step4(){
			
		}
};

int main(){
	Library* pLib = new Application();
	pLib->Run();
	
	delete pLib;
}
