package gui;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Dialog;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public abstract class DefaultDialog extends Dialog implements WindowClosing {

	// Always accepts two messages
	public DefaultDialog(Frame owner, String dialogName, String msg0, String msg1) {
		
		// Third parameter defines if dialog is modal
		super(owner,dialogName,true);
		
		setLayout(new BorderLayout());
		setupWindowClosing(this);
		
		// Panels
		Panel buttonPanel = createButtonPanel();
		Panel labelPanel = new Panel(new GridLayout(0,1));
		
		// Add takes Component as parameter
		labelPanel.add(new Label(msg0,Label.CENTER));
		labelPanel.add(new Label(msg1,Label.CENTER));
		add(labelPanel,BorderLayout.NORTH);
		add(buttonPanel,BorderLayout.SOUTH);

	}
	
	// Helper class for button adding
	protected Panel createButtonPanel() {
		Button button = new Button();
		button.setLabel("        OK        ");							// Extra spaces as a half measure for button widening
		button.addActionListener(e->{ dispose(); });					// Closes dialog if X is pressed
		button.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				if(e.getKeyCode() == KeyEvent.VK_ENTER) {
					dispose();
				}	
			}
		});
		button.requestFocus();											// Button focused upon dialog box opening
		Panel buttonPanel = new Panel(new FlowLayout());				
		buttonPanel.add(button);
		return buttonPanel;
	}
}
