package utils;

import java.awt.Frame;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import exception.InvalidDataException;
import exception.InvalidFileFormatException;
import gui.TextDialog;
import model.AirportTable;
import model.FlightTable;

public class FileManager {
	
	// For further processing
	private AirportTable airportTable;
	private FlightTable flightTable;
	
	// Used for Error dialog ownership 
	private Frame owner;
	
	// Importers/exporters, parser
	private CsvImporter csvImporter;
	private Parser parser;
	
	
	
	// Used for separating file types
	public enum FileType{
		CSV,JSON
	}
	
	// Used for separating import and export cases
	public enum Mode{
		IMPORT,EXPORT
	}
	
	public FileManager(Frame owner, AirportTable at, FlightTable ft) {
		this.owner = owner;
		this.airportTable = at;
		this.flightTable = ft;
		this.csvImporter = new CsvImporter();
		this.parser = new Parser(airportTable, flightTable, owner);
	}
	
	// Method for file and exception handling
	public void handle(File file, FileType type, Mode mode) {
		
			if(type == FileType.CSV && mode == Mode.IMPORT) {importFile(csvImporter,file);}
			// TODO csvExporter, jsonExporter,jsonImporter
			
	}
	
	// Method for tokenization, parsing and table updating
	public void importFile(Importable importer, File file) {
		try {
			TokenizedData tokens = importer.readFile(file);
			parser.parse(tokens);
			}
		catch(FileNotFoundException e) {
			new TextDialog(owner,"Error","File not found"," The file may have been moved or deleted");
			}
		catch(IOException e) {
			new TextDialog(owner,"Error","Unable to read file","The file might be open in another program or the program does not have privileges to read the file");
		} 
		catch (InvalidFileFormatException e) {
			new TextDialog(owner,"Error",e.getMessage());
		}
		catch (NumberFormatException e) {
			new TextDialog(owner,"Error","Invalid x/y coordinate, check if coordinates represent numbers");
		}
		catch (InvalidDataException e) {
			new TextDialog(owner,"Error",e.getMessage());
		}
	}
}
