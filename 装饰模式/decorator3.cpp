class Stream{
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;
	
	virtual ~Stream(){}
}; 

class FileStream: public Stream{
public:
	
	virtual char Read(int number){
		//读文件流 
	}
	
	virtual void Seek(int position){
		//定位文件流 
	}
	
	virtual void Write(char data){
		//写文件流 
	}
};

class NetWorkStream: public Stream{
public:
	
	virtual char Read(int number){
		//读文件流 
	}
	
	virtual void Seek(int position){
		//定位文件流 
	}
	
	virtual void Write(char data){
		//写文件流 
	}
};

class MemoryStream: public Stream{
public:
	
	virtual char Read(int number){
		//读文件流 
	}
	
	virtual void Seek(int position){
		//定位文件流 
	}
	
	virtual void Write(char data){
		//写文件流 
	}
};

DecoratorStream :public Stream{
protected:
    Stream * stream;
    DecoratorStream(Stream* stm):stream(stm){
	}

}

class CryptoStream:public DecoratorStream/*用于基类接口规范*/{
public:
	CryptoStream(Stream * stm):DecoratorStream(stm){	
	}
	virtual char Read(int number){
		//额外加密操作等 
		stream->Read(number);//读文件流 
	}
	
	virtual void Seek(int position){
		//额外操加密作等 
		stream->Seek(position);
	}
	
	virtual void Write(char data){
		//额外的操作等 
		stream->Write(data);
	}
};

class BufferedStream :public DecoratorStream{
public:
	BufferedStream(Stream * stm):DecoratorStream(stm){	
	virtual char Read(int number){
		//额外缓存操作等 
		stream->Read(number);//读文件流 
	}
	
	virtual void Seek(int position){
		//额外缓存操作等 
		stream->Seek(position);
	}
	
	virtual void Write(char data){
		//额外的缓存操作等 
		stream->Write(data);
	}
};
//............................................省略 


void Process(){
	//运行时装配 
	FileStream *s1 = new FileStream();
	
	CryptoStream* s2 = new CryptoStream(s1);
	
	BufferedStream *s3 = new BufferedStream(s1);
	
	BufferedStream *s4 = new BufferedStream(s2); 
} 




