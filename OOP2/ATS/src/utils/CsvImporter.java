package utils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;


public class CsvImporter implements Importable{

	@Override
	public void fileImport(File file) throws FileNotFoundException, IOException {
		
		try(BufferedReader reader = new BufferedReader(new FileReader(file))){
			
			String line;
			String section = null;
			ArrayList<ArrayList<String>> airports = new ArrayList<>();
			ArrayList<ArrayList<String>> flights = new ArrayList<>();
			
			while((line = reader.readLine()) != null) {
				
				// Checking for FLIGHTS/AIRPORTS section
				if(line.startsWith("#")) {
					section = line.trim();
					continue;
				}
				// Skip header row
				if(line.startsWith("CODE") || line.startsWith("FROM")) {
					continue;
				}
				// Skip empty rows
				if(line.isEmpty()) continue;
				
				// Add airport to ArrayList
				if(section.contains("AIRPORTS") && !line.isEmpty()) {
					ArrayList<String> airport = new ArrayList<>(Arrays.asList(line.split(",")));
					airports.add(airport);
				}
				// Add flight to ArrayList
				if(section.contains("FLIGHTS") && !line.isEmpty()) {
					ArrayList<String> flight = new ArrayList<>(Arrays.asList(line.split(",")));
					flights.add(flight);
				}
			};
		
		}
		
	}

}
