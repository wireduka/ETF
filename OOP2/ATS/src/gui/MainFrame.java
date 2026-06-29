package gui;

import java.awt.FileDialog;
import utils.FileManager;
import utils.FileManager.FileType;
import utils.FileManager.Mode;
import java.awt.Frame;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;

public class MainFrame extends Frame implements WindowClosing{
	
	// File managing
	private FileManager fileManager = new FileManager(this);
	// Frame constructor
	public MainFrame() {
		
		super("ATS");
		this.setSize(1600,800);
		setupWindowClosing(this);
		setupMenu();
		this.setVisible(true);
		
	}
	// Method for menu handling
	private void setupMenu() {
		MenuBar menuBar = new MenuBar();
		Menu fileMenu = new Menu("File");

		// File menu sub-menus
		Menu importMenu = new Menu("Import as");
		Menu exportMenu = new Menu("Export as");
		
		// Import sub-menu items
		MenuItem entry = new MenuItem("Entry");
		MenuItem jsonImport = new MenuItem("JSON");
		MenuItem csvImport = new MenuItem("CSV");
		
		// Export sub-menu items
		MenuItem jsonExport = new MenuItem("JSON");
		MenuItem csvExport = new MenuItem("CSV");
		
		// Import sub-menu adding
		importMenu.add(entry);
		importMenu.add(jsonImport);
		importMenu.add(csvImport);
		
		// Export sub-menu adding
		exportMenu.add(jsonExport);
		exportMenu.add(csvExport);
		
		// Entry import action listener
		entry.addActionListener(e->{
			openTextDialog();
		}); 
		
		// JSON import action listener
		jsonImport.addActionListener(e->{
			openFileDialog(Mode.IMPORT, FileType.JSON);
		});
		
		// CSV import action listener
		csvImport.addActionListener(e->{
			openFileDialog(Mode.IMPORT, FileType.CSV);
		});
		
		// JSON export action listener
		jsonExport.addActionListener(e->{
			openFileDialog(Mode.EXPORT, FileType.JSON);
		});
				
		// CSV export action listener
		csvExport.addActionListener(e->{
			openFileDialog(Mode.EXPORT, FileType.CSV);
		});
		
	
		fileMenu.add(importMenu);
		fileMenu.add(exportMenu);
		
		menuBar.add(fileMenu);
		this.setMenuBar(menuBar);
	}
	
	
	// Helper method for file importing/exporting
	private void openFileDialog(FileManager.Mode mode, FileManager.FileType type ) {
		
		// FileDialog requires integer constant
		int fdMode = mode == Mode.IMPORT ? FileDialog.LOAD : FileDialog.SAVE;
		
		FileDialog fd = new FileDialog(this, fdMode == FileDialog.LOAD ? "Import" : "Export", fdMode);
		fd.setVisible(true);
		
		// Helper variables
		String fileName = fd.getFile();
		String fileDirectory = fd.getDirectory();
		String expectedExtension;
		
		// If user clicks Cancel
		if(fileName == null) return;
		
		// Adding extension cases
		switch(type) {
		case JSON: expectedExtension = ".json"; 	break;
		case CSV: expectedExtension = ".csv"; 		break;
		default: expectedExtension = "";			break;
		}
		
		// Checking for extension
		if(!fileName.endsWith(expectedExtension)) {
			new ErrorDialog(this,"Invalid file format. Expected a " + 
							expectedExtension + " file.", "Please select a valid " + 
							expectedExtension + " file.");
			return;
		}

		// Paths.get returns String as return value
		Path path = Paths.get(fileDirectory,fileName);
		File file = path.toFile();
		
		// Delegate to FileManager for further processing
		fileManager.handle(file, type, mode);
		
	}
	
	// Helper method for text importing
	private void openTextDialog() {
		TextAreaDialog txtDialog = new TextAreaDialog(this, "AIRPORT format: CODE, NAME, X, Y"," FLIGHT format: FROM, TO, DEPARTURE, DURATION");
		String text = txtDialog.getInput();
		// TODO parsing
	}
}
