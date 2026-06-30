package model;

import java.util.ArrayList;
import java.util.List;

public class AirportTable implements Observable{
	
	private List<Observer> observers = new ArrayList<>();
	private List<Airport> airports = new ArrayList<>();
	

	@Override
	public void addObserver(Observer o) {
		observers.add(o);
	}

	@Override
	public void notifyObservers() {
		for(Observer o : observers) o.onObserverSignal();
	}
	
	public void add(Airport airport) {
		airports.add(airport);
		notifyObservers();
	}
	public boolean exists(String s) {
		
		for(Airport airport : airports) {
			if(airport.getCode().equals(s)) return true;
		}
		return false;
	}

}
