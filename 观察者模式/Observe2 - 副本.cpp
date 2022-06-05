class MainForm: public Form,public IProgress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	
	ProgressBar* progressBar;
	
public:
	void Button1_Click(){
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());
		
		FileSplitter splitter(filePath,number,progressBar);
		
		splitter.split();
	}
	
	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}
	
};
