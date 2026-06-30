package utils;

import java.awt.Frame;
import java.util.ArrayList;
import java.util.List;

import exception.InvalidDataException;
import exception.InvalidFileFormatException;
import gui.TextDialog;
import model.Airport;
import model.AirportTable;
import model.FlightTable;

public class Parser {
	
	// Variables
	private AirportTable airportTable;
	private FlightTable flightTable;
	private Frame owner;
	
	// Main constructor
	public Parser(AirportTable airportTable, FlightTable flightTable, Frame owner) {
		this.airportTable = airportTable;
		this.flightTable = flightTable;
		this.owner = owner;
	}

	public void parse(TokenizedData tokens) throws InvalidFileFormatException, NumberFormatException, InvalidDataException{
		
		
		
		// Nothing for parser to parse
		if(tokens.airportTokens.isEmpty() && tokens.flightTokens.isEmpty()) throw new InvalidFileFormatException("File contains no data.");
		
		parseAirports(tokens.airportTokens);
	}
	
	public void parseAirports(List<List<String>> airportTokens) throws InvalidFileFormatException, NumberFormatException, InvalidDataException {
		
		List<String> duplicates = new ArrayList<>();
		
		for(List<String> airportToken : airportTokens) {
			if(airportToken.size() != 4) throw new InvalidFileFormatException("Invalid number of tokens, check file structure ");
			
			String code = airportToken.get(0);
			String name = airportToken.get(1);
			int x = Integer.parseInt(airportToken.get(2));
			int y = Integer.parseInt(airportToken.get(3));
			
			if(!isValidCode(code)) 
				throw new InvalidDataException("Code length must be 3 characters and written only using upper case letters, code in file: " + code);
			
			if(airportTable.exists(code)) {duplicates.add(code); continue;} 
			
			if((x > Airport.MAX_X || x < Airport.MIN_X) || (y > Airport.MAX_Y || y < Airport.MIN_Y))
				throw new InvalidDataException("X must be in interval [-180,180], Y must be in interval [-90,90], X: " + x + " Y:" + y);			
			
			Airport airport = new Airport(code,name,x,y);
			airportTable.add(airport);
		}
		
		if(!duplicates.isEmpty()) {
			new TextDialog(owner,"Duplicates!", "Airports skipped due to duplicate codes: ",String.join(", ", duplicates));
		}
		
	}
	
	public boolean isValidCode(String code) {
		return code.matches("[A-Z]{3}");
	}
}
