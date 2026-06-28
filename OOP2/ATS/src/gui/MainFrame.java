package gui;

import java.awt.Frame;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.event.*;

public class MainFrame extends Frame{
	
	// Frame constructor
	public MainFrame() {
		
		super("ATS");
		this.setSize(1600,800);
		
		
		this.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				dispose();
				
			}
		});
		setupMenu();
		this.setVisible(true);
		;
	}
	// Method for menu handling
	public void setupMenu() {
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
		
		// TODO action listeners for both menus
		
		fileMenu.add(importMenu);
		fileMenu.add(exportMenu);
		
		menuBar.add(fileMenu);
		this.setMenuBar(menuBar);
	}
	

}
