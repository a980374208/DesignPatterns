class MainForm: public Form,public IProgress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	
	ProgressBar* progressBar;
	
public:
	void Button1_Click(){
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());
		
		
		ConsoleNotifer cn;
		FileSplitter splitter(filePath,number);
		
		spliter.addIProgress(this);
		spliter.addIProgress(&cn);
		
		splitter.split();
	}
	
	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}
	
};

class ConsoleNotitier : public IProgress{
public:
	virtual void DoProgress(float valur){
		coutt<<value;
	}
};
