package model;

public class Airport {
	
	// Constants
	public static final int MIN_X = -180;
    public static final int MAX_X = 180;
    public static final int MIN_Y = -90;
    public static final int MAX_Y = 90;
    
    // Variables
	private String code;
	private String name;
	private int x;
	private int y;
	// TODO departureQueue, nextAvaliableTime
	
	public Airport(String code, String name, int x, int y) {
		
		this.code = code;
		this.name = name;
		this.x = x;
		this.y = y;
	}
	// Getter methods
	public String getCode() {return code;}
	public String getName() {return name;}
	public int getX() {return x;}
	public int getY() {return y;}
	
	// Setter methods
	public void setCode(String code) {this.code = code;}
	public void setName(String name) {this.name = name;}
	public void setX(int x) {this.x = x;}
	public void setY(int y) {this.y = y;}

}