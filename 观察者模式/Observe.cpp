class FileSplitter
{
	string m_filePath;
	int m_fileNumber;
	ProgressBar* m_progressBar;
	
public:
	FileSplitter(const string& filePath,int fileNumber,
	ProgressBar* m_progressBar):m_filePath(filePath),
	m_fileNumber(fileNumber),m_progressBar(progressBar){
		
	}
	void split(){ 
		//1.��ȡ���ļ�
		
		//2.��������С�ļ���д��
		 for(int i =0;i<m_fileNumber;i++){
		 	//...
		 	if(m_iprogress != nullptr){
		 	    m_progressBar->SetValue((i+1)/m_fileNumber);
		    }
		 }
	}
	
	
};
