class Messager{
protected:
	MessagerImp * messagerImp;
	Messager(MessagerImp * Imp):messagerImp(Imp){	}
public:
	virtual void Login(string username,string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(Image image) = 0;
	
	
	virutal ~Messager(){}
}; 

class MessagerImp{
public:

	
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;
	
	virutal ~MessagerImp(){}
}; 

class PCMessagerBase :public MessagerImp{
public:
	
	virtual void PlaySoung(){
		
	};
	
	virtual void DrawShape(){
		
	};
	
	virtual void WriteText(){
		
	};
	
	virtual void Connect(){
		
	};
};

class MobileMessagerBase : public MessagerImp{
public:
	virtual void PlaySoung(){
		 
	};
	
	virtual void DrawShape(){
		
	};
	
	virtual void WriteText(){
		
	};
	
	virtual void Connect(){
		
	};
};

class MessagerLite:public Messager{
    MessagerLite(MessagerImp * Imp):Messager(Imp){	}
    
	virtual void Login(string username,string password){
		messagerImp->Connect();
	};
	
	virtual void SendMessage(string message){
		messagerImp->WriteText();
	};
	
	virtual void SendPicture(Image image){
		messagerImp->DrawShape();
	};
};


class MessagerPerfect:public Messager{
    MessagerPerfect(MessagerImp * Imp):Messager(Imp){	}
	virtual void Login(string username,string password){
		messagerImp->PlaySound();
		messagerImp->Connect();
	};
	
	virtual void SendMessage(string message){
		messagerImp->PlaySound();
		messagerImp->WriteText();
	};
	
	virtual void SendPicture(Image image){
		messagerImp->PlaySound();
		messagerImp->DrawShape();

void Process(){
	
	MessagerImp *mImp = new PcMessagerImp();
	Messager * m = new Messager(mImp);
}


