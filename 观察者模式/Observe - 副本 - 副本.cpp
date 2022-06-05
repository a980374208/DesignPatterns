class IProgress{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~IProgress(){}
};



class FileSplitter
{
	string m_filePath;
	int m_fileNumber;
	//ProgressBar* m_progressBar;
	list<IProgress*>  m_iprogressList; 
	
public:
	FileSplitter(const string& filePath,int fileNumber) :
	   m_filePath(filePath),
	   m_fileNumber(fileNumber){
		
	}
	void addIProgress(IProgress* iprogress){
		m_iprogressList.push_back(iprogress); 
	}
	void removeIProgress(IProgress* iprogress){
		m_iprogressList.remove(iprogress); 
	}
	
	void split(){ 
		//1.读取大文件
		
		//2.分批次向小文件中写入
		 for(int i =0;i<m_fileNumber;i++){
		 	//...
		 	
		 	float progressValue = m_fileNumber;
		 	progressValue = (i+1)/progressValue;
		 	onProgress(progressValue);	 
		 	
		 }
	}
protected:
	virtual void onProgress(){
		for(auto progressTmp:m_iprogressList){
			progressTmp->DoProgress(value);
		}
	}
	
	
};
