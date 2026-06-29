package utils;

import java.io.File;

public class FileManager {
	
	// Used for separating file types
	public enum FileType{
		CSV,JSON
	}
	// Used for separating import and export cases
	public enum Mode{
		IMPORT,EXPORT
	}
	public void handle(File file, FileType type, Mode mode) {}
}
