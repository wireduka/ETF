package gui;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.TextArea;

public class TextAreaDialog extends DefaultDialog{
	
	private TextArea input = new TextArea();

	public TextAreaDialog(Frame owner, String msg0, String msg1) {
		
		// Third parameter defines if dialog is modal
		super(owner,"Enter values",msg0,msg1);
		setSize(1000,400);
		setLocationRelativeTo(owner);
		add(input,BorderLayout.CENTER);
		
		// Necessary in all classes that extend DefaultDialog
		setVisible(true);

	}
	public String getInput() {
		return input.getText();
		
	}
}
