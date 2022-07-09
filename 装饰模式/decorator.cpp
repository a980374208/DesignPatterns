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



class CryptoFileStream :public FileStream{
public:
	virtual char Read(int number){
		//������ܲ����� 
		FileStream::Read(number);//���ļ��� 
	}
	
	virtual void Seek(int position){
		//����ټ������� 
		FileStream::Seek(position);
	}
	
	virtual void Write(char data){
		//����Ĳ����� 
		FileStream::Write(data);
	}
};



class CryptoNetWorkStream :public NetWorkStream{
public:
	virtual char Read(int number){
		//������ܲ����� 
		FileStream::Read(number);//���ļ��� 
	}
	
	virtual void Seek(int position){
		//����ټ������� 
		FileStream::Seek(position);
	}
	
	virtual void Write(char data){
		//����Ĳ����� 
		FileStream::Write(data);
	}
};


class BufferedFileStream :public FileStream{
public:
	virtual char Read(int number){
		//���⻺������� 
		FileStream::Read(number);//���ļ��� 
	}
	
	virtual void Seek(int position){
		//���⻺������� 
		FileStream::Seek(position);
	}
	
	virtual void Write(char data){
		//����Ļ�������� 
		FileStream::Write(data);
	}
};



class BufferedNetWorkStream :public NetWorkStream{
public:
	virtual char Read(int number){
		//���⻺������� 
		FileStream::Read(number);//���ļ��� 
	}
	
	virtual void Seek(int position){
		//����ٻ������� 
		FileStream::Seek(position);
	}
	
	virtual void Write(char data){
		//���⻺������� 
		FileStream::Write(data);
	}
};
//............................................ʡ�� 


void Process(){
	
	//װ��ʱ���� 
	CryptoFileStream *fs1 = new CryptoFileStream();
	
	BufferedFileStream *fs2 = new BufferedFileStream();
	
	CryptoBufferedFileStream *fs3 = new CryproBufferedFileStream;
} 


