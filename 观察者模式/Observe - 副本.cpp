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
	IProgress * m_iprogress; 
	
public:
	FileSplitter(const string& filePath,int fileNumber,
	ProgressBar* m_progressBar):m_filePath(filePath),
	m_fileNumber(fileNumber),m_iprogress(iprogress){
		
	}
	void split(){ 
		//1.读取大文件
		
		//2.分批次向小文件中写入
		 for(int i =0;i<m_fileNumber;i++){
		 	//...
		 	if(m_iprogress != nullptr){
		 		float progressValue = m_fileNumber;
		 		progressValue = (i+1)/progressValue;
		 		m_iprogress->DoProgress(progressValue);
			 }
		 	
		 }
	}
	
	
};
