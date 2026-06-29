package gui;

import java.awt.FileDialog;
import utils.FileManager;
import utils.FileManager.FileType;
import utils.FileManager.Mode;
import java.awt.Frame;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.event.*;
import java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;

public class MainFrame extends Frame{
	
	// File managing
	private FileManager fileManager = new FileManager();
	// Frame constructor
	public MainFrame() {
		
		super("ATS");
		this.setSize(1600,800);
		setupWindowClosing();
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
		entry.addActionListener(null); // TODO
		
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
	
	// Method for window closing
	private void setupWindowClosing() {
		this.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				dispose();
			}
		});
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
		// If user clicks Cancel
		if(fileName == null) return;
		
		// Adding extension cases
		String expectedExtension = type == FileType.JSON ? ".json" : ".csv";
		
		// Import extension case
		if(mode == Mode.IMPORT && !fileName.endsWith(expectedExtension)) {
			// TODO ErrorDialog box
			return;
		}
		// Export extension case
		if(mode == Mode.EXPORT && !fileName.endsWith(expectedExtension)) {
			fileName += expectedExtension;
		}
		// Paths.get returns String as return value
		Path path = Paths.get(fileDirectory,fileName);
		File file = path.toFile();
		
		// Delegate to FileManager for further processing
		fileManager.handle(file, type, mode);
		
		
	}
	
	

}
