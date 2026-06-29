package gui;

import java.awt.Frame;

public class ErrorDialog extends DefaultDialog{

	public ErrorDialog(Frame owner, String msg0, String msg1) {
		
		// Third parameter defines if dialog is modal
		super(owner,"Error",msg0,msg1);
		setSize(500,150);
		setLocationRelativeTo(owner);

		// Necessary in all classes that extend DefaultDialog
		setVisible(true);

	}
}
