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
		//���ļ��� 
	}
	
	virtual void Seek(int position){
		//��λ�ļ��� 
	}
	
	virtual void Write(char data){
		//д�ļ��� 
	}
};

class NetWorkStream: public Stream{
public:
	
	virtual char Read(int number){
		//���ļ��� 
	}
	
	virtual void Seek(int position){
		//��λ�ļ��� 
	}
	
	virtual void Write(char data){
		//д�ļ��� 
	}
};

class MemoryStream: public Stream{
public:
	
	virtual char Read(int number){
		//���ļ��� 
	}
	
	virtual void Seek(int position){
		//��λ�ļ��� 
	}
	
	virtual void Write(char data){
		//д�ļ��� 
	}
};

DecoratorStream :public Stream{
protected:
    Stream * stream;
    DecoratorStream(Stream* stm):stream(stm){
	}

}

class CryptoStream:public DecoratorStream/*���ڻ���ӿڹ淶*/{
public:
	CryptoStream(Stream * stm):DecoratorStream(stm){	
	}
	virtual char Read(int number){
		//������ܲ����� 
		stream->Read(number);//���ļ��� 
	}
	
	virtual void Seek(int position){
		//����ټ������� 
		stream->Seek(position);
	}
	
	virtual void Write(char data){
		//����Ĳ����� 
		stream->Write(data);
	}
};

class BufferedStream :public DecoratorStream{
public:
	BufferedStream(Stream * stm):DecoratorStream(stm){	
	virtual char Read(int number){
		//���⻺������� 
		stream->Read(number);//���ļ��� 
	}
	
	virtual void Seek(int position){
		//���⻺������� 
		stream->Seek(position);
	}
	
	virtual void Write(char data){
		//����Ļ�������� 
		stream->Write(data);
	}
};
//............................................ʡ�� 


void Process(){
	//����ʱװ�� 
	FileStream *s1 = new FileStream();
	
	CryptoStream* s2 = new CryptoStream(s1);
	
	BufferedStream *s3 = new BufferedStream(s1);
	
	BufferedStream *s4 = new BufferedStream(s2); 
} 




