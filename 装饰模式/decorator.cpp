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



class CryptoFileStream :public FileStream{
public:
	virtual char Read(int number){
		//额外加密操作等 
		FileStream::Read(number);//读文件流 
	}
	
	virtual void Seek(int position){
		//额外操加密作等 
		FileStream::Seek(position);
	}
	
	virtual void Write(char data){
		//额外的操作等 
		FileStream::Write(data);
	}
};



class CryptoNetWorkStream :public NetWorkStream{
public:
	virtual char Read(int number){
		//额外加密操作等 
		FileStream::Read(number);//读文件流 
	}
	
	virtual void Seek(int position){
		//额外操加密作等 
		FileStream::Seek(position);
	}
	
	virtual void Write(char data){
		//额外的操作等 
		FileStream::Write(data);
	}
};


class BufferedFileStream :public FileStream{
public:
	virtual char Read(int number){
		//额外缓存操作等 
		FileStream::Read(number);//读文件流 
	}
	
	virtual void Seek(int position){
		//额外缓存操作等 
		FileStream::Seek(position);
	}
	
	virtual void Write(char data){
		//额外的缓存操作等 
		FileStream::Write(data);
	}
};



class BufferedNetWorkStream :public NetWorkStream{
public:
	virtual char Read(int number){
		//额外缓存操作等 
		FileStream::Read(number);//读文件流 
	}
	
	virtual void Seek(int position){
		//额外操缓存作等 
		FileStream::Seek(position);
	}
	
	virtual void Write(char data){
		//额外缓存操作等 
		FileStream::Write(data);
	}
};
//............................................省略 


void Process(){
	
	//装配时编译 
	CryptoFileStream *fs1 = new CryptoFileStream();
	
	BufferedFileStream *fs2 = new BufferedFileStream();
	
	CryptoBufferedFileStream *fs3 = new CryproBufferedFileStream;
} 


