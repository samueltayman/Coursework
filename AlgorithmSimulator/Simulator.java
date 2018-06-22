
/*************************************************************************************************
 *************************************************************************************************
 * 							Name: Samuel Tayman
 * 
 * 					  Assignment: Project 2 Demand Paging Simulator
 * 
 * 						Date Due: 12-17-2017
 * 
 ************************************************************************************************** 
 **************************************************************************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * The Simulator class displays a prompt and allows the user to select from a
 * menu of options to create, or generate a reference string. The user can then
 * choose from the prompt to simulate the following, FIFO page replacement OPT
 * page replacement LRU page replacement LFU page replacement
 * 
 * @author nicho
 *
 */
public class Simulator {

	// Number of physical frames
	static int physicalFrames = 0;
	// Number of virtual frames
	final int VIRTUAL_FRAMES = 20;
	// Integer array for LFU calculation
	static int[] referenceString;

	/*
	 * This method retrieves a number of physical frames specified by the user
	 */
	private void setNumPhysFrames() {
		System.out.println("Set a number of physical frames: ");
		Scanner scan = new Scanner(System.in);
		physicalFrames = scan.nextInt();
	}

	/*
	 * This method displays the possible options the user may specify
	 */
	private void printPrompt() {
		System.out.println("0 - Exit");
		System.out.println("1 - Read reference string");
		System.out.println("2 - Generate reference string");
		System.out.println("3 - Display current reference string");
		System.out.println("4 - Simulate FIFO");
		System.out.println("5 - Simulate OPT");
		System.out.println("6 - Simulate LRU");
		System.out.println("7 - Simulate LFU");
		System.out.print("Select option: ");
	}

	/*
	 * This method allows the user to select an option displayed
	 */
	private String selectOption() {
		Scanner scan = new Scanner(System.in);
		String input = scan.next();
		return input;
	}

	/*
	 * This method retrieves a reference string determined by the user and stores
	 * the input into an array
	 */
	private char[] readReference() {
		char[] array = new char[VIRTUAL_FRAMES];
		System.out.print("Set a reference string (less than " + VIRTUAL_FRAMES + " figures): ");
		Scanner scan = new Scanner(System.in);
		String input = scan.next();
		array = input.toCharArray();
		referenceString = new int[input.length()];
		for (int i = 0; i < input.length(); i++) {
			referenceString[i] = input.charAt(i) - '0';
		}
		return array;
	}

	/*
	 * This method generates a random reference string and stores the result in an
	 * array
	 */
	private char[] generateReference() {
		char[] array = new char[VIRTUAL_FRAMES];
		Random random = new Random();
		String input = "";
		for (int i = 0; i < VIRTUAL_FRAMES; i++) {
			input = input.concat(String.valueOf(random.nextInt(10)));
		}
		array = input.toCharArray();
		return array;
	}

	/*
	 * The simulateFIFO method takes an array with a reference string stored and
	 * runs a simulation of First-in First-out page replacement
	 */
	private void simulateFIFO(char[] array) {
		BufferedReader pause = new BufferedReader(new InputStreamReader(System.in));
		LinkedList<Character> fifoQueue = new LinkedList<Character>();
		int pageFaults = 0;
		for (int i = 0; i < array.length; i++) {
			if (fifoQueue.contains(array[i])) {
			} else {
				fifoQueue.addLast(array[i]);
				pageFaults++;
				if (fifoQueue.size() > physicalFrames) {
					fifoQueue.removeFirst();
				}
			}

			for (int j = 0; j < fifoQueue.size(); j++) {
				System.out.println("Physical frame " + j + ": " + fifoQueue.get(fifoQueue.size() - 1 - j));

			}

			try {
				String s = pause.readLine();
			} catch (IOException e) {

				e.printStackTrace();
			}

		}
		System.out.println("");
		System.out.println("Number of page faults: " + pageFaults);

	}

