class Messager{
public:
	virtual void Login(string username,string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(Image image) = 0;
	
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;
	
	virutal ~Messager(){}
}; 

class PCMessagerBase :public Messager{
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

class MobileMessagerBase : public Messager{
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

class PCMessagerLite : public PCMessagerBase{
	virtual void Login(string username,string password){
		PCMessagerBase::Connect();
	};
	
	virtual void SendMessage(string message){
		PCMessagerBase::WriteText();
	};
	
	virtual void SendPicture(Image image){
		PCMessagerBase::DrawShape();
	};
};


class PCMessagerPerfect : public PCMessagerBase{
	virtual void Login(string username,string password){
		PCMessagerBase::PlaySound();
		PCMessagerBase::Connect();
	};
	
	virtual void SendMessage(string message){
		PCMessagerBase::PlaySound();
		PCMessagerBase::WriteText();
	};
	
	virtual void SendPicture(Image image){
		PCMessagerBase::PlaySound();
		PCMessagerBase::DrawShape(image);
	};
};

class MobileMessagerLite : public MobileMessagerBase{
	virtual void Login(string username,string password){
		MobileMessagerBase::Connect();
	};
	
	virtual void SendMessage(string message){
		MobileMessagerBase::WriteText();
	};
	
	virtual void SendPicture(Image image){
		MobileMessagerBase::DrawShape();
	};
};

class MobileMessagerPerfect : public MobileMessagerBase{
	virtual void Login(string username,string password){
		PCMessagerBase::PlaySound();
		PCMessagerBase::Connect();
	};
	
	virtual void SendMessage(string message){
		MobileMessagerBase::PlaySound();
		MobileMessagerBase::WriteText();
	};
	
	virtual void SendPicture(Image image){
		MobileMessagerBase::PlaySound();
		MobileMessagerBase::DrawShape(image);
	};
};

void Process(){
	
	Messager *m = new MobileMessagerPerfect();
}


