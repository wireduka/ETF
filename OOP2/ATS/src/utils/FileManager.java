package utils;

import java.awt.Frame;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

import gui.ErrorDialog;

public class FileManager {
	
	private CsvImporter csvimp = new CsvImporter();
	
	// Used for Error dialog ownership 
	private Frame owner;
	
	// Used for separating file types
	public enum FileType{
		CSV,JSON
	}
	
	// Used for separating import and export cases
	public enum Mode{
		IMPORT,EXPORT
	}
	
	public FileManager(Frame owner) {
		this.owner = owner;
	}
	
	// Method for file and exception handling
	public void handle(File file, FileType type, Mode mode) {
		
		try {
			if(type == FileType.CSV && mode == Mode.IMPORT) {csvimp.fileImport(file);}
			// TODO csvExporter, jsonExporter,jsonImporter
			}
		
		catch(FileNotFoundException e) {
			new ErrorDialog(owner,"File not found"," The file may have been moved or deleted");
		}
		catch(IOException e) {
			new ErrorDialog(owner,"Unable to read file","The file might be open in another program or the program does not have privileges to read the file");
		}
	}
}