	/*
	 * The simulateOPT method takes an array with a reference string stored and runs
	 * a simulation of Belady's Optimal Algorithm for page replacement
	 */
	private void simulateOPT(char[] array) {
		BufferedReader pause = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<Character> list = new ArrayList<Character>();
		int pageFaults = 0;
		for (int i = 0; i < array.length; i++) {
			if (list.contains(array[i])) {
			} else if (list.size() < physicalFrames) {
				list.add(array[i]);
				pageFaults++;
			} else {
				LinkedList<Character> optQueue = new LinkedList<Character>();
				for (int j = i; j < array.length; j++) {
					optQueue.addLast(array[j]);
				}
				int count = 0;
				for (int k = 0; k < optQueue.size(); k++) {
					if (list.contains(optQueue.get(k))) {
						count++;
						if (count >= physicalFrames) {
							list.add(list.indexOf(optQueue.get(k)), array[i]);
							list.remove(optQueue.get(k));
							break;
						}
					}
				}
				if (count == 0) {
					if (optQueue.size() == 1) {
						list.remove(0);
						list.add(0, array[i]);
						break;
					}

				}
				pageFaults++;
			}

			for (int l = 0; l < list.size(); l++) {
				System.out.println("Physical frame " + l + ": " + list.get(l));
			}

			try {
				String s = pause.readLine();
			} catch (IOException e) {

				e.printStackTrace();
			}
		}
		System.out.println("");
		System.out.println("Number of page faults: " + pageFaults);
	}

	/*
	 * The simulateLRU method takes an array with a reference string stored and
	 * simulates the Least Recently Used page replacement algorithm
	 */
	private void simulateLRU(char[] array) {
		BufferedReader pause = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<Character> list = new ArrayList<Character>();
		int pageFaults = 0;
		for (int i = 0; i < array.length; i++) {
			if (list.contains(array[i])) {
			} else if (list.size() < physicalFrames) {
				list.add(array[i]);
				pageFaults++;
			} else {
				LinkedList<Character> lruQueue = new LinkedList<Character>();
				for (int j = 0; j < i; j++) {
					lruQueue.addFirst(array[j]);
				}
				int count = 0;
				for (int k = 0; k < lruQueue.size(); k++) {
					if (list.contains(lruQueue.get(k))) {
						count++;
						if (count >= physicalFrames) {
							list.add(list.indexOf(lruQueue.get(k)), array[i]);
							list.remove(lruQueue.get(k));
							break;
						}
					}
				}
				if (count == 0) {
					if (lruQueue.size() == 1) {
						list.add(0, array[i]);
						list.remove(0);
						break;
					}
				}
				pageFaults++;
			}
			for (int l = 0; l < list.size(); l++) {
				System.out.println("Physical frame " + l + ": " + list.get(l));
			}

			try {
				String s = pause.readLine();
			} catch (IOException e) {

				e.printStackTrace();
			}
		}
		System.out.println("");
		System.out.println("Number of page faults: " + pageFaults);
	}

	/*
	 * The simulateLFU takes an array with a reference string stored and simulates
	 * the Least Frequency Used page replacement algorithm
	 */
	private void simulateLFU(char[] array) {
		BufferedReader pause = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<Character> list = new ArrayList<Character>();
		int pageFaults = 0;

		int[] cache = new int[physicalFrames];
		int[] frequency = new int[physicalFrames];

		// Set cache array to negative default values; Reference strings cannot be
		// negative
		for (int i = 0; i < physicalFrames; i++) {
			cache[i] = -1;
		}

		for (int i = 0; i < array.length; i++) {

			int done = 0;
			int minFrequency = 100;
			int minFreqPos = -1;

			for (int j = 0; j < physicalFrames; j++) {

				if (cache[j] == referenceString[i]) {

					frequency[j]++;
					done = 1;
					break;
				}

			}

			if (done == 0) {

				for (int j = 0; j < physicalFrames; j++) {

					if (cache[j] == -1) {

						cache[j] = referenceString[i];
						frequency[j]++;
						done = 1;
						break;

					}

				}

			}

			if (done == 0) {
				for (int k = 0; k < physicalFrames; k++) {
					if (frequency[k] < minFrequency) {
						minFrequency = frequency[k];
						minFreqPos = k;
					}
				}
				cache[minFreqPos] = referenceString[i];
				frequency[minFreqPos] = 1;
			}

			for (int m = 0; m < physicalFrames; m++) {
				if (cache[m] != -1)
					System.out.println("Physical Frame " + m + ": " + cache[m]);

			}

			try {
				String s = pause.readLine();
			} catch (IOException e) {

				e.printStackTrace();
			}
			System.out.println("");

		}

		/*
		 * This loop is used to calculate page faults only
		 */
		for (int i = 0; i < array.length; i++) {
			if (list.contains(array[i])) {
			} else if (list.size() < physicalFrames) {
				list.add(array[i]);
				pageFaults++;
			} else {
				LinkedList<Character> lfuQueue = new LinkedList<Character>();
				for (int j = 0; j < i; j++) {
					lfuQueue.addFirst(array[j]);
				}
				TreeMap<Object, Integer> map = new TreeMap<Object, Integer>();
				Integer value = 1;
				for (int k = 0; k < lfuQueue.size(); k++) {
					Object key = lfuQueue.get(k);
					if (map.containsKey(key)) {
						value = value + 1;
						map.put(key, value);
					} else {
						map.put(key, value);
					}
				}
				pageFaults++;
			}

		}
		System.out.println("");
		System.out.println("Number of page faults: " + pageFaults);

	}

	public static void main(String[] args) {
		// Create instance of Simulator class
		Simulator pagingSimulator = new Simulator();

		// Ask user to set the number of Physical Frames
		pagingSimulator.setNumPhysFrames();

		// Array to hold reference string
		char[] reference = new char[8];

		// Used to check if a reference string is stored
		boolean hasReference = false;
		for (;;) {
			pagingSimulator.printPrompt();
			String option = pagingSimulator.selectOption();
			
			//Option to close program
			if (option.equals("0")) {
				System.out.println("Exit!");
				System.exit(0);
				break;
			} 
			//Option to run readReference method
			else if (option.equals("1")) {
				reference = pagingSimulator.readReference();
				hasReference = true;
				System.out.println("");
			} 
			//Option to run generateReference method
			else if (option.equals("2")) {
				reference = pagingSimulator.generateReference();
				System.out.println(reference);
				hasReference = true;
				System.out.println("");
			} 
			//Option to display reference string to user
			else if (option.equals("3")) {
				if (hasReference == true) {
					System.out.print("Current reference string is ");
					System.out.println(reference);
				} else {
					System.out.println("No reference string stored. Please set a reference string.");
				}
				System.out.println("");
			} 
			//Option to run simulateFIFO method
			else if (option.equals("4")) {
				if (hasReference == true) {
					pagingSimulator.simulateFIFO(reference);
				} else {
					System.out.println("No reference string stored. Please set a reference string.");
				}
				System.out.println("");
			} 
			//Option to run simulateOPT method
			else if (option.equals("5")) {
				if (hasReference == true) {
					pagingSimulator.simulateOPT(reference);
				} else {
					System.out.println("No reference string stored. Please set a reference string.");
				}
				System.out.println("");
			} 
			//Option to run simulateLRU method
			else if (option.equals("6")) {
				if (hasReference == true) {
					pagingSimulator.simulateLRU(reference);
				} else {
					System.out.println("No reference string stored. Please set a reference string.");
				}
				System.out.println("");
			} 
			//Option to run simulateLFU method
			else if (option.equals("7")) {
				if (hasReference == true) {
					pagingSimulator.simulateLFU(reference);
				} else {
					System.out.println("No reference string stored. Please set a reference string.");
				}
				System.out.println("");
			} else {
				System.out.println("Please enter a number between 0 and 7.");
				System.out.println("");
			}
		}
	}

}